#pragma once

#include <basis/seadTypes.h>
#include <container/seadBuffer.h>
#include <container/seadListImpl.h>
#include <container/seadSafeArray.h>
#include <cstddef>
#include <math/seadVector.h>
#include <prim/seadBitFlag.h>
#include <prim/seadDelegate.h>
#include <prim/seadNamable.h>
#include <prim/seadSafeString.h>
#include <thread/seadAtomic.h>
#include "KingSystem/Game/Physics/physDefines.h"
#include "KingSystem/Physics/RigidBody/physRigidBody.h"
#include "KingSystem/Physics/physLayerMaskBuilder.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::phys {

struct ContactPoint;

class ContactPointInfoBase : public sead::INamable {
public:
    using Points = sead::Buffer<ContactPoint*>;

    ContactPointInfoBase(const sead::SafeString& name, int overflow_mode,
                         int ignore_separated_points, int ignore_disabled_contacts)
        : sead::INamable(name), mOverflowMode(overflow_mode),
          mIgnoreSeparatedPoints(ignore_separated_points),
          mIgnoreDisabledContacts(ignore_disabled_contacts) {}
    virtual ~ContactPointInfoBase() = default;
    virtual void freePoints() = 0;

    u32 getIgnoreSeparatedPoints() const { return mIgnoreSeparatedPoints; }
    void setIgnoreSeparatedPoints(u32 value) { mIgnoreSeparatedPoints = value; }

    bool acceptsPointDistance(float distance) const {
        return getIgnoreSeparatedPoints() == 0 || distance <= 0;
    }

    u32 getIgnoreDisabledContacts() const { return mIgnoreDisabledContacts; }
    void setIgnoreDisabledContacts(u32 value) { mIgnoreDisabledContacts = value; }

    bool isLayerSubscribed(ContactLayer layer) const {
        const auto type = getContactLayerType(layer);
        return mSubscribedLayers[int(type)].isOnBit(getContactLayerBaseRelativeValue(layer));
    }

    bool isNoCallbackDelayLayer(ContactLayer layer) const {
        const auto type = getContactLayerType(layer);
        return mNoCallbackDelayLayers[int(type)].isOnBit(getContactLayerBaseRelativeValue(layer));
    }

    void setLayerMasks(const LayerMaskBuilder& builder) {
        for (int i = 0; i < NumContactLayerTypes; ++i) {
            mSubscribedLayers[i] = builder.getMasks()[i].layers;
            mNoCallbackDelayLayers[i] = builder.getMasks()[i].no_callback_delay_layers;
        }
    }

public:
    // For internal use by the physics system.

    sead::Atomic<int>& getNumContactPoints() { return mNumContactPoints; }

    bool isLinked() const { return mListNode.isLinked(); }

    static constexpr size_t getListNodeOffset() {
        return offsetof(ContactPointInfoBase, mListNode);
    }

protected:
    friend class ContactMgr;

    sead::Atomic<int> mNumContactPoints;
    sead::SafeArray<sead::BitFlag32, 2> mSubscribedLayers;
    sead::SafeArray<sead::BitFlag32, 2> mNoCallbackDelayLayers;
    u32 mOverflowMode{};
    u32 mIgnoreSeparatedPoints{};
    u32 mIgnoreDisabledContacts{};
    sead::ListNode mListNode{};
};

class ContactPointInfo : public ContactPointInfoBase {
public:
    enum class ShouldDisableContact : bool {
        Yes = true,
        No = false,
    };

    /// Contact data passed to ContactCallback. The vector and collision-mask pointers are borrowed
    /// for the duration of the callback; copy their values if they are needed afterwards.
    struct Event {
        /// The other rigid body in the contact, rather than the body receiving the callback.
        RigidBody* body;
        const sead::Vector3f* position;
        const sead::Vector3f* separating_normal;
        const RigidBody::CollisionMasks* collision_masks;
    };

    class Iterator {
    public:
        enum class IsEnd : bool { Yes = true };

        enum class Point {
            BodyA,
            BodyB,
            Midpoint,
        };

        Iterator(const Points& points, int count);
        Iterator(const Points& points, int count, IsEnd is_end);

        Iterator& operator++() {
            ++mIdx;
            return *this;
        }

        virtual void getPointPosition(sead::Vector3f* out, Point point) const;
        virtual sead::Vector3f getPointPosition(Point point) const;

        const ContactPoint* getPoint() const { return mPoints[mIdx]; }
        const ContactPoint* operator*() const { return getPoint(); }

        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return lhs.mIdx == rhs.mIdx;
        }
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return !operator==(lhs, rhs);
        }

    private:
        int mIdx = 0;
        const ContactPoint* const* mPoints = nullptr;
        int mPointsNum = 0;
        const ContactPoint* const* mPointsStart = nullptr;
    };

    /// The output parameter starts at ShouldDisableContact::No. Set it to Yes to request that the
    /// physical contact be disabled, independently of the return value.
    ///
    /// When called by ContactMgr::registerContactPoint, return false to skip recording the point,
    /// or true to allow recording (subject to available storage). ContactListener's manifold
    /// callback ignores the return value and only checks the ShouldDisableContact output.
    using ContactCallback = sead::IDelegate2R<ShouldDisableContact*, const Event&, bool>;

    static ContactPointInfo* make(sead::Heap* heap, int num, const sead::SafeString& name,
                                  int overflow_mode, int ignore_separated_points,
                                  int ignore_disabled_contacts);
    static void free(ContactPointInfo* instance);

    ContactPointInfo(const sead::SafeString& name, int overflow_mode, int ignore_separated_points,
                     int ignore_disabled_contacts);
    ~ContactPointInfo() override;
    void freePoints() override;
    virtual void allocPoints(sead::Heap* heap, int num);

    ContactCallback* getContactCallback() const { return mContactCallback; }
    void setContactCallback(ContactCallback* cb) { mContactCallback = cb; }

    auto begin() const { return Iterator(mPoints, mNumContactPoints); }
    auto end() const { return Iterator(mPoints, mNumContactPoints, Iterator::IsEnd::Yes); }

protected:
    friend class ContactMgr;

    Points mPoints;
    ContactCallback* mContactCallback{};
};
KSYS_CHECK_SIZE_NX150(ContactPointInfo, 0x60);

}  // namespace ksys::phys
