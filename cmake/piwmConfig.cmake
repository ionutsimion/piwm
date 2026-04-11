include(CMakeFindDependencyMacro)
include(FetchContent)

FetchContent_Declare(
        typedecl
        GIT_REPOSITORY https://github.com/ionutsimion/typelists.git
        GIT_TAG v0.1.0
)
FetchContent_MakeAvailable(typedecl)

include(${CMAKE_CURRENT_LIST_DIR}/piwmTargets.cmake)
