#include "Gui.h"

#include <iostream>
#include <string>

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

  // Example buttons and input fields
  Rectangle addTaskButton = {10, 50, 100, 30};
  DrawRectangleRec(addTaskButton, LIGHTGRAY);
  DrawText("Add Task", addTaskButton.x + 10, addTaskButton.y + 10, 10,
           DARKGRAY);
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
      CheckCollisionPointRec(GetMousePosition(), addTaskButton)) {
    showAddTaskWindow();  // Show add task window
  }

  Rectangle displayTasksButton = {10, 90, 100, 30};
  DrawRectangleRec(displayTasksButton, LIGHTGRAY);
  DrawText("Display Tasks", displayTasksButton.x + 10,
           displayTasksButton.y + 10, 10, DARKGRAY);
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
      CheckCollisionPointRec(GetMousePosition(), displayTasksButton)) {
    cmdObjects[3]->execute();  // display tasks
  }

  EndDrawing();
}

void Gui::showAddTaskWindow() const {
  // Create a new window for adding a task
  InitWindow(400, 500, "Add Task");

  std::string title;
  std::string description;
  std::string assignee;
  std::string status;
  std::string dueDate;
  std::string groupName;
  bool addTask = false;
  bool typingTitle = true;
  bool typingDescription = false;
  bool typingAssignee = false;
  bool typingStatus = false;
  bool typingDueDate = false;
  bool typingGroupName = false;

  Rectangle titleBox = {10, 40, 380, 30};
  Rectangle descriptionBox = {10, 110, 380, 30};
  Rectangle assigneeBox = {10, 180, 380, 30};
  Rectangle statusBox = {10, 250, 380, 30};
  Rectangle dueDateBox = {10, 320, 380, 30};
  Rectangle groupNameBox = {10, 390, 380, 30};

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // Update
    bool mouseOnTitleBox = CheckCollisionPointRec(GetMousePosition(), titleBox);
    bool mouseOnDescriptionBox =
        CheckCollisionPointRec(GetMousePosition(), descriptionBox);
    bool mouseOnAssigneeBox =
        CheckCollisionPointRec(GetMousePosition(), assigneeBox);
    bool mouseOnStatusBox =
        CheckCollisionPointRec(GetMousePosition(), statusBox);
    bool mouseOnDueDateBox =
        CheckCollisionPointRec(GetMousePosition(), dueDateBox);
    bool mouseOnGroupNameBox =
        CheckCollisionPointRec(GetMousePosition(), groupNameBox);

    if (mouseOnTitleBox) {
      SetMouseCursor(MOUSE_CURSOR_IBEAM);
      typingTitle = true;
      typingDescription = false;
      typingAssignee = false;
      typingStatus = false;
      typingDueDate = false;
      typingGroupName = false;
    } else if (mouseOnDescriptionBox) {
      SetMouseCursor(MOUSE_CURSOR_IBEAM);
      typingTitle = false;
      typingDescription = true;
      typingAssignee = false;
      typingStatus = false;
      typingDueDate = false;
      typingGroupName = false;
    } else if (mouseOnAssigneeBox) {
      SetMouseCursor(MOUSE_CURSOR_IBEAM);
      typingTitle = false;
      typingDescription = false;
      typingAssignee = true;
      typingStatus = false;
      typingDueDate = false;
      typingGroupName = false;
    } else if (mouseOnStatusBox) {
      SetMouseCursor(MOUSE_CURSOR_IBEAM);
      typingTitle = false;
      typingDescription = false;
      typingAssignee = false;
      typingStatus = true;
      typingDueDate = false;
      typingGroupName = false;
    } else if (mouseOnDueDateBox) {
      SetMouseCursor(MOUSE_CURSOR_IBEAM);
      typingTitle = false;
      typingDescription = false;
      typingAssignee = false;
      typingStatus = false;
      typingDueDate = true;
      typingGroupName = false;
    } else if (mouseOnGroupNameBox) {
      SetMouseCursor(MOUSE_CURSOR_IBEAM);
      typingTitle = false;
      typingDescription = false;
      typingAssignee = false;
      typingStatus = false;
      typingDueDate = false;
      typingGroupName = true;
    } else {
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);
      typingTitle = false;
      typingDescription = false;
      typingAssignee = false;
      typingStatus = false;
      typingDueDate = false;
      typingGroupName = false;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Enter Task Title:", 10, 10, 20, DARKGRAY);
    DrawTextBox(title, titleBox.x, titleBox.y, titleBox.width, titleBox.height,
                typingTitle);

    DrawText("Enter Task Description:", 10, 80, 20, DARKGRAY);
    DrawTextBox(description, descriptionBox.x, descriptionBox.y,
                descriptionBox.width, descriptionBox.height, typingDescription);

    DrawText("Enter Assignee:", 10, 150, 20, DARKGRAY);
    DrawTextBox(assignee, assigneeBox.x, assigneeBox.y, assigneeBox.width,
                assigneeBox.height, typingAssignee);

    DrawText("Enter Status:", 10, 220, 20, DARKGRAY);
    DrawTextBox(status, statusBox.x, statusBox.y, statusBox.width,
                statusBox.height, typingStatus);

    DrawText("Enter Due Date:", 10, 290, 20, DARKGRAY);
    DrawTextBox(dueDate, dueDateBox.x, dueDateBox.y, dueDateBox.width,
                dueDateBox.height, typingDueDate);

    DrawText("Enter Group Name:", 10, 360, 20, DARKGRAY);
    DrawTextBox(groupName, groupNameBox.x, groupNameBox.y, groupNameBox.width,
                groupNameBox.height, typingGroupName);

    Rectangle addButton = {150, 440, 100, 30};
    DrawRectangleRec(addButton, LIGHTGRAY);
    DrawText("Add", addButton.x + 30, addButton.y + 5, 20, DARKGRAY);
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        CheckCollisionPointRec(GetMousePosition(), addButton)) {
      addTask = true;
      break;
    }

    EndDrawing();
  }

  if (addTask) {
    // Add the task to the manager

    // Code here

    // Show success message
    InitWindow(200, 100, "Success");
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Task added successfully!", 10, 40, 20, DARKGRAY);
      EndDrawing();
    }
    CloseWindow();
  }

  CloseWindow();
}

void Gui::DrawTextBox(std::string& buffer, int x, int y, int width, int height,
                      bool typing) {
  DrawRectangle(x, y, width, height, LIGHTGRAY);
  DrawText(buffer.c_str(), x + 5, y + 5, 20, DARKGRAY);

  if (typing) {
    int key = GetCharPressed();
    while (key > 0) {
      if ((key >= 32) && (key <= 125) && buffer.length() < 30) {
        buffer += static_cast<char>(key);
      }
      key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) && !buffer.empty()) {
      buffer.pop_back();
    }
  }
}

void Gui::shutdown() {
  // Cleanup code here
  if (customFont.texture.id != 0) {
    UnloadFont(customFont);  // Unload the custom font
  }
  CloseWindow();
}