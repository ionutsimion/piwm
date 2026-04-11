#ifndef PIWM_WINDOW_HXX
#define PIWM_WINDOW_HXX

#include <memory>

namespace pi
{

    class Window
    {
    public:
        Window() = default;

        Window(Window &) = delete;
        Window(Window &&) = delete;

        Window &operator=(Window &) = delete;
        Window &operator=(Window &&) = delete;

        virtual ~Window() = default;
    };

    auto make_window() -> std::unique_ptr<Window>;

}

#endif
