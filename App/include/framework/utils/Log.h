#pragma once

#include <string_view>

namespace Log {
void info(std::string_view msg);
void warning(std::string_view msg);
void error(std::string_view msg);
}  // namespace Log