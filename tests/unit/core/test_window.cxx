#include <catch2/catch_test_macros.hpp>

#include <struct.hxx>

#include <piwm/types.hxx>
#include <piwm/window.hxx>

using namespace std::string_literals;

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
                REQUIRE(window->title() == "Hello"s);
            }

            THEN("The window should be positioned at position (0, 0)")
            {
                REQUIRE(window->position() == pi::Position{ pi::X{ pi::Scalar{ 0 } }, pi::Y{ pi::Scalar{ 0 } } });
            }

            THEN("The window size is 800 pixels in width by 600 pixels in height")
            {
                REQUIRE(window->size() == pi::Size{ pi::Width{ pi::Scalar{ 800 } }, pi::Height{ pi::Scalar{ 600 } } });
            }
        }
    }
}
