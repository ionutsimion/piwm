#include <catch2/catch_test_macros.hpp>

#include <piwm/window.hxx>

SCENARIO("Instantiating a Window")
{
    GIVEN("The piwm library")
    {
        WHEN("A window is created with default parameters")
        {
            auto window = pi::make_window();

            THEN("The window should not be null.")
            {
                REQUIRE(window != nullptr);
            }
        }
    }
}
