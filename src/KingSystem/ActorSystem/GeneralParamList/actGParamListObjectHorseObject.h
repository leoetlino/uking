#pragma once

#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObject.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class GParamListObjectHorseObject : public GParamListObject {
public:
    GParamListObjectHorseObject();
    const char* getName() const override { return "HorseObject"; }

    agl::utl::Parameter<bool> mHideHorseMane;
    agl::utl::Parameter<bool> mIsHorseClothDisable;
};

inline GParamListObjectHorseObject::GParamListObjectHorseObject() {
    auto* const obj = &mObj;

    mHideHorseMane.init(false, "HideHorseMane", "", obj);
    mIsHorseClothDisable.init(false, "IsHorseClothDisable", "", obj);
}

}  // namespace ksys::act
