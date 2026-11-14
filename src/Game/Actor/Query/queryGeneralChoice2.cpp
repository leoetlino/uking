#include "Game/Actor/Query/queryGeneralChoice2.h"
#include <evfl/Query.h>
#include "KingSystem/Game/Util/ActorUtil.h"

namespace uking::query {

GeneralChoice2::GeneralChoice2(const InitArg& arg) : ksys::act::ai::Query(arg) {}

GeneralChoice2::~GeneralChoice2() = default;

int GeneralChoice2::doQuery() {
    s32 idx = ksys::game::getSelectedChoiceIdx(2, getName());
    if (idx < 0)
        return 0;

    return idx;
}

void GeneralChoice2::loadParams(const evfl::QueryArg& arg) {}

void GeneralChoice2::loadParams() {}

}  // namespace uking::query
