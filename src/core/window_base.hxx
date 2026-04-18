#ifndef PIWM_WINDOW_BASE_HXX
#define PIWM_WINDOW_BASE_HXX

#include <piwm/window.hxx>

#include <core/constants.hxx>

namespace piwm::core
{
    class WindowBase: public Window
    {
    public:
        using Window::Window;

        ~WindowBase() override = default;

    private:
        [[nodiscard]] auto title() const -> Title override;
        [[nodiscard]] auto title() -> Title & override;
        [[nodiscard]] auto position() const -> Position override;
        [[nodiscard]] auto position() -> Position & override;
        [[nodiscard]] auto size() const -> Size override;

        auto set_title(Title const &) -> void override;
        auto set_title(Title &&) -> void override;
        auto set_position(Position const &) -> void override;
        auto set_position(Position &&) -> void override;
        auto set_size(Size const &) -> void override;
        auto set_size(Size &&) -> void override;

    protected:
        Title title_{ default_window_title };
        Position position_{ default_window_position };
    };
}

#endif
