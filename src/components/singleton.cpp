#include "singleton.h"
using namespace std;

TaskManager* TaskManager::instance = nullptr;
int TaskManager::taskId = 0;

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
  while (true) {
    cout << "Create new task \n"
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
        getline(cin, temp);
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
        builder.setId(++taskId);
        newTask = builder.build();
        tasks.push_back(newTask.release());
        cout << "Task created successfully with ID: " << taskId << endl;
        cout << "-----------------------------------" << endl;
        return;
      default:
        cout << "Invalid choice!" << endl;
        break;
    }
  }
}

void TaskManager::updateTask(int taskId) {
  TaskComponent* task = getTask(taskId);
  if (task) {
    string temp;
    int choice = -1;
    while (true) {
      cout << "Update task \n"
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
          getline(cin, temp);
          task->setTitle(temp);
          break;
        case 2:
          cout << "Enter description: ";
          getline(cin, temp);
          task->setDescription(temp);
          break;
        case 3:
          cout << "Enter assignee: ";
          getline(cin, temp);
          task->setAssignee(temp);
          break;
        case 4:
          cout << "Enter status: ";
          getline(cin, temp);
          task->setStatus(temp);
          break;
        case 5:
          cout << "Enter due date: ";
          getline(cin, temp);
          task->setDueDate(temp);
          break;
        case 6:
          cout << "Task " << task->getId() << " updated successfully!" << endl;
          cout << "-----------------------------------" << endl;
          return;
        default:
          cout << "Invalid choice!" << endl;
          break;
      }
    }
  } else {
    cout << "Task not found!" << endl;
  }
}

void TaskManager::removeTask(int taskId) {
  for (int i = 0; i < tasks.size(); i++) {
    Task* t = dynamic_cast<Task*>(tasks[i]);
    if (t && t->getId() == taskId) {
      tasks.erase(tasks.begin() + i);
      return;
    }
  }
}

TaskComponent* TaskManager::getTask(int taskId) {
  for (TaskComponent* task : tasks) {
    Task* t = dynamic_cast<Task*>(task);
    if (t && t->getId() == taskId) {
      return task;
    }
  }
  return nullptr;
}

void TaskManager::displayAllTasks() {
  for (TaskComponent* task : tasks) {
    task->display();
  }
}
