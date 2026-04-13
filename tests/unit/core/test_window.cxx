#include <catch2/catch_test_macros.hpp>

#include <struct.hxx>

#include <piwm/types.hxx>
#include <piwm/window.hxx>

using namespace std::string_literals;

using namespace piwm;

SCENARIO("Instantiating a Window")
{
    GIVEN("The piwm library")
    {
        WHEN("A window is created with default parameters")
        {
            auto const window = make_window();
            auto const default_title = "Hello"s;
            auto const default_x = X{ Scalar{ 0 } };
            auto const default_y = Y{ Scalar{ 0 } };
            // TODO: Add copy and move constructors for wrapper_for_fundamental to use default_x and default_y
            auto const default_position = Position{ X{ Scalar{ 0 } }, Y{ Scalar{ 0 } } };
            auto const default_width = Width{ Scalar{ 800 } };
            auto const default_height = Height{ Scalar{ 600 } };
            auto const default_size = Size{ Width{ Scalar{ 800 } }, Height{ Scalar{ 600 } } };

            THEN("The window should not be null")
            {
                REQUIRE(window != nullptr);
            }

            THEN("The window should have a default title")
            {
                REQUIRE(window->get<Title>() == default_title);
            }

            THEN("The window should be positioned at position (0, 0)")
            {
                REQUIRE(window->get<Position>() == default_position);
            }

            THEN("The horizontal position of the window should be 0")
            {
                REQUIRE(window->get<X>() == default_x);
            }

            THEN("The vertical position of the window should be 0")
            {
                REQUIRE(window->get<Y>() == default_y);
            }

            THEN("The window size is 800 pixels in width by 600 pixels in height")
            {
                REQUIRE(window->get<Size>() == default_size);
            }

            THEN("The window is 800 pixels wide")
            {
                REQUIRE(window->get<Width>() == default_width);
            }

            THEN("The window is 600 pixels tall")
            {
                REQUIRE(window->get<Height>() == default_height);
            }
        }
    }
}
