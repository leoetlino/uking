#include "KingSystem/Awareness/awnAwarenessMiscUtils.h"
#include <utility/aglParameter.h>

namespace ksys::awn {

u32 calcAwarenessHash(const sead::SafeString& key) {
    return agl::utl::ParameterBase::calcHash(key);
}

}  // namespace ksys::awn
