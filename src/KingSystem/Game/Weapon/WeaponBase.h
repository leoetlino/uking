#pragma once

#include "KingSystem/ActorSystem/actActor.h"

namespace ksys::act {
class BaseProcHandle;
}  // namespace ksys::act

namespace ksys::frm {
class ActorInstParamPack;
}  // namespace ksys::frm

namespace ksys::game {

// TODO
class WeaponBase : public act::Actor {
public:
    bool areExtraActorsReady() const;

    static void requestCreateWeaponActor(const char* actor, const sead::Matrix34f& matrix,
                                         f32 scale, sead::Heap* heap,
                                         ksys::act::BaseProcHandle* handle, s32 life,
                                         ksys::frm::ActorInstParamPack* params, s32 task_lane_id);
};

}  // namespace ksys::game
