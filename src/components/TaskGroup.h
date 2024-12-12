#pragma once

#include <algorithm>
#include <vector>

#include "TaskComponent.h"

class TaskGroup : public TaskComponent {
 private:
  std::string title;
  std::vector<TaskComponent*> tasks;

 public:
  TaskGroup(const std::string& title);

  void add(TaskComponent* component) override;
  void remove(TaskComponent* component);
  TaskComponent* getChild(int index);
  std::string getTitle() const override;
  void display() const override;

  // Implement pure virtual functions
  void setId(int id) override;
  void setTitle(const std::string& title) override;
  void setDescription(const std::string& description) override;
  void setAssignee(const std::string& assignee) override;
  void setStatus(const std::string& status) override;
  void setDueDate(const std::string& dueDate) override;
  int getId() const override;
  std::string getDescription() const override;
  std::string getAssignee() const override;
  std::string getStatus() const override;
  std::string getDueDate() const override;
};

#include "TaskGroup.cpp"