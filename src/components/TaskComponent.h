#pragma once

#include <string>
#include <fstream>
class TaskComponent {
 public:
  virtual ~TaskComponent() = default;
  virtual void setId(int id) = 0;
  virtual void setTitle(const std::string& title) = 0;
  virtual void setDescription(const std::string& description) = 0;
  virtual void setAssignee(const std::string& assignee) = 0;
  virtual void setStatus(const std::string& status) = 0;
  virtual void setDueDate(const std::string& dueDate) = 0;
  virtual int getId() const = 0;
  virtual std::string getTitle() const = 0;
  virtual std::string getDescription() const = 0;
  virtual std::string getAssignee() const = 0;
  virtual std::string getStatus() const = 0;
  virtual std::string getDueDate() const = 0;
  virtual int getType() const = 0;
  virtual void add(TaskComponent* component) {};
  virtual void remove(int id) {};
  virtual TaskComponent* get(int id) { return nullptr; };
  virtual void displayAll() const {};
  virtual void display(int indent) const = 0;
  virtual void displayName(int indent) const = 0;
  virtual void writeToFile(std::ofstream& file) const {};
  virtual void readFromFile(std::ifstream& file) {};
};
