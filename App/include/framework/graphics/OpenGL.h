#pragma once
#include <glad/glad.h>

#include "Graphics.h"

namespace framework::opengl {
template <typename T>
GLenum toGLEnum() {
  if (std::is_same_v<std::remove_cvref_t<T>, float>)
    return GL_FLOAT;
  else if (std::is_same_v<std::remove_cvref_t<T>, int>)
    return GL_INT;
  else if (std::is_same_v<std::remove_cvref_t<T>, unsigned int>)
    return GL_UNSIGNED_INT;
  else if (std::is_same_v<std::remove_cvref_t<T>, char>)
    return GL_BYTE;
  else if (std::is_same_v<std::remove_cvref_t<T>, unsigned char>)
    return GL_UNSIGNED_BYTE;
  else if (std::is_same_v<std::remove_cvref_t<T>, bool>)
    return GL_BOOL;
  else
    return GL_NONE;
}

static GLenum toGLEnum(graphics::DataType dataType) {
  switch (dataType) {
    case graphics::DataType::Float:
      return GL_FLOAT;
    case graphics::DataType::Int:
      return GL_INT;
    case graphics::DataType::UInt:
      return GL_UNSIGNED_INT;
    case graphics::DataType::Byte:
      return GL_BYTE;
    case graphics::DataType::UByte:
      return GL_UNSIGNED_BYTE;
    case graphics::DataType::Bool:
      return GL_BOOL;
    case graphics::DataType::None:
      return GL_NONE;
    default:
      return GL_NONE;
  }
}

static GLenum toGLEnum(graphics::BufferAccessMethod accessMethod) {
  switch (accessMethod) {
    case graphics::BufferAccessMethod::Read:
      return GL_READ_ONLY;
    case graphics::BufferAccessMethod::Write:
      return GL_WRITE_ONLY;
    case graphics::BufferAccessMethod::ReadWrite:
      return GL_READ_WRITE;
    default:
      return GL_NONE;
  }
}

static GLenum toGLEnum(graphics::Primitive primitive) {
  switch (primitive) {
    case graphics::Primitive::Triangle:
      return GL_TRIANGLES;
    case graphics::Primitive::Line:
      return GL_LINES;
    default:
      return GL_NONE;
  }
}
}  // namespace framework::opengl