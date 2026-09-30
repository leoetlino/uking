#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace ksys::game {

class EventAutoSaveAction : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(EventAutoSaveAction, ksys::act::ai::Action)
public:
    explicit EventAutoSaveAction(const InitArg& arg);
    ~EventAutoSaveAction() override;

protected:
};

}  // namespace ksys::game
