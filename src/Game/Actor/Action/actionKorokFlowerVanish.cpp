#include "Game/Actor/Action/actionKorokFlowerVanish.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/Physics/RigidBody/physRigidBody.h"

namespace uking::action {

KorokFlowerVanish::KorokFlowerVanish(const InitArg& arg) : ksys::act::ai::Action(arg) {}

KorokFlowerVanish::~KorokFlowerVanish() = default;

bool KorokFlowerVanish::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void KorokFlowerVanish::enter_(ksys::act::ai::InlineParamPack* params) {
    mActor->emitBasicSigOn();
    mActor->getActorFlags2().set(ksys::act::Actor::ActorFlag2::Invisible);

    auto* main_body = mActor->getMainBody();
    auto* tgt_body = mActor->getTgtBody();
    if (main_body != nullptr && tgt_body != nullptr) {
        main_body->setContactAll();
        main_body->disableRayHit();
        tgt_body->setContactAll();
        tgt_body->disableRayHit();
    }
}

void KorokFlowerVanish::leave_() {
    ksys::act::ai::Action::leave_();
}

void KorokFlowerVanish::loadParams_() {}

void KorokFlowerVanish::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
