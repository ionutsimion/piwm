#include <catch2/catch_test_macros.hpp>

#include <piwm/window.hxx>

SCENARIO("creating a window")
{
    GIVEN("pi::WindowManager")
    {
        WHEN("a window is created with default parameters")
        {
            auto const window = piwm::make_window();

            THEN("the window should not be null.")
        }
    }
}
