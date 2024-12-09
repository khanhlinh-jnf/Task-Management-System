#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "task.h"

class TaskManager {
 protected:
  static TaskManager* instance;
  vector<Task> tasks;

 public:
  static TaskManager* getInstance();
  void addTask(Task task);
  void removeTask(int taskId);
  Task* getTask(int taskId);
  vector<Task> getAllTasks();
};