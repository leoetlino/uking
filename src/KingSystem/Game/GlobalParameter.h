#pragma once

#include <heap/seadDisposer.h>
#include "KingSystem/Resource/resHandle.h"

namespace ksys::act {
class ActorParam;
class GParamListObjectGlobal;
}  // namespace ksys::act

namespace ksys::game {

class GlobalParameter {
    SEAD_SINGLETON_DISPOSER(GlobalParameter)
    GlobalParameter() = default;
    ~GlobalParameter() = default;

public:
    bool init(sead::Heap* heap);
    void finalize();

    void loadActorPack(sead::Heap* heap);
    bool isActorPackReady() const;
    bool loadActorParams();

    const act::GParamListObjectGlobal* getGlobalParam() const { return mGlobalParam; }

private:
    bool loadActorParams_();

    act::ActorParam* mActorParam{};
    const act::GParamListObjectGlobal* mGlobalParam{};
    res::Handle mResHandle{};
};

}  // namespace ksys::game
