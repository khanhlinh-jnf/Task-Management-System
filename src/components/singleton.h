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
  static int taskId;
  std::vector<TaskComponent*> tasks;

 public:
  static TaskManager* getInstance();
  void addTask();
  void updateTask(int taskId);
  void removeTask(int taskId);
  void displayAllTasks();


  TaskComponent* getTask(int taskId);

};

#include "singleton.cpp"