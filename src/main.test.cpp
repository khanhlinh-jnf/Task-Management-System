#include "header.h"

int main() {
  InitWindow(800, 600, "Task Management System");
  SetTargetFPS(60);

  Font myFont = LoadFontEx("public/fonts/UTMTimesBold.ttf", 40, 0, 250);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTextEx(myFont, "Hello, Raylib!", {100, 100}, 40, 2, DARKGRAY);

    EndDrawing();
  }
  return 0;
}