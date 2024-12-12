#include "TaskGroup.h"

#include <iostream>

TaskGroup::TaskGroup(const std::string& title) : title(title) {}

void TaskGroup::add(TaskComponent* component) { tasks.push_back(component); }

void TaskGroup::remove(TaskComponent* component) {
  tasks.erase(std::remove(tasks.begin(), tasks.end(), component), tasks.end());
}

TaskComponent* TaskGroup::getChild(int index) {
  if (index < tasks.size()) {
    return tasks[index];
  }
  return nullptr;
}

std::string TaskGroup::getTitle() const { return title; }

void TaskGroup::display(int indent) const {
  std::string indentation(indent, ' ');
  std::cout << indentation << "Task Group: " << title << std::endl;
  for (const auto& task : tasks) {
    task->display(indent + 2);
  }
}

void TaskGroup::setId(int id) {}

void TaskGroup::setTitle(const std::string& title) { this->title = title; }

void TaskGroup::setDescription(const std::string& description) {}

void TaskGroup::setAssignee(const std::string& assignee) {}

void TaskGroup::setStatus(const std::string& status) {}

void TaskGroup::setDueDate(const std::string& dueDate) {}

int TaskGroup::getId() const { return -1; }

std::string TaskGroup::getDescription() const { return ""; }

std::string TaskGroup::getAssignee() const { return ""; }

std::string TaskGroup::getStatus() const { return ""; }

std::string TaskGroup::getDueDate() const { return ""; }