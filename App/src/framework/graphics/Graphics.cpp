#include <string>

#include "framework/graphics/Graphics.h"
#include "framework/graphics/OpenGL.h"
#include "framework/utils/Log.h"

namespace framework::graphics {
bool checkErrors() {
  bool hasError = false;
  std::string errorMessage = "";
  GLenum error = GL_NO_ERROR;

  while ((error = glGetError()) != GL_NO_ERROR) {
    hasError = true;
    errorMessage = "GL Error: ";
    switch (error) {
      case GL_NO_ERROR:
        errorMessage += "No error";
        break;
      case GL_INVALID_ENUM:
        errorMessage += "Invalid enum";
        break;
      case GL_INVALID_VALUE:
        errorMessage += "Invalid value";
        break;
      case GL_INVALID_OPERATION:
        errorMessage += "Invalid operation";
        break;
      case GL_STACK_OVERFLOW:
        errorMessage += "Stack overflow";
        break;
      case GL_STACK_UNDERFLOW:
        errorMessage += "Stack underflow";
        break;
      case GL_OUT_OF_MEMORY:
        errorMessage += "Out of memory";
        break;
      default:
        errorMessage += "Unknown error";
        break;
    }
    framework::Log::error(errorMessage);
  }
  return hasError;
}

void setDepthTesting(bool state) {
  if (state)
    glEnable(GL_DEPTH_TEST);
  else
    glDisable(GL_DEPTH_TEST);
}

void setFaceCulling(bool state) {
  if (state)
    glEnable(GL_CULL_FACE);
  else
    glDisable(GL_CULL_FACE);
}

void setWireframe(bool state) {
  if (state)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  else
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void setBackgroundColor(float r, float g, float b, float a) {
  glClearColor(r, g, b, a);
}

void clearColor() { glClear(GL_COLOR_BUFFER_BIT); }

void clearDepth() { glClear(GL_DEPTH_BUFFER_BIT); }

void setViewport(int x, int y, int width, int height) {
  glViewport(x, y, width, height);
}
}  // namespace framework::graphics