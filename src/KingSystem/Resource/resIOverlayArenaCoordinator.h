#pragma once

namespace ksys::res {

class IOverlayArenaCoordinator {
public:
    virtual ~IOverlayArenaCoordinator() = default;

    virtual void init() = 0;
    virtual void onReleaseForegroundForShutdown() = 0;
    virtual void prepareShutdown() = 0;
    virtual void onReleaseForeground() = 0;
    virtual void prepareDestroy() = 0;
    virtual bool destroy() = 0;
    virtual void restore() = 0;
    virtual void waitForRestore() = 0;
    virtual void finishRestore() = 0;
    virtual bool enterMovieMode() = 0;
    virtual void leaveMovieMode() = 0;
    virtual void waitForLeaveMovieMode() = 0;
    virtual void finishLeaveMovieMode() = 0;
};

}  // namespace ksys::res
