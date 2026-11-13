#include "Game/Actor/Player/Action/actionPlayerRequestRecreateDyeArmor.h"

namespace uking::action {

PlayerRequestRecreateDyeArmor::PlayerRequestRecreateDyeArmor(const InitArg& arg)
    : PlayerBase(arg) {}

PlayerRequestRecreateDyeArmor::~PlayerRequestRecreateDyeArmor() = default;

bool PlayerRequestRecreateDyeArmor::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerRequestRecreateDyeArmor::loadParams_() {}

}  // namespace uking::action
