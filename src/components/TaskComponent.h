#pragma once

class TaskComponent {
 public:
  virtual ~TaskComponent() {}
  virtual void display() const = 0;
};