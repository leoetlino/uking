#pragma once

#include <container/seadRingBuffer.h>
#include <container/seadSafeArray.h>
#include <prim/seadSafeString.h>
#include "KingSystem/System/CoreInfo.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::gdt {

class FlagIncreaseQueue {
public:
    struct Record {
        bool debug = false;
        u32 name_hash = 0;
        s32 sub_idx = -1;
        s32 value = 0;
    };
    KSYS_CHECK_SIZE_NX150(Record, 0x10);

    void addRecord(s32 value, const sead::SafeString& name, s32 sub_idx, bool debug);

    u64 counts = 0;
    sead::SafeArray<sead::FixedRingBuffer<Record, 64>, NumCores> ring_buffers[2];
    sead::SafeArray<Record, 0xc0> arrays[2]{};
};

}  // namespace ksys::gdt
