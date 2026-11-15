#pragma once

#include <heap/seadDisposer.h>
#include <prim/seadSafeString.h>
#include "KingSystem/ActorSystem/actASSetting.h"
#include "KingSystem/Resource/resResourceBinder.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

// FIXME: very incomplete
class ASSettingMgr {
    SEAD_SINGLETON_DISPOSER(ASSettingMgr)
    ASSettingMgr() = default;
    virtual ~ASSettingMgr() = default;

public:
    void init(const sead::SafeString& config_path, sead::Heap* heap);
    ASParamParser* getBoneParams(const sead::SafeString& key) const;

private:
    res::ResourceBinder mHandle;
};
KSYS_CHECK_SIZE_NX150(ASSettingMgr, 0x78);

}  // namespace ksys::act
