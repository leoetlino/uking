#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>
#include "KingSystem/Resource/Actor/resResourceActorCapture.h"
#include "KingSystem/Resource/resHandle.h"
#include "KingSystem/System/Timer.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {
class Actor;
}

namespace ksys::res {
class EntryFactoryBase;
}

namespace uking {

// TODO: incomplete
class ActorCaptureMgr {
public:
    struct InitArg {
        sead::Heap* heap;
    };

    ActorCaptureMgr();
    virtual ~ActorCaptureMgr();

    void init(const InitArg& arg);
    void setCamera(ksys::act::Actor* camera);

    void loadCaptureParam();
    const char* getCapturedActorName() const;

private:
    ksys::act::Actor* mActor{};
    ksys::act::Actor* mCamera{};
    ksys::res::EntryFactoryBase* mFactory{};
    ksys::res::Handle mDummyFile;
    ksys::res::Handle mCaptureParamFile;
    sead::FixedSafeString<64> mStr;
    sead::FixedSafeString<256> mStr2;
    ksys::res::ActorCapture mRes;
    struct Field768 {
        Field768() {
            _76c = 0;
            _768 = 0;
        }
        u32 _768;
        u8 _76c;
    } _768;
    s32 _770 = -1;
    u32 _774{};
    u32 _778{};
    ksys::Timer mTimer;
};
KSYS_CHECK_SIZE_NX150(ActorCaptureMgr, 0x788);

}  // namespace uking
