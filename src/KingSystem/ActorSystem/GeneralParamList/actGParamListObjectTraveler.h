#pragma once

#include <utility/aglParameter.h>
#include "KingSystem/ActorSystem/GeneralParamList/actGParamListObject.h"
#include "KingSystem/Utils/FixedString.h"
#include "KingSystem/Utils/Types.h"

#define STR5_HELP(A, B, C, D, E) A##B##C##D##E
#define STR5(a, b, c, d, e) STR5_HELP(a, b, c, d, e)

#define ROUTE_POINT(PT)                                                                            \
    PT(0, 1)                                                                                       \
    PT(1, 2)                                                                                       \
    PT(2, 3)                                                                                       \
    PT(3, 4)                                                                                       \
    PT(4, 5)                                                                                       \
    PT(5, 6)                                                                                       \
    PT(6, 7)                                                                                       \
    PT(7, 8)                                                                                       \
    PT(8, 9)                                                                                       \
    PT(9, 10)                                                                                      \
    PT(10, 11)                                                                                     \
    PT(11, 12)                                                                                     \
    PT(12, 13)                                                                                     \
    PT(13, 14)                                                                                     \
    PT(14, 15)                                                                                     \
    PT(15, 16)                                                                                     \
    PT(16, 17)                                                                                     \
    PT(17, 18)                                                                                     \
    PT(18, 19)                                                                                     \
    PT(19, 20)                                                                                     \
    PT(20, 21)                                                                                     \
    PT(21, 22)                                                                                     \
    PT(22, 23)                                                                                     \
    PT(23, 24)                                                                                     \
    PT(24, 25)                                                                                     \
    PT(25, 26)                                                                                     \
    PT(26, 27)                                                                                     \
    PT(27, 28)                                                                                     \
    PT(28, 29)

namespace ksys::act {

class GParamListObjectTraveler : public GParamListObject {
public:
    struct RoutePoint {
        RoutePoint();

        template <s32 I>
        KSYS_VISIBILITY_HIDDEN void initParameters_(agl::utl::ParameterObj* obj);

        struct DirectionInfo {
            template <s32 From, s32 To>
            KSYS_VISIBILITY_HIDDEN void initParameters_(agl::utl::ParameterObj* obj);

            agl::utl::Parameter<sead::SafeString> mEntryPoint;
            agl::utl::Parameter<f32> mWaitFrame;
            agl::utl::Parameter<sead::SafeString> mSchedule;
            agl::utl::Parameter<sead::SafeString> mMoveAS;
            agl::utl::Parameter<sead::SafeString> mWaitAS;
        };

        agl::utl::Parameter<sead::SafeString> mName;
        // i to i+1
        DirectionInfo mForward;
        // i+1 to i
        DirectionInfo mBackward;
    };
    static constexpr size_t NumRoutePoints = 29;

    GParamListObjectTraveler();
    const char* getName() const override { return "Traveler"; }

    agl::utl::Parameter<sead::SafeString> mAppearGameDataName;
    agl::utl::Parameter<sead::SafeString> mDeleteGameDataName;
    agl::utl::Parameter<sead::SafeString> mRouteType;
    agl::utl::Parameter<sead::SafeString> mRideHorseName;
    agl::utl::Parameter<bool> mIsLeadHorse;
    agl::utl::Parameter<s32> mHorseGearLevel;

    struct RoutePoints {
        RoutePoints();
        auto& operator[](s32 i) { return reinterpret_cast<RoutePoint&>(mStorage[i]); }
        auto& operator[](s32 i) const { return reinterpret_cast<const RoutePoint&>(mStorage[i]); }
        auto data() { return reinterpret_cast<RoutePoint*>(&mStorage[0]); }

