#include "Game/SiteBossRematchMgr.h"

namespace uking {

SEAD_SINGLETON_DISPOSER_IMPL(SiteBossRematchMgr)

void SiteBossRematchMgr::init() {
    mBlightCounts = {};
}

void SiteBossRematchMgr::setBlightRematchCount(s8 count, BlightType blight_type) {
    if (count >= 0 && blight_type <= BlightType::Water) {
        if (count >= 30) {
            count = 30;
        }
        mBlightCounts[u32(blight_type)] = count;
    }
}

void SiteBossRematchMgr::incrementBlightRematchCount(BlightType blight_type) {
    if (blight_type <= BlightType::Water) {
        s8 count = mBlightCounts[u32(blight_type)] + 1;
        setBlightRematchCount(count, blight_type);
    }
}

s8 SiteBossRematchMgr::getBlightRematchCount(BlightType blight_type) const {
    if (blight_type <= BlightType::Water)
        return mBlightCounts[u32(blight_type)];
    return 0;
}
}  // namespace uking
