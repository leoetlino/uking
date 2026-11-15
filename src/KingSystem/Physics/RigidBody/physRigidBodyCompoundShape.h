#pragma once

#include "KingSystem/Physics/RigidBody/physRigidBodyFromShape.h"

namespace ksys::phys {

struct BoxShapeParam;
struct CapsuleShapeParam;
struct CharacterPrismShapeParam;
struct CylinderShapeParam;
struct PolytopeShapeParam;
struct SphereShapeParam;

class CompoundShape;

class CompoundShapeRigidBody : public RigidBodyFromShape {
    SEAD_RTTI_OVERRIDE(CompoundShapeRigidBody, RigidBodyFromShape)
public:
    static CompoundShapeRigidBody* make(RigidBodyInstanceParam* param, sead::Heap* heap);

    CompoundShapeRigidBody(hkpRigidBody* hk_body, CompoundShape* shape, ContactLayerType layer_type,
                           const sead::SafeString& name, bool owns_shape, sead::Heap* heap);
    ~CompoundShapeRigidBody() override;

    /// Replace the shape at the specified index with a new sphere shape.
    /// The shape that is being replaced will be deleted.
    Shape* replaceWithNewSphere(int index, const SphereShapeParam& param, sead::Heap* heap);

    /// Replace the shape at the specified index with a new capsule shape.
    /// The shape that is being replaced will be deleted.
    Shape* replaceWithNewCapsule(int index, const CapsuleShapeParam& param, sead::Heap* heap);

    /// Replace the shape at the specified index with a new cylinder shape.
    /// The shape that is being replaced will be deleted.
    Shape* replaceWithNewCylinder(int index, const CylinderShapeParam& param, sead::Heap* heap);

    /// Replace the shape at the specified index with a new box shape.
    /// The shape that is being replaced will be deleted.
    Shape* replaceWithNewBox(int index, const BoxShapeParam& param, sead::Heap* heap);

    /// Replace the shape at the specified index with a new polytope shape.
    /// The shape that is being replaced will be deleted.
    Shape* replaceWithNewPolytope(int index, const PolytopeShapeParam& param, sead::Heap* heap);

    /// Replace the shape at the specified index with a new character prism.
    /// The shape that is being replaced will be deleted.
    Shape* replaceWithNewCharacterPrism(int index, const CharacterPrismShapeParam& param,
                                        sead::Heap* heap);

    /// Set the material mask for the shape at the specified index.
    void setMaterialMask(const MaterialMask& mask, int index);

    /// Get the material mask for the shape at the specified index.
    const MaterialMask& getMaterialMask(int index) const;

    float getVolume() override;

protected:
    Shape* getShape_() override;
    const Shape* getShape_() const override;
    u32 getCollisionMasks(RigidBody::CollisionMasks* masks, const u32* shape_key,
                          const sead::Vector3f& contact_point) override;

private:
    CompoundShape* mShape{};
};

}  // namespace ksys::phys
