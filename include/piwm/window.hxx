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

        /**
         * Set attribute values of the Window instance.
         * @tparam Types Expected piwm types: Title, Position (or X and/or Y), Size (or Width and/or Height)
         * @param values The attribute values to set
         */
        template <typename ...Types>
        auto set(Types &&...) -> void;

    private:
        [[nodiscard]] virtual auto title() const -> Title = 0;
        [[nodiscard]] virtual auto title() -> Title & = 0;
        [[nodiscard]] virtual auto position() const -> Position = 0;
        [[nodiscard]] virtual auto position() -> Position & = 0;
        [[nodiscard]] virtual auto size() const -> Size = 0;
		[[nodiscard]] virtual auto size() -> Size & = 0;
    };

    auto make_window() -> std::unique_ptr<Window>;
}

namespace piwm
{
	template <typename ...Types>
    consteval auto validate_arguments()
    {
        auto constexpr number_of_arguments = sizeof...(Types);
        static_assert(number_of_arguments > 0,
            "piwm::Window::get() expects at least one argument. "
            "Expected types: piwm::Title, piwm::Size, piwm::Position, piwm::X, piwm::Y, piwm::Width, piwm::Height."
            );

        auto constexpr title_count = pi::tl::count<Title, Types...>();
        auto constexpr position_count = pi::tl::count<Position, Types...>();
        auto constexpr x_count = pi::tl::count<X, Types...>();
        auto constexpr y_count = pi::tl::count<Y, Types...>();
        auto constexpr size_count = pi::tl::count<Size, Types...>();
        auto constexpr width_count = pi::tl::count<Width, Types...>();
        auto constexpr height_count = pi::tl::count<Height, Types...>();

        static_assert(number_of_arguments == title_count
            + position_count
            + x_count
            + y_count
            + size_count
            + width_count
            + height_count,
            "Expected types: piwm::Title, piwm::Size, piwm::Position, piwm::X, piwm::Y, piwm::Width, piwm::Height.");

        static_assert(title_count <= 1ul, "piwm::Title is expected at most once.");
        static_assert(position_count <= 1ul, "piwm::Position is expected at most once.");
        static_assert(x_count <= 1ul, "piwm::X is expected at most once.");
        static_assert(y_count <= 1ul, "piwm::Y is expected at most once.");
        static_assert(size_count <= 1ul, "piwm::Size is expected at most once.");
        static_assert(width_count <= 1ul, "piwm::Width is expected at most once.");
        static_assert(height_count <= 1ul, "piwm::Height is expected at most once.");

        static_assert(!(position_count && x_count | y_count),
            "piwm::Position cannot be requested along with piwm::X or piwm::Y.");
        static_assert(!(size_count && width_count | height_count),
            "piwm::Size cannot be requested along with piwm::Width or piwm::Height.");
    }

    template <typename ...Types>
    auto Window::get() const
    {
		validate_arguments<Types...>();

        if constexpr (sizeof...(Types) == 1ul)
        {
            if constexpr (constexpr auto pos = pi::tl::find<Title, Types...>(); pos != pi::tl::npos)
                return title();
            else if constexpr (constexpr auto pos = pi::tl::find<Position, Types...>(); pos != pi::tl::npos)
                return position();
            else if constexpr (constexpr auto pos = pi::tl::find<X, Types...>(); pos != pi::tl::npos)
                return position().get<X>();
            else if constexpr (constexpr auto pos = pi::tl::find<Y, Types...>(); pos != pi::tl::npos)
                return position().get<Y>();
            else if constexpr (constexpr auto pos = pi::tl::find<Size, Types...>(); pos != pi::tl::npos)
                return size();
            else if constexpr (constexpr auto pos = pi::tl::find<Width, Types...>(); pos != pi::tl::npos)
                return size().get<Width>();
            else if constexpr (constexpr auto pos = pi::tl::find<Height, Types...>(); pos != pi::tl::npos)
                return size().get<Height>();
        }
        else
            return std::make_tuple(get<Types>()...);
    }

    template<typename ...Types>
    auto Window::set(Types &&...values) -> void
    {
        validate_arguments<Types...>();

        if constexpr (constexpr auto pos = pi::tl::find<Title, Types...>(); pos != pi::tl::npos)
            title() = pi::tl::get<pos, Types...>(std::forward<Types>(values)...);

        if constexpr (constexpr auto pos = pi::tl::find<Position, Types...>(); pos != pi::tl::npos)
            position() = pi::tl::get<pos, Types...>(std::forward<Types>(values)...);

        if constexpr (constexpr auto pos = pi::tl::find<X, Types...>(); pos != pi::tl::npos)
			position().set(pi::tl::get<pos, Types...>(values...));

        if constexpr (constexpr auto pos = pi::tl::find<Y, Types...>(); pos != pi::tl::npos)
            position().set(pi::tl::get<pos, Types...>(values...));

        if constexpr (constexpr auto pos = pi::tl::find<Size, Types...>(); pos != pi::tl::npos)
			size() = pi::tl::get<pos, Types...>(std::forward<Types>(values)...);

        if constexpr (constexpr auto pos = pi::tl::find<Width, Types...>(); pos != pi::tl::npos)
			size().set(pi::tl::get<pos, Types...>(std::forward<Types>(values)...));

		if constexpr (constexpr auto pos = pi::tl::find<Height, Types...>(); pos != pi::tl::npos)
			size().set(pi::tl::get<pos, Types...>(std::forward<Types>(values)...));
    }
}

#endif
