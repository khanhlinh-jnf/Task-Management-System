#pragma once

#include <functional>
#include <string>
#include <vector>

#include "TaskCommand.h"
#include "TaskManager.h"
#include "raylib.h"

class Gui {
 public:
  Gui(TaskManager* manager, const std::vector<TaskCommand*>& cmdObjects);
  ~Gui();

  void initialize();
  void update(std::function<void()> callback);
  void draw() const;
  void shutdown();

 private:
  Font customFont;
  TaskManager* manager;
  std::vector<TaskCommand*> cmdObjects;

  void showAddTaskWindow() const;
  static void DrawTextBox(std::string& buffer, int x, int y, int width,
                          int height, bool typing);
};