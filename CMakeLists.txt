cmake_minimum_required(VERSION 3.23)

project(piwm
        VERSION 0.1.0
        DESCRIPTION "Yet another window management library"
        LANGUAGES CXX
)

include(cmake/options.cmake)
include(cmake/dependencies.cmake)

enable_testing()

add_subdirectory(src)
if(PIWM_BUILD_TESTS)
    add_subdirectory(tests)
endif()
if(PIWM_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

include(cmake/install.cmake)
