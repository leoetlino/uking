#pragma once

#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObject.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class GParamListObjectMonsterShop : public GParamListObject {
public:
    GParamListObjectMonsterShop();
    const char* getName() const override { return "MonsterShop"; }

    agl::utl::Parameter<s32> mBuyMamo;
    agl::utl::Parameter<s32> mSellMamo;
};
KSYS_CHECK_SIZE_NX150(GParamListObjectMonsterShop, 0x78);

inline GParamListObjectMonsterShop::GParamListObjectMonsterShop() {
    auto* const obj = &mObj;

    mBuyMamo.init(0, "BuyMamo", "", obj);
    mSellMamo.init(0, "SellMamo", "", obj);
}

}  // namespace ksys::act
