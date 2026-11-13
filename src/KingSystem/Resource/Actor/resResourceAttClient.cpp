#include "resResourceAttClient.h"
#include <container/seadSafeArray.h>
#include "resResourceAttCheck.h"

namespace ksys::res {

AttClientList::~AttClientList() {
    mClients.freeBuffer();
}

void AttClientList::doCreate_(u8* buffer, u32 buffer_size, sead::Heap* heap) {}

bool AttClientList::parse_(u8* data, size_t size, sead::Heap* heap) {
    if (!data)
        return false;

    agl::utl::ResParameterArchive archive{data};
    const auto root = archive.getRootList();

    mAttPos.init(&mAttPosObj);
    mForceEdit.init(false, "ForceEdit", "強制編集", "", &mAttPosObj);
    addObj(&mAttPosObj, "AttPos");

    const auto AttClients = agl::utl::getResParameterList(root, "AttClients");
    if (int num; AttClients && (num = AttClients.getResParameterObjNum()) != 0) {
        mClients.allocBufferAssert(num, heap);
        for (auto it = mClients.begin(), end = mClients.end(); it != end; ++it) {
            it->client = nullptr;
            it->name.init("", "Name", "クライアントのキー名", "", &it->obj);
            it->file_name.init("", "FileName", "クライアントのデータファイル名", "", &it->obj);
            it->is_valid.init(true, "IsValid", "デフォルトの有効・無効状態", "", &it->obj);

            mAttClientsList.addObj(
                &it->obj, sead::FormatFixedSafeString<32>("%s%d", "AttClient_", it.getIndex()));
        }
    }

    addList(&mAttClientsList, "AttClients");

    applyResParameterArchive(archive);
    return true;
}

bool AttClientList::finishParsing_() {
    return true;
}

bool AttClientList::prepareUnload_() {
    for (auto& client : mClients)
        client.client = nullptr;
    return true;
}

bool AttClientList::isForceEdit() const {
    return mForceEdit.ref();
}

AttClient::~AttClient() {
    for (int i = 0; i < mChecks.size(); ++i) {
        if (mChecks[i]) {
            delete mChecks[i];
            mChecks[i] = nullptr;
        }
    }
    mChecks.freeBuffer();
}

void AttClient::doCreate_(u8*, u32, sead::Heap*) {}

namespace {

// Keep this in sync with ksys::att::AttType!
sead::SafeArray<const char*, 8> sAttTypes = {{
    "Action",
    "Lock",
    "SwordSearch",
    "Attack",
    "Appeal",
    "JumpRide",
    "NameBalloon",
    "LookOnly",
}};

void parseAttType(const agl::utl::ResParameterObj& AttClientParams, att::AttType* type) {
    const sead::SafeString AttType =
        agl::utl::getResParameter(AttClientParams, "AttType").getData<char>();

    *type = att::AttType::Invalid;

    for (int i = 0; i < sAttTypes.size(); ++i) {
        if (AttType == sAttTypes[i]) {
            *type = static_cast<att::AttType>(i);
            break;
        }
    }

    if (*type == att::AttType::Invalid)
        *type = att::AttType::Action;
}

void parseActionType(const agl::utl::ResParameterObj& AttClientParams, att::AttActionCode* code) {
    const sead::SafeString ActionType =
        agl::utl::getResParameter(AttClientParams, "ActionType").getData<char>();

    *code = att::AttActionCode::Dummy;

    for (int i = int(att::AttActionCode::None); i < int(att::AttActionCode::Dummy); ++i) {
        if (ActionType == att::AttActionType::text(i - int(att::AttActionCode::None))) {
            *code = static_cast<att::AttActionCode>(i);
            break;
        }
    }

    if (*code == att::AttActionCode::Dummy)
        *code = att::AttActionCode::None;
}

}  // namespace

bool AttClient::parse_(u8* data, size_t size, sead::Heap* heap) {
    if (!data)
        return false;

    agl::utl::ResParameterArchive archive{data};
    const auto root = archive.getRootList();
    const auto AttClientParams = root.getResParameterObj(0);

    parseAttType(AttClientParams, &mAttType);
    parseActionType(AttClientParams, &mActionCode);
    addObj(&mAttClientParamsObj, "AttClientParams");

    mAttTypeParam.init({sAttTypes[0]}, "AttType", "", &mAttClientParamsObj);
    mActionTypeParam.init({att::AttActionType(att::AttActionType::None).text()}, "ActionType", "",
                          &mAttClientParamsObj);
    mPriorityTypeParam.init({att::AttPriorityType(att::AttPriorityType::Obj).text()},
                            "PriorityType", "", &mAttClientParamsObj);

    const int num_checks = root.getResParameterListNum();
    if (num_checks != 0) {
        mChecks.allocBufferAssert(num_checks, heap);
        for (int i = 0; i < num_checks; ++i)
            mChecks[i] = nullptr;

        AttCheck::CreateArg arg{};
        arg.heap = heap;
        arg.client = this;

        auto it = mChecks.begin(), end = mChecks.end();
        auto res_it = root.listBegin(), res_end = root.listEnd();
        for (; it != end && res_it != res_end; ++res_it, ++it) {
            arg.res_list = res_it.getList();

            auto* check = *it = AttCheck::make(arg);
            if (check == nullptr)
                return false;

            addList(&check->getList_(),
                    sead::FormatFixedSafeString<32>("%s%d", "Check_", it.getIndex()));
        }
    }

    applyResParameterArchive(archive);

    const sead::SafeString PriorityType = mPriorityTypeParam.ref();
    for (auto priority : att::AttPriorityType{}) {
        if (PriorityType == priority.text()) {
            mPriorityType = priority;
            mPriorityTypeStr = PriorityType;
            return true;
        }
    }
    mPriorityType = att::AttPriorityType::Obj;
    mPriorityTypeStr = mPriorityType.text();
    return true;
}

int AttClient::getNumChecks() const {
    return mChecks.size();
}

void AttClient::appendPriority(sead::BufferedSafeString* str) {
    str->append(mPriorityTypeStr);
}

}  // namespace ksys::res
