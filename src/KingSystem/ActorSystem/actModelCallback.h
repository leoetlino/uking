#pragma once

#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class Actor;

class ModelCallback {
public:
    explicit ModelCallback(Actor* actor) : mActor(actor) {}

    virtual void m0() {}
    virtual void m1() {}
    virtual void m2() {}
    virtual void m3() {}

private:
    Actor* mActor = nullptr;
};
KSYS_CHECK_SIZE_NX150(ModelCallback, 0x10);

}  // namespace ksys::act
