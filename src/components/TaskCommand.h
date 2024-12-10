#pragma once

#include <iostream>

#include "singleton.h"

using namespace std;

class TaskCommand {
	protected:
		TaskManager* taskManager;
		Task task;
	public:
		virtual void execute() = 0;
};

class AddTaskCommand : public TaskCommand {
 public:
  AddTaskCommand();
  AddTaskCommand(TaskManager* _TaskManager, Task _task);
  ~AddTaskCommand();

  void execute();
};

class RemoveTaskCommand : public TaskCommand {
 public:
  RemoveTaskCommand();
  RemoveTaskCommand(TaskManager* _taskManager, Task _task);
  ~RemoveTaskCommand();

  void execute();
};

class UpdateTaskCommand : public TaskCommand {
 public:
  UpdateTaskCommand();
  UpdateTaskCommand(TaskManager* _taskManager, Task _task);
  ~UpdateTaskCommand();

  void execute();
};