    private:
        std::aligned_storage_t<sizeof(RoutePoint), alignof(RoutePoint)> mStorage[NumRoutePoints];
    };
    RoutePoints mRoutePoints;
    agl::utl::Parameter<sead::SafeString> mRoutePoint29Name;

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const float& STR5(getRoutePoint, FROM, to, TO, WaitFrame()) const {                    \
        return *mRoutePoints[FROM].mForward.mWaitFrame;                                            \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const float& STR5(getRoutePoint, TO, to, FROM, WaitFrame()) const {                    \
        return *mRoutePoints[FROM].mBackward.mWaitFrame;                                           \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const sead::SafeString& STR5(getRoutePoint, FROM, to, TO, WaitAS()) const {            \
        return *mRoutePoints[FROM].mForward.mWaitAS;                                               \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const sead::SafeString& STR5(getRoutePoint, TO, to, FROM, WaitAS()) const {            \
        return *mRoutePoints[FROM].mBackward.mWaitAS;                                              \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const sead::SafeString& STR5(getRoutePoint, FROM, to, TO, MoveAS()) const {            \
        return *mRoutePoints[FROM].mForward.mMoveAS;                                               \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const sead::SafeString& STR5(getRoutePoint, TO, to, FROM, MoveAS()) const {            \
        return *mRoutePoints[FROM].mBackward.mMoveAS;                                              \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const sead::SafeString& STR5(getRoutePoint, FROM, to, TO, EntryPoint()) const {        \
        return *mRoutePoints[FROM].mForward.mEntryPoint;                                           \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const sead::SafeString& STR5(getRoutePoint, TO, to, FROM, EntryPoint()) const {        \
        return *mRoutePoints[FROM].mBackward.mEntryPoint;                                          \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const sead::SafeString& STR5(getRoutePoint, FROM, to, TO, Schedule()) const {          \
        return *mRoutePoints[FROM].mForward.mSchedule;                                             \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION

#define ROUTE_POINT_FUNCTION(FROM, TO)                                                             \
    virtual const sead::SafeString& STR5(getRoutePoint, TO, to, FROM, Schedule()) const {          \
        return *mRoutePoints[FROM].mBackward.mSchedule;                                            \
    }
    ROUTE_POINT(ROUTE_POINT_FUNCTION)
#undef ROUTE_POINT_FUNCTION
};
KSYS_CHECK_SIZE_NX150(GParamListObjectTraveler, 0x3148);

template <std::size_t N, std::size_t I = 0>
KSYS_ALWAYS_INLINE inline void
initGParamListTravelerRoutePoints(GParamListObjectTraveler::RoutePoint* point,
                                  agl::utl::ParameterObj* obj) {
    if constexpr (I < N) {
        point->initParameters_<I>(obj);
        initGParamListTravelerRoutePoints<N, I + 1>(point + 1, obj);
    }
}

inline GParamListObjectTraveler::GParamListObjectTraveler() {
    auto* const obj = &mObj;

    mAppearGameDataName.init("", "AppearGameDataName", "", obj);
    mDeleteGameDataName.init("", "DeleteGameDataName", "", obj);
    mRouteType.init("", "RouteType", "", obj);
    mRideHorseName.init("", "RideHorseName", "", obj);
    mIsLeadHorse.init(false, "IsLeadHorse", "", obj);
    mHorseGearLevel.init(-1, "HorseGearLevel", "", obj);

    initGParamListTravelerRoutePoints<NumRoutePoints>(mRoutePoints.data(), obj);
    mRoutePoint29Name.init("", "RoutePoint29Name", "", obj);
}

KSYS_ALWAYS_INLINE inline GParamListObjectTraveler::RoutePoints::RoutePoints() {
    // Nintendo seems to have duplicated the definitions for each of the 29 route points,
    // which is utterly disgusting and error prone. Manually writing out the loop and using
    // placement-new is necessary to prevent Clang from emitting a loop.
#pragma clang loop unroll(full)
    for (auto& storage : mStorage)
        new (&storage) RoutePoint;
}

KSYS_ALWAYS_INLINE inline GParamListObjectTraveler::RoutePoint::RoutePoint() = default;

template <s32 I>
KSYS_ALWAYS_INLINE void
GParamListObjectTraveler::RoutePoint::initParameters_(agl::utl::ParameterObj* obj) {
    mName.init("", KSYS_STR(Str("RoutePoint") + Str<I>() + Str("Name")), "", obj);
    mForward.initParameters_<I, I + 1>(obj);
    mBackward.initParameters_<I + 1, I>(obj);
}

template <s32 From, s32 To>
KSYS_ALWAYS_INLINE void
GParamListObjectTraveler::RoutePoint::DirectionInfo::initParameters_(agl::utl::ParameterObj* obj) {
    static constexpr auto prefix = [] {
        using ksys::util::Str;
        return Str("RoutePoint") + Str<From>() + Str("to") + Str<To>();
    }();

    mEntryPoint.init("", KSYS_STR(prefix + Str("EntryPoint")), "", obj);
    mWaitFrame.init(0.0, KSYS_STR(prefix + Str("WaitFrame")), "", obj);
    mSchedule.init("", KSYS_STR(prefix + Str("Schedule")), "", obj);
    mMoveAS.init("", KSYS_STR(prefix + Str("MoveAS")), "", obj);
    mWaitAS.init("", KSYS_STR(prefix + Str("WaitAS")), "", obj);
}

}  // namespace ksys::act
