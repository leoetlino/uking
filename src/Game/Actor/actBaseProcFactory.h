#pragma once

#include <heap/seadDisposer.h>
#include "KingSystem/ActorSystem/actActorCreator.h"

namespace uking::act {

class BaseProcFactory : public ksys::act::IBaseProcFactory {
public:
    void dummy() override;
    ksys::act::BaseProc* createActor(const ksys::act::ActorCreateArg& arg) override;
    void dummy2() override;
};

class BaseProcFactoryHolder {
    SEAD_SINGLETON_DISPOSER(BaseProcFactoryHolder)
    BaseProcFactoryHolder() = default;
    virtual ~BaseProcFactoryHolder();

public:
    void init(sead::Heap* heap);

private:
    BaseProcFactory mFactory;
};

}  // namespace uking::act
