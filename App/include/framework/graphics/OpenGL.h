#pragma once
#include "Graphics.h"
#include <glad/glad.h>


template<typename T>
GLenum toGLEnum()
{
    if (std::is_same_v<std::remove_cvref_t<T>, float>)              return GL_FLOAT;
    else if (std::is_same_v<std::remove_cvref_t<T>, int>)           return GL_INT;
    else if (std::is_same_v<std::remove_cvref_t<T>, unsigned int>)  return GL_UNSIGNED_INT;
    else if (std::is_same_v<std::remove_cvref_t<T>, char>)          return GL_BYTE;
    else if (std::is_same_v<std::remove_cvref_t<T>, unsigned char>) return GL_UNSIGNED_BYTE;
    else if (std::is_same_v<std::remove_cvref_t<T>, bool>)          return GL_BOOL;
    else                                            return GL_NONE;
}

static GLenum toGLEnum(Graphics::DataType dataType) {
    switch (dataType) {
        case Graphics::DataType::Float: return GL_FLOAT;
        case Graphics::DataType::Int:   return GL_INT;
        case Graphics::DataType::UInt:  return GL_UNSIGNED_INT;
        case Graphics::DataType::Byte:  return GL_BYTE;
        case Graphics::DataType::UByte: return GL_UNSIGNED_BYTE;
        case Graphics::DataType::Bool:  return GL_BOOL;
        case Graphics::DataType::None:  return GL_NONE;
        default:                        return GL_NONE;
    }
}

static GLenum toGLEnum(Graphics::BufferAccessMethod accessMethod) {
    switch (accessMethod) {
        case Graphics::BufferAccessMethod::Read:      return GL_READ_ONLY;
        case Graphics::BufferAccessMethod::Write:     return GL_WRITE_ONLY;
        case Graphics::BufferAccessMethod::ReadWrite: return GL_READ_WRITE;
        default:                                      return GL_NONE;
    }
}

static GLenum toGLEnum(Graphics::Primitive primitive) {
    switch (primitive) {
        case Graphics::Primitive::Triangle: return GL_TRIANGLES;
        case Graphics::Primitive::Line:     return GL_LINES;
        default:                            return GL_NONE;
    }
}
