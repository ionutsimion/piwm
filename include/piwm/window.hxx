#ifndef PIWM_WINDOW_HXX
#define PIWM_WINDOW_HXX

#include <memory>

using namespace std::string_view_literals;

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

        [[nodiscard]] virtual auto title() const -> std::string_view = 0;
    };

    auto make_window() -> std::unique_ptr<Window>;

}

#endif
