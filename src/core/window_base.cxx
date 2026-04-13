#include <core/window_base.hxx>

using namespace std::string_literals;

auto piwm::core::WindowBase::title() const -> Title
{
    return Title{ "Hello"s };}

auto piwm::core::WindowBase::position() const -> Position
{
    return Position{ X{ Scalar{ 0 } }, Y{ Scalar{ 0 } } };
}

auto piwm::core::WindowBase::size() const -> Size
{
    return Size{ Width{ Scalar{ 800 } }, Height{ Scalar{ 600 } } };
}

auto piwm::make_window() -> std::unique_ptr<Window>
{
    return std::make_unique<core::WindowBase>();
}
