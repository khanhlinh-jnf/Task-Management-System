#pragma once

#include <memory>
#include <vector>
#include <string>
#include <fstream>

#include "Task.h"
#include "TaskComponent.h"
#include "TaskGroup.h"

class TaskManager {
 private:
  static TaskManager* instance;
  std::vector<std::unique_ptr<TaskComponent>> tasks;
  int taskId = 0;
  int groupId = 0;

  TaskManager() = default;

 public:
  static TaskManager* getInstance();

  void addTask(std::vector<std::string> data);
  void addTask(std::unique_ptr<TaskComponent> task);  // Add this method

  void updateTask(TaskComponent* task, std::vector<std::string> data, std::vector<int> choice);
  void addTaskToGroup(TaskComponent* task, TaskGroup* group);
  void createTaskGroup(const std::string& title);
  TaskComponent* getTask(int id);
  TaskComponent* getGroup(int id);
  void removeTask(int id);
  void displayAllTasks() const;
  void displayAllGroupName() const;
  void displayGroup(int id);
  void displayAllTaskName() const;
  void writeToFile(const std::string& filename) const;
  void readFromFile(const std::string& filename);

};