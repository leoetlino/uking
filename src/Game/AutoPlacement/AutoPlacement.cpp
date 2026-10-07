#include "Game/AutoPlacement/AutoPlacement.h"
#include "Game/AutoPlacement/AutoPlacementFlowMgr.h"
#include "Game/AutoPlacement/AutoPlacementMgr.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/ActorSystem/actActorUtil.h"
#include "KingSystem/ActorSystem/actInfoData.h"
#include "KingSystem/ActorSystem/actPhysicsUserTag.h"
#include "KingSystem/Game/Ecosystem/Ecosystem.h"
#include "KingSystem/Physics/RigidBody/physRigidBody.h"
#include "KingSystem/Physics/System/physRayCastForRequest.h"
#include "KingSystem/Utils/Byaml/Byaml.h"
#include "KingSystem/World/worldWeatherMgr.h"

namespace uking {

AutoPlacement::AutoPlacement() = default;
AutoPlacement::~AutoPlacement() = default;

bool AutoPlacement::init(sead::Heap* heap, u8 flag, s32 num_spawn, s32 num_obj) {
    mNearFlag = flag;

    if (!mSpawnInfo.tryAllocBuffer(num_spawn, heap))
        return false;

    if (num_obj > 0 && !mObjectRefs.tryAllocBuffer(num_obj, heap))
        return false;
    return true;
}

u32 AutoPlacement::isWithinOneCellOf(u32 a, u32 b) {
    auto calc = [](u32 x, u32 y, u32 a, u32 b) { return (1 - a + x < 3) & (1 - b + y < 3); };
    return calc(mGridX, mGridZ, a, b);
}

void ActorSpawnInfo::calcSpawnLocations() {
    auto* mgr = ksys::act::InfoData::instance();
    al::ByamlIter iter;

    using namespace ksys::act::tags;

    spawn_location.makeAllZero();
    if (mgr == nullptr || !mgr->getActorIter(&iter, name.cstr()))
        return;

    if (mgr->hasTag(iter, CheckBirdSafetyArea))
        spawn_location.set(SpawnLocation::CheckBirdSafetyArea);
    if (mgr->hasTag(iter, IsSnowBall))
        spawn_location.set(SpawnLocation::IsSnowBall);

    if (mgr->hasTag(iter, CreateFromTrunkOrGlowStoneLocator))
        spawn_location.set(SpawnLocation::TrunkOrGlowStoneLocator);
    else if (mgr->hasTag(iter, 0x923A4962))
        spawn_location.set(SpawnLocation::TrunkLocator);
    else if (mgr->hasTag(iter, CreateFromTrunkLocatorRandom))
        spawn_location.set(SpawnLocation::TrunkLocatorRandom);
    else if (mgr->hasTag(iter, 0x7881F260))
        spawn_location.set(SpawnLocation::BranchLocator);
    else if (mgr->hasTag(iter, CreateFromBranchLocatorRandom))
        spawn_location.set(SpawnLocation::BranchLocatorRandom);
    else if (mgr->hasTag(iter, CreateFromOnTreeLocator))
        spawn_location.set(SpawnLocation::OnTreeLocator);
    else if (mgr->hasTag(iter, CreateFromOnTreeLocatorRandom))
        spawn_location.set(SpawnLocation::OnTreeLocatorRandom);
}

void AutoPlacement::setSpawnInfo(const sead::SafeString& name, s32 count) {
    reset(false);
    ActorSpawnInfo* info = &mSpawnInfo[0];
    auto* flow = AutoPlacementFlowMgr::instance()->getFlow(name, mNearFlag == 0xff);
    if (flow != nullptr) {
        info->name = name;
        info->flow = flow;
        info->num_groups_placed = 0;
        s32 value = std::min(count, 255);
        info->max_groups = value;
        info->max_attempts = value * 30;
        info->num_attempts = 0;
        info->calcSpawnLocations();
        mNumSpawnInfos = 1;
        mState = State::Ready;
    } else {
        mNumSpawnInfos = 0;
    }
}

void AutoPlacement::deactivate() {
    reset(false);
    mState = State::Inactive;
}

ksys::game::AreaItemType sPlacementItemTypesData[] = {
    ksys::game::AreaItemType::Enemy,  ksys::game::AreaItemType::Animal,
    ksys::game::AreaItemType::Insect, ksys::game::AreaItemType::Fish,
    ksys::game::AreaItemType::Bird,   ksys::game::AreaItemType::AutoPlacementMaterial,
};
sead::Buffer<ksys::game::AreaItemType> sPlacementItemTypes{sPlacementItemTypesData};

// NON_MATCHING: stack
bool AutoPlacement::isActorInEcosystemAreaAtPos(const sead::SafeString& name, u32 placement_type,
                                                const sead::Vector3f& pos) {
    if (mNearFlag == 0xFE)
        return true;

    auto* eco = ksys::game::Ecosystem::instance();
    if (eco == nullptr)
        return false;

    s32 area = eco->getFieldMapArea(pos.x, pos.z);
    if (area < 0)
        return false;

    ksys::game::AreaItemSet item_set;
    eco->getAreaItems(area, sPlacementItemTypes[placement_type], &item_set);

    for (int i = 0; i < item_set.count; ++i) {
        const auto& item = item_set.items[i];
        if (item.num > 0.0f && name == item.name)
            return true;
    }
    return false;
}

// NON_MATCHING: blocked by raycast
bool PlacementThing::invoke() {
    auto lock = sead::makeScopedLock(mCS);

    if (AutoPlacementMgr::instance()->auto9())
        return true;

    if (mRaycast == nullptr || mState != State::Initialized)
        return false;

    mRaycast->enableLayer(ksys::phys::ContactLayer::EntityGround);
    mRaycast->enableLayer(ksys::phys::ContactLayer::EntityGroundRough);
    mRaycast->enableLayer(ksys::phys::ContactLayer::EntityGroundSmooth);
    mRaycast->enableLayer(ksys::phys::ContactLayer::EntityAirWall);
    mRaycast->enableLayer(ksys::phys::ContactLayer::EntityGroundObject);
    mRaycast->enableLayer(ksys::phys::ContactLayer::EntityTree);

    if (mIsObstacleSweep) {
        sead::Vector3f v1 = mStartPos + sead::Vector3f{0, 4, 30};
        sead::Vector3f v2 = mStartPos - sead::Vector3f{0, 4, 30};
        mRaycast->setStartAndEnd(v1, v2);
    } else {
        sead::Vector3f v1{mStartPos.x, 2000.0f, mStartPos.z};
        sead::Vector3f v2{mStartPos.x, -100.0f, mStartPos.z};
        mRaycast->setStartAndEnd(v1, v2);
        mRaycast->setCallback(&mDelegate);
    }

    mState = State::LayersDone;
    return true;
}

bool AutoPlacement::isGroupLocatorUnavailable(PlacementGroup* grp, bool check_exposure) {
    if (grp->locator_type == 0xFF)
        return false;
    if (grp->object_ref_idx == -1)
        return false;

    auto* object = mObjectRefs[grp->object_ref_idx].obj;
    if (object == nullptr)
        return false;

    if (object->shouldSkipSpawn()) {
        return true;
    }

    if (object->getProc() == nullptr && object->getFlags0().isOn(ksys::map::PreActor::Flag0::_80))
        return true;

    if (grp->locator_type != 2)
        return false;

    if (check_exposure && !ksys::world::WeatherMgr::isExposureZero())
        return true;
    return false;
}

bool AutoPlacement::canSpawnEntryAtPos(ActorSpawnInfo* info, const sead::Vector3f& pos) {
    auto* mgr = AutoPlacementMgr::instance();
    u32 placement_type = info->flow->placement_type;
    if (mgr->auto0(pos, placement_type)) {
        if (mNearFlag != 0xFF) {
            return false;
        }
        if (info->name.findIndex("Enemy_Dragon") == -1) {
            return false;
        }
    }

    if ((mNearFlag != 0xFF && mgr->auto11(pos)) ||
        (!isActorInEcosystemAreaAtPos(info->name, placement_type, pos))) {
        return false;
    }

    if (mNearFlag != 0xFE && mNearFlag != 0xFF) {
        if (AutoPlacementMgr::instance()->auto2(info->name, pos))
            return false;
    }
    return true;
}

void AutoPlacement::updateCurrentGroupNum(u8 num, u8 equip_weapon_actor_count) {
    if (mNearFlag != 0xFF)
        return;
    if (mGroupIdx < 0)
        return;

    auto& grp = mGroups[mGroupIdx];
    if (!grp.num_alive) {
        grp.num = num;
        grp.equip_weapon_actor_count = equip_weapon_actor_count;
    }
}

void AutoPlacement::incrementGroup() {
    if (mGroupIdx < 0)
        return;
    mGroupIdx++;
}

s32 AutoPlacement::placeGroup(AutoPlacementFlowRes* res) {
    if (mGroupIdx < 0) {
        return -1;
    }

    mSpawnRay.mRaycast = mCandidateRay.mRaycast;
    mNearCreateWaitFrame = 0;
    mEquipCategory = 0xFF;

    auto& grp = mGroups[mGroupIdx];
    if (grp.b.isEmpty()) {
        return -1;
    }

    mRailName = sead::SafeString::cEmptyString;
    int tmp = 0;
    res->start(this, grp.actor_name, &tmp);
    if (!mCurrentGroupMatched)
        return -1;
    mCurrentGroupMatched = 0;

    return mGroupIdx;
}

s32 AutoPlacement::getCurrentGroupFlowIdx() {
    if (mGroupIdx < 0) {
        return -1;
    }
    return mGroups[mGroupIdx].flow_idx;
}

void AutoPlacement::stepAllRaycasts() {
    mCandidateRay.stepRaycast();
    mSpawnRay.stepRaycast();
    mObstacleRay.stepRaycast();
}

void PlacementThing::stepRaycast() {
    auto lock = sead::makeScopedLock(mCS);

    if (AutoPlacementMgr::instance()->auto9()) {
        if (mRaycast != nullptr) {
            mRaycast->release();
            mRaycast = nullptr;
        }
        mState = State::Invalid;
        mHit = mIsObstacleSweep;
        return;
    }

    State next;

    switch (mState) {
    case State::Uninitialized:
        mRaycast =
            ksys::phys::RayCastForRequest::allocRequest(nullptr, ksys::phys::GroundHit::Animal);
        next = mRaycast != nullptr ? State::Initialized : State::Invalid;
        break;
    case State::LayersDone:
        mRaycast->submitRequest(ksys::phys::ContactLayerType::Entity);
        next = State::RaycastDone;
        break;
    case State::PlacementDone:
        if (mRaycast != nullptr) {
            mRaycast->release();
            next = State::Invalid;
            mRaycast = nullptr;
        } else {
            next = State::Invalid;
        }
        break;
    default:
        return;
    }
    mState = next;
}

void AutoPlacement::onRayHitRigidBody(ksys::phys::RigidBody* rb) {
    if (rb == nullptr)
        return;

    if (rb->getContactLayer() == ksys::phys::ContactLayer::EntityTree)
        mNearFlag.setDirect(1);

    auto* tag = sead::DynamicCast<ksys::act::PhysicsUserTag>(rb->getUserTag());
    if (tag == nullptr)
        return;

    auto* actor = tag->getActor();
    if (actor == nullptr)
        return;

    mNearFlag.set(ksys::act::hasTag(actor, ksys::act::tags::Tree) ||
                  ksys::act::hasTag(actor, ksys::act::tags::AutoPlacementForbidCreate));

    mEquipCategory.set(actor->getName() == "AirWallHorse");
}

const char* PlacementThing::getCurrentGroundMat() const {
    if (mWaterQuery > 0.0f) {
        return mWaterMaterial.getMaterialName();
    } else {
        return mGroundMaterial.getMaterialName();
    }
}

const char* PlacementThing::getCurrentWaterSubMat() const {
    if (mWaterQuery > 0.0f) {
        return mWaterMaterial.getSubMaterialName();
    } else {
        return mGroundMaterial.getSubMaterialName();
    }
}

}  // namespace uking
