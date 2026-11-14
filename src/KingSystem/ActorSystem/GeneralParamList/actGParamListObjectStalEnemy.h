#pragma once

#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObject.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class GParamListObjectStalEnemy : public GParamListObject {
public:
    GParamListObjectStalEnemy() {
        auto* const obj = &mObj;

        mHeadActorName.init("", "HeadActorName", "", obj);
        mLeftArmActorName.init("", "LeftArmActorName", "", obj);
    }

    const char* getName() const override { return "StalEnemy"; }

    agl::utl::Parameter<sead::SafeString> mHeadActorName;
    agl::utl::Parameter<sead::SafeString> mLeftArmActorName;
};
KSYS_CHECK_SIZE_NX150(GParamListObjectStalEnemy, 0x88);

}  // namespace ksys::act
