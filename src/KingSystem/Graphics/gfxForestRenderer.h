#pragma once

#include <math/seadVector.h>

namespace ksys::gfx {

class ForestRenderer {
public:
    s32 findTreeIdxByPos(const sead::Vector3f& vec);
};

}  // namespace ksys::gfx
