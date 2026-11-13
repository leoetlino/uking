#include "Game/Actor/Player/Action/actionPlayerUnbindSheikPad.h"

namespace uking::action {

PlayerUnbindSheikPad::PlayerUnbindSheikPad(const InitArg& arg) : PlayerBase(arg) {}

PlayerUnbindSheikPad::~PlayerUnbindSheikPad() = default;

bool PlayerUnbindSheikPad::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerUnbindSheikPad::loadParams_() {}

}  // namespace uking::action
