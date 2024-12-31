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

  vector<string> data(5, "");
  int choice = -1;
  string temp;
  cout << "Create new task \n"
       << "1. Set title\n"
       << "2. Set description\n"
       << "3. Set assignee\n"
       << "4. Set status\n"
       << "5. Set due date\n"
       << "6. Save task\n"
       << endl;
  while (true) {
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
      case 1:
        cout << "Enter title: ";
        getline(std::cin, temp);
        data[0] = temp;
        break;
      case 2:
        cout << "Enter description: ";
        getline(std::cin, temp);
        data[1] = temp;
        break;
      case 3:
        cout << "Enter assignee: ";
        getline(std::cin, temp);
        data[2] = temp;
        break;
      case 4:
        cout << "Enter status: ";
        getline(std::cin, temp);
        data[3] = temp;
        break;
      case 5:
        cout << "Enter due date: ";
        getline(std::cin, temp);
        data[4] = temp;
        break;
      case 6:
        taskManager->addTask(data);
        return;
      default:
        cout << "Invalid choice!" << std::endl;
        break;
    }
  }
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
  cout << "Please enter task ID to be removed: ";
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
  cout << "Please enter task ID to be updated: ";
  cin >> taskID;

  vector<string> data(5, "");
  vector<int> record(5, -1);
  TaskComponent* task = taskManager->getTask(taskID);
  if (task) {
    string temp;
    int choice = -1;
    cout << "Update task \n"
         << "1. Set title\n"
         << "2. Set description\n"
         << "3. Set assignee\n"
         << "4. Set status\n"
         << "5. Set due date\n"
         << "6. Save task\n"
         << endl;
    while (true) {
      cout << "Enter choice: ";
      cin >> choice;
      cin.ignore();
      switch (choice) {
        case 1:
          cout << "Enter title: ";
          getline(cin, temp);
          data[0] = temp;
          record[0] = 1;
          break;
        case 2:
          cout << "Enter description: ";
          getline(cin, temp);
          data[1] = temp;
          record[1] = 1;
          break;
        case 3:
          cout << "Enter assignee: ";
          getline(cin, temp);
          data[2] = temp;
          record[2] = 1;
          break;
        case 4:
          cout << "Enter status: ";
          getline(cin, temp);
          data[3] = temp;
          record[3] = 1;
          break;
        case 5:
          cout << "Enter due date: ";
          getline(cin, temp);
          data[4] = temp;
          record[4] = 1;
          break;
        case 6:
          taskManager->updateTask(task, data, record);
          return;
        default:
          cout << "Invalid choice!" << endl;
          break;
      }
    }
  } else {
    cout << "Task not found!" << endl;
  }
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
  int taskID;
  cout << "Please enter task ID to be displayed: ";
  cin >> taskID;
  TaskComponent* task = taskManager->getTask(taskID);
  if (task) {
    task->display(0);
  } else {
    cout << "Task not found!" << endl;
  }
  cout << "-----------------------------------" << endl;
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
  cout << "Please enter group title: ";
  getline(cin, title);
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
  cout << "Please enter task ID to be added: ";
  cin >> taskID;
  cout << "Please enter group ID: ";
  cin >> groupID;

  TaskComponent* task = taskManager->getTask(taskID);
  TaskComponent* group = taskManager->getGroup(groupID);

  if (task && group) {
    TaskGroup* taskGroup = dynamic_cast<TaskGroup*>(group);
    if (taskGroup) {
      taskManager->addTaskToGroup(task, taskGroup);
    } else {
      cout << "Group ID does not correspond to a group!" << endl;
      return;
    }
  } else {
    cout << "Task or group ID not found!" << endl;
    return;
  }
  cout << "Added task " << taskID << " to group " << groupID << " successfully!"
       << endl;
  cout << "-----------------------------------" << endl;
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
  cout << "Please enter sub group ID to be added: ";
  cin >> groupID;
  cout << "Please enter parent group ID: ";
  cin >> parentGroupID;

  TaskComponent* group = taskManager->getGroup(groupID);
  TaskComponent* parentGroup = taskManager->getGroup(parentGroupID);

  if (group && parentGroup) {
    TaskGroup* taskParentGroup = dynamic_cast<TaskGroup*>(parentGroup);
    if (taskParentGroup) {
      taskParentGroup->add(group);
    } else {
      cout << "Parent group ID does not correspond to a group!" << endl;
      return;
    }
  } else {
    cout << "Group or parent group ID not found!" << endl;
    return;
  }
  cout << "Added group " << groupID << " to parent group " << parentGroupID
       << " successfully!" << endl;
  cout << "-----------------------------------" << endl;
}

// DisplayGroupCommand implementation
DisplayAllGroupNameCommand::DisplayAllGroupNameCommand() {
  taskManager = nullptr;
}
DisplayAllGroupNameCommand::DisplayAllGroupNameCommand(
    TaskManager* _taskManager) {
  taskManager = _taskManager;
}
DisplayAllGroupNameCommand::~DisplayAllGroupNameCommand() {
  taskManager = nullptr;
}

void DisplayAllGroupNameCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  taskManager->displayAllGroupName();
}

// DisplayGroupCommand implementation
DisplayGroupCommand::DisplayGroupCommand() { taskManager = nullptr; }
DisplayGroupCommand::DisplayGroupCommand(TaskManager* _taskManager) {
  taskManager = _taskManager;
}
DisplayGroupCommand::~DisplayGroupCommand() { taskManager = nullptr; }
void DisplayGroupCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  int groupID;
  cout << "Please enter group ID to be displayed: ";
  cin >> groupID;
  taskManager->displayGroup(groupID);
}

// DisplayAllTaskNameCommand implementation
DisplayAllTaskNameCommand::DisplayAllTaskNameCommand() {
  taskManager = nullptr;
}
DisplayAllTaskNameCommand::DisplayAllTaskNameCommand(
    TaskManager* _taskManager) {
  taskManager = _taskManager;
}
DisplayAllTaskNameCommand::~DisplayAllTaskNameCommand() {
  taskManager = nullptr;
}

void DisplayAllTaskNameCommand::execute() {
  if (!taskManager) {
    cout << "Task manager not linked!" << endl;
    return;
  }

  taskManager->displayAllTaskName();
}
