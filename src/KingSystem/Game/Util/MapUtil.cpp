#include "KingSystem/Game/Util/MapUtil.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/Map/mapPlacementMgr.h"

namespace ksys::game {

bool printDebugMsg(act::PreActor* object, const sead::SafeString& msg, const char* config_name) {
    if (object == nullptr)
        return false;

    map::makeProjectMapMuuntPath(sead::FixedSafeString<0x200>(), object);
    return true;
}

bool printDebugMsg(act::Actor* actor, const sead::SafeString& msg, const char* config_name) {
    act::PreActor* o = actor->getMapObject();
    if (o == nullptr)
        return false;

    map::makeProjectMapMuuntPath(sead::FixedSafeString<0x200>(), o);
    return true;
}

}  // namespace ksys::game
