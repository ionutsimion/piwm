#ifndef PIWM_WINDOW_HXX
#define PIWM_WINDOW_HXX

#include <memory>

#include "types.hxx"

namespace piwm
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

        template <typename ...Types>
        [[nodiscard]] auto get() const;

    private:
        [[nodiscard]] virtual auto title() const -> Title = 0;
        [[nodiscard]] virtual auto position() const -> Position = 0;
        [[nodiscard]] virtual auto size() const -> Size = 0;
    };

    auto make_window() -> std::unique_ptr<Window>;
}

namespace piwm
{
    template <typename ...Types>
    auto Window::get() const
    {
        auto constexpr number_of_arguments = sizeof...(Types);

        auto constexpr title_requests = tl::count<Title, Types...>();
        auto constexpr position_requests = tl::count<Position, Types...>();
        auto constexpr x_requests = tl::count<X, Types...>();
        auto constexpr y_requests = tl::count<Y, Types...>();
        auto constexpr size_requests = tl::count<Size, Types...>();
        auto constexpr width_requests = tl::count<Width, Types...>();
        auto constexpr height_requests = tl::count<Height, Types...>();

        static_assert(number_of_arguments ==  title_requests
                                            + position_requests
                                            + x_requests
                                            + y_requests
                                            + size_requests
                                            + width_requests
                                            + height_requests,
            "piwm::Window::get() expects one argument: "
            "piwm::Title; "
            "piwm::Position or piwm::X or piwm::Y; "
            "piwm::Size or piwm::Width or piwm::Height.");

        static_assert(title_requests <= 1ul, "piwm::Title is expected at most once.");
        static_assert(position_requests <= 1ul, "piwm::Position is expected at most once.");
        static_assert(x_requests <= 1ul, "piwm::X is expected at most once.");
        static_assert(y_requests <= 1ul, "piwm::Y is expected at most once.");
        static_assert(size_requests <= 1ul, "piwm::Size is expected at most once.");
        static_assert(width_requests <= 1ul, "piwm::Width is expected at most once.");
        static_assert(height_requests <= 1ul, "piwm::Height is expected at most once.");

        if constexpr (title_requests)
            return title();
        else if constexpr (position_requests)
            return position();
        else if constexpr (x_requests)
            return position().get<X>();
        else if constexpr (y_requests)
            return position().get<Y>();
        else if constexpr (size_requests)
            return size();
        else if constexpr (width_requests)
            return size().get<Width>();
        else if constexpr (height_requests)
            return size().get<Height>();
    }
}

#endif
