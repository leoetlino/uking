#pragma once

#include <container/seadBuffer.h>
#include <prim/seadSafeString.h>
#include <utility/aglParameter.h>
#include <utility/aglParameterList.h>
#include <utility/aglParameterObj.h>
#include "KingSystem/ActorSystem/actAttPos.h"
#include "KingSystem/Attention/attAttention.h"
#include "KingSystem/Resource/resResource.h"
#include "KingSystem/Utils/ParamIO.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::act {

class AttCheck;

class AttClient : public ParamIO, public res::Resource {
    SEAD_RTTI_OVERRIDE(AttClient, res::Resource)
public:
    AttClient() : ParamIO("atcl", 0) {}
    ~AttClient() override;

    att::AttType getAttType() const { return mAttType; }
    att::AttActionCode getActionCode() const { return mActionCode; }
    att::AttPriorityType getPriorityType() const { return mPriorityType; }
    const sead::SafeString& getPriorityTypeStr() const { return mPriorityTypeStr; }
    const sead::Buffer<AttCheck*>& getChecks() const { return mChecks; }

    int getNumChecks() const;

    // TODO: check functions

    void appendPriority(sead::BufferedSafeString* str);

    void doCreate_(u8*, u32, sead::Heap*) override;
    bool needsParse() const override { return true; }
    bool parse_(u8* data, size_t size, sead::Heap* heap) override;

private:
    att::AttType mAttType = att::AttType::Action;
    att::AttActionCode mActionCode = att::AttActionCode::None;
    att::AttPriorityType mPriorityType = att::AttPriorityType::Default;
    sead::FixedSafeString<32> mPriorityTypeStr;
    agl::utl::ParameterObj mAttClientParamsObj;
    agl::utl::Parameter<sead::FixedSafeString<32>> mAttTypeParam;
    agl::utl::Parameter<sead::FixedSafeString<32>> mActionTypeParam;
    agl::utl::Parameter<sead::FixedSafeString<32>> mPriorityTypeParam;
    sead::Buffer<AttCheck*> mChecks;
};
KSYS_CHECK_SIZE_NX150(AttClient, 0x428);

class AttClientList : public ParamIO, public res::Resource {
    SEAD_RTTI_OVERRIDE(AttClientList, res::Resource)
public:
    struct Client {
        const char* getFileName() const { return file_name.ref().cstr(); }

        agl::utl::Parameter<sead::SafeString> name;
        agl::utl::Parameter<sead::SafeString> file_name;
        agl::utl::Parameter<bool> is_valid;
        agl::utl::ParameterObj obj;
        AttClient* client;
    };
    KSYS_CHECK_SIZE_NX150(Client, 0xa8);

    AttClientList() : ParamIO("atcllist", 0) {}
    ~AttClientList() override;
    AttClientList(const AttClientList&) = delete;
    auto operator=(const AttClientList&) = delete;

    const AttPos& getAttPos() const { return mAttPos; }
    bool isForceEdit() const;
    const sead::Buffer<Client>& getClients() const { return mClients; }

    // TODO: one more function

    void addClient_(s32 index, AttClient* client) { mClients[index].client = client; }

    void doCreate_(u8* buffer, u32 buffer_size, sead::Heap* heap) override;
    bool needsParse() const override { return true; }
    bool parse_(u8* data, size_t size, sead::Heap* heap) override;
    bool finishParsing_() override;
    bool prepareUnload_() override;

private:
    agl::utl::ParameterList mAttClientsList;
    agl::utl::ParameterObj mAttPosObj;
    AttPos mAttPos;
    agl::utl::Parameter<bool> mForceEdit;
    sead::Buffer<Client> mClients;
};
KSYS_CHECK_SIZE_NX150(AttClientList, 0x3f0);

}  // namespace ksys::act
