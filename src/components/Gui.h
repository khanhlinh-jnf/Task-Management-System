#pragma once

#include <functional>
#include <string>
#include <vector>
using namespace std;

#include "raylib.h"

class Gui {
 private:
  const int screenWidth;
  const int screenHeight;
  std::string title;

  Font customFont;

 public:
  Gui(int width, int height, const std::string& windowTitle);
  ~Gui();

  void update(function<void()>);
};
