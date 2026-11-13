#include "Game/Actor/Player/Action/actionPlayerParashawlGlideBase.h"

namespace uking::action {

PlayerParashawlGlideBase::PlayerParashawlGlideBase(const InitArg& arg) : PlayerBase(arg) {}

void PlayerParashawlGlideBase::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerParashawlGlideBase::leave_() {
    PlayerBase::leave_();
}

void PlayerParashawlGlideBase::loadParams_() {
    getStaticParam(&mGlideSpeedMax_s, "GlideSpeedMax");
    getStaticParam(&mLv2GlideSpeedMax_s, "Lv2GlideSpeedMax");
    getStaticParam(&mGlideBodyFrontX_s, "GlideBodyFrontX");
    getStaticParam(&mGlideBodyBackX_s, "GlideBodyBackX");
    getStaticParam(&mGlideBodySideZ_s, "GlideBodySideZ");
    getStaticParam(&mGlideRotMax_s, "GlideRotMax");
    getStaticParam(&mGlideRotMin_s, "GlideRotMin");
    getStaticParam(&mGlideRotRate_s, "GlideRotRate");
    getStaticParam(&mWindScale_s, "WindScale");
    getStaticParam(&mOverSpeedDec_s, "OverSpeedDec");
    getStaticParam(&mGlideRotSpeed_s, "GlideRotSpeed");
    getStaticParam(&mGlideNoSideAngle_s, "GlideNoSideAngle");
}

void PlayerParashawlGlideBase::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
