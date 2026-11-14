#pragma once

#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObject.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class GParamListObjectEvent : public GParamListObject {
public:
    GParamListObjectEvent();
    const char* getName() const override { return "Event"; }

    agl::utl::Parameter<sead::SafeString> mVisibleOffActor1;
    agl::utl::Parameter<sead::SafeString> mVisibleOffActor2;
    agl::utl::Parameter<sead::SafeString> mVisibleOffActor3;
    agl::utl::Parameter<sead::SafeString> mVisibleOffActor4;
    agl::utl::Parameter<sead::SafeString> mVisibleOffActor5;
    agl::utl::Parameter<sead::SafeString> mVisibleOffActor6;
    agl::utl::Parameter<sead::SafeString> mVisibleOffActor7;
    agl::utl::Parameter<sead::SafeString> mVisibleOffActor8;
};
KSYS_CHECK_SIZE_NX150(GParamListObjectEvent, 0x178);

inline GParamListObjectEvent::GParamListObjectEvent() {
    auto* const obj = &mObj;

    mVisibleOffActor1.init("", "VisibleOffActor1", "", obj);
    mVisibleOffActor2.init("", "VisibleOffActor2", "", obj);
    mVisibleOffActor3.init("", "VisibleOffActor3", "", obj);
    mVisibleOffActor4.init("", "VisibleOffActor4", "", obj);
    mVisibleOffActor5.init("", "VisibleOffActor5", "", obj);
    mVisibleOffActor6.init("", "VisibleOffActor6", "", obj);
    mVisibleOffActor7.init("", "VisibleOffActor7", "", obj);
    mVisibleOffActor8.init("", "VisibleOffActor8", "", obj);
}

}  // namespace ksys::act
