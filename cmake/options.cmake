option(PIWM_BUILD_TESTS "Build piwm tests" ON)

option(PIWM_BUILD_EXAMPLES "Build piwm examples" ON)

set(PIWM_DISPLAY_SERVER "Wayland" CACHE STRING "Display server to use on Linux")
set_property(CACHE PIWM_DISPLAY_SERVER PROPERTY STRINGS "Wayland" "X11")
