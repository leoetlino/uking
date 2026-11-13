#include "Game/Actor/Player/Action/actionPlayerEquipHaveMasterSword.h"

namespace uking::action {

PlayerEquipHaveMasterSword::PlayerEquipHaveMasterSword(const InitArg& arg) : PlayerBase(arg) {}

PlayerEquipHaveMasterSword::~PlayerEquipHaveMasterSword() = default;

bool PlayerEquipHaveMasterSword::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerEquipHaveMasterSword::enter_(ksys::act::ai::InlineParamPack* params) {
    PlayerBase::enter_(params);
}

void PlayerEquipHaveMasterSword::leave_() {
    PlayerBase::leave_();
}

void PlayerEquipHaveMasterSword::loadParams_() {}

void PlayerEquipHaveMasterSword::calc_() {
    PlayerBase::calc_();
}

}  // namespace uking::action
