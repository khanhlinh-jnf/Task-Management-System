#pragma once

#include "task.h"

class TaskBuilder {
 protected:
  Task* task;

 public:
  TaskBuilder& setId(int id);
  TaskBuilder& setTitle(const std::string& title);
  TaskBuilder& setDescription(const std::string& description);
  TaskBuilder& setAssignee(const std::string& assignee);
  TaskBuilder& setStatus(const std::string& status);
  TaskBuilder& setDueDate(const std::string& dueDate);
  Task build();
};