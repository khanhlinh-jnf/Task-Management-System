#include <iostream>

#include "header.h"

int main() {
  TaskManager* manager = TaskManager::getInstance();
  // Create a new task
  TaskBuilder builder;
  builder.setId(1);
  builder.setTitle("Task 1");
  builder.setDescription("Description 1");
  builder.setAssignee("Assignee 1");
  builder.setStatus("Pending");
  builder.setDueDate("2021-12-31");
  std::unique_ptr<Task> task1 = builder.build();

  // Add the task to the manager
  manager->addTask(std::move(task1));

  // Create a new task
  TaskBuilder builder2;
  builder2.setId(2);
  builder2.setTitle("Task 2");
  builder2.setDescription("Description 2");
  builder2.setAssignee("Assignee 2");
  builder2.setStatus("In Progress");

  // Add the task to the manager
  manager->addTask(std::move(builder2.build()));

  // Create group and add tasks to it
  TaskComponent* group1 = new TaskGroup("Group 1");
  group1->add(manager->getTask(1));

  // Add task 2 to group 2
  TaskComponent* group2 = new TaskGroup("Group 2");
  group2->add(manager->getTask(2));

  // Create a new task
  TaskBuilder builder3;
  builder3.setId(3);
  builder3.setTitle("Task 3");
  builder3.setDescription("Description 3");
  builder3.setAssignee("Assignee 3");
  builder3.setStatus("Completed");
  builder3.setDueDate("2021-12-31");

  manager->addTask(std::move(builder3.build()));
  // Create a group 3
  TaskComponent* group3 = new TaskGroup("Group 3");
  group3->add(manager->getTask(3));

  // Add group 1 and group 2 to group 3
  group3->add(group1);
  group3->add(group2);

  // Add group 3 to the manager
  manager->addTask(std::unique_ptr<TaskComponent>(group3));

  // Display all tasks
  manager->displayAllTasks();

  return 0;
}