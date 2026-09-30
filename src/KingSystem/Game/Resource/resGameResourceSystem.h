#pragma once

#include <heap/seadDisposer.h>

namespace ksys::game {

class CompactionMgr;

// Also known as game::ResourceSystem (?)
class ResourceSystem {
    SEAD_SINGLETON_DISPOSER(ResourceSystem)
    ResourceSystem() = default;
    virtual ~ResourceSystem();

public:
    struct InitArg {
        sead::Heap* heap;
    };

    bool init(const InitArg& arg);

    void calc();
    void pauseCompaction();
    void resumeCompaction();

private:
    CompactionMgr* mCompactionMgr = nullptr;
    bool mPauseCompaction = false;
};

class ScopedCompactionPauser {
public:
    ScopedCompactionPauser() { ResourceSystem::instance()->pauseCompaction(); }
    ~ScopedCompactionPauser() { ResourceSystem::instance()->resumeCompaction(); }
    ScopedCompactionPauser(const ScopedCompactionPauser&) = delete;
    ScopedCompactionPauser(ScopedCompactionPauser&&) = delete;
    auto operator=(const ScopedCompactionPauser&) = delete;
    auto operator=(ScopedCompactionPauser&&) = delete;
};

}  // namespace ksys::game
