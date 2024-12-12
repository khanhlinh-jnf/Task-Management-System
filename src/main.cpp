#include "header.h"

int main() {
  TaskManager* manager = TaskManager::getInstance();

  manager->addTask();  // Add individual task

  manager->createTaskGroup("Group 1");
  TaskGroup* group1 = dynamic_cast<TaskGroup*>(
      manager->getTask(1));  // Assuming the first group has ID 1

  manager->addTask();  // Add another individual task
  Task* task2 = dynamic_cast<Task*>(
      manager->getTask(2));  // Assuming the second task has ID 2

  manager->addTaskToGroup(task2, group1);  // Add task to group

  manager->displayAllTasks();  // Display all tasks and groups

  return 0;
}