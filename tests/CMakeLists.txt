include(CTest)
include(Catch)

add_executable(piwm_unit_tests unit/core/test_window.cxx)

target_link_libraries(piwm_unit_tests PRIVATE pi::WindowManager)
target_link_libraries(piwm_unit_tests PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(piwm_unit_tests)

add_executable(piwm_integration_tests integration/test_window.cxx)

target_link_libraries(piwm_integration_tests PRIVATE pi::WindowManager)
target_link_libraries(piwm_integration_tests PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(piwm_integration_tests)
