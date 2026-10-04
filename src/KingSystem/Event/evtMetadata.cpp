#include "KingSystem/Event/evtMetadata.h"
#include "KingSystem/Event/evtManager.h"
#include "KingSystem/Event/evtOrderParam.h"

namespace ksys::evt {

Metadata::Metadata() {
    reset();
    initOrderParam_();
}

Metadata::Metadata(const char* event, const char* entry_point, const char* type) {
    reset();
    initOrderParam_();
    init(event, entry_point, type);
}

Metadata::~Metadata() {
    if (mOrderParam) {
        delete mOrderParam;
        mOrderParam = nullptr;
    }
}

void Metadata::doAssign_(const Metadata& other) {
    reset();
    init(other.mEventName.cstr(), other.mEntryPointName.cstr(), other.mType.cstr());

    mCurrentActor = other.mCurrentActor;
    if (other.mSetNoDeleteCurrentActor)
        mSetNoDeleteCurrentActor = true;
    _18 = other._18;
    _20 = other._20;
    mIsAsync = other.mIsAsync;
    mSkipIsStartableAirCheck = other.mSkipIsStartableAirCheck;
    mForceNoChild = other.mForceNoChild;
    _13 = other._13;
    mEventStartWaitFrame = other.mEventStartWaitFrame;
    if (mOrderParam && other.mOrderParam)
        *mOrderParam = *other.mOrderParam;
}

Metadata& Metadata::operator=(const Metadata& other) {
    if (this != &other)
        doAssign_(other);
    return *this;
}

void Metadata::init(const char* event, const char* entry_point, const char* type) {
    mEventName = event;
    mEntryPointName = entry_point;
    mType = type;
    initPriority_();
}

void Metadata::reset() {
    mEventName.clear();
    mEntryPointName.clear();
    mType.clear();
    mPriority = Priority::Default;
    _18 = {};
    mIsAsync = false;
    mSetNoDeleteCurrentActor = false;
    mSkipIsStartableAirCheck = false;
    mForceNoChild = false;
    _13 = false;
    mCurrentActor = nullptr;
    _20 = 0;
    mEventStartWaitFrame = -1;
}

void Metadata::initOrderParam_() {
    if (mOrderParam)
        return;

    if (!Manager::instance())
        return;

    sead::Heap* heap = Manager::instance()->getEventHeap();
    if (!heap)
        return;

    mOrderParam = new (heap, std::nothrow_t()) OrderParam(heap);
    if (mOrderParam)
        mOrderParam->initialize(8);
}

void Metadata::initPriority_() {
    if (mEventName == "Demo006_0") {
        mPriority = Priority::Timeline;
    } else if (mEventName == "Demo017_0") {
        mPriority = Priority::Demo017;
    } else if (mEventName == "ClearRemains" || mEventName.comparen("Demo", 4) == 0) {
        mPriority = Priority::Demo;
    } else if (mEventName.comparen("OpenDoor", 8) == 0) {
        mPriority = Priority::Demo;
    } else if (mType == "Timeline") {
        mPriority = Priority::Timeline;
    } else if (mType == "Talk") {
        mPriority = Priority::Talk;
    } else if (mType == "EachFrame") {
        mPriority = Priority::Async;
    } else if (mType == "Near" || mType == "NearActors") {
        mPriority = Priority::Near;
    } else if (mType == "StepStart") {
        mPriority = Priority::StepStart;
    } else if (mType == "Background") {
        mPriority = Priority::Background;
    } else {
        mPriority = Priority::Default;
    }
}

}  // namespace ksys::evt
