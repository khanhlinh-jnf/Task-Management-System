#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Task{
	protected:
	int id;
	string title;
	string description;
	string assignee;
	string status;
	string dueDate;

	public:
	int getId();
};