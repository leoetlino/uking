#pragma once

namespace sead {
class Heap;
}

namespace ksys::tera {

// TODO:
class ApertureMaps {
    void updateMap();
};
class ApertureMapsCollector {
    void allocateImage();
    void releaseImage();
};
class Core {
    class Grass;
    class Model;
    class Tree;
};
class ImageResourceMgr {
    void procUnloadResidualRequest();
};
class ResourceHolder;
class Scene {
public:
    static Scene* instance();
    void allocateApertureMapsCollectorImage(sead::Heap* heap);
    void loadScene();

private:
    void exportFileBinary();
};
class Water {
    void setUpAttributeTable();
};

bool checkTeraSystemStatus();

}  // namespace ksys::tera
