#include "Task.h"

#include <iostream>
#include <sstream>

Task::Task()
    : id(0),
      title(""),
      description(""),
      assignee(""),
      status("Pending"),
      dueDate("") {}

Task::Task(int id, const std::string &title, const std::string &description,
           const std::string &assignee, const std::string &status,
           const std::string &dueDate)
    : id(id),
      title(title),
      description(description),
      assignee(assignee),
      status(status),
      dueDate(dueDate) {}

int Task::getId() const { return id; }
void Task::setId(int id) { this->id = id; }

std::string Task::getTitle() const { return title; }
void Task::setTitle(const std::string &title) { this->title = title; }

std::string Task::getDescription() const { return description; }
void Task::setDescription(const std::string &description) {
  this->description = description;
}

std::string Task::getAssignee() const { return assignee; }
void Task::setAssignee(const std::string &assignee) {
  this->assignee = assignee;
}

std::string Task::getStatus() const { return status; }
void Task::setStatus(const std::string &status) { this->status = status; }

std::string Task::getDueDate() const { return dueDate; }
void Task::setDueDate(const std::string &dueDate) { this->dueDate = dueDate; }

void Task::display() const {
  std::cout << "Task ID: " << id << "\n"
            << "Title: " << title << "\n"
            << "Description: " << description << "\n"
            << "Assignee: " << assignee << "\n"
            << "Status: " << status << "\n"
            << "Due Date: " << dueDate << std::endl;
}
