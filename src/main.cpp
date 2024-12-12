#include "header.h"

int main() {
  TaskManager* taskManager = TaskManager::getInstance();

  TaskCommand* newTask = new AddTaskCommand(taskManager);
  TaskCommand* Task2 = new AddTaskCommand(taskManager);
  TaskCommand* Task3 = new AddTaskCommand(taskManager);

  // Create group
  taskManager->createTaskGroup("Group 1");
  TaskGroup* group = dynamic_cast<TaskGroup*>(taskManager->getTask(0));
  

  newTask->execute();
  taskManager->displayAllTasks();

  return 0;
}