#include "singleton.h"

TaskManager::TaskManager() {
  tasks = {};
}

TaskManager* TaskManager::instance = 0;

TaskManager* TaskManager::getInstance() {
  if (!instance) {
	instance = new TaskManager();
  }
  return instance;
}

void TaskManager::addTask(Task task) {
  tasks.push_back(task);
}

void TaskManager::removeTask(int taskId) {
  for (int i = 0; i < tasks.size(); i++) {
	if (tasks[i].getId() == taskId) {
	  tasks.erase(tasks.begin() + i);
	  break;
	}
  }
}

Task* TaskManager::getTask(int taskId) {
  for (int i = 0; i < tasks.size(); i++) {
	if (tasks[i].getId() == taskId) {
	  return &tasks[i];
	}
  }
  return nullptr;
}

vector<Task> TaskManager::getAllTasks() {
  return tasks;
}


