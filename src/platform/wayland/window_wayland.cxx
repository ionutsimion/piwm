#include <piwm/window.hxx>

auto pi::make_window() -> std::unique_ptr<Window>
{
    return std::make_unique<Window>();
}
