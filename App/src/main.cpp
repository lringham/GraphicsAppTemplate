#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "ExampleGUI.h"
#include "framework/core/App.h"
#include "framework/graphics/Graphics.h"

using namespace framework;
class MyApp : public App {
 public:
  MyApp(int width, int height, std::string_view windowTitle)
      : App(width, height, windowTitle) {}

  virtual void initialize() override {
    graphics::setBackgroundColor(0.6f, 0.6f, 1.f, 1.f);
    gui_.initialize(window_.getNativeHandle());
  }

  virtual void handleInput() override {
    // TODO: Implement an input abstraction
    if (glfwGetKey(window_.getNativeHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      window_.shouldClose(true);
    }
  }

  virtual void render(float interp) const override {
    graphics::clearColor();
    gui_.render();
    graphics::checkErrors();
  }

 private:
  ExampleGUI gui_;
};

int main(int argc, char **argv) {
  MyApp app(800, 600, "app");
  return app.run();
}
