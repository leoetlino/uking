#include "Game/Framework/SceneLoadProgress.h"
#include "Game/UI/uiUtils.h"
#include "KingSystem/Game/UI/UIGlue.h"

namespace uking {

SEAD_SINGLETON_DISPOSER_IMPL(SceneLoadProgress)

void SceneLoadProgress::init() {
    mActive = false;
    mProgress = 0.0;
    mGaugeValue = 0.0;
    mSteps = 1.0;
}

void SceneLoadProgress::reset() {
    init();
}

void SceneLoadProgress::updateFadeScreen() {
    if (!mActive)
        return;

    float progress = mProgress;
    float difference = progress - mGaugeValue;

    if (difference > 0.1f)
        mSteps = 1.1;
    if (difference > 0.2f)
        mSteps = 1.2;
    if (progress > 0.94f)
        mSteps = 10.0;

    if (difference <= 0.0001f && difference >= -0.0001f)
        mSteps = 1.0;

    float new_progress = mGaugeValue + (mProgressPerStep * mSteps);
    if (new_progress < progress)
        progress = new_progress;
    mGaugeValue = progress;
    ksys::ui::applyScreenFade(progress);
}

void SceneLoadProgress::setProgress(float value) {
    if (mProgress < value)
        mProgress = value;
}

float SceneLoadProgress::getGaugeValue() const {
    return mGaugeValue;
}

void SceneLoadProgress::setIsActive() {
    mActive = true;
}

}  // namespace uking