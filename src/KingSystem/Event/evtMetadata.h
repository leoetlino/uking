#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>
#include "KingSystem/Utils/Types.h"

namespace ksys::act {
class Actor;
}

namespace ksys::evt {

class OrderParam;

class Metadata {
public:
    enum class Priority {
        Timeline = 4,
        Demo017 = 5,
        StepStart = 10,
        Demo = 15,
        Default = 100,
        Talk = 400,
        Near = 410,
        Async = 500,
        Background = 510,
    };

    Metadata();
    Metadata(const char* event, const char* entry_point, const char* type = "");
    explicit Metadata(const char* event) : Metadata(event, event) {}
    virtual ~Metadata();

    Metadata(const Metadata& other) { *this = other; }
    Metadata& operator=(const Metadata& other);

    void init(const char* event, const char* entry_point, const char* type = "");
    void reset();

    act::Actor* getCurrentActor() const { return mCurrentActor; }
    void setCurrentActor(act::Actor* actor) { mCurrentActor = actor; }

    bool isSetNoDeleteCurrentActor() const { return mSetNoDeleteCurrentActor; }
    bool isSkipIsStartableAirCheck() const { return mSkipIsStartableAirCheck; }
    bool isForceNoChild() const { return mForceNoChild; }
    bool is13() const { return _13; }
    void* get18() const { return _18; }
    u32 get20() const { return _20; }
    int getEventStartWaitFrame() const { return mEventStartWaitFrame; }
    const sead::SafeString& getEventName() const { return mEventName; }
    const sead::SafeString& getEntryPointName() const { return mEntryPointName; }
    const sead::SafeString& getType() const { return mType; }
    Priority getPriority() const { return mPriority; }
    OrderParam* getOrderParam() const { return mOrderParam; }
    bool isAsync() const { return mIsAsync; }

private:
    void initOrderParam_();
    void initPriority_();
    void doAssign_(const Metadata& other);

    act::Actor* mCurrentActor;
    bool mSetNoDeleteCurrentActor;
    bool mSkipIsStartableAirCheck;
    bool mForceNoChild;
    bool _13;
    void* _18;
    u32 _20;
    int mEventStartWaitFrame;
    sead::FixedSafeString<64> mEventName;
    sead::FixedSafeString<128> mEntryPointName;
    sead::FixedSafeString<16> mType;
    Priority mPriority = Priority::Default;
    OrderParam* mOrderParam{};
    bool mIsAsync;
};
KSYS_CHECK_SIZE_NX150(Metadata, 0x158);

}  // namespace ksys::evt
