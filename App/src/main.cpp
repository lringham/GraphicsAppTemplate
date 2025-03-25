#include "framework/core/App.h"
#include "framework/graphics/Graphics.h"
#include "framework/gui/GUI.h"

class MyApp : public App {
 public:
  MyApp(int width, int height, std::string_view windowTitle)
      : App(width, height, windowTitle) {}

  virtual void initialize() override {
    Graphics::setBackgroundColor(0.6, 0.6, 1.0, 1.0);
    gui_.initialize(window_.getNativeHandle());
  }

  virtual void render(float interp) const override {
    Graphics::clearColor();
    gui_.render(this);
  }

 private:
  GUI gui_;
};

int main(int argc, char **argv) {
  MyApp app(800, 600, "app");
  return app.run();
}
