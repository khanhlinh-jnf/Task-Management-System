#include <iostream>

#include "header.h"

int main() {
  TaskManager* manager = TaskManager::getInstance();

  // Initializing command objects
  vector<TaskCommand*> cmdObjects;

  cmdObjects.push_back(new DisplayAllTaskNameCommand(manager));
  cmdObjects.push_back(new DisplayAllGroupNameCommand(manager));
  cmdObjects.push_back(new DisplayGroupCommand(manager));
  cmdObjects.push_back(new DisplayTaskCommand(manager));
  cmdObjects.push_back(new AddTaskCommand(manager));
  cmdObjects.push_back(new RemoveTaskCommand(manager));
  cmdObjects.push_back(new UpdateTaskCommand(manager));
  cmdObjects.push_back(new CreateGroupCommand(manager));
  cmdObjects.push_back(new AddTaskToGroupCommand(manager));
  cmdObjects.push_back(new AddGroupToGroupCommand(manager));

  manager->readFromFile("../assets/tasks.txt");

  int choice = -1;
  while (choice != 0) {
    cout << "Task Management System\n"
         << "1. Display all task names\n"
         << "2. Display all group names\n"
         << "3. Display group\n"
         << "4. Display task\n"
         << "5. Add task\n"
         << "6. Remove task\n"
         << "7. Update task\n"
         << "8. Create group\n"
         << "9. Add task to group\n"
         << "10. Add group to group\n"
         << "0. Exit\n"
         << "Enter choice: ";
    cin >> choice;
    cin.ignore();
    cout << "-----------------------------------" << endl;
    if (choice > 0 && choice <= 10) {
      cmdObjects[choice - 1]->execute();
    } else if (choice == 0) {
      cout << "Exiting..." << endl;
    } else {
      cout << "Invalid choice!" << endl;
    }
  }

  manager->writeToFile("../assets/tasks.txt");
  
  return 0;
}
