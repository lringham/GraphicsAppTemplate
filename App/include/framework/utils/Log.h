#pragma once

#include <string_view>

namespace framework {
struct Log {
  static void info(std::string_view msg);
  static void warning(std::string_view msg);
  static void error(std::string_view msg);
};
}  // namespace framework