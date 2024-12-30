#include "TaskGroup.h"

#include <iostream>


TaskGroup::TaskGroup(const std::string& title, int id) : title(title), id(id) {}
TaskGroup::TaskGroup() : title(""), id(0) {}

void TaskGroup::add(TaskComponent* component) { tasks.push_back(component); }

void TaskGroup::remove(TaskComponent* component) {
  tasks.erase(std::remove(tasks.begin(), tasks.end(), component), tasks.end());
}

int TaskGroup::getType() const { return type; }

TaskComponent* TaskGroup::getChild(int index) {
  if (index < tasks.size()) {
    return tasks[index];
  }
  return nullptr;
}

std::string TaskGroup::getTitle() const { return title; }

void TaskGroup::display(int indent) const {
  std::string indentation(indent, ' ');
  displayName(indent);
  for (const auto& task : tasks) {
    task->display(indent + 2);
  }
  std::cout << indentation << "----------------" << std::endl;
}

void TaskGroup::displayName(int indent) const {
  std::string indentation(indent, ' ');
  std::cout << indentation << "Group ID: " << id << "\n"
            << indentation << "Title: " << title << std::endl;
}

void TaskGroup::setId(int id) { this->id = id; }

void TaskGroup::setTitle(const std::string& title) { this->title = title; }

void TaskGroup::setDescription(const std::string& description) {}

void TaskGroup::setAssignee(const std::string& assignee) {}

void TaskGroup::setStatus(const std::string& status) {}

void TaskGroup::setDueDate(const std::string& dueDate) {}

int TaskGroup::getId() const { return id; }

std::string TaskGroup::getDescription() const { return ""; }

std::string TaskGroup::getAssignee() const { return ""; }

std::string TaskGroup::getStatus() const { return ""; }

std::string TaskGroup::getDueDate() const { return ""; }

void TaskGroup::writeToFile(std::ofstream& file) const {
  file << type << "\n"
       << id << "\n"
       << title << "\n"
       << tasks.size() << "\n";
  for (const auto& task : tasks) {
    task->writeToFile(file);
  }
}

void TaskGroup::readFromFile(std::ifstream& file) {
  file >> id;
  file.ignore();
  std::getline(file, title);
  int numTasks;
  file >> numTasks;
  int type;
  for (int i = 0; i < numTasks; i++) {
    file >> type;
    file.ignore();
    if (type == 0) {
      TaskComponent* task = new Task();
      task->readFromFile(file);
      tasks.push_back(task);
    } else {
      TaskComponent* group = new TaskGroup();
      group->readFromFile(file);
      tasks.push_back(group);
    }
  }
}

