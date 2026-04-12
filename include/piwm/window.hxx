#ifndef PIWM_WINDOW_HXX
#define PIWM_WINDOW_HXX

#include <memory>

#include "types.hxx"

namespace pi
{

    class Window
    {
    public:
        Window() = default;

        Window(Window &) = delete;
        Window(Window &&) = default;

        Window &operator=(Window &) = delete;
        Window &operator=(Window &&) = default;

        virtual ~Window() = default;

        [[nodiscard]] virtual auto title() const -> Title = 0;
        [[nodiscard]] virtual auto position() const -> Position = 0;
        [[nodiscard]] virtual auto size() const -> Size = 0;
    };

    auto make_window() -> std::unique_ptr<Window>;

}

#endif
