#include "Game/Actor/Query/queryCheckManufactResult.h"
#include <evfl/Query.h>
#include "Game/gdtCommonFlags.h"

namespace uking::query {

CheckManufactResult::CheckManufactResult(const InitArg& arg) : ksys::act::ai::Query(arg) {}

CheckManufactResult::~CheckManufactResult() = default;

static constexpr s32 sManufactResults[8] = {0, 6, 4, 6, 1, 2, 3, 5};

int CheckManufactResult::doQuery() {
    if (getFlag_Shop_IsDecide()) {
        s32 state = getFlag_Shop_CurrentItemState();
        if (state < 8 && state >= 0)
            return sManufactResults[state];
    }
    return 6;
}

void CheckManufactResult::loadParams(const evfl::QueryArg& arg) {}

void CheckManufactResult::loadParams() {}

}  // namespace uking::query
