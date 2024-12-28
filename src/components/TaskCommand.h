#pragma once

#include <iostream>

#include "TaskManager.h"

using namespace std;

class TaskCommand {
 protected:
  TaskManager* taskManager;

 public:
  virtual void execute() = 0;
};

class AddTaskCommand : public TaskCommand {
 public:
  AddTaskCommand();
  AddTaskCommand(TaskManager* _TaskManager);
  ~AddTaskCommand();

  void execute();
};

class RemoveTaskCommand : public TaskCommand {
 public:
  RemoveTaskCommand();
  RemoveTaskCommand(TaskManager* _taskManager);
  ~RemoveTaskCommand();

  void execute();
};

class UpdateTaskCommand : public TaskCommand {
 public:
  UpdateTaskCommand();
  UpdateTaskCommand(TaskManager* _taskManager);
  ~UpdateTaskCommand();

  void execute();
};

class DisplayTaskCommand : public TaskCommand {
  public:
    DisplayTaskCommand();
    DisplayTaskCommand(TaskManager* _taskManager);
    ~DisplayTaskCommand();

    void execute();
};

class CreateGroupCommand : public TaskCommand {
  public:
    CreateGroupCommand();
    CreateGroupCommand(TaskManager* _taskManager);
    ~CreateGroupCommand();

    void execute();
};

class AddTaskToGroupCommand : public TaskCommand {
  public:
    AddTaskToGroupCommand();
    AddTaskToGroupCommand(TaskManager* _taskManager);
    ~AddTaskToGroupCommand();

    void execute();
};

class AddGroupToGroupCommand : public TaskCommand {
  public:
    AddGroupToGroupCommand();
    AddGroupToGroupCommand(TaskManager* _taskManager);
    ~AddGroupToGroupCommand();

    void execute();
};

class DisplayGroupCommand : public TaskCommand {
  public:
    DisplayGroupCommand();
    DisplayGroupCommand(TaskManager* _taskManager);
    ~DisplayGroupCommand();

    void execute();
};

class DisplayAllGroupNameCommand : public TaskCommand {
  public:
    DisplayAllGroupNameCommand();
    DisplayAllGroupNameCommand(TaskManager* _taskManager);
    ~DisplayAllGroupNameCommand();

    void execute();
};

class DisplayAllTaskNameCommand : public TaskCommand {
  public:
    DisplayAllTaskNameCommand();
    DisplayAllTaskNameCommand(TaskManager* _taskManager);
    ~DisplayAllTaskNameCommand();

    void execute();
};
