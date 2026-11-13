#pragma once

#include "Game/Actor/AI/aiCloseAttack.h"
#include "KingSystem/ActorSystem/actAiAi.h"

namespace uking::ai {

class CloseSmallAttack : public CloseAttack {
    SEAD_RTTI_OVERRIDE(CloseSmallAttack, CloseAttack)
public:
    explicit CloseSmallAttack(const InitArg& arg);
    ~CloseSmallAttack() override;

protected:
};

}  // namespace uking::ai
