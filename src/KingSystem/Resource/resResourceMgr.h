#pragma once

#include <hostio/seadHostIONode.h>
#include <thread/seadCriticalSection.h>
#include "KingSystem/Resource/resResourceBinder.h"
#include "KingSystem/Resource/resResourceUnit.h"
#include "KingSystem/Utils/Container/StrTreeMap.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::res {

class ControlTaskData;

class ResourceMgr : public sead::hostio::Node {
public:
    ResourceMgr();
    virtual ~ResourceMgr();

    void init();
    ResourceUnit* findUnit(const ResourceUnitMapNode::KeyType& key) const;
    ResourceBinder::Status loadResource(const ControlTaskData& data);

    void eraseUnit(ResourceUnit* unit);
    void eraseUnits();

private:
    void removeUnitAndClearCache_(ResourceUnit* unit);

    // This seems to be unused.
    [[maybe_unused]] u8 _8 = 2;
    util::StrTreeMap<ResourceUnitMapNode> mMap;
};
KSYS_CHECK_SIZE_NX150(ResourceMgr, 0x18);

extern sead::CriticalSection gCacheCriticalSection;

void lockCacheCriticalSection();
void unlockCacheCriticalSection();

}  // namespace ksys::res
