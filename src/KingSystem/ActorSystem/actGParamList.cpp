#include "KingSystem/ActorSystem/actGParamList.h"
#include <prim/seadRuntimeTypeInfo.h>
#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/actActorParamMgr.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObject.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectAirWall.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectAnimalFollowOffset.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectAnimalUnit.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectArmor.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectArmorEffect.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectArmorHead.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectArmorUpper.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectArrow.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectAttack.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectAttackInterval.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectAutoGen.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectBeam.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectBindActor.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectBindBone.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectBow.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectBullet.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectCamera.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectChemicalType.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectClothReaction.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectCookSpice.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectCureItem.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectEatTarget.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectEnemy.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectEnemyLevel.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectEnemyRace.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectEnemyShown.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectEvent.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectExtendedEntity.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectFish.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGelEnemy.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGeneral.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGiantArmor.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGiantArmorSlot.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGlobal.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGolem.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGolemIK.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGrab.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGuardian.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGuardianMini.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectGuardianMiniWeapon.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectHorse.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectHorseCreator.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectHorseObject.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectHorseRider.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectHorseTargetedInfo.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectHorseUnit.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectInsect.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectItem.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectLargeSword.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectLiftable.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectLumberjackTree.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectMasterSword.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectMonsterShop.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectMotorcycle.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectNest.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectNpc.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectNpcEquipment.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectPictureBook.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectPlayer.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectPrey.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectRod.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectRope.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectRupee.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectSandworm.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectSeriesArmor.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectShiekerStone.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectShield.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectSmallSword.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectSpear.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectStalEnemy.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectSwarm.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectSystem.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectTraveler.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectWeaponCommon.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectWeaponOption.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectWeaponThrow.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectWizzrobe.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectWolfLink.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListObjectZora.h"
#include "KingSystem/Resource/GeneralParamList/resGParamListTraits.h"

