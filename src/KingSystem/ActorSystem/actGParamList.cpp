#include "KingSystem/ActorSystem/actGParamList.h"
#include <prim/seadRuntimeTypeInfo.h>
#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObject.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectAirWall.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectAnimalFollowOffset.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectAnimalUnit.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectArmor.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectArmorEffect.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectArmorHead.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectArmorUpper.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectArrow.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectAttack.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectAttackInterval.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectAutoGen.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectBeam.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectBindActor.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectBindBone.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectBow.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectBullet.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectCamera.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectChemicalType.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectClothReaction.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectCookSpice.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectCureItem.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectEatTarget.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectEnemy.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectEnemyLevel.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectEnemyRace.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectEnemyShown.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectEvent.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectExtendedEntity.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectFish.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGelEnemy.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGeneral.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGiantArmor.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGiantArmorSlot.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGlobal.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGolem.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGolemIK.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGrab.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGuardian.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGuardianMini.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectGuardianMiniWeapon.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectHorse.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectHorseCreator.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectHorseObject.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectHorseRider.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectHorseTargetedInfo.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectHorseUnit.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectInsect.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectItem.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectLargeSword.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectLiftable.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectLumberjackTree.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectMasterSword.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectMonsterShop.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectMotorcycle.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectNest.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectNpc.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectNpcEquipment.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectPictureBook.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectPlayer.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectPrey.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectRod.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectRope.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectRupee.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectSandworm.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectSeriesArmor.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectShiekerStone.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectShield.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectSmallSword.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectSpear.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectStalEnemy.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectSwarm.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectSystem.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectTraveler.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectWeaponCommon.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectWeaponOption.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectWeaponThrow.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectWizzrobe.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectWolfLink.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObjectZora.h"
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListTraits.h"
#include "KingSystem/ActorSystem/actActorParamMgr.h"

namespace ksys::act {

void GParamList::doCreate_(u8*, u32, sead::Heap*) {}

bool GParamList::parse_(u8* data, size_t, sead::Heap* heap) {
    GParamList* dummy_list = nullptr;
    if (!sead::IsDerivedFrom<DummyGParamList>(this) && act::ActorParamMgr::instance())
        dummy_list = act::ActorParamMgr::instance()->getDummyGParamList();

    mObjects.allocBufferAssert(NumGParamListObjTypes, heap);

    const agl::utl::ResParameterArchive archive{data};

#define KSYS_GPARAM_ADD_(NAME)                                                                     \
    do {                                                                                           \
        using Traits = GParamListObjTypeTraits<GParamListObjType::NAME>;                           \
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
    size += sizeof(GParamListObjectSystem);
    size += sizeof(GParamListObjectGeneral);
    size += sizeof(GParamListObjectEnemy);
    size += sizeof(GParamListObjectEnemyLevel);
    size += sizeof(GParamListObjectEnemyRace);
    size += sizeof(GParamListObjectAttackInterval);
    size += sizeof(GParamListObjectEnemyShown);
    size += sizeof(GParamListObjectBindBone);
    size += sizeof(GParamListObjectAttack);
    size += sizeof(GParamListObjectWeaponCommon);
    size += sizeof(GParamListObjectWeaponThrow);
    size += sizeof(GParamListObjectSandworm);
    size += sizeof(GParamListObjectSmallSword);
    size += sizeof(GParamListObjectRod);
    size += sizeof(GParamListObjectLargeSword);
    size += sizeof(GParamListObjectSpear);
    size += sizeof(GParamListObjectShield);
    size += sizeof(GParamListObjectBow);
    size += sizeof(GParamListObjectWeaponOption);
    size += sizeof(GParamListObjectMasterSword);
    size += sizeof(GParamListObjectGuardianMiniWeapon);
    size += sizeof(GParamListObjectPlayer);
    size += sizeof(GParamListObjectCamera);
    size += sizeof(GParamListObjectGrab);
    size += sizeof(GParamListObjectArmor);
    size += sizeof(GParamListObjectArmorEffect);
    size += sizeof(GParamListObjectArmorHead);
    size += sizeof(GParamListObjectArmorUpper);
    size += sizeof(GParamListObjectShiekerStone);
    size += sizeof(GParamListObjectSeriesArmor);
    size += sizeof(GParamListObjectLiftable);
    size += sizeof(GParamListObjectItem);
    size += sizeof(GParamListObjectRupee);
    size += sizeof(GParamListObjectArrow);
    size += sizeof(GParamListObjectBullet);
    size += sizeof(GParamListObjectCureItem);
    size += sizeof(GParamListObjectCookSpice);
    size += sizeof(GParamListObjectLumberjackTree);
    size += sizeof(GParamListObjectNpc);
    size += sizeof(GParamListObjectNpcEquipment);
    size += sizeof(GParamListObjectZora);
    size += sizeof(GParamListObjectTraveler);
    size += sizeof(GParamListObjectPrey);
    size += sizeof(GParamListObjectAnimalFollowOffset);
    size += sizeof(GParamListObjectExtendedEntity);
    size += sizeof(GParamListObjectBindActor);
    size += sizeof(GParamListObjectEatTarget);
    size += sizeof(GParamListObjectAnimalUnit);
    size += sizeof(GParamListObjectInsect);
    size += sizeof(GParamListObjectFish);
    size += sizeof(GParamListObjectRope);
    size += sizeof(GParamListObjectHorse);
    size += sizeof(GParamListObjectHorseUnit);
    size += sizeof(GParamListObjectHorseObject);
    size += sizeof(GParamListObjectHorseRider);
    size += sizeof(GParamListObjectHorseCreator);
    size += sizeof(GParamListObjectGiantArmorSlot);
    size += sizeof(GParamListObjectGiantArmor);
    size += sizeof(GParamListObjectGuardian);
    size += sizeof(GParamListObjectMonsterShop);
    size += sizeof(GParamListObjectSwarm);
    size += sizeof(GParamListObjectGelEnemy);
    size += sizeof(GParamListObjectNest);
    size += sizeof(GParamListObjectWizzrobe);
    size += sizeof(GParamListObjectStalEnemy);
    size += sizeof(GParamListObjectGuardianMini);
    size += sizeof(GParamListObjectClothReaction);
    size += sizeof(GParamListObjectGlobal);
    size += sizeof(GParamListObjectBeam);
    size += sizeof(GParamListObjectAutoGen);
    size += sizeof(GParamListObjectChemicalType);
    size += sizeof(GParamListObjectGolem);
    size += sizeof(GParamListObjectHorseTargetedInfo);
    size += sizeof(GParamListObjectWolfLink);
    size += sizeof(GParamListObjectEvent);
    size += sizeof(GParamListObjectGolemIK);
    size += sizeof(GParamListObjectPictureBook);
    size += sizeof(GParamListObjectAirWall);
    size += sizeof(GParamListObjectMotorcycle);
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
