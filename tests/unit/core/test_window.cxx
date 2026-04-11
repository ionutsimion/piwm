#include <catch2/catch_test_macros.hpp>

#include <piwm/window.hxx>

using namespace std::string_view_literals;

SCENARIO("Instantiating a Window")
{
    GIVEN("The piwm library")
    {
        WHEN("A window is created with default parameters")
        {
            auto window = pi::make_window();

            THEN("The window should not be null")
            {
                REQUIRE(window != nullptr);
            }

            THEN("The window should have a default title")
            {
                REQUIRE(window->title() == "Hello"sv);
            }
        }
    }
}
