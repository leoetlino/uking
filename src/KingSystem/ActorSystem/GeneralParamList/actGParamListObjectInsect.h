#pragma once

#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObject.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class GParamListObjectInsect : public GParamListObject {
public:
    GParamListObjectInsect();
    const char* getName() const override { return "Insect"; }

    agl::utl::Parameter<s32> mFireResistanceLevel;
};
KSYS_CHECK_SIZE_NX150(GParamListObjectInsect, 0x58);

inline GParamListObjectInsect::GParamListObjectInsect() {
    auto* const obj = &mObj;

    mFireResistanceLevel.init(0, "FireResistanceLevel", "", obj);
}

}  // namespace ksys::act
