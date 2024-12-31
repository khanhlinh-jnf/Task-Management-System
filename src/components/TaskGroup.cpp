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
  if (tasks.size() != 0)
    std::cout << indentation << "----------------" << std::endl;
  for (int i = 0; i < tasks.size(); i++) {
    tasks[i]->display(indent + 4);
    if (i == tasks.size() - 1) break;
    std::cout << indentation << "----------------" << std::endl;
  }
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
  file << type << "\n" << id << "\n" << title << "\n";
}

void TaskGroup::writeGroupToFile(std::ofstream& file) const {
  file << id << "\n";
  file << tasks.size() << "\n";
  for (const auto& task : tasks) {
    if (task->getType() == 0) {
      file << task->getType() << "\n";
      file << task->getId() << "\n";
    } else {
      file << task->getType() << "\n";
      file << task->getId() << "\n";
    }
  }
}

void TaskGroup::readFromFile(std::ifstream& file) {
  file >> id;
  file.ignore();
  std::getline(file, title);
}
