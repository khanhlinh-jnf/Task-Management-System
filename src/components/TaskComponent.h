#pragma once

#include <string>

class TaskComponent {
 public:
  virtual ~TaskComponent() {}
  virtual void display() const = 0;
};