#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "TaskComponent.h"

class TaskGroup : public TaskComponent {
 private:
  std::string groupName;
  std::vector<TaskComponent*> children;

 public:
  TaskGroup(const std::string& name) : groupName(name) {}

  ~TaskGroup() {
    for (TaskComponent* child : children) {
      delete child;
    }
  }

  void add(TaskComponent* component) { children.push_back(component); }

  void remove(TaskComponent* component) {
    children.erase(std::remove(children.begin(), children.end(), component),
                   children.end());
  }

  void display() const override {
    std::cout << "Task Group: " << groupName << std::endl;
    for (const TaskComponent* child : children) {
      child->display();
    }
  }
};

#include "TaskGroup.cpp"