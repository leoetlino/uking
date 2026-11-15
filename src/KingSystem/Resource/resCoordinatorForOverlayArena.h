#pragma once

#include "KingSystem/Utils/Types.h"

namespace ksys::res {

// FIXME: incomplete
class CoordinatorForOverlayArena final {
public:
    CoordinatorForOverlayArena();
    virtual ~CoordinatorForOverlayArena();

    // TODO: figure out if this is the same interface as OverlayArenaCoordinator.
    // Both have the exact same number of virtual functions and some of the functions
    // look somewhat similar (suspending threads, looping while waiting for their status to
    // change).

    virtual void init();
    // Resume resource compaction
    virtual void onReleaseForegroundForShutdown();
    virtual void prepareShutdown();
    // Resume resource compaction + EventMgr
    virtual void onReleaseForeground();
    // Stop threads, clear cache, etc.
    virtual void prepareDestroy();
    virtual bool destroy();
    virtual void restore();
    virtual void waitForRestore();
    // Does nothing
    virtual void finishRestore();
    virtual bool enterMovieMode();
    virtual void leaveMovieMode();
    virtual void waitForLeaveMovieMode();
    // Does nothing
    virtual void finishLeaveMovieMode();
};
KSYS_CHECK_SIZE_NX150(CoordinatorForOverlayArena, 0x8);

}  // namespace ksys::res
