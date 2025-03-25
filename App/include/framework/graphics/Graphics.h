#pragma once
#include <type_traits>

namespace Graphics {
bool checkErrors();
void setDepthTesting(bool state);
void setFaceCulling(bool state);
void setWireframe(bool state);
void setBackgroundColor(float r, float g, float b, float a);
void clearColor();
void setViewport(int x, int y, int width, int height);

enum class BufferAccessMethod { Read, Write, ReadWrite };

enum class Primitive { Triangle, Line };

enum class DataType { Float, Int, UInt, Byte, UByte, Bool, None };

template <typename T>
static DataType dataTypeEnum() {
  if (std::is_same_v<std::remove_cvref_t<T>, float>)
    return DataType::Float;
  else if (std::is_same_v<std::remove_cvref_t<T>, int>)
    return DataType::Int;
  else if (std::is_same_v<std::remove_cvref_t<T>, unsigned int>)
    return DataType::UInt;
  else if (std::is_same_v<std::remove_cvref_t<T>, char>)
    return DataType::Byte;
  else if (std::is_same_v<std::remove_cvref_t<T>, unsigned char>)
    return DataType::UByte;
  else if (std::is_same_v<std::remove_cvref_t<T>, bool>)
    return DataType::Bool;

  return DataType::None;
}

}  // namespace Graphics
