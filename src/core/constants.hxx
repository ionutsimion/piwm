#ifndef PIWM_CONSTANTS_HXX
#define PIWM_CONSTANTS_HXX

#include <string>

#include <piwm/types.hxx>

using namespace std::string_literals;

namespace piwm::core
{
    auto constexpr default_window_x         = X{ 0 };
    auto constexpr default_window_y         = Y{ 0 };
    auto constexpr default_window_width     = Width{ 800 };
    auto constexpr default_window_height    = Height{ 600 };
    auto const default_window_title         = Title{ "PiWM"s };
    auto const default_window_position      = Position{ default_window_x, default_window_y };
    auto const default_window_size          = Size{ default_window_width, default_window_height };
}

#endif
