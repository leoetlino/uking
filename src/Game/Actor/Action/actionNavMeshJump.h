#pragma once

#include "Game/Actor/Action/actionJumpToTargetBase.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class NavMeshJump : public JumpToTargetBase {
    SEAD_RTTI_OVERRIDE(NavMeshJump, JumpToTargetBase)
public:
    explicit NavMeshJump(const InitArg& arg);

protected:
};

}  // namespace uking::action
