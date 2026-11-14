#pragma once

#include <prim/seadSafeString.h>

namespace ksys::act {
class Actor;
class PreActor;
}  // namespace ksys::act

namespace ksys::map {

void* makeProjectMapMuuntPath(const sead::SafeString& path, act::PreActor* object);
bool printDebugMsg(act::PreActor* object, const sead::SafeString& msg, const char* config_name);
bool printDebugMsg(ksys::act::Actor* actor, const sead::SafeString& msg, const char* config_name);

}  // namespace ksys::map
