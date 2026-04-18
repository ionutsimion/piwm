#include <core/constants.hxx>
#include <core/window_base.hxx>

auto piwm::make_window() -> std::unique_ptr<Window>
{
    return std::make_unique<core::WindowBase>();
}

auto piwm::core::WindowBase::title() const -> Title
{
    return title_;
}

auto piwm::core::WindowBase::title() -> Title &
{
    return title_;
}

auto piwm::core::WindowBase::position() const -> Position
{
    return position_;
}

auto piwm::core::WindowBase::position() -> Position &
{
    return position_;
}

auto piwm::core::WindowBase::size() const -> Size
{
    return size_;
}

auto piwm::core::WindowBase::size() -> Size &
{
    return size_;
}
