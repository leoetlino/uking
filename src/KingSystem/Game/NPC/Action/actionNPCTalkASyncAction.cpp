#include "KingSystem/Game/NPC/Action/actionNPCTalkASyncAction.h"

namespace ksys::game {

NPCTalkASyncAction::NPCTalkASyncAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

NPCTalkASyncAction::~NPCTalkASyncAction() = default;

bool NPCTalkASyncAction::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void NPCTalkASyncAction::loadParams_() {
    getDynamicParam(&mDispFrame_d, "DispFrame");
    getDynamicParam(&mIsChecked_d, "IsChecked");
    getDynamicParam(&mMessageId_d, "MessageId");
}

}  // namespace ksys::game
