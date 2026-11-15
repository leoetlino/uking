#pragma once

#include "KingSystem/Resource/resOverlayArenaSystem.h"
#include "KingSystem/Utils/Types.h"

namespace uking {

class OverlayArenaCoordinator : public ksys::res::ISystemPauseMgr {
public:
    OverlayArenaCoordinator();
    ~OverlayArenaCoordinator() override;

    void m2() override;
    void waitForOnUiActorMgrAndBlockSaveMaybe() override;
    void stopNfpAndWaitForSaveMgr() override;
    void waitForOnUiActorMgr() override;
    void pauseGameSceneAndWait() override;
    bool releaseScreensAndShowMainLayer() override;
    void onSystemPauseResume() override;
    void waitForStageGenFinalStep() override;
    void restoreMainLayerAndResumeGameScene() override;
    bool hideMainLayer() override;
    void openFadeScreen() override;
    void showMainLayerAndPauseProcJobs() override;
    void clearHideMainLayerAndResumeEvents() override;

    bool wasMainLayerVisible() const { return mMainLayerWasVisible; }

private:
    bool mMainLayerWasVisible = true;
};
KSYS_CHECK_SIZE_NX150(OverlayArenaCoordinator, 0x10);

}  // namespace uking
