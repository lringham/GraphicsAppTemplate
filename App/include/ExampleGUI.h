#pragma once

class ExampleGUI {
 public:
  ExampleGUI() = default;
  virtual ~ExampleGUI();

  ExampleGUI(const ExampleGUI &other) = delete;
  ExampleGUI &operator=(const ExampleGUI &other) = delete;
  ExampleGUI(ExampleGUI &&other) = delete;
  ExampleGUI &operator=(ExampleGUI &&rhs) = delete;

  void initialize(struct GLFWwindow *windowPtr);

  void render() const;
};