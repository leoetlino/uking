add_subdirectory(Action)
add_subdirectory(AI)
add_subdirectory(Area)
add_subdirectory(Ecosystem)
add_subdirectory(Event)
add_subdirectory(Horse)
add_subdirectory(NPC)
add_subdirectory(Physics)
add_subdirectory(Player)
add_subdirectory(Resource)
add_subdirectory(Rope)
add_subdirectory(System)
add_subdirectory(Weapon)

target_sources(uking PRIVATE
  GlobalParameter.cpp
  GlobalParameter.h
  StageInfo.cpp
  StageInfo.h
  StagePreActorCache.cpp
  StagePreActorCache.h
)
