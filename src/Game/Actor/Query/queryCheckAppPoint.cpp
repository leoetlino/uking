#include "Game/Actor/Query/queryCheckAppPoint.h"
#include <evfl/Query.h>
#include "Game/gdtCommonFlags.h"

namespace uking::query {

CheckAppPoint::CheckAppPoint(const InitArg& arg) : ksys::act::ai::Query(arg) {}

CheckAppPoint::~CheckAppPoint() = default;

int CheckAppPoint::doQuery() {
    s32 reach = getS32ByKey("ReachPointActorDiscoverNum");
    s32 use = getS32ByKey("App_ExtendUsePoint");
    return reach - use > 1;
}

void CheckAppPoint::loadParams(const evfl::QueryArg& arg) {}

void CheckAppPoint::loadParams() {}

}  // namespace uking::query
