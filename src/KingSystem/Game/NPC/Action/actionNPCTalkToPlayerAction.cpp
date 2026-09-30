#include "KingSystem/Game/NPC/Action/actionNPCTalkToPlayerAction.h"

namespace ksys::game {

NPCTalkToPlayerAction::NPCTalkToPlayerAction(const InitArg& arg) : ksys::act::ai::Action(arg) {}

NPCTalkToPlayerAction::~NPCTalkToPlayerAction() = default;

void NPCTalkToPlayerAction::loadParams_() {
    getDynamicParam(&mMessageId_d, "MessageId");
    getDynamicParam(&mASKeyName_d, "ASKeyName");
}

}  // namespace ksys::game
