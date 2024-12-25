#pragma once

#include "Task.h"
#include <memory>

class TaskBuilder {
 private:
  std::unique_ptr<Task> task; // Smart pointer to the Task object

 public:
  TaskBuilder();
  
  TaskBuilder& setId(int id);
  TaskBuilder& setTitle(const std::string& title);
  TaskBuilder& setDescription(const std::string& description);
  TaskBuilder& setAssignee(const std::string& assignee);
  TaskBuilder& setStatus(const std::string& status);
  TaskBuilder& setDueDate(const std::string& dueDate);

  std::unique_ptr<Task> build(); // Returns ownership of the Task
};
