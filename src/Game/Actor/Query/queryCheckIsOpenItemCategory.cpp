#include "Game/Actor/Query/queryCheckIsOpenItemCategory.h"
#include <evfl/Query.h>
#include "Game/gdtCommonFlags.h"

namespace uking::query {

CheckIsOpenItemCategory::CheckIsOpenItemCategory(const InitArg& arg) : ksys::act::ai::Query(arg) {}

CheckIsOpenItemCategory::~CheckIsOpenItemCategory() = default;

int CheckIsOpenItemCategory::doQuery() {
    return !getFlag_IsOpenItemCategory(*mCategory);
}

void CheckIsOpenItemCategory::loadParams(const evfl::QueryArg& arg) {
    loadInt(arg.param_accessor, "Category");
}

void CheckIsOpenItemCategory::loadParams() {
    getDynamicParam(&mCategory, "Category");
}

}  // namespace uking::query
