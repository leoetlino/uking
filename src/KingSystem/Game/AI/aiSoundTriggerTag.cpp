#include "KingSystem/Game/AI/aiSoundTriggerTag.h"

namespace ksys::game {

SoundTriggerTag::SoundTriggerTag(const InitArg& arg) : ksys::act::ai::Ai(arg) {}

SoundTriggerTag::~SoundTriggerTag() = default;

bool SoundTriggerTag::init_(sead::Heap* heap) {
    return ksys::act::ai::Ai::init_(heap);
}

void SoundTriggerTag::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Ai::enter_(params);
}

void SoundTriggerTag::leave_() {
    ksys::act::ai::Ai::leave_();
}

void SoundTriggerTag::loadParams_() {
    getMapUnitParam(&mSoundDelay_m, "SoundDelay");
    getMapUnitParam(&mSound_m, "Sound");
    getMapUnitParam(&mSLinkInst_m, "SLinkInst");
}

}  // namespace ksys::game
