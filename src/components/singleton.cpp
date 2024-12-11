#include "singleton.h"

TaskManager* TaskManager::instance = nullptr;

TaskManager* TaskManager::getInstance() {
  if (instance == nullptr) {
    instance = new TaskManager();
  }
  return instance;
}

void TaskManager::addTask(TaskComponent* task) { tasks.push_back(task); }

void TaskManager::removeTask(int taskId) {
  tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                             [taskId](TaskComponent* task) {
                               Task* t = dynamic_cast<Task*>(task);
                               return t && t->getId() == taskId;
                             }),
              tasks.end());
}

TaskComponent* TaskManager::getTask(int taskId) {
  for (TaskComponent* task : tasks) {
    Task* t = dynamic_cast<Task*>(task);
    if (t && t->getId() == taskId) {
      return t;
    }
  }
  return nullptr;
}

std::vector<TaskComponent*> TaskManager::getAllTasks() { return tasks; }