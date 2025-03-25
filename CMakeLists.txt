cmake_minimum_required(VERSION 3.11)

project(App VERSION 1.0
        DESCRIPTION "App"
        LANGUAGES CXX)
        
message(" ** CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(imgui REQUIRED)
find_package(spdlog)
find_package(imgui)

set(SOURCES
        App/src/main.cpp
        App/src/framework/core/App.cpp
        App/src/framework/core/Window.cpp
        App/src/framework/graphics/Graphics.cpp
        App/src/framework/gui/GUI.cpp
        App/src/framework/utils/Log.cpp)

set(IMGUI_SOURCES
        build/conan/imgui/imgui_impl_glfw.cpp
        build/conan/imgui/imgui_impl_opengl3.cpp)
        
add_executable(app ${SOURCES} ${IMGUI_SOURCES})

target_link_libraries(app PRIVATE glad::glad glfw imgui::imgui spdlog::spdlog)

target_include_directories(app PRIVATE App/include)
target_include_directories(app PUBLIC ${glfw3_INCLUDE_DIRS})
target_include_directories(app PUBLIC ${imgui_INCLUDE_DIRS})
target_include_directories(app PUBLIC ${glad_INCLUDE_DIRS})
target_include_directories(app PRIVATE build/conan/imgui/include)