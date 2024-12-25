#include "header.h"

int main() {
  Gui screen;
  screen.initialize();

  while (!WindowShouldClose()) {
    screen.update([]() {
      // Update logic here
    });
    screen.draw();
  }

  screen.shutdown();
  return 0;
}