#pragma once

class TaskComponent {
 public:
  virtual ~TaskComponent() {}
  virtual void display() const = 0;
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
};