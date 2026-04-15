#ifndef PIWM_WINDOW_HXX
#define PIWM_WINDOW_HXX

#include <memory>

#include <piwm/types.hxx>

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

        /**
         * Get attribute values of the Window instance.
         * @tparam Types Expected piwm types: Title, Position (or X and/or Y), Size (or Width and/or Height)
         * @return The requested attribute value if one is requested, a tuple of attribute values if more are requested
         */
        template <typename ...Types>
        [[nodiscard]] auto get() const;

        template <typename ...Types>
        auto set(Types &&...) -> void;

    private:
        [[nodiscard]] virtual auto title() const -> Title = 0;
        [[nodiscard]] virtual auto position() const -> Position = 0;
        [[nodiscard]] virtual auto size() const -> Size = 0;

        virtual auto set_title(Title const &) -> void = 0;
        virtual auto set_title(Title &&) -> void = 0;
        virtual auto set_position(Position const &) -> void = 0;
        virtual auto set_position(Position &&) -> void = 0;
        virtual auto set_size(Size const &) -> void = 0;
        virtual auto set_size(Size &&) -> void = 0;
    };

    auto make_window() -> std::unique_ptr<Window>;
}

namespace piwm
{
    template <typename ...Types>
    auto Window::get() const
    {
        auto constexpr number_of_arguments = sizeof...(Types);
        static_assert(number_of_arguments > 0,
            "piwm::Window::get() expects at least one argument. "
            "Expected types: piwm::Title, piwm::Size, piwm::Position, piwm::X, piwm::Y, piwm::Width, piwm::Height."
            );

        auto constexpr title_requests = pi::tl::count<Title, Types...>();
        auto constexpr position_requests = pi::tl::count<Position, Types...>();
        auto constexpr x_requests = pi::tl::count<X, Types...>();
        auto constexpr y_requests = pi::tl::count<Y, Types...>();
        auto constexpr size_requests = pi::tl::count<Size, Types...>();
        auto constexpr width_requests = pi::tl::count<Width, Types...>();
        auto constexpr height_requests = pi::tl::count<Height, Types...>();

        static_assert(number_of_arguments ==  title_requests
                                            + position_requests
                                            + x_requests
                                            + y_requests
                                            + size_requests
                                            + width_requests
                                            + height_requests,
            "Expected types: piwm::Title, piwm::Size, piwm::Position, piwm::X, piwm::Y, piwm::Width, piwm::Height.");

        static_assert(title_requests <= 1ul, "piwm::Title is expected at most once.");
        static_assert(position_requests <= 1ul, "piwm::Position is expected at most once.");
        static_assert(x_requests <= 1ul, "piwm::X is expected at most once.");
        static_assert(y_requests <= 1ul, "piwm::Y is expected at most once.");
        static_assert(size_requests <= 1ul, "piwm::Size is expected at most once.");
        static_assert(width_requests <= 1ul, "piwm::Width is expected at most once.");
        static_assert(height_requests <= 1ul, "piwm::Height is expected at most once.");

        static_assert(!(position_requests && x_requests | y_requests),
            "piwm::Position cannot be requested along with piwm::X or piwm::Y.");
        static_assert(!(size_requests && width_requests | height_requests),
            "piwm::Size cannot be requested along with piwm::Width or piwm::Height.");

        if constexpr (number_of_arguments == 1ul)
        {
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
        else
            return std::make_tuple(get<Types>()...);
    }

    template<typename... Types>
    auto Window::set(Types &&...) -> void
    {

    }
}

#endif
