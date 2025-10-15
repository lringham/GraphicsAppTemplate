cmake_minimum_required(VERSION 3.11)

project(App VERSION 1.0
        DESCRIPTION "App"
        LANGUAGES CXX)
        
message(" ** CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_TESTS ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(imgui REQUIRED)
find_package(spdlog REQUIRED)

set(IMGUI_SOURCES
    App/thirdparty/imgui/imgui_impl_glfw.cpp
    App/thirdparty/imgui/imgui_impl_opengl3.cpp
)

add_executable(app ${IMGUI_SOURCES})

target_sources(app PRIVATE
    App/src/main.cpp
    App/src/framework/core/App.cpp
    App/src/framework/core/Window.cpp
    App/src/framework/graphics/Graphics.cpp
    App/src/framework/utils/Log.cpp
    App/src/ExampleGUI.cpp
    ${IMGUI_SOURCES}
)

target_link_libraries(app PRIVATE glad::glad glfw imgui::imgui spdlog::spdlog)

target_include_directories(app PRIVATE App/include App/thirdparty/imgui/include)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()