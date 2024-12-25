#include "Gui.h"

Gui::Gui(TaskManager* manager, const std::vector<TaskCommand*>& cmdObjects)
    : manager(manager), cmdObjects(cmdObjects) {
  // Initialization code here
}

Gui::~Gui() {
  // Cleanup code here
}

void Gui::initialize() {
  // Initialization code here
  InitWindow(800, 600, "Task Management System");

  // Load custom font from TTF file
  const char* fontPath = "public/fonts/UTMTimesBold.ttf";
  if (FileExists(fontPath)) {
    customFont = LoadFontEx(fontPath, 40, nullptr, 250);
    if (customFont.texture.id == 0) {
      std::cerr << "Failed to load font from " << fontPath << std::endl;
    }
  } else {
    std::cerr << "Font file not found: " << fontPath << std::endl;
  }

  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
}

void Gui::update(std::function<void()> callback) {
  // Update code here
  callback();
}

void Gui::draw() const {
  // Draw
  BeginDrawing();
  ClearBackground(RAYWHITE);

  // Draw your GUI elements here using the custom font
  if (customFont.texture.id != 0) {
    DrawTextEx(customFont, "Task Management System", {10, 10},
               customFont.baseSize * 2, 2, DARKGRAY);
  } else {
    DrawText("Failed to load font", 10, 10, 20, RED);
  }

  // Example buttons and input fields
  Rectangle addTaskButton = {10, 50, 100, 30};
  DrawRectangleRec(addTaskButton, LIGHTGRAY);
  DrawText("Add Task", addTaskButton.x + 10, addTaskButton.y + 10, 10,
           DARKGRAY);
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
      CheckCollisionPointRec(GetMousePosition(), addTaskButton)) {
    cmdObjects[0]->execute();  // add task
  }

  Rectangle displayTasksButton = {10, 90, 100, 30};
  DrawRectangleRec(displayTasksButton, LIGHTGRAY);
  DrawText("Display Tasks", displayTasksButton.x + 10,
           displayTasksButton.y + 10, 10, DARKGRAY);
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
      CheckCollisionPointRec(GetMousePosition(), displayTasksButton)) {
    cmdObjects[3]->execute();  // display tasks
  }

  // Additional buttons...

  EndDrawing();
}

void Gui::shutdown() {
  // Cleanup code here
  if (customFont.texture.id != 0) {
    UnloadFont(customFont);  // Unload the custom font
  }
  CloseWindow();
}