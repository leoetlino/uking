#include "Game/Actor/Query/queryHasPorchArrow.h"
#include <evfl/Query.h>
#include "KingSystem/Game/System/UIGlue.h"

namespace uking::query {

HasPorchArrow::HasPorchArrow(const InitArg& arg) : ksys::act::ai::Query(arg) {}

HasPorchArrow::~HasPorchArrow() = default;

int HasPorchArrow::doQuery() {
    s32 arrow_cnt =
        ksys::game::getItemValue("NormalArrow") + ksys::game::getItemValue("FireArrow") +
        ksys::game::getItemValue("IceArrow") + ksys::game::getItemValue("ElectricArrow") +
        ksys::game::getItemValue("BombArrow_A") + ksys::game::getItemValue("AncientArrow");
    return arrow_cnt < *mCheckNum;
}

void HasPorchArrow::loadParams(const evfl::QueryArg& arg) {
    loadInt(arg.param_accessor, "CheckNum");
}

void HasPorchArrow::loadParams() {
    getDynamicParam(&mCheckNum, "CheckNum");
}

}  // namespace uking::query
