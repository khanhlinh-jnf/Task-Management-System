#include "Gui.h"

Gui::Gui(int width, int height, const std::string& windowTitle)
    : screenWidth(width), screenHeight(height), title(windowTitle) {
  InitWindow(screenWidth, screenHeight, title.c_str());
  SetTargetFPS(60);
}

Gui::~Gui() { CloseWindow(); }


void Gui::update(std::function<void()> func) {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText(title.c_str(), 10, 10, 20, DARKGRAY);

    EndDrawing();
  }
}