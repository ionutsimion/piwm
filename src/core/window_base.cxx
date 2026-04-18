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
    return default_window_size;
}

auto piwm::core::WindowBase::set_title(Title const &) -> void
{
}

auto piwm::core::WindowBase::set_title(Title &&) -> void
{
}

auto piwm::core::WindowBase::set_position(Position const &) -> void
{
}

auto piwm::core::WindowBase::set_position(Position &&) -> void
{
}

auto piwm::core::WindowBase::set_size(Size const &) -> void
{
}

auto piwm::core::WindowBase::set_size(Size &&) -> void
{
}
