#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "raylib.h"

class Gui {
 public:
  Gui();
  ~Gui();

  void initialize();
  void update(std::function<void()> callback);
  void draw() const;
  void shutdown();

 private:
  Font customFont;
};
