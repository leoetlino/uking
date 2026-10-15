#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace sead {
class ExpHeap;
}  // namespace sead

namespace xlink2 {
class Handle;
}  // namespace xlink2

namespace ksys::snd {

class SoundProxy;

enum class SoundProxyShapeType {
    None,
    Sphere,
    Capsule,
    Box,
    Cylinder,
};

class SoundProxyRootAction : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(SoundProxyRootAction, ksys::act::ai::Action)
public:
    explicit SoundProxyRootAction(const InitArg& arg);
    ~SoundProxyRootAction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    bool mIsActive{};
    SoundProxy* mSoundProxy{};
    sead::ExpHeap* mHeap{};
    SoundProxyShapeType mShapeType{};
    xlink2::Handle* mWaitEventHandle{};
};
KSYS_CHECK_SIZE_NX150(SoundProxyRootAction, 0x40);

}  // namespace ksys::snd
