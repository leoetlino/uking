#include "KingSystem/ActorSystem/actionDemoGetItem.h"

namespace ksys::act::ai {

DemoGetItem::DemoGetItem(const InitArg& arg) : Action(arg) {}

DemoGetItem::~DemoGetItem() = default;

bool DemoGetItem::init_(sead::Heap* heap) {
    return Action::init_(heap);
}

void DemoGetItem::loadParams_() {}

}  // namespace ksys::act::ai
