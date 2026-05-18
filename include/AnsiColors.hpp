#pragma once

#include <string_view>

namespace ansi {
	constexpr std::string_view reset      = "\033[0m";

    constexpr std::string_view black_fg   = "\033[30m";
    constexpr std::string_view red_fg     = "\033[31m";
    constexpr std::string_view green_fg   = "\033[32m";
    constexpr std::string_view yellow_fg  = "\033[33m";
    constexpr std::string_view blue_fg    = "\033[34m";
    constexpr std::string_view magenta_fg = "\033[35m";
    constexpr std::string_view cyan_fg    = "\033[36m";
    constexpr std::string_view white_fg   = "\033[37m";

    constexpr std::string_view white_bg   = "\033[47m";
}
