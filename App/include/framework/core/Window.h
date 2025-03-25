#pragma once

#include <map>
#include <string_view>

struct GLFWwindow;

namespace framework {
class Window {
 public:
  explicit Window();
  Window(int width, int height, const std::string_view title);
  ~Window();

  Window(const Window &other) = delete;
  Window &operator=(const Window &other) = delete;
  Window(Window &&other) = delete;
  Window &operator=(Window &&rhs) = delete;

  void initialize(int width, int height, const std::string_view title);
  bool shouldClose() const;
  void shouldClose(bool state) const;
  void updateEvents() const;
  void present() const;
  std::pair<int, int> getSize() const;
  float getAspectRatio() const;

  GLFWwindow *getNativeHandle() const;

 private:
  static bool glfwInitialized_;
  static std::map<GLFWwindow *, Window *> windowPtrs_;
  GLFWwindow *window_ = nullptr;

  void initGLFW();
  void shutdownGLFW();
};
}  // namespace framework