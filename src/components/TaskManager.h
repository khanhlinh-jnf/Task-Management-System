#pragma once

#include <memory>
#include <vector>

#include "Task.h"
#include "TaskComponent.h"
#include "TaskGroup.h"

class TaskManager {
 private:
  static TaskManager* instance;
  std::vector<std::unique_ptr<TaskComponent>> tasks;
  int taskId = 0;

  TaskManager() = default;

 public:
  static TaskManager* getInstance();

  void addTask();
  void addTask(std::unique_ptr<TaskComponent> task);  // Add this method

  void updateTask(int id);
  void addTaskToGroup(TaskComponent* task, TaskGroup* group);
  void createTaskGroup(const std::string& title);
  TaskComponent* getTask(int id);
  void removeTask(int id);
  void displayAllTasks() const;
};

#include "TaskManager.cpp"