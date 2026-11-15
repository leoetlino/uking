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
    virtual void m3();
    virtual void m4();
    // Resume resource compaction + EventMgr
    virtual void m5();
    // Stop threads, clear cache, etc.
    virtual void m6();
    virtual bool m7();
    virtual void m8();
    virtual void m9();
    // Does nothing
    virtual void m10();
    virtual bool m11();
    virtual void m12();
    virtual void m13();
    // Does nothing
    virtual void m14();
};
KSYS_CHECK_SIZE_NX150(CoordinatorForOverlayArena, 0x8);

}  // namespace ksys::res
