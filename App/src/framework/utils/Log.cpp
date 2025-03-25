#include <spdlog/spdlog.h>

#include "framework/utils/Log.h"

namespace framework {

void Log::info(std::string_view msg) { spdlog::info(msg); }

void Log::warning(std::string_view msg) { spdlog::warn(msg); }

void Log::error(std::string_view msg) { spdlog::error(msg); }

}  // namespace framework
