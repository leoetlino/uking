#include "Game/Actor/Query/queryGeneralChoice8.h"
#include <evfl/Query.h>
#include "KingSystem/Game/Util/ActorUtil.h"

namespace uking::query {

GeneralChoice8::GeneralChoice8(const InitArg& arg) : ksys::act::ai::Query(arg) {}

GeneralChoice8::~GeneralChoice8() = default;

// FIXME: implement
int GeneralChoice8::doQuery() {
    s32 idx = ksys::game::getSelectedChoiceIdx(8, getName());
    if (idx < 0)
        return 0;

    return idx;
}

void GeneralChoice8::loadParams(const evfl::QueryArg& arg) {}

void GeneralChoice8::loadParams() {}

}  // namespace uking::query
