#include "Game/Actor/actBaseProcFactory.h"
#include "KingSystem/ActorSystem/actActorCreator.h"

namespace uking::act {

SEAD_SINGLETON_DISPOSER_IMPL(BaseProcFactoryHolder)

void BaseProcFactory::dummy() {}

void BaseProcFactory::dummy2() {}

BaseProcFactoryHolder::~BaseProcFactoryHolder() {
    ksys::act::ActorCreator::deleteInstance();
}

void BaseProcFactoryHolder::init(sead::Heap* heap) {
    ksys::act::ActorCreator::createInstance(heap);
    ksys::act::ActorCreator::instance()->setBaseProcFactory(&mFactory);
}

}  // namespace uking::act
