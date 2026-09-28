#include "KingSystem/ActorSystem/actActorConstDataAccess.h"
#include <prim/seadRuntimeTypeInfo.h>
#include "KingSystem/ActorSystem/actActor.h"

namespace ksys::act {

bool acquireActor(BaseProcLink* link, ActorConstDataAccess* accessor) {
    return link->getProcInContext([accessor](BaseProc* proc, bool valid) {
        if (!proc) {
            if (!valid)
                accessor->acquire(nullptr);
            return false;
        }
        return accessor->acquire(sead::DynamicCast<Actor>(proc));
    });
}

}  // namespace ksys::act
