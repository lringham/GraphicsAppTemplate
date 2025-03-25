#include <chrono>

#include "framework/core/App.h"
#include "framework/utils/Cast.h"

using namespace framework;
App::App(int width, int height, std::string_view windowTitle)
    : window_(width, height, windowTitle) {}

namespace {
int msSinceStart() {
  static auto start = std::chrono::steady_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::steady_clock::now() - start)
      .count();
}
}  // namespace

int App::run() {
  doInitialize();

  const int TICKS_PER_SEC = 60;
  const int TICKS_PER_UPDATE = 1000 / TICKS_PER_SEC;
  const int MAX_FRAMESKIP = 5;
  int loops = 0;
  int nextUpdateMS = msSinceStart();

  while (!window_.shouldClose() && errorCode_ == 0) {
    loops = 0;
    while (msSinceStart() >= nextUpdateMS && loops < MAX_FRAMESKIP) {
      doHandleInput();
      doUpdate(TICKS_PER_UPDATE);
      nextUpdateMS += TICKS_PER_UPDATE;
      ++loops;
    }
    float interp = as<float>(msSinceStart() + TICKS_PER_UPDATE - nextUpdateMS) /
                   as<float>(TICKS_PER_UPDATE);
    doRender(interp);
  }
  return doShutdown();
}

void App::doInitialize() { initialize(); }

void App::doHandleInput() {
  window_.updateEvents();
  handleInput();
}

void App::doUpdate(int dt) { update(dt); }

void App::doRender(float interp) const {
  render(interp);
  window_.present();
}

int App::doShutdown() { return shutdown(); }