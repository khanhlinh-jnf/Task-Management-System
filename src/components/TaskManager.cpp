#include "TaskManager.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "TaskBuilder.h"

using namespace std;
const string BREAK = "-----------------------------------";

TaskManager* TaskManager::instance = nullptr;

TaskManager* TaskManager::getInstance() {
  if (instance == nullptr) {
    instance = new TaskManager();
  }
  return instance;
}

void TaskManager::addTask(vector<string> data) {
  TaskBuilder builder;
  unique_ptr<Task> newTask;

  if (data[0] != "") {
    builder.setTitle(data[0]);
  }
  if (data[1] != "") {
    builder.setDescription(data[1]);
  }
  if (data[2] != "") {
    builder.setAssignee(data[2]);
  }
  if (data[3] != "") {
    builder.setStatus(data[3]);
  }
  if (data[4] != "") {
    builder.setDueDate(data[4]);
  }

  builder.setId(++taskId);
  newTask = builder.build();
  tasks.push_back(std::move(newTask));
  cout << "Task created successfully with ID: " << taskId << std::endl;
  cout << BREAK << endl;
}

void TaskManager::addTask(std::unique_ptr<TaskComponent> task) {
  taskId++;
  tasks.push_back(std::move(task));
}

void TaskManager::addTaskToGroup(TaskComponent* task, TaskGroup* group) {
  group->add(task);
}

void TaskManager::createTaskGroup(const std::string& title) {
  tasks.push_back(std::make_unique<TaskGroup>(title, ++groupId));
  cout << "Group created successfully with ID: " << groupId << std::endl;
  cout << BREAK << endl;
}

TaskComponent* TaskManager::getTask(int id) {
  for (const auto& task : tasks) {
    if (task->getId() == id && task->getType() == 0) {
      return task.get();
    }
  }
  return nullptr;
}

TaskComponent* TaskManager::getGroup(int id) {
  for (const auto& task : tasks) {
    if (task->getId() == id && task->getType() == 1) {
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
  cout << "Task " << id << " removed successfully!" << endl;
  cout << BREAK << endl;
}

void TaskManager::updateTask(TaskComponent* task, vector<string> data, vector<int> choice) {
  if (task) {
    if (choice[0] == 1) {
      task->setTitle(data[0]);
    }
    if (choice[1] == 1) {
      task->setDescription(data[1]);
    }
    if (choice[2] == 1) {
      task->setAssignee(data[2]);
    }
    if (choice[3] == 1) {
      task->setStatus(data[3]);
    }
    if (choice[4] == 1) {
      task->setDueDate(data[4]);
    }
    cout << "Task " << task->getId() << " updated successfully!" << endl;
    cout << BREAK << endl;
  } else {
    cout << "Task not found!" << endl;
  }
}

void TaskManager::displayAllTasks() const {
  cout << "All tasks: " << endl;
  cout << BREAK << endl;
  for (const auto& task : tasks) {
    if (task->getType() == 1) continue;
    task->display(0);  // Start with no indentation
    cout << BREAK << endl;
  }
}

void TaskManager::displayGroup(int id) {
  TaskComponent* group = getGroup(id);
  if (group) {
    group->display(0);
  } else {
    cout << "Group not found!" << endl;
  }
}

void TaskManager::displayAllGroupName() const {
  cout << "All groups: " << endl;
  for (const auto& task : tasks) {
    if (task->getType() == 0) continue;
    task->displayName(0);  // Start with no indentation
  }
  cout << BREAK << endl;
}

void TaskManager::displayAllTaskName() const {
  cout << "All tasks: " << endl;
  for (const auto& task : tasks) {
    if (task->getType() == 1) continue;
    task->displayName(0);  // Start with no indentation
  }
  cout << BREAK << endl;
}

void TaskManager::writeToFile(const std::string& filename) const {
  ofstream file(filename);
  if (!file.is_open()) {
    cout << "Error opening file!" << endl;
    return;
  }
  file << tasks.size() << "\n";
  for (const auto& task : tasks) {
    task->writeToFile(file);
  }
  file << taskId << "\n";
  file << groupId << "\n";
  file.close();
}

void TaskManager::readFromFile(const std::string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Error opening file!" << endl;
    return;
  }
  int numTasks, type;
  file >> numTasks;
  for (int i = 0; i < numTasks; i++) {
    file >> type;
    file.ignore();
    if (type == 0) {
      unique_ptr<TaskComponent> task = std::make_unique<Task>();
      task->readFromFile(file);
      tasks.push_back(std::move(task));
    } else {
      unique_ptr<TaskComponent> group = std::make_unique<TaskGroup>();
      group->readFromFile(file);
      tasks.push_back(std::move(group));
    }
  }

  file >> taskId;
  file >> groupId;
  file.close();
}