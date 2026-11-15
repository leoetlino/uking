#pragma once

#include "KingSystem/Resource/resIOverlayArenaCoordinator.h"
#include "KingSystem/Utils/Types.h"

namespace uking {

class OverlayArenaCoordinator : public ksys::res::IOverlayArenaCoordinator {
public:
    OverlayArenaCoordinator();
    ~OverlayArenaCoordinator() override;

    void init() override;
    void onReleaseForegroundForShutdown() override;
    void prepareShutdown() override;
    void onReleaseForeground() override;
    void prepareDestroy() override;
    bool destroy() override;
    void restore() override;
    void waitForRestore() override;
    void finishRestore() override;
    bool enterMovieMode() override;
    void leaveMovieMode() override;
    void waitForLeaveMovieMode() override;
    void finishLeaveMovieMode() override;

    bool wasMainLayerVisible() const { return mMainLayerWasVisible; }

private:
    bool mMainLayerWasVisible = true;
};
KSYS_CHECK_SIZE_NX150(OverlayArenaCoordinator, 0x10);

}  // namespace uking
