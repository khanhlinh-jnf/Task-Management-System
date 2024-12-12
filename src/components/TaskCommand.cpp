#include "TaskCommand.h"

// AddTaskCommand implementation

AddTaskCommand::AddTaskCommand() { taskManager = nullptr; }

AddTaskCommand::AddTaskCommand(TaskManager* _taskManager) {
  taskManager = _taskManager;
}

AddTaskCommand::~AddTaskCommand() { taskManager = nullptr; }

void AddTaskCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }
  taskManager->addTask();
}

// RemoveTaskCommand implementation

RemoveTaskCommand::RemoveTaskCommand() { taskManager = nullptr; }

RemoveTaskCommand::RemoveTaskCommand(TaskManager* _taskManager) {
  taskManager = _taskManager;
}

RemoveTaskCommand::~RemoveTaskCommand() { taskManager = nullptr; }

void RemoveTaskCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  int taskID;
  cout << "Please enter task ID to be removed: " << endl;
  cin >> taskID;
  taskManager->removeTask(taskID);
}

// UpdateTaskCommand implementation

UpdateTaskCommand::UpdateTaskCommand() { taskManager = nullptr; }

UpdateTaskCommand::UpdateTaskCommand(TaskManager* _taskManager) {
  taskManager = _taskManager;
}

UpdateTaskCommand::~UpdateTaskCommand() { taskManager = nullptr; }

void UpdateTaskCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  int taskID;
  cout << "Please enter task ID to be updated: " << endl;
  cin >> taskID;
  taskManager->updateTask(taskID);
}
