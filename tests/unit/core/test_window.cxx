#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <typelists/struct.hxx>

#include <piwm/types.hxx>
#include <piwm/window.hxx>

using namespace std::string_literals;

namespace
{
    auto constexpr scalar_epsilon = piwm::Scalar{ 1.e-10 };
}

TEST_CASE("A window instance can be created with default attributes.", "[Window][Default]")
{
	using namespace piwm;

    auto const default_title = Title{ "PiWM" };
    auto constexpr default_x = X{ Scalar{ 0 } };
    auto constexpr default_y = Y{ Scalar{ 0 } };
    auto const default_position = Position(default_x, default_y);
	auto constexpr default_width = Width{ Scalar{ 800 } };
	auto constexpr default_height = Height{ Scalar{ 600 } };
    auto const default_size = Size{ default_width, default_height };

    auto const window = make_window();

    SECTION("The instance is not null.")
    {
		REQUIRE(window != nullptr);
    }

    SECTION("The instance has the expected default title.")
    {
        REQUIRE(window->get<Title>() == default_title);
	}

    SECTION("The instance has the expected default position.")
    {
        REQUIRE(window->get<Position>() == default_position);
	}

    SECTION("The instance has the expected default X position.")
    {
        REQUIRE_THAT(window->get<X>(), Catch::Matchers::WithinAbs(default_x, scalar_epsilon));
	}

    SECTION("The instance has the expected default Y position.")
    {
        REQUIRE_THAT(window->get<Y>(), Catch::Matchers::WithinAbs(default_y, scalar_epsilon));
    }

    SECTION("The instance has the expected default size.")
    {
        REQUIRE(window->get<Size>() == default_size);
    }

    SECTION("The instance has the expected default width.")
    {
        REQUIRE_THAT(window->get<Width>(), Catch::Matchers::WithinAbs(default_width, scalar_epsilon));
	}

    SECTION("The instance has the expected default height.")
    {
        REQUIRE_THAT(window->get<Height>(), Catch::Matchers::WithinAbs(default_height, scalar_epsilon));
	}

    SECTION("All attributes can be queried with one call.")
    {
        auto const [title, position, size] = window->get<Title, Position, Size>();

		REQUIRE(title == default_title);
		REQUIRE(position == default_position);
		REQUIRE(size == default_size);
    }

    SECTION("Several attributes can be queried with one call.")
    {
        auto const [x, y, width, height] = window->get<X, Y, Width, Height>();

		REQUIRE_THAT(x, Catch::Matchers::WithinAbs(default_x, scalar_epsilon));
		REQUIRE_THAT(y, Catch::Matchers::WithinAbs(default_y, scalar_epsilon));
		REQUIRE_THAT(width, Catch::Matchers::WithinAbs(default_width, scalar_epsilon));
		REQUIRE_THAT(height, Catch::Matchers::WithinAbs(default_height, scalar_epsilon));
    }
}

TEST_CASE("The attributes of a window can be changed.", "[Window][Set]")
{
	using namespace piwm;

	auto const new_title = Title{ "New title" };
	auto constexpr new_x = X{ Scalar{ 100 } };
	auto constexpr new_y = Y{ Scalar{ 100 } };
	auto const new_position = Position(new_x, new_y);
	auto constexpr new_width = Width{ Scalar{ 640 } };
	auto constexpr new_height = Height{ Scalar{ 480 } };
	auto const new_size = Size{ new_width, new_height };

    auto const window = make_window();

    SECTION("The title can be changed.")
    {
		window->set(new_title);

		REQUIRE(window->get<Title>() == new_title);
    }

    SECTION("The position can be changed.")
    {
		window->set(new_position);

		REQUIRE(window->get<Position>() == new_position);
    }

    SECTION("The size can be changed.")
    {
        window->set(new_size);

        REQUIRE(window->get<Size>() == new_size);
    }

	SECTION("All attributes can be changed with one call.")
    {
        window->set(new_title, new_size, new_position);

		REQUIRE(window->get<Title>() == new_title);
        REQUIRE(window->get<Position>() == new_position);
        REQUIRE(window->get<Size>() == new_size);
    }

    SECTION("Several attributes can be changed with one call.")
    {
        window->set(new_x, new_y, new_width, new_height);

        REQUIRE_THAT(window->get<X>(), Catch::Matchers::WithinAbs(new_x, scalar_epsilon));
		REQUIRE_THAT(window->get<Y>(), Catch::Matchers::WithinAbs(new_y, scalar_epsilon));
		REQUIRE_THAT(window->get<Width>(), Catch::Matchers::WithinAbs(new_width, scalar_epsilon));
		REQUIRE_THAT(window->get<Height>(), Catch::Matchers::WithinAbs(new_height, scalar_epsilon));
    }
}
