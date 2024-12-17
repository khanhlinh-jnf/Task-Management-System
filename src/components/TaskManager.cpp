#include "TaskManager.h"

#include <algorithm>
#include <iostream>

#include "TaskBuilder.h"

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
  unique_ptr<Task> newTask;
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
        getline(std::cin, temp);
        builder.setTitle(temp);
        break;
      case 2:
        cout << "Enter description: ";
        getline(std::cin, temp);
        builder.setDescription(temp);
        break;
      case 3:
        cout << "Enter assignee: ";
        getline(std::cin, temp);
        builder.setAssignee(temp);
        break;
      case 4:
        cout << "Enter status: ";
        getline(std::cin, temp);
        builder.setStatus(temp);
        break;
      case 5:
        cout << "Enter due date: ";
        getline(std::cin, temp);
        builder.setDueDate(temp);
        break;
      case 6:
        builder.setId(++taskId);
        newTask = builder.build();
        tasks.push_back(std::move(newTask));
        cout << "Task created successfully with ID: " << taskId << std::endl;
        cout << "-----------------------------------" << std::endl;
        return;
      default:
        cout << "Invalid choice!" << std::endl;
        break;
    }
  }
}

void TaskManager::addTask(std::unique_ptr<TaskComponent> task) {
  taskId++;
  tasks.push_back(std::move(task));
}

void TaskManager::addTaskToGroup(TaskComponent* task, TaskGroup* group) {
  group->add(task);
}

void TaskManager::createTaskGroup(const std::string& title) {
  tasks.push_back(std::make_unique<TaskGroup>(title, ++taskId));
}

TaskComponent* TaskManager::getTask(int id) {
  for (const auto& task : tasks) {
    if (task->getId() == id) {
      return task.get();
    }
  }
  return nullptr;
}

void TaskManager::removeTask(int id) {
  auto it = std::remove_if(tasks.begin(), tasks.end(),
                           [id](const std::unique_ptr<TaskComponent>& task) {
                             return task->getId() == id;
                           });
  tasks.erase(it, tasks.end());
}

void TaskManager::displayAllTasks() const {
  for (const auto& task : tasks) {
    task->display(0);  // Start with no indentation
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