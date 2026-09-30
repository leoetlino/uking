#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"
#include "KingSystem/Game/Area/Action/actionFireObserveBase.h"

namespace uking::action {

class AreaFireObserve : public FireObserveBase {
    SEAD_RTTI_OVERRIDE(AreaFireObserve, FireObserveBase)
public:
    explicit AreaFireObserve(const InitArg& arg);

protected:
};

}  // namespace uking::action
