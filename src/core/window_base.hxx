#ifndef PIWM_WINDOW_BASE_HXX
#define PIWM_WINDOW_BASE_HXX

#include <piwm/window.hxx>

namespace piwm::core
{
    class WindowBase: public Window
    {
    public:
        using Window::Window;

        ~WindowBase() override = default;

    private:
        [[nodiscard]] auto title() const -> Title override;
        [[nodiscard]] auto position() const -> Position override;
        [[nodiscard]] auto size() const -> Size override;
    };
}

#endif
