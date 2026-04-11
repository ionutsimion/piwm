cmake_minimum_required(VERSION 3.23)

project(piwm
        VERSION 0.1.0
        DESCRIPTION "Yet another window management library"
        LANGUAGES CXX
)

include(cmake/dependencies.cmake)
include(cmake/install.cmake)

option(PIWM_BUILD_TESTS "Build piwm tests" ON)
option(PIWM_BUILD_EXAMPLES "Build piwm examples" ON)
if(UNIX AND NOT APPLE)
    option(PIWM_SUPPORT_WAYLAND "Support Wayland windows management system" ON)
    option(PIWM_SUPPORT_X11 "Support X11 windows management system" ON)
endif()

enable_testing()

add_subdirectory(src)
if(PIWM_BUILD_TESTS)
    add_subdirectory(tests)
endif()
if(PIWM_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
