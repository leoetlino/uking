#include "KingSystem/ActorSystem/actRagdollConfigResource.h"

namespace ksys::act {

const int RagdollConfigResource::cNumReceiveObjs = 3;
const int RagdollConfigResource::cNumImpulseObjs = 5;
const int RagdollConfigResource::cNumImpulseParams = 10;
const std::array<char, 64> RagdollConfigResource::cImpulseParamNames[10] = {
    {"Default"}, {"Sword"},    {"LargeSword"}, {"Spear"},      {"Arrow"},
    {"Bomb"},    {"HeadShot"}, {"ShockWave"},  {"SilentKill"}, {"Gust"},
};

RagdollConfigResource::RagdollConfigResource() : ParamIO("rgconfig", 0) {}

RagdollConfigResource::~RagdollConfigResource() = default;

void RagdollConfigResource::doCreate_(u8* buffer, u32 buffer_size, sead::Heap* heap) {}

bool RagdollConfigResource::parse_(u8* data, size_t size, sead::Heap* heap) {
    if (!data)
        return false;

    addList(&mConfig, "ConfigRoot");

    agl::utl::ResParameterArchive archive{data};
    applyResParameterArchive(archive);
    return true;
}

}  // namespace ksys::act
