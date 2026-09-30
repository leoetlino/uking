add_subdirectory(Action)
add_subdirectory(AI)
add_subdirectory(Area)
add_subdirectory(Event)
add_subdirectory(Horse)
add_subdirectory(NPC)
add_subdirectory(Player)
add_subdirectory(System)

target_sources(uking PRIVATE
  StageInfo.cpp
  StageInfo.h
  StagePreActorCache.cpp
  StagePreActorCache.h
)
