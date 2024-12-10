#pragma once

#include <iostream>
#include <string>

#include "TaskComponent.h"

class Task : public TaskComponent {
 protected:
  int id;
  std::string title;
  std::string description;
  std::string assignee;
  std::string status;
  std::string dueDate;

 public:
  Task();
  Task(int id, std::string title, std::string description, std::string assignee,
       std::string status, std::string dueDate)
      : id(id),
        title(title),
        description(description),
        assignee(assignee),
        status(status),
        dueDate(dueDate) {}

  int getId() const { return id; }
  std::string getTitle() const { return title; }
  std::string getDescription() const { return description; }
  std::string getAssignee() const { return assignee; }
  std::string getStatus() const { return status; }
  std::string getDueDate() const { return dueDate; }

  void setId(int id) { this->id = id; }
  void setTitle(const std::string& title) { this->title = title; }
  void setDescription(const std::string& description) {
    this->description = description;
  }
  void setAssignee(const std::string& assignee) { this->assignee = assignee; }
  void setStatus(const std::string& status) { this->status = status; }
  void setDueDate(const std::string& dueDate) { this->dueDate = dueDate; }

  void display() const override {
    std::cout << "Task ID: " << id << ", Title: " << title
              << ", Description: " << description << ", Assignee: " << assignee
              << ", Status: " << status << ", Due Date: " << dueDate
              << std::endl;
  }
};