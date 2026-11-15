#pragma once

#include "KingSystem/Resource/resIOverlayArenaCoordinator.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::res {

// FIXME: incomplete
class CoordinatorForOverlayArena : public IOverlayArenaCoordinator {
public:
    CoordinatorForOverlayArena();
    ~CoordinatorForOverlayArena() override;

    void init() override;
    // Resume resource compaction
    void onReleaseForegroundForShutdown() override;
    void prepareShutdown() override;
    // Resume resource compaction + EventMgr
    void onReleaseForeground() override;
    // Stop threads, clear cache, etc.
    void prepareDestroy() override;
    bool destroy() override;
    void restore() override;
    void waitForRestore() override;
    // Does nothing
    void finishRestore() override;
    bool enterMovieMode() override;
    void leaveMovieMode() override;
    void waitForLeaveMovieMode() override;
    // Does nothing
    void finishLeaveMovieMode() override;
};
KSYS_CHECK_SIZE_NX150(CoordinatorForOverlayArena, 0x8);

}  // namespace ksys::res
