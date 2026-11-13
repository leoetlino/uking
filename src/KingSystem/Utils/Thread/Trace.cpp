#include "KingSystem/Utils/Thread/Trace.h"

namespace ksys {

TraceScope::TraceScope(Trace* trace, const sead::SafeString& name, const sead::SafeString& caller,
                       s32 level) {
    mTrace = trace;
}

TraceScope::~TraceScope() {
    // force D1 to be non-trivial
    ;
}

Trace* Trace::make(const sead::SafeString& name, s32 level) {
    return nullptr;
}

void Tracer::finish() {}

}  // namespace ksys