namespace ksys::act {

void GParamList::doCreate_(u8*, u32, sead::Heap*) {}

bool GParamList::parse_(u8* data, size_t, sead::Heap* heap) {
    GParamList* dummy_list = nullptr;
    if (!sead::IsDerivedFrom<DummyGParamList>(this) && act::ActorParamMgr::instance())
        dummy_list = act::ActorParamMgr::instance()->getDummyGParamList();

    mObjects.allocBufferAssert(res::NumGParamListObjTypes, heap);

    const agl::utl::ResParameterArchive archive{data};

#define KSYS_GPARAM_ADD_(NAME)                                                                     \
    do {                                                                                           \
        using Traits = res::GParamListObjTypeTraits<res::GParamListObjType::NAME>;                 \
        const auto pobj = agl::utl::getResParameterObj(archive.getRootList(), #NAME);              \
        if (pobj.ptr()) {                                                                          \
            auto* obj = new (heap) Traits::type;                                                   \
            if (obj)                                                                               \
                addObj(&obj->getObj(), obj->getName());                                            \
                                                                                                   \
            mObjects[Traits::index] = obj;                                                         \
                                                                                                   \
        } else {                                                                                   \
            mObjects[Traits::index] = dummy_list ? dummy_list->mObjects[Traits::index] : nullptr;  \
        }                                                                                          \
    } while (0)

    KSYS_GPARAM_ADD_(System);
    KSYS_GPARAM_ADD_(General);
    KSYS_GPARAM_ADD_(Enemy);
    KSYS_GPARAM_ADD_(EnemyLevel);
    KSYS_GPARAM_ADD_(EnemyRace);
    KSYS_GPARAM_ADD_(AttackInterval);
    KSYS_GPARAM_ADD_(EnemyShown);
    KSYS_GPARAM_ADD_(BindBone);
    KSYS_GPARAM_ADD_(Attack);
    KSYS_GPARAM_ADD_(WeaponCommon);
    KSYS_GPARAM_ADD_(WeaponThrow);
    KSYS_GPARAM_ADD_(Sandworm);
    KSYS_GPARAM_ADD_(SmallSword);
    KSYS_GPARAM_ADD_(Rod);
    KSYS_GPARAM_ADD_(LargeSword);
    KSYS_GPARAM_ADD_(Spear);
    KSYS_GPARAM_ADD_(Shield);
    KSYS_GPARAM_ADD_(Bow);
    KSYS_GPARAM_ADD_(WeaponOption);
    KSYS_GPARAM_ADD_(MasterSword);
    KSYS_GPARAM_ADD_(GuardianMiniWeapon);
    KSYS_GPARAM_ADD_(Player);
    KSYS_GPARAM_ADD_(Camera);
    KSYS_GPARAM_ADD_(Grab);
    KSYS_GPARAM_ADD_(Armor);
    KSYS_GPARAM_ADD_(ArmorEffect);
    KSYS_GPARAM_ADD_(ArmorHead);
    KSYS_GPARAM_ADD_(ArmorUpper);
    KSYS_GPARAM_ADD_(ShiekerStone);
    KSYS_GPARAM_ADD_(SeriesArmor);
    KSYS_GPARAM_ADD_(Liftable);
    KSYS_GPARAM_ADD_(Item);
    KSYS_GPARAM_ADD_(Rupee);
    KSYS_GPARAM_ADD_(Arrow);
    KSYS_GPARAM_ADD_(Bullet);
    KSYS_GPARAM_ADD_(CureItem);
    KSYS_GPARAM_ADD_(CookSpice);
    KSYS_GPARAM_ADD_(LumberjackTree);
    KSYS_GPARAM_ADD_(Npc);
    KSYS_GPARAM_ADD_(NpcEquipment);
    KSYS_GPARAM_ADD_(Zora);
    KSYS_GPARAM_ADD_(Traveler);
    KSYS_GPARAM_ADD_(Prey);
    KSYS_GPARAM_ADD_(AnimalFollowOffset);
    KSYS_GPARAM_ADD_(ExtendedEntity);
    KSYS_GPARAM_ADD_(BindActor);
    KSYS_GPARAM_ADD_(EatTarget);
    KSYS_GPARAM_ADD_(AnimalUnit);
    KSYS_GPARAM_ADD_(Insect);
    KSYS_GPARAM_ADD_(Fish);
    KSYS_GPARAM_ADD_(Rope);
    KSYS_GPARAM_ADD_(Horse);
    KSYS_GPARAM_ADD_(HorseUnit);
    KSYS_GPARAM_ADD_(HorseObject);
    KSYS_GPARAM_ADD_(HorseRider);
    KSYS_GPARAM_ADD_(HorseCreator);
    KSYS_GPARAM_ADD_(GiantArmorSlot);
    KSYS_GPARAM_ADD_(GiantArmor);
    KSYS_GPARAM_ADD_(Guardian);
    KSYS_GPARAM_ADD_(MonsterShop);
    KSYS_GPARAM_ADD_(Swarm);
    KSYS_GPARAM_ADD_(GelEnemy);
    KSYS_GPARAM_ADD_(Nest);
    KSYS_GPARAM_ADD_(Wizzrobe);
    KSYS_GPARAM_ADD_(StalEnemy);
    KSYS_GPARAM_ADD_(GuardianMini);
    KSYS_GPARAM_ADD_(ClothReaction);
    KSYS_GPARAM_ADD_(Global);
    KSYS_GPARAM_ADD_(Beam);
    KSYS_GPARAM_ADD_(AutoGen);
    KSYS_GPARAM_ADD_(ChemicalType);
    KSYS_GPARAM_ADD_(Golem);
    KSYS_GPARAM_ADD_(HorseTargetedInfo);
    KSYS_GPARAM_ADD_(WolfLink);
    KSYS_GPARAM_ADD_(Event);
    KSYS_GPARAM_ADD_(GolemIK);
    KSYS_GPARAM_ADD_(PictureBook);
    KSYS_GPARAM_ADD_(AirWall);
    KSYS_GPARAM_ADD_(Motorcycle);

#undef KSYS_GPARAM_ADD_

    if (data)
        applyResParameterArchive(archive);

    return true;
}

void GParamList::finalize_() {}

static constexpr size_t getResourceFactoryFallbackSizeConst() {
    size_t size = 0;
    size += sizeof(res::GParamListObjectSystem);
    size += sizeof(res::GParamListObjectGeneral);
    size += sizeof(res::GParamListObjectEnemy);
    size += sizeof(res::GParamListObjectEnemyLevel);
    size += sizeof(res::GParamListObjectEnemyRace);
    size += sizeof(res::GParamListObjectAttackInterval);
    size += sizeof(res::GParamListObjectEnemyShown);
    size += sizeof(res::GParamListObjectBindBone);
    size += sizeof(res::GParamListObjectAttack);
    size += sizeof(res::GParamListObjectWeaponCommon);
    size += sizeof(res::GParamListObjectWeaponThrow);
    size += sizeof(res::GParamListObjectSandworm);
    size += sizeof(res::GParamListObjectSmallSword);
    size += sizeof(res::GParamListObjectRod);
    size += sizeof(res::GParamListObjectLargeSword);
    size += sizeof(res::GParamListObjectSpear);
    size += sizeof(res::GParamListObjectShield);
    size += sizeof(res::GParamListObjectBow);
    size += sizeof(res::GParamListObjectWeaponOption);
    size += sizeof(res::GParamListObjectMasterSword);
    size += sizeof(res::GParamListObjectGuardianMiniWeapon);
    size += sizeof(res::GParamListObjectPlayer);
    size += sizeof(res::GParamListObjectCamera);
    size += sizeof(res::GParamListObjectGrab);
    size += sizeof(res::GParamListObjectArmor);
    size += sizeof(res::GParamListObjectArmorEffect);
    size += sizeof(res::GParamListObjectArmorHead);
    size += sizeof(res::GParamListObjectArmorUpper);
    size += sizeof(res::GParamListObjectShiekerStone);
    size += sizeof(res::GParamListObjectSeriesArmor);
    size += sizeof(res::GParamListObjectLiftable);
    size += sizeof(res::GParamListObjectItem);
    size += sizeof(res::GParamListObjectRupee);
    size += sizeof(res::GParamListObjectArrow);
    size += sizeof(res::GParamListObjectBullet);
    size += sizeof(res::GParamListObjectCureItem);
    size += sizeof(res::GParamListObjectCookSpice);
    size += sizeof(res::GParamListObjectLumberjackTree);
    size += sizeof(res::GParamListObjectNpc);
    size += sizeof(res::GParamListObjectNpcEquipment);
    size += sizeof(res::GParamListObjectZora);
    size += sizeof(res::GParamListObjectTraveler);
    size += sizeof(res::GParamListObjectPrey);
    size += sizeof(res::GParamListObjectAnimalFollowOffset);
    size += sizeof(res::GParamListObjectExtendedEntity);
    size += sizeof(res::GParamListObjectBindActor);
    size += sizeof(res::GParamListObjectEatTarget);
    size += sizeof(res::GParamListObjectAnimalUnit);
    size += sizeof(res::GParamListObjectInsect);
    size += sizeof(res::GParamListObjectFish);
    size += sizeof(res::GParamListObjectRope);
    size += sizeof(res::GParamListObjectHorse);
    size += sizeof(res::GParamListObjectHorseUnit);
    size += sizeof(res::GParamListObjectHorseObject);
    size += sizeof(res::GParamListObjectHorseRider);
    size += sizeof(res::GParamListObjectHorseCreator);
    size += sizeof(res::GParamListObjectGiantArmorSlot);
    size += sizeof(res::GParamListObjectGiantArmor);
    size += sizeof(res::GParamListObjectGuardian);
    size += sizeof(res::GParamListObjectMonsterShop);
    size += sizeof(res::GParamListObjectSwarm);
    size += sizeof(res::GParamListObjectGelEnemy);
    size += sizeof(res::GParamListObjectNest);
    size += sizeof(res::GParamListObjectWizzrobe);
    size += sizeof(res::GParamListObjectStalEnemy);
    size += sizeof(res::GParamListObjectGuardianMini);
    size += sizeof(res::GParamListObjectClothReaction);
    size += sizeof(res::GParamListObjectGlobal);
    size += sizeof(res::GParamListObjectBeam);
    size += sizeof(res::GParamListObjectAutoGen);
    size += sizeof(res::GParamListObjectChemicalType);
    size += sizeof(res::GParamListObjectGolem);
    size += sizeof(res::GParamListObjectHorseTargetedInfo);
    size += sizeof(res::GParamListObjectWolfLink);
    size += sizeof(res::GParamListObjectEvent);
    size += sizeof(res::GParamListObjectGolemIK);
    size += sizeof(res::GParamListObjectPictureBook);
    size += sizeof(res::GParamListObjectAirWall);
    size += sizeof(res::GParamListObjectMotorcycle);
    size += sizeof(GParamList);
    return size;
}

u32 GParamList::getResourceFactoryFallbackSize() {
    constexpr size_t size = getResourceFactoryFallbackSizeConst();
    static_assert(size == static_cast<u32>(size));
    return static_cast<u32>(size);
}

void DummyGParamList::doCreate_(u8*, u32, sead::Heap*) {}

bool DummyGParamList::parse_(u8* data, size_t size, sead::Heap* heap) {
    GParamList::parse_(data, size, heap);
    return true;
}

}  // namespace ksys::act
