#include "KingSystem/ActorSystem/actAISchedule.h"

namespace ksys::act {

void AISchedule::doCreate_(u8* buffer, u32 buffer_size, sead::Heap* heap) {
    mData = buffer;
}

}  // namespace ksys::act
