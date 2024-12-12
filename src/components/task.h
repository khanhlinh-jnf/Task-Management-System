#pragma once

#include <string>

#include "TaskComponent.h"

class Task : public TaskComponent {
 private:
  int id;
  std::string title;
  std::string description;
  std::string assignee;
  std::string status;
  std::string dueDate;

 public:
  // Constructors
  Task();
  Task(int id, const std::string &title, const std::string &description,
       const std::string &assignee, const std::string &status,
       const std::string &dueDate);

  // Getters and setters
  int getId() const;
  void setId(int id);

  std::string getTitle() const;
  void setTitle(const std::string &title);

  std::string getDescription() const;
  void setDescription(const std::string &description);

  std::string getAssignee() const;
  void setAssignee(const std::string &assignee);

  std::string getStatus() const;
  void setStatus(const std::string &status);

  std::string getDueDate() const;
  void setDueDate(const std::string &dueDate);

  // Displays task details
  void display(int indent = 0) const;
};   

#include "Task.cpp"