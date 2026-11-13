#pragma once

#include "KingSystem/Game/Area/AreaObserverBase.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::frm {
class BaseProcAccessor;
}  // namespace ksys::frm

namespace ksys::phys {
class RigidBody;
}  // namespace ksys::phys

namespace ksys::game {

class AreaObserver : public AreaObserverBase {
public:
    explicit AreaObserver(AreaActionBase* area_tag_action);
    ~AreaObserver() override = default;

    bool observeCollisionBody(const CollidingBodiesIterator& it) override;
    bool observeContactPoint(const ContactPointIterator& it) override;
    bool isValidCollisionBody(const CollidingBodiesIterator& it) override;
    bool isValidContactPoint(const ContactPointIterator& it) override;
    bool isCollisionBodyActorInCollisionRange(const CollidingBodiesIterator& it,
                                              const CollidingBodiesIterator& begin,
                                              const CollidingBodiesIterator& end) override;
    bool isCollisionBodyActorInContactRange(const CollidingBodiesIterator& it,
                                            const ContactPointIterator& begin,
                                            const ContactPointIterator& end) override;
    bool isContactPointActorInContactRange(const ContactPointIterator& it,
                                           const ContactPointIterator& begin,
                                           const ContactPointIterator& end) override;
    bool isContactPointActorInCollisionRange(const ContactPointIterator& it,
                                             const CollidingBodiesIterator& begin,
                                             const CollidingBodiesIterator& end) override;

    virtual bool observeActor(const frm::BaseProcAccessor& actor);
    virtual bool shouldIgnoreBody(phys::RigidBody* body);
};
KSYS_CHECK_SIZE_NX150(AreaObserver, 0x18);

}  // namespace ksys::game
