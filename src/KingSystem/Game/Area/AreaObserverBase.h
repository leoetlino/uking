#pragma once

#include <container/seadBuffer.h>
#include "KingSystem/Game/Physics/physDefines.h"
#include "KingSystem/Utils/Types.h"

namespace ksys {
class Message;
}  // namespace ksys

namespace ksys::game {

class AreaActionBase;

struct AreaContactLayerEntry {
    phys::ContactLayer layer;
    bool is_registered_with_area;
};

class AreaObserverBase {
public:
    struct CollidingBodiesIterator;
    struct ContactPointIterator;

    explicit AreaObserverBase(AreaActionBase* area_tag_action);
    virtual ~AreaObserverBase() = default;

    virtual void preObserve();
    virtual bool observeCollisionBody(const CollidingBodiesIterator& it);
    virtual bool observeContactPoint(const ContactPointIterator& it);
    virtual void postObserve();
    virtual sead::Buffer<AreaContactLayerEntry>* getContactLayers();
    virtual bool isValidCollisionBody(const CollidingBodiesIterator& it);
    virtual bool isValidContactPoint(const ContactPointIterator& it);
    virtual bool isCollisionBodyActorInCollisionRange(const CollidingBodiesIterator& it,
                                                      const CollidingBodiesIterator& begin,
                                                      const CollidingBodiesIterator& end);
    virtual bool isCollisionBodyActorInContactRange(const CollidingBodiesIterator& it,
                                                    const ContactPointIterator& begin,
                                                    const ContactPointIterator& end);
    virtual bool isContactPointActorInContactRange(const ContactPointIterator& it,
                                                   const ContactPointIterator& begin,
                                                   const ContactPointIterator& end);
    virtual bool isContactPointActorInCollisionRange(const ContactPointIterator& it,
                                                     const CollidingBodiesIterator& begin,
                                                     const CollidingBodiesIterator& end);
    virtual bool shouldSkipCollisionBodyForPreviousAreas(const CollidingBodiesIterator& it,
                                                         int area_index);
    virtual bool shouldSkipContactPointForPreviousAreas(const ContactPointIterator& it,
                                                        int area_index);

    void enterAndResetContactLayersSent();
    void calc();
    bool handleMessage(const Message* message);

protected:
    AreaActionBase* mAreaTagAction;
    bool mContactLayersSent;
    bool mContactLayersResendRequested;
};
KSYS_CHECK_SIZE_NX150(AreaObserverBase, 0x18);

}  // namespace ksys::game
