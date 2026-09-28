#!/usr/bin/env python3
"""Check data/function_groups.yml against data/uking_functions.csv.

Every function must lie entirely inside exactly one range, ranges must not overlap,
and group paths must be unique. Exits non-zero on the first category of failure.
"""

import bisect
import csv
import re
import sys
from pathlib import Path

import yaml

DATA = Path(__file__).resolve().parent.parent / "data"
RANGE = re.compile(r"^0x([0-9a-fA-F]+)-0x([0-9a-fA-F]+)$")
MAX_REPORTED = 20


class UniqueKeyLoader(yaml.SafeLoader):
    def construct_mapping(self, node, deep=False):
        seen = set()
        for key_node, _ in node.value:
            key = self.construct_object(key_node, deep=deep)
            if key in seen:
                raise yaml.YAMLError(f"duplicate group path {key!r} at line {key_node.start_mark.line + 1}")
            seen.add(key)
        return super().construct_mapping(node, deep)


def load_ranges(path: Path) -> list[tuple[int, int, str]]:
    try:
        groups = yaml.load(path.read_text(), Loader=UniqueKeyLoader)
    except yaml.YAMLError as error:
        fail("invalid YAML", [str(error)])
    errors = []
    ranges = []
    for group, spans in groups.items():
        if not isinstance(spans, list) or not spans:
            errors.append(f"{group}: expected a non-empty list of ranges")
            continue
        for span in spans:
            match = RANGE.match(str(span))
            if not match:
                errors.append(f"{group}: malformed range {span!r}")
                continue
            start, end = int(match.group(1), 16), int(match.group(2), 16)
            if start >= end:
                errors.append(f"{group}: empty range {span}")
                continue
            ranges.append((start, end, group))
    if errors:
        fail("malformed entries", errors)
    return sorted(ranges)


def fail(title: str, problems: list[str]) -> None:
    print(f"{title} ({len(problems)}):")
    for problem in problems[:MAX_REPORTED]:
        print(f"  {problem}")
    if len(problems) > MAX_REPORTED:
        print(f"  ... and {len(problems) - MAX_REPORTED} more")
    sys.exit(1)


def main() -> None:
    ranges = load_ranges(DATA / "function_groups.yml")

    overlaps = [
        f"{group_a} {start_a:#x}-{end_a:#x} overlaps {group_b} {start_b:#x}-{end_b:#x}"
        for (start_a, end_a, group_a), (start_b, end_b, group_b) in zip(ranges, ranges[1:])
        if end_a > start_b
    ]
    if overlaps:
        fail("overlapping ranges", overlaps)

    starts = [start for start, _, _ in ranges]
    used = [False] * len(ranges)
    uncovered = []
    with open(DATA / "uking_functions.csv", newline="") as file:
        for row in csv.DictReader(file):
            address, size = int(row["Address"], 16), int(row["Size"])
            i = bisect.bisect_right(starts, address) - 1
            if i < 0 or address + size > ranges[i][1]:
                uncovered.append(f"{address:#x} {row['Name']} (size {size})")
                continue
            used[i] = True
    if uncovered:
        fail("functions outside every range or straddling a range end", uncovered)

    unused = [f"{group} {start:#x}-{end:#x}" for (start, end, group), hit in zip(ranges, used) if not hit]
    if unused:
        fail("ranges containing no function", unused)

    print(f"ok: {len(ranges)} ranges in {len({group for _, _, group in ranges})} groups cover every function")


if __name__ == "__main__":
    main()
