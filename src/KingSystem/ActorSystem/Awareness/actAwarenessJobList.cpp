#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/Awareness/actAwareness.h"

namespace ksys::act {

u32 Awareness::calcHash(const sead::SafeString& key) {
    return agl::utl::ParameterBase::calcHash(key);
}

}  // namespace ksys::act
