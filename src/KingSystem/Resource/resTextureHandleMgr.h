#pragma once

namespace ksys::res {

class TextureArchiveWork;

// TODO: very incomplete
class TextureHandleMgr {
public:
    virtual ~TextureHandleMgr();

    void preCalc();
    void calc();

    TextureArchiveWork* getArchiveWork() const;
    void clearAllCache();
};

}  // namespace ksys::res
