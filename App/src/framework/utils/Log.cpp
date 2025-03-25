#include <spdlog/spdlog.h>

#include "framework/utils/Log.h"

namespace Log {

void info(std::string_view msg) { spdlog::info(msg); }

void warning(std::string_view msg) { spdlog::warn(msg); }

void error(std::string_view msg) { spdlog::error(msg); }

}  // namespace Log
