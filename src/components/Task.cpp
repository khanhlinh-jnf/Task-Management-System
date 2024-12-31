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

int Task::getType() const { return type; }

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

void Task::display(int indent) const {
  std::string indentation(indent, ' ');
  std::cout << std::endl;
  std::cout << indentation << "Task ID: " << id << "\n"
            << indentation << "Title: " << title << "\n"
            << indentation << "Description: " << description << "\n"
            << indentation << "Assignee: " << assignee << "\n"
            << indentation << "Status: " << status << "\n"
            << indentation << "Due Date: " << dueDate << std::endl;
}

void Task::displayName(int indent) const {
  std::string indentation(indent, ' ');
  std::cout << std::endl;
  std::cout << indentation << "Task ID: " << id << "\n"
            << indentation << "Title: " << title << std::endl;
}

void Task::writeToFile(std::ofstream &file) const {
  file << type << "\n"
       << id << "\n"
       << title << "\n"
       << description << "\n"
       << assignee << "\n"
       << status << "\n"
       << dueDate << "\n";
}

void Task::readFromFile(std::ifstream &file) {
  file >> id;
  file.ignore();
  std::getline(file, title);
  std::getline(file, description);
  std::getline(file, assignee);
  std::getline(file, status);
  std::getline(file, dueDate);
}