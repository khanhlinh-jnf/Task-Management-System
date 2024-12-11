#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "TaskBuilder.h"
#include "task.h"

class TaskManager {
 protected:
  static TaskManager* instance;
  std::vector<TaskComponent*> tasks;

 public:
  static TaskManager* getInstance();
  void addTask();
  void removeTask(int taskId);
  void displayAllTasks();

  TaskComponent* getTask(int taskId);
  //vector<TaskComponent*> getAllTasks() { return tasks; }
};

#include "singleton.cpp"