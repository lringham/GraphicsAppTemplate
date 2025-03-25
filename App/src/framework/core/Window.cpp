#include "framework/core/Window.h"

bool Window::glfwInitialized_ = false;
std::map<GLFWwindow*, Window*> Window::windowPtrs_;