#include "singleton.h"
using namespace std;

TaskManager* TaskManager::instance = nullptr;

TaskManager* TaskManager::getInstance() {
  if (instance == nullptr) {
    instance = new TaskManager();
  }
  return instance;
}

void TaskManager::addTask() {
  TaskBuilder builder;
  std::unique_ptr<Task> newTask; 
  int choice = -1;
  string temp;
  while (true){
    cout << "Menu: \n"
         << "1. Set title\n"
         << "2. Set description\n"
         << "3. Set assignee\n"
         << "4. Set status\n"
         << "5. Set due date\n"
         << "6. Save task\n"
         << "Enter choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
      case 1:
        cout << "Enter title: ";
        getline(cin,temp);
        builder.setTitle(temp);
        break;
      case 2:
        cout << "Enter description: ";
        getline(cin, temp);
        builder.setDescription(temp);
        break;
      case 3:
        cout << "Enter assignee: ";
        getline(cin, temp);
        builder.setAssignee(temp);
        break;
      case 4:
        cout << "Enter status: ";
        getline(cin, temp);
        builder.setStatus(temp);
        break;
      case 5:
        cout << "Enter due date: ";
        getline(cin, temp);
        builder.setDueDate(temp);
        break;
      case 6:
        newTask = builder.build();
        tasks.push_back(newTask.release());
        return;
      default:
        cout << "Invalid choice!" << endl;
        break;
    }
  }
  
}

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

void TaskManager::displayAllTasks() {
  for (TaskComponent* task : tasks) {
    task->display();
  }
}

//vector<TaskComponent*> TaskManager::getAllTasks() { return tasks; }