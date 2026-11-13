target_include_directories(uking PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(uking PRIVATE
  Byaml/Byaml.cpp
  Byaml/Byaml.h
  Byaml/ByamlArrayIter.cpp
  Byaml/ByamlArrayIter.h
  Byaml/ByamlData.cpp
  Byaml/ByamlData.h
  Byaml/ByamlHashIter.cpp
  Byaml/ByamlHashIter.h
  Byaml/ByamlLocal.cpp
  Byaml/ByamlLocal.h
  Byaml/ByamlStringTableIter.cpp
  Byaml/ByamlStringTableIter.h
  Byaml/ByamlUtil.cpp
)
