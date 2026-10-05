#pragma once

#include <container/seadListImpl.h>
#include "KingSystem/Utils/Types.h"

namespace sead {
class PrimitiveDrawer;
}  // namespace sead

namespace ksys::snd {

class ReverbArea {
public:
    ReverbArea();
    virtual ~ReverbArea() = default;

    virtual void drawDebug(sead::PrimitiveDrawer* drawer, bool draw_full_shape,
                           bool draw_inner_shape);

protected:
    float mReverbSendAdd{};
    float mReverbTimeAdd{};
    float mEarlyReflectionFeedbackAdd{};
    float mRoomHfAdd{};
    float mReverbAdd{};
    float mMerginDistance{};
    float mWeight{};
    int mAliveFrames{};
    sead::ListNode mListNode;
};
KSYS_CHECK_SIZE_NX150(ReverbArea, 0x38);

}  // namespace ksys::snd
