#pragma once

namespace framework {
class GUI {
 public:
  GUI() = default;
  ~GUI();

  void initialize(struct GLFWwindow* windowPtr);
  void render(class App const* app) const;
  void handleEvents();
};
}  // namespace framework