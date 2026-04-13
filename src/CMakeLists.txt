add_library(piwm)
add_library(pi::WindowManager ALIAS piwm)

target_sources(
        piwm
        PRIVATE core/window_base.cxx
)

if(WIN32)
    target_sources(
            piwm
            PRIVATE
            platform/win32/window_win32.cxx
    )
elseif(UNIX AND NOT APPLE)
    if(PIWM_DISPLAY_SERVER STREQUAL "Wayland")
        find_package(PkgConfig REQUIRED)
        pkg_check_modules(Wayland REQUIRED wayland-client)

        target_sources(piwm PRIVATE platform/wayland/window_wayland.cxx )

        target_link_libraries(piwm PRIVATE ${Wayland_LIBRARIES})

        target_include_directories(piwm PRIVATE ${Wayland_INCLUDE_DIRS})
    elseif(PIWM_DISPLAY_SERVER STREQUAL "X11")
        find_package(X11 REQUIRED)

        target_sources(piwm PRIVATE platform/x11/window_x11.cxx)

        target_link_libraries(piwm PRIVATE X11::X11)
    endif()
endif()

target_include_directories(
        piwm
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC
            $<BUILD_INTERFACE:${typelists_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
)

target_sources(
        piwm
        PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ../include/
        FILES
            ../include/piwm/display.hxx
            ../include/piwm/input.hxx
            ../include/piwm/types.hxx
            ../include/piwm/window.hxx
)

target_compile_features(piwm PUBLIC cxx_std_23)
