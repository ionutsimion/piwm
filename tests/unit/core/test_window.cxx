#include <catch2/catch_test_macros.hpp>

#include <typelists/struct.hxx>

#include <piwm/types.hxx>
#include <piwm/window.hxx>

#include "catch2/matchers/catch_matchers_floating_point.hpp"

using namespace std::string_literals;

namespace
{
    auto constexpr scalar_epsilon = piwm::Scalar{ 1.e-10 };
}

TEST_CASE("1.1. A Window instance created with default attributes is not null", "[make_window]")
{
    REQUIRE(piwm::make_window() != nullptr);
}

TEST_CASE("1.2.1.1. get<Title> returns a Title instance", "[Window::get][Title]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_same_v<decltype(window->get<piwm::Title>()), piwm::Title>);
}

TEST_CASE("1.2.1.2. get<Title> is convertible to std::string", "[Window::get][Title]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_convertible_v<decltype(window->get<piwm::Title>()), std::string>);
}

TEST_CASE("1.2.1.3. get<Title> for default initialized windows", "[Window::get][Title]")
{
    auto const window = piwm::make_window();
    REQUIRE(window->get<piwm::Title>() == "PiWM"s);
}

TEST_CASE("1.2.2.1. get<Position> returns a Position instance", "[Window::get][Position]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_same_v<decltype(window->get<piwm::Position>()), piwm::Position>);
}

TEST_CASE("1.2.2.2. get<Position> for default initialized windows", "[Window::get][Position]")
{
    auto const window = piwm::make_window();
    REQUIRE(window->get<piwm::Position>() == piwm::Position{ piwm::X{ 0 }, piwm::Y{ 0 } });
}

TEST_CASE("1.2.2.3. get<X> returns an X instance", "[Window::get][Position][X]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_same_v<decltype(window->get<piwm::X>()), piwm::X>);
}

TEST_CASE("1.2.2.4. get<X> is convertible to Scalar", "[Window::get][Position][X]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_convertible_v<decltype(window->get<piwm::X>()), piwm::Scalar>);
}

TEST_CASE("1.2.2.5. get<X> for default initialized windows", "[Window::get][Position][X]")
{
    auto const window = piwm::make_window();
    REQUIRE_THAT(window->get<piwm::X>(), Catch::Matchers::WithinAbs(piwm::Scalar{ 0 }, scalar_epsilon));
}

TEST_CASE("1.2.2.6. get<Y> returns a Y instance", "[Window::get][Position][Y]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_same_v<decltype(window->get<piwm::Y>()), piwm::Y>);
}

TEST_CASE("1.2.2.7. get<Y> is convertible to Scalar", "[Window::get][Position][Y]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_convertible_v<decltype(window->get<piwm::Y>()), piwm::Scalar>);
}

TEST_CASE("1.2.2.8. get<Y> for default initialized windows", "[Window::get][Position][Y]")
{
    auto const window = piwm::make_window();
    REQUIRE_THAT(window->get<piwm::Y>(), Catch::Matchers::WithinAbs(piwm::Scalar{ 0 }, scalar_epsilon));
}

TEST_CASE("1.2.3.1. get<Size> returns a Size instance", "[Window::get][Size]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_same_v<decltype(window->get<piwm::Size>()), piwm::Size>);
}

TEST_CASE("1.2.3.2. get<Size> for default initialized windows", "[Window::get][Size]")
{
    auto const window = piwm::make_window();
    REQUIRE(window->get<piwm::Size>() == piwm::Size{ piwm::Width{ piwm::Scalar{ 800 } }, piwm::Height{ 600 } });
}

TEST_CASE("1.2.3.3. get<Width> return a Width instance", "[Window::get][Size][Width]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_same_v<decltype(window->get<piwm::Width>()), piwm::Width>);
}

TEST_CASE("1.2.3.4. get<Width> is convertible to Scalar", "[Window::get][Size][Width]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_convertible_v<decltype(window->get<piwm::Width>()), piwm::Scalar>);
}

TEST_CASE("1.2.3.5. get<Width> for default initialized windows", "[Window::get][Size][Width]")
{
    auto const window = piwm::make_window();
    REQUIRE_THAT(window->get<piwm::Width>(), Catch::Matchers::WithinAbs(piwm::Scalar{ 800 }, scalar_epsilon));
}

TEST_CASE("1.2.3.6. get<Height> return a Height instance", "[Window::get][Size][Height]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_same_v<decltype(window->get<piwm::Height>()), piwm::Height>);
}

TEST_CASE("1.2.3.7. get<Height> is convertible to Scalar", "[Window::get][Size][Height]")
{
    auto const window = piwm::make_window();
    REQUIRE(std::is_convertible_v<decltype(window->get<piwm::Height>()), piwm::Scalar>);
}

TEST_CASE("1.2.3.8. get<Height> for default initialized windows", "[Window::get][Size][Height]")
{
    auto const window = piwm::make_window();
    REQUIRE_THAT(window->get<piwm::Height>(), Catch::Matchers::WithinAbs(piwm::Scalar{ 600 }, scalar_epsilon));
}

TEST_CASE("1.2.4.1. get<Types...> for two or more, different, non-excluding types")
{
    auto const window = piwm::make_window();

    using namespace piwm;

    SECTION("Title & Position")
    {
        auto const [title, position] = window->get<Title, Position>();

        REQUIRE(title == "PiWM");
        REQUIRE(position == piwm::Position{ piwm::X{ 0 }, piwm::Y{ 0 } });
    }
    SECTION("Size & Title")
    {
        auto const [size, title] = window->get<Size, Title>();

        REQUIRE(title == "PiWM");
        REQUIRE(size == piwm::Size{ piwm::Width{ 800 }, piwm::Height{ 600 } });
    }
    SECTION("Position & Size")
    {
        auto const [position, size] = window->get<Position, Size>();

        REQUIRE(position == piwm::Position{ piwm::X{ 0 }, piwm::Y{ 0 } });
        REQUIRE(size == piwm::Size{ piwm::Width{ 800 }, piwm::Height{ 600 } });
    }
    SECTION("X and Height")
    {
        auto const [x, height] = window->get<X, Height>();

        REQUIRE_THAT(x, Catch::Matchers::WithinAbs(Scalar{ 0 }, scalar_epsilon));
        REQUIRE_THAT(height, Catch::Matchers::WithinAbs(Scalar{ 600 }, scalar_epsilon));
    }
    SECTION("X, Y, Width, Height, Title")
    {
        auto const [x, y, width, height, title] = window->get<X, Y, Width, Height, Title>();

        REQUIRE(title == "PiWM");
        REQUIRE_THAT(x, Catch::Matchers::WithinAbs(Scalar{ 0 }, scalar_epsilon));
        REQUIRE_THAT(y, Catch::Matchers::WithinAbs(Scalar{ 0 }, scalar_epsilon));
        REQUIRE_THAT(width, Catch::Matchers::WithinAbs(Scalar{ 800 }, scalar_epsilon));
        REQUIRE_THAT(height, Catch::Matchers::WithinAbs(Scalar{ 600 }, scalar_epsilon));
    }
}
