#include "builder.h"

TaskBuilder& TaskBuilder::setId(int id) {
  task->setId(id);
  return *this;
}

TaskBuilder& TaskBuilder::setTitle(const std::string& title) {
  task->setTitle(title);
  return *this;
}

TaskBuilder& TaskBuilder::setDescription(const std::string& description) {
  task->setDescription(description);
  return *this;
}

TaskBuilder& TaskBuilder::setAssignee(const std::string& assignee) {
  task->setAssignee(assignee);
  return *this;
}

TaskBuilder& TaskBuilder::setStatus(const std::string& status) {
  task->setStatus(status);
  return *this;
}

TaskBuilder& TaskBuilder::setDueDate(const std::string& dueDate) {
  task->setDueDate(dueDate);
  return *this;
}

Task TaskBuilder::build() { return *task; }
