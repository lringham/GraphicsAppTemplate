#pragma once

class GUI {
 public:
  GUI() = default;
  ~GUI();

  void initialize(class GLFWwindow* windowPtr);
  void render(class App const* app) const;
  void handleEvents();
};