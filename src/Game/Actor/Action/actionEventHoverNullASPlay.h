#pragma once

#include "Game/Actor/Action/actionEventNullASPlayBase.h"
#include "Game/Actor/actTemporaryMotionTypeChanger.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class EventHoverNullASPlay : public EventNullASPlayBase {
    SEAD_RTTI_OVERRIDE(EventHoverNullASPlay, EventNullASPlayBase)
public:
    explicit EventHoverNullASPlay(const InitArg& arg);
    ~EventHoverNullASPlay() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    void resetAllMotion(ksys::act::Actor* actor) {
        mMotionTypeChanger.resetRigidBodyMotion(actor);
        mMotionTypeChanger.resetMotionType(actor->getCharacterController());
    }

    act::TemporaryMotionTypeChanger mMotionTypeChanger;
};

}  // namespace uking::action
