#include "header.h"

void displayMenu() {
  cout << "=====================================\n";
  cout << "       Task Management System        \n";
  cout << "=====================================\n";
  cout << "1. Display all task names\n";
  cout << "2. Display all group names\n";
  cout << "3. Display group\n";
  cout << "4. Display task\n";
  cout << "5. Add task\n";
  cout << "6. Remove task\n";
  cout << "7. Update task\n";
  cout << "8. Create group\n";
  cout << "9. Add task to group\n";
  cout << "10. Add group to group\n";
  cout << "0. Exit\n";
  cout << "=====================================\n";
  cout << "Enter your choice: ";
}

bool isNumber(const string& str) {
  for (char const& c : str) {
    if (!isdigit(c)) return false;
  }
  return true;
}

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

  string choice = "-1";
  int choosen = -1;
  while (choosen != 0) {
    displayMenu();
    cin >> choice;
    cin.ignore();
    cout << "-----------------------------------" << endl;
    if (isNumber(choice)) {
      choosen = stoi(choice);
      if (choosen > 0 && choosen <= 10) {
        cmdObjects[choosen - 1]->execute();
        manager->writeToFile("../assets/tasks.txt");

      } else if (choosen == 0) {
        cout << "Exiting..." << endl;
      } else {
        cout << "Invalid choice! Please try again.\n";
      }
    } else {
      cout << "Invalid choice! Please enter a number.\n";
    }
    cout << "-----------------------------------" << endl;
  }

  manager->writeToFile("../assets/tasks.txt");

  // Cleanup command objects
  for (TaskCommand* cmd : cmdObjects) {
    delete cmd;
  }

  return 0;
}