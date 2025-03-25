#pragma once
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <map>
#include <string>

#include "framework/utils/Cast.h"
#include "framework/utils/Log.h"

class Window {
  static bool glfwInitialized_;
  static std::map<GLFWwindow *, Window *> windowPtrs_;

  GLFWwindow *window_ = nullptr;

  void initGLFW() {
    if (glfwInitialized_) {
      return;
    }
    glfwInitialized_ = glfwInit();
  }

  void shutdownGLFW() {
    glfwTerminate();
    glfwInitialized_ = false;
  }

 public:
  explicit Window() { initGLFW(); };

  Window(int width, int height, const std::string_view title) {
    initGLFW();
    initialize(width, height, title);
  }

  ~Window() {
    windowPtrs_.erase(window_);
    if (windowPtrs_.size() == 0) {
      shutdownGLFW();
    }
  }

  Window(const Window &other) = delete;
  Window &operator=(const Window &other) = delete;
  Window(Window &&other) = delete;
  Window &operator=(Window &&rhs) = delete;

  void initialize(int width, int height, const std::string_view title) {
    if (!glfwInitialized_) {
      Log::error("GLFW not initialized!\n");
      return;
    }

    window_ = glfwCreateWindow(width, height, std::string(title).c_str(),
                               nullptr, nullptr);
    if (!window_) {
      Log::error("Failed to create window!\n");
      glfwTerminate();
      return;
    }

    glfwMakeContextCurrent(window_);

    if (!gladLoadGL()) {
      Log::error("Failed to load glad!\n");
      return;
    }

    windowPtrs_[window_] = this;
  }

  bool shouldClose() const {
    return !glfwInitialized_ || glfwWindowShouldClose(window_);
  }

  void updateEvents() const {
    glfwPollEvents();
    if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window_, true);
  }

  void present() const { glfwSwapBuffers(window_); }

  std::pair<int, int> getSize() const {
    int width, height;
    glfwGetWindowSize(window_, &width, &height);
    return std::make_pair(width, height);
  }

  float getAspectRatio() const {
    using namespace framework;
    auto [width, height] = getSize();
    return as<float>(width) / as<float>(height);
  }

  GLFWwindow *getNativeHandle() const { return window_; }
};