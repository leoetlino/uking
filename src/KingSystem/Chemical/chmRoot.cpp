#include "KingSystem/Chemical/chmRoot.h"

namespace ksys::chm {

Root::Root() : res_shape_num(0, "res_shape_num", "シェイプ", "Min=0 ,Max=10", &chemical_header) {
    addObj(&chemical_header, "chemical_header");
    addList(&chemical_body, "chemical_body");
}

Root::~Root() {
    shapes.freeBuffer();
    rigids.freeBuffer();
}

void Root::parse(const agl::utl::ResParameterList& res_list, sead::Heap* heap) {
    const auto header_obj = agl::utl::getResParameterObj(res_list, "chemical_header");
    chemical_header.applyResParameterObj(header_obj);

    if (res_shape_num.ref() != 0) {
        shapes.allocBufferAssert(res_shape_num.ref(), heap);
        rigids.allocBufferAssert(res_shape_num.ref(), heap);
    }

    const auto body_list = agl::utl::getResParameterList(res_list, "chemical_body");
    for (auto it = shapes.begin(), end = shapes.end(); it != end; ++it) {
        chemical_body.addObj(std::addressof(*it),
                             sead::FormatFixedSafeString<16>("shape_%02d", it.getIndex()));
        chemical_body.addObj(&rigids[it.getIndex()],
                             sead::FormatFixedSafeString<16>("rigid_c_%02d", it.getIndex()));
    }
    chemical_body.applyResParameterList(body_list);
}

Rigid::Rigid()
    : attribute(0, "attribute", "フラグ", this),
      rigid_set_name({""}, "rigid_set_name", "剛体セット名", this),
      rigid_name({""}, "rigid_name", "剛体名", this), volume(1.0, "volume", "直指定体積", this),
      mass(1.0, "mass", "直指定質量", this),
      burn_out_time(0.0, "burn_out_time", "燃え尽き時間", this) {}

}  // namespace ksys::chm
