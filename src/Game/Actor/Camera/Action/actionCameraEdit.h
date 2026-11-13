#pragma once

#include "Game/Actor/actActionEx.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class CameraEdit : public act::ActionEx {
    SEAD_RTTI_OVERRIDE(CameraEdit, act::ActionEx)
public:
    explicit CameraEdit(const InitArg& arg);
    ~CameraEdit() override;

    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void loadParams_() override;

protected:
    // static_param at offset 0x20
    const char* mNormal_s{};
    // static_param at offset 0x28
    const char* mLockOn_s{};
    // static_param at offset 0x30
    const char* mWall_s{};
    // static_param at offset 0x38
    const char* mNormalSubject_s{};
    // static_param at offset 0x40
    const char* mBow_s{};
    // static_param at offset 0x48
    const char* mBowSquat_s{};
    // static_param at offset 0x50
    const char* mBowLockOn_s{};
};

}  // namespace uking::action
