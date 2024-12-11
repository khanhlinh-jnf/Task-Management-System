#include <memory>
#include "header.h"

using namespace std;

int main() {
  TaskManager* taskManager = TaskManager::getInstance();

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

  // TaskBuilder builder;
  // std::unique_ptr<Task> task = builder.setId(1)
  //                                     .setTitle("Implement Builder Pattern")
  //                                     .setDescription("Create a builder for the Task object.")
  //                                     .setAssignee("John Doe")
  //                                     .setStatus("In Progress")
  //                                     .setDueDate("2024-12-31")
  //                                     .build();

  // // Print the task details
  // if (task) {
  //   task->display();
  // } else {
  //   std::cerr << "Failed to build Task." << std::endl;
  // }

  taskManager->addTask();
  taskManager->displayAllTasks();
  taskManager->addTask();
  taskManager->displayAllTasks();
  taskManager->updateTask(1);
  taskManager->displayAllTasks();


  return 0;
}