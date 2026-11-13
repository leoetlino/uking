#include "Game/ActorCaptureMgr.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/Resource/resEntryFactory.h"
#include "KingSystem/Resource/resLoadRequest.h"
#include "KingSystem/Resource/resResourceMgrTask.h"
#include "KingSystem/Resource/resSystem.h"
#include "KingSystem/Utils/SafeDelete.h"

namespace uking {

ActorCaptureMgr::ActorCaptureMgr() {
    mRes.reset();
    mTimer.reset(30.0);
}

ActorCaptureMgr::~ActorCaptureMgr() {
    mActor = nullptr;
    mCamera = nullptr;
    ksys::res::unregisterEntryFactory(mFactory);
    ksys::util::safeDelete(mFactory);
}

void ActorCaptureMgr::init(const InitArg& arg) {
    mFactory = new (arg.heap) ksys::res::EntryFactory<ksys::res::ActorCapture>(1.0, 0x1000);
    ksys::res::registerEntryFactory(mFactory, "bactcapt");

    ksys::res::LoadRequest req;
    req.mRequester = "ActorCaptureMgr";
    req._26 = false;
    mDummyFile.load("Actor/ActorCapture/Dummy.bactcapt", &req);
}

void ActorCaptureMgr::setCamera(ksys::act::Actor* camera) {
    if (camera)
        mCamera = camera;
}

void ActorCaptureMgr::loadCaptureParam() {
    if (!mActor || !mActor->getParam())
        return;

    const char* name = getCapturedActorName();
    if (!name)
        return;

    ksys::res::ActorCapture* param = nullptr;

    {
        ksys::res::LoadRequest req;
        req.mRequester = "ActorCaptureMgr";
        sead::FormatFixedSafeString<128> path("Actor/ActorCapture/%s.bactcapt", name);
        ksys::res::ResourceMgrTask::instance()->controlField9c0d88(false);
        auto* file = sead::DynamicCast<ksys::res::ActorCapture>(mCaptureParamFile.load(path, &req));
        ksys::res::ResourceMgrTask::instance()->controlField9c0d88(true);
        if (file)
            param = file;
        if (!param)
            param = sead::DynamicCast<ksys::res::ActorCapture>(mDummyFile.getResource());
    }

    mRes.mCameraInfoObj.copy(param->mCameraInfoObj);
    mRes.mActorInfoObj.copy(param->mActorInfoObj);
    mRes.mLightInfoObj.copy(param->mLightInfoObj);
}

}  // namespace uking
