#include "Gui.h"

Gui::Gui() {
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
    DrawTextEx(customFont, "Hello, Raylib!", {100, 100}, 40, 2, DARKGRAY);
  } else {
    DrawText("Failed to load font", 10, 10, 20, RED);
  }

  EndDrawing();
}

void Gui::shutdown() {
  // Cleanup code here
  if (customFont.texture.id != 0) {
    UnloadFont(customFont);  // Unload the custom font
  }
  CloseWindow();
}