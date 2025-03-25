#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "framework/core/App.h"
#include "framework/gui/GUI.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

void GUI::initialize(GLFWwindow* windowPtr) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(windowPtr, true);
  ImGui_ImplOpenGL3_Init("#version 150");
}

GUI::~GUI() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void GUI::render(const App* app) const {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();

  ImGui::NewFrame();
  ImGui::Begin("My Window");
  ImGui::Text("Hello, world!");
  ImGui::End();
  ImGui::Render();

  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUI::handleEvents() {}