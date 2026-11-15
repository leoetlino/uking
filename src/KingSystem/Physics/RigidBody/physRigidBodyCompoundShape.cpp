#include "KingSystem/Physics/RigidBody/physRigidBodyCompoundShape.h"
#include "KingSystem/Physics/RigidBody/Shape/physCompoundShape.h"
#include "KingSystem/Utils/SafeDelete.h"

namespace ksys::phys {

CompoundShapeRigidBody* CompoundShapeRigidBody::make(RigidBodyInstanceParam* param,
                                                     sead::Heap* heap) {
    return createCompound(param, heap);
}

CompoundShapeRigidBody::CompoundShapeRigidBody(hkpRigidBody* hk_body, CompoundShape* shape,
                                               ContactLayerType layer_type,
                                               const sead::SafeString& name, bool owns_shape,
                                               sead::Heap* heap)
    : RigidBodyFromShape(hk_body, layer_type, name, owns_shape, heap), mShape(shape) {}

CompoundShapeRigidBody::~CompoundShapeRigidBody() {
    if (hasFlag(RigidBody::Flag::OwnsShape) && mShape) {
        util::safeDelete(mShape);
    }
}

Shape* CompoundShapeRigidBody::replaceWithNewSphere(int index, const SphereShapeParam& param,
                                                    sead::Heap* heap) {
    return mShape->replaceWithNewSphere(index, param, heap);
}

Shape* CompoundShapeRigidBody::replaceWithNewCapsule(int index, const CapsuleShapeParam& param,
                                                     sead::Heap* heap) {
    return mShape->replaceWithNewCapsule(index, param, heap);
}

Shape* CompoundShapeRigidBody::replaceWithNewCylinder(int index, const CylinderShapeParam& param,
                                                      sead::Heap* heap) {
    return mShape->replaceWithNewCylinder(index, param, heap);
}

Shape* CompoundShapeRigidBody::replaceWithNewBox(int index, const BoxShapeParam& param,
                                                 sead::Heap* heap) {
    return mShape->replaceWithNewBox(index, param, heap);
}

Shape* CompoundShapeRigidBody::replaceWithNewPolytope(int index, const PolytopeShapeParam& param,
                                                      sead::Heap* heap) {
    return mShape->replaceWithNewPolytope(index, param, heap);
}

Shape* CompoundShapeRigidBody::replaceWithNewCharacterPrism(int index,
                                                            const CharacterPrismShapeParam& param,
                                                            sead::Heap* heap) {
    return mShape->replaceWithNewCharacterPrism(index, param, heap);
}

void CompoundShapeRigidBody::setMaterialMask(const MaterialMask& mask, int index) {
    mShape->setMaterialMask(mask, index);
}

const MaterialMask& CompoundShapeRigidBody::getMaterialMask(int index) const {
    return mShape->getMaterialMask(index);
}

float CompoundShapeRigidBody::getVolume() {
    return mShape->getVolume();
}

Shape* CompoundShapeRigidBody::getShape_() {
    return mShape;
}

const Shape* CompoundShapeRigidBody::getShape_() const {
    return mShape;
}

u32 CompoundShapeRigidBody::getCollisionMasks(RigidBody::CollisionMasks* masks,
                                              const u32* shape_key,
                                              const sead::Vector3f& contact_point) {
    masks->ignored_layers = ~mContactMask;
    masks->collision_filter_info = getCollisionFilterInfo();
    masks->material_mask = getMaterialMask(shape_key != nullptr ? int(*shape_key) : 0).getRawData();
    return 0;
}

}  // namespace ksys::phys
