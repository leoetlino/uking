#include "KingSystem/Game/Action/actionArmorBindWithAS.h"

namespace ksys::game {

ArmorBindWithAS::ArmorBindWithAS(const InitArg& arg) : ArmorBindAction(arg) {}

ArmorBindWithAS::~ArmorBindWithAS() = default;

void ArmorBindWithAS::enter_(ksys::act::ai::InlineParamPack* params) {
    ArmorBindAction::enter_(params);
}

void ArmorBindWithAS::leave_() {
    ArmorBindAction::leave_();
}

void ArmorBindWithAS::loadParams_() {
    ArmorBindAction::loadParams_();
    getDynamicParam(&mASName_d, "ASName");
}

}  // namespace ksys::game
