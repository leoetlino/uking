#include "Game/Actor/Query/queryCheckShopSelectedItemName.h"
#include <evfl/Query.h>
#include "Game/gdtCommonFlags.h"

namespace uking::query {

CheckShopSelectedItemName::CheckShopSelectedItemName(const InitArg& arg)
    : ksys::act::ai::Query(arg) {}

CheckShopSelectedItemName::~CheckShopSelectedItemName() = default;

int CheckShopSelectedItemName::doQuery() {
    const char* result = &sead::SafeString::cNullChar;
    getStr64ByKey(&result, "Shop_SelectItemName");
    return mPorchItemName == result;
}

void CheckShopSelectedItemName::loadParams(const evfl::QueryArg& arg) {
    loadString(arg.param_accessor, "PorchItemName");
}

void CheckShopSelectedItemName::loadParams() {
    getDynamicParam(&mPorchItemName, "PorchItemName");
}

}  // namespace uking::query
