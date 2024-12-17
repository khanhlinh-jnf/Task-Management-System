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

// DisplayTaskCommand implementation

DisplayTaskCommand::DisplayTaskCommand() { taskManager = nullptr; }

DisplayTaskCommand::DisplayTaskCommand(TaskManager* _taskManager) {
  taskManager = _taskManager;
}

DisplayTaskCommand::~DisplayTaskCommand() { taskManager = nullptr; }

void DisplayTaskCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  taskManager->displayAllTasks();
}

// CreateGroupCommand implementation

CreateGroupCommand::CreateGroupCommand() { taskManager = nullptr; }

CreateGroupCommand::CreateGroupCommand(TaskManager* _taskManager) {
  taskManager = _taskManager;
}

CreateGroupCommand::~CreateGroupCommand() { taskManager = nullptr; }

void CreateGroupCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  string title;
  cout << "Please enter group title: " << endl;
  cin >> title;
  taskManager->createTaskGroup(title);
}

// AddTaskToGroupCommand implementation

AddTaskToGroupCommand::AddTaskToGroupCommand() { taskManager = nullptr; }

AddTaskToGroupCommand::AddTaskToGroupCommand(TaskManager* _taskManager) {
  taskManager = _taskManager;
}

AddTaskToGroupCommand::~AddTaskToGroupCommand() { taskManager = nullptr; }

void AddTaskToGroupCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  int taskID, groupID;
  cout << "Please enter task ID to be added: " << endl;
  cin >> taskID;
  cout << "Please enter group ID: " << endl;
  cin >> groupID;

  TaskComponent* task = taskManager->getTask(taskID);
  TaskComponent* group = taskManager->getTask(groupID);

  if (task && group) {
    TaskGroup* taskGroup = dynamic_cast<TaskGroup*>(group);
    if (taskGroup) {
      taskManager->addTaskToGroup(task, taskGroup);
    } else {
      cout << "Group ID does not correspond to a group!" << endl;
    }
  } else {
    cout << "Task or group ID not found!" << endl;
  }
}

// AddGroupToGroupCommand implementation

AddGroupToGroupCommand::AddGroupToGroupCommand() { taskManager = nullptr; }

AddGroupToGroupCommand::AddGroupToGroupCommand(TaskManager* _taskManager) {
  taskManager = _taskManager;
}

AddGroupToGroupCommand::~AddGroupToGroupCommand() { taskManager = nullptr; }

void AddGroupToGroupCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  int groupID, parentGroupID;
  cout << "Please enter sub group ID to be added: " << endl;
  cin >> groupID;
  cout << "Please enter parent group ID: " << endl;
  cin >> parentGroupID;

  TaskComponent* group = taskManager->getTask(groupID);
  TaskComponent* parentGroup = taskManager->getTask(parentGroupID);

  if (group && parentGroup) {
    TaskGroup* taskParentGroup = dynamic_cast<TaskGroup*>(parentGroup);
    if (taskParentGroup )
    {
      taskParentGroup->add(group);
    } else {
      cout << "Parent group ID does not correspond to a group!" << endl;
    }
  }
  else {
    cout << "Group or parent group ID not found!" << endl;
  }
}