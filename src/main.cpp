#include <memory>
#include "header.h"

using namespace std;

int main() {
  // TaskManager* taskManager = TaskManager::getInstance();

  // Task* task1 = new Task(1, "Task 1", "Description 1", "Assignee 1", "Status 1",
  //                        "Due Date 1");
  // Task* task2 = new Task(2, "Task 2", "Description 2", "Assignee 2", "Status 2",
  //                        "Due Date 2");
  // Task* task3 = new Task(3, "Task 3", "Description 3", "Assignee 3", "Status 3",
  //                        "Due Date 3");

  // taskManager->addTask(task1);
  // taskManager->addTask(task2);
  // taskManager->addTask(task3);

  // TaskGroup group1("Group 1");
  // group1.add(task1);
  // group1.add(task2);

  // TaskGroup group2("Group 2");
  // group2.add(task3);

  // group1.display();
  // group2.display();

  // delete taskManager;  // Ensure to delete the singleton instance if necessary

 Task task = TaskBuilder().setId(1).setTitle("Task 1").setDescription("Description 1").setAssignee("Assignee 1").setStatus("Status 1").setDueDate("Due Date 1").build();
  task.display();

  return 0;
}