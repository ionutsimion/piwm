#ifndef PIWM_WINDOW_BASE_HXX
#define PIWM_WINDOW_BASE_HXX

#include <piwm/window.hxx>

namespace pi::core
{
    class WindowBase: public Window
    {
    public:
        using Window::Window;

        ~WindowBase() override = default;

        [[nodiscard]] auto title() const -> std::string_view override;
    };
}

#endif
