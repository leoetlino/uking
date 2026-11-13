#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>
#include <utility>

namespace ksys::act {
class ActorLinkConstDataAccess;
class BaseProc;
class BaseProcHandle;
class BaseProcUnit;
}  // namespace ksys::act

namespace ksys::frm {

/// Holds a reference to a BaseProc for safe, multi-threaded access.
class BaseProcAccessor {
public:
    BaseProcAccessor() = default;
    explicit BaseProcAccessor(act::BaseProc* proc) { acquire(proc); }
    /// Destructor that automatically releases any acquired BaseProc.
    ~BaseProcAccessor();

    BaseProcAccessor(const BaseProcAccessor&) = delete;
    BaseProcAccessor& operator=(const BaseProcAccessor&) = delete;
    BaseProcAccessor(BaseProcAccessor&& other) noexcept { *this = std::move(other); }
    BaseProcAccessor& operator=(BaseProcAccessor&& other) noexcept {
        std::swap(mAcquired, other.mAcquired);
        std::swap(mProc, other.mProc);
        return *this;
    }

    /// Acquire a BaseProc. This increments its reference count.
    /// If an actor was already acquired, it is released.
    bool acquire(act::BaseProc* proc);

    void release() { acquire(nullptr); }

    bool hasProc() const { return mProc != nullptr; }

protected:
    friend class act::ActorLinkConstDataAccess;
    friend class act::BaseProc;
    friend class act::BaseProcHandle;
    friend class act::BaseProcUnit;

    bool mAcquired = false;
    act::BaseProc* mProc = nullptr;
};

/// Acquire the specified BaseProc using `accessor`. Using ActorLinkConstDataAccess is mandatory
/// when acquiring from a low priority thread (see BaseProcMgr for a definition).
bool acquireProc(BaseProcAccessor* accessor, act::BaseProc* proc, const sead::SafeString& from,
                 s32 = 2);

}  // namespace ksys::frm
