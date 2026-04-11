#include <core/window_base.hxx>

auto pi::core::WindowBase::title() const -> std::string_view
{
    return "Hello"sv;
}

auto pi::make_window() -> std::unique_ptr<Window>
{
    return std::make_unique<core::WindowBase>();
}
