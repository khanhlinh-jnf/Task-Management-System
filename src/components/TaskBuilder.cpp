#include "TaskBuilder.h"

// Constructor: Initializes the unique_ptr with a new Task
TaskBuilder::TaskBuilder() : task(std::make_unique<Task>()) {}

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

// Transfers ownership of the Task to the caller
std::unique_ptr<Task> TaskBuilder::build() {
  return std::move(task); // Transfers ownership of the unique_ptr
}