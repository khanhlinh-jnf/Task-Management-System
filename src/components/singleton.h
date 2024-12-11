#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "task.h"

class TaskManager {
 protected:
  static TaskManager* instance;
  std::vector<TaskComponent*> tasks;

 public:
  static TaskManager* getInstance() {
    if (instance == nullptr) {
      instance = new TaskManager();
    }
    return instance;
  }

  void addTask(TaskComponent* task) { tasks.push_back(task); }

  void removeTask(int taskId) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                               [taskId](TaskComponent* task) {
                                 Task* t = dynamic_cast<Task*>(task);
                                 return t && t->getId() == taskId;
                               }),
                tasks.end());
  }

  TaskComponent* getTask(int taskId) {
    for (TaskComponent* task : tasks) {
      Task* t = dynamic_cast<Task*>(task);
      if (t && t->getId() == taskId) {
        return t;
      }
    }
    return nullptr;
  }

  std::vector<TaskComponent*> getAllTasks() { return tasks; }
};