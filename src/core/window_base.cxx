#include <core/constants.hxx>
#include <core/window_base.hxx>

auto piwm::make_window() -> std::unique_ptr<Window>
{
    return std::make_unique<core::WindowBase>();
}

auto piwm::core::WindowBase::title() const -> Title
{
    return default_window_title;
}

auto piwm::core::WindowBase::position() const -> Position
{
    return default_window_position;
}

auto piwm::core::WindowBase::size() const -> Size
{
    return default_window_size;
}
