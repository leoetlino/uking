#pragma once

#include <prim/seadDelegate.h>
#include "KingSystem/Utils/Types.h"

namespace ksys {

class CoordinatorForOverlayArena;
class ISystemPauseMgr;

// FIXME: incomplete
class CoordinatorDeferredRequest {
public:
    struct InitArg {
        CoordinatorForOverlayArena* system_coordinator;
        ISystemPauseMgr* system_pause_mgr;
    };

    CoordinatorDeferredRequest();

    void init(const InitArg& arg);

private:
    u32 _0 = 0;
    sead::Delegate1R<CoordinatorDeferredRequest, void*, bool> mDelegate;
    u32 _28 = 1;
    void* _30 = nullptr;
    void* _38 = nullptr;
};
KSYS_CHECK_SIZE_NX150(CoordinatorDeferredRequest, 0x40);

}  // namespace ksys
