#pragma once

#include <hostio/seadHostIONode.h>
#include "KingSystem/Physics/System/physSkeletonModelPose.h"
#include "KingSystem/Physics/System/physSkeletonPose.h"

class hkaSkeletonMapper;

namespace ksys::phys {

class SkeletonMapper : public sead::hostio::Node {
public:
    SkeletonMapper();
    virtual ~SkeletonMapper();

    bool init(hkaSkeletonMapper* skeleton_mapper, hkaSkeletonMapper* model_skeleton_mapper,
              gsys::Model* model, sead::Heap* heap);

    void mapPoseA();
    void mapPoseB();

    SkeletonPose& getSkeletonPose() { return mSkeletonPose; }
    SkeletonModelPose& getSkeletonModelPose() { return mSkeletonModelPose; }

private:
    SkeletonPose mSkeletonPose;
    SkeletonModelPose mSkeletonModelPose;
    hkaSkeletonMapper* mMapperA{};
    hkaSkeletonMapper* mMapperB{};
};

}  // namespace ksys::phys
