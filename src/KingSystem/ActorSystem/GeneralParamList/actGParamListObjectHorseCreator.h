#pragma once

#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObject.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class GParamListObjectHorseCreator : public GParamListObject {
public:
    GParamListObjectHorseCreator() {
        auto* const obj = &mObj;

        mHorseNames.init("", "HorseNames", "", obj);
        mLeaderHorseNames.init("", "LeaderHorseNames", "", obj);
    }

    const char* getName() const override { return "HorseCreator"; }

    agl::utl::Parameter<sead::SafeString> mHorseNames;
    agl::utl::Parameter<sead::SafeString> mLeaderHorseNames;
};
KSYS_CHECK_SIZE_NX150(GParamListObjectHorseCreator, 0x88);

}  // namespace ksys::act
