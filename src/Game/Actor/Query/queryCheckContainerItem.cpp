#include "Game/Actor/Query/queryCheckContainerItem.h"
#include <evfl/Query.h>
#include "KingSystem/ActorSystem/actTag.h"
#include "KingSystem/Game/Util/ActorUtil.h"

namespace uking::query {

CheckContainerItem::CheckContainerItem(const InitArg& arg) : ksys::act::ai::Query(arg) {}

CheckContainerItem::~CheckContainerItem() = default;

int CheckContainerItem::doQuery() {
    if (ksys::game::hasTag(mPorchItemName, ksys::act::tags::HeartContainer))
        return 1;

    if (ksys::game::hasTag(mPorchItemName, ksys::act::tags::StaminaContainer))
        return 1;

    return 0;
}

void CheckContainerItem::loadParams(const evfl::QueryArg& arg) {
    loadString(arg.param_accessor, "PorchItemName");
}

void CheckContainerItem::loadParams() {
    getDynamicParam(&mPorchItemName, "PorchItemName");
}

}  // namespace uking::query
