#include "KingSystem/GameData/gdtFlagIncreaseQueue.h"
#include <codec/seadHashCRC32.h>
#include <mc/seadCoreInfo.h>

namespace ksys::gdt {

void FlagIncreaseQueue::addRecord(s32 value, const sead::SafeString& name, s32 sub_idx,
                                  bool debug) {
    const u32 name_hash = sead::HashCRC32::calcStringHash(name);
    const auto core = sead::CoreInfo::getCurrentCoreId();
    const u32 platform_core_id = sead::CoreInfo::getPlatformCoreId(core);

    Record record;
    record.debug = debug;
    record.name_hash = name_hash;
    record.sub_idx = sub_idx;
    record.value = value;
    ring_buffers[0][platform_core_id].pushBack(record);
}

}  // namespace ksys::gdt
