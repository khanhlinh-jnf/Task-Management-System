#include <iostream>

#include "header.h"

int main() {
  TaskManager* manager = TaskManager::getInstance();

  // Initializing command objects
  vector<TaskCommand*> cmdObjects;
  cmdObjects.push_back(new AddTaskCommand(manager));
  cmdObjects.push_back(new RemoveTaskCommand(manager));
  cmdObjects.push_back(new UpdateTaskCommand(manager));
  cmdObjects.push_back(new DisplayTaskCommand(manager));
  cmdObjects.push_back(new CreateGroupCommand(manager));
  cmdObjects.push_back(new AddTaskToGroupCommand(manager));
  cmdObjects.push_back(new AddGroupToGroupCommand(manager));

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

  // Add task 2 to the manager
  manager->addTask(std::move(builder2.build()));

  cout << endl << endl;
  cmdObjects[3]->execute();  // display all tasks
  cout << endl << endl;

  // cmdObjects[1]->execute();  // remove task 1
  cmdObjects[2]->execute();  // update task 2

  cout << endl << endl;
  cmdObjects[3]->execute();  // display all tasks
  cout << endl << endl;

  // Create a new task
  // TaskBuilder builder3;
  // builder3.setId(3);
  // builder3.setTitle("Task 3");
  // builder3.setDescription("Description 3");
  // builder3.setAssignee("Assignee 3");
  // builder3.setStatus("Completed");
  // builder3.setDueDate("2021-12-31");

  cmdObjects[0]->execute(); // add task 3

  cout << endl << endl;
  cmdObjects[3]->execute();  // display all tasks
  cout << endl << endl;

  // Create group 1 and add tasks to it
  cmdObjects[4]->execute(); // create group 1
  cmdObjects[5]->execute(); // add task 1 to group 1

  // Add task 2 to group 2
  cmdObjects[4]->execute(); // create group 2
  cmdObjects[5]->execute(); // add task 2 to group 2

  // Create group 3 and add group 1 and 2
  cmdObjects[4]->execute(); // create group 3
  cmdObjects[6]->execute(); // add group 1 to group 3
  cmdObjects[6]->execute(); // add group 2 to group 3

  // // Add group 1 and group 2 to group 3
  // group3->add(group1);
  // group3->add(group2);

  // // Add group 3 to the manager
  // manager->addTask(std::unique_ptr<TaskComponent>(group3));

  // Display all tasks
  cmdObjects[3]->execute();

  return 0;
}