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

#include "TaskCommand.cpp"