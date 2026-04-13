include(FetchContent)

FetchContent_Declare(
        typelists
        GIT_REPOSITORY https://github.com/ionutsimion/typelists.git
        GIT_TAG v0.1.3
)
FetchContent_MakeAvailable(typelists)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.14.0
)
FetchContent_MakeAvailable(Catch2)
