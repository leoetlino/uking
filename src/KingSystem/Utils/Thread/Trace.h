
#pragma once

#include <prim/seadSafeString.h>
#include "KingSystem/Utils/Types.h"

namespace ksys {

// This is used in CreatePlayerEquipActorMgr and CreatePlayerTrashActorMgr
// and nowhere else. It's completely stubbed out, so the implementation is purely by usage-based
// guess

// This exists because makeScope doesn't match
// when made an inlined function in Tracer
// i.e. tracer.trace()->makeScope() matches but not tracer.makeScope()
class Trace;

class TraceScope {
public:
    TraceScope(Trace* trace, const sead::SafeString& name, const sead::SafeString& caller,
               s32 level);
    virtual ~TraceScope();

private:
    Trace* mTrace = nullptr;
};
KSYS_CHECK_SIZE_NX150(TraceScope, 0x10);

class Trace {
public:
    TraceScope makeScope(const sead::SafeString& name, const sead::SafeString& caller, s32 level) {
        return {this, name, caller, level};
    }
    static Trace* make(const sead::SafeString& name, s32 level);
};

class Tracer {
public:
    void init(const sead::SafeString& name) { mTrace = Trace::make(name, 0); }
    void finish();
    Trace* trace() { return mTrace; }

private:
    Trace* mTrace = nullptr;
};
KSYS_CHECK_SIZE_NX150(Tracer, 0x8);

}  // namespace ksys
