add_library(piwm)
add_library(pi::WindowManager ALIAS piwm)

#target_sources(
#        piwm
#        PRIVATE src/core/
#)

if(WIN32)
    target_sources(
            piwm
            PRIVATE src/platform/win32/window_win32.cxx
    )
elseif(UNIX AND NOT APPLE)
    if(PIWM_SUPPORT_WAYLAND)
        find_package(Wayland REQUIRED)

        target_sources(piwm PRIVATE src/platform/wayland/window_wayland.cxx)

        target_link_libraries(piwm PRIVATE Wayland::Wayland)
    endif()
    if(PIWM_SUPPORT_X11)
        find_package(X11 REQUIRED)

        target_sources(piwm PRIVATE src/platform/x11/window_x11.cxx)

        target_link_libraries(piwm PRIVATE X11::X11)
    endif()
endif()

target_include_directories(
        piwm
        PRIVATE src/
)

target_sources(
        piwm PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include/
        FILES
            include/piwm/display.hxx
            include/piwm/input.hxx
            include/piwm/window.hxx
)

target_link_libraries(piwm PRIVATE pi::TypeLists)

target_compile_features(piwm PUBLIC cxx_std_23)
