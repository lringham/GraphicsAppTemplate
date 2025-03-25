#pragma once
#include <string_view>

#include "framework/core/Window.h"

namespace framework {
class App {
 public:
  App(int width, int height, std::string_view windowTitle);
  int run();

 protected:
  Window window_;

  virtual void initialize() {};
  virtual void handleInput() {};
  virtual void update(int) {};
  virtual void render(float) const {};
  virtual int shutdown() { return errorCode_; };

 private:
  int errorCode_ = 0;

  void doInitialize();
  void doHandleInput();
  void doUpdate(int dt);
  void doRender(float interp) const;
  int doShutdown();
};
}  // namespace framework