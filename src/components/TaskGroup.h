#pragma once

#include <algorithm>
#include <vector>

#include "Task.h"
#include "TaskComponent.h"

class TaskGroup : public TaskComponent {
 private:
  int type = 1;  // 0 for task, 1 for group
  std::string title;
  std::vector<TaskComponent*> tasks;
  int id;

 public:
  TaskGroup(const std::string& title, int id);
  TaskGroup();

  void add(TaskComponent* component) override;
  void remove(TaskComponent* component);
  TaskComponent* getChild(int index);
  std::string getTitle() const override;
  void display(int ident = 0) const;
  void displayName(int ident = 0) const;

  // Implement pure virtual functions
  void setId(int id) override;
  void setTitle(const std::string& title) override;
  void setDescription(const std::string& description) override;
  void setAssignee(const std::string& assignee) override;
  void setStatus(const std::string& status) override;
  void setDueDate(const std::string& dueDate) override;
  int getId() const override;
  int getType() const;
  std::string getDescription() const override;
  std::string getAssignee() const override;
  std::string getStatus() const override;
  std::string getDueDate() const override;
  void writeToFile(std::ofstream& file) const override;
  void writeGroupToFile(std::ofstream& file) const;
  void readFromFile(std::ifstream& file);
};