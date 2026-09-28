#pragma once

#include <prim/seadSafeString.h>

namespace ksys::act {
class Actor;
}  // namespace ksys::act

namespace ksys::map {

class PreActor;

void* makeProjectMapMuuntPath(const sead::SafeString& path, PreActor* object);
bool printDebugMsg(PreActor* object, const sead::SafeString& msg, const char* config_name);
bool printDebugMsg(ksys::act::Actor* actor, const sead::SafeString& msg, const char* config_name);

}  // namespace ksys::map
