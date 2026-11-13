#include "Game/Actor/Query/queryCheckHorseCustomizeSelect.h"
#include <evfl/Query.h>
#include "Game/gdtCommonFlags.h"

namespace uking::query {

CheckHorseCustomizeSelect::CheckHorseCustomizeSelect(const InitArg& arg)
    : ksys::act::ai::Query(arg) {}

CheckHorseCustomizeSelect::~CheckHorseCustomizeSelect() = default;

int CheckHorseCustomizeSelect::doQuery() {
    if (getFlag_Shop_IsDecide()) {
        s32 state = getFlag_Shop_CurrentItemState();
        if (state == 0)
            return 0;
        if (state == 0xF)
            return 1;
    }
    return 2;
}

void CheckHorseCustomizeSelect::loadParams(const evfl::QueryArg& arg) {}

void CheckHorseCustomizeSelect::loadParams() {}

}  // namespace uking::query
