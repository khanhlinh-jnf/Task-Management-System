#pragma once

#include <iostream>

<<<<<<< HEAD
#include "TaskManager.h"
=======
#include "singleton.h"
>>>>>>> 3ea4f7f (Implement TaskCommand interface and classes for update, remove and add task operations.)

using namespace std;

class TaskCommand {
<<<<<<< HEAD
 protected:
  TaskManager* taskManager;

 public:
  virtual void execute() = 0;
=======
	protected:
		TaskManager* taskManager;
		Task task;
	public:
		virtual void execute() = 0;
>>>>>>> 3ea4f7f (Implement TaskCommand interface and classes for update, remove and add task operations.)
};

class AddTaskCommand : public TaskCommand {
 public:
  AddTaskCommand();
<<<<<<< HEAD
  AddTaskCommand(TaskManager* _TaskManager);
=======
  AddTaskCommand(TaskManager* _TaskManager, Task _task);
>>>>>>> 3ea4f7f (Implement TaskCommand interface and classes for update, remove and add task operations.)
  ~AddTaskCommand();

  void execute();
};

class RemoveTaskCommand : public TaskCommand {
 public:
  RemoveTaskCommand();
<<<<<<< HEAD
  RemoveTaskCommand(TaskManager* _taskManager);
=======
  RemoveTaskCommand(TaskManager* _taskManager, Task _task);
>>>>>>> 3ea4f7f (Implement TaskCommand interface and classes for update, remove and add task operations.)
  ~RemoveTaskCommand();

  void execute();
};

class UpdateTaskCommand : public TaskCommand {
 public:
  UpdateTaskCommand();
<<<<<<< HEAD
  UpdateTaskCommand(TaskManager* _taskManager);
  ~UpdateTaskCommand();

  void execute();
};

#include "TaskCommand.cpp"
=======
  UpdateTaskCommand(TaskManager* _taskManager, Task _task);
  ~UpdateTaskCommand();

  void execute();
};
>>>>>>> 3ea4f7f (Implement TaskCommand interface and classes for update, remove and add task operations.)
