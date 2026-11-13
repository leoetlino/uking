#include "Game/Actor/Player/Action/actionPlayerBindSheikPad.h"

namespace uking::action {

PlayerBindSheikPad::PlayerBindSheikPad(const InitArg& arg) : PlayerBase(arg) {}

PlayerBindSheikPad::~PlayerBindSheikPad() = default;

bool PlayerBindSheikPad::init_(sead::Heap* heap) {
    return PlayerBase::init_(heap);
}

void PlayerBindSheikPad::loadParams_() {}

}  // namespace uking::action
