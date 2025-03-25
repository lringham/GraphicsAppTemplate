#include <glad/glad.h>

#include "framework/core/Window.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "framework/core/Window.h"
#include "framework/utils/Cast.h"
#include "framework/utils/Log.h"

using namespace framework;

bool Window::glfwInitialized_ = false;
std::map<::GLFWwindow *, Window *> Window::windowPtrs_;

Window::Window(int width, int height, const std::string_view title) {
  initGLFW();
  initialize(width, height, title);
}

Window::~Window() {
  windowPtrs_.erase(window_);
  if (windowPtrs_.size() == 0) {
    shutdownGLFW();
  }
}

void Window::initialize(int width, int height, const std::string_view title) {
  if (!glfwInitialized_) {
    framework::Log::error("GLFW not initialized!\n");
    return;
  }

  window_ = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
  if (!window_) {
    framework::Log::error("Failed to create window!\n");
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window_);

  if (!gladLoadGL()) {
    framework::Log::error("Failed to load glad!\n");
    return;
  }

  windowPtrs_[window_] = this;
}

bool Window::shouldClose() const {
  return !glfwInitialized_ || glfwWindowShouldClose(window_);
}

void Window::shouldClose(bool close) const {
  glfwSetWindowShouldClose(window_, close);
}

void Window::updateEvents() const { glfwPollEvents(); }

void Window::present() const { glfwSwapBuffers(window_); }

std::pair<int, int> Window::getSize() const {
  int width, height;
  glfwGetWindowSize(window_, &width, &height);
  return std::make_pair(width, height);
}

float Window::getAspectRatio() const {
  auto [width, height] = getSize();
  return as<float>(width) / as<float>(height);
}

void Window::initGLFW() {
  if (glfwInitialized_) {
    return;
  }
  glfwInitialized_ = glfwInit();
}

GLFWwindow *Window::getNativeHandle() const { return window_; }

void Window::shutdownGLFW() {
  glfwTerminate();
  glfwInitialized_ = false;
}
