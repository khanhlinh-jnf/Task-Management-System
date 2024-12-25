#include "header.h"

int main() {
  TaskManager* manager = TaskManager::getInstance();

  // Initializing command objects
  std::vector<TaskCommand*> cmdObjects;
  cmdObjects.push_back(new AddTaskCommand(manager));
  cmdObjects.push_back(new RemoveTaskCommand(manager));
  cmdObjects.push_back(new UpdateTaskCommand(manager));
  cmdObjects.push_back(new DisplayTaskCommand(manager));
  cmdObjects.push_back(new CreateGroupCommand(manager));
  cmdObjects.push_back(new AddTaskToGroupCommand(manager));
  cmdObjects.push_back(new AddGroupToGroupCommand(manager));

  Gui gui(manager, cmdObjects);
  gui.initialize();

  while (!WindowShouldClose()) {
    gui.update([]() {
      // Update logic here
    });
    gui.draw();
  }

  gui.shutdown();

  return 0;
}