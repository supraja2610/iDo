#ifndef LOGIC_H_
#define LOGIC_H_

#include <iostream>
#include <string>
#include <cstring>
#include <assert.h>
#include <exception>
#include <time.h>
#include <time.h>
#include <vector>
#include <stack>

using namespace std;

#include "UI.h"
#include "Search.h"
#include "FileIO.h"
#include "Sort.h"
#include "CommandProcessor.h"
#include "Task.h"
#include "TimedTask.h"
#include "DeadlinedTask.h"
#include "FloatingTask.h"


class Logic
{
	static const string TASK_FILE_NAME;
	UI UIObj;
	Search searchObj;
	FileIO fileObj;
	Sort sortObj;
	vector<Task*> taskList; 
	string userInput;
	CommandProcessor cmdObj;
	Task* userInputTask, *userInputNewTask ;

	static enum CommandType {
		ADD, REMOVE, EDIT, SEARCH, UNDO, REDO, ALT, EXIT , VIEW
	} ;

	static const string FILENAME_ADD_ALTERNATES ;
	static const string FILENAME_REMOVE_ALTERNATES ;
	static const string FILENAME_EDIT_ALTERNATES ;
	static const string FILENAME_EXIT_ALTERNATES ;
	static const string FILENAME_SEARCH_ALTERNATES ;
	static const string FILENAME_ALTERNATE_ALTERNATES ;
	static const string FILENAME_UNDO_ALTERNATES ;
	static const string FILENAME_REDO_ALTERNATES ;
	static const int MAX_KEYWORD_SIZE = 100 ;
	//structure to hold the type of operation, the task, and index of position in task list being used by th tassk (used by undo and redo stack)
	struct Input
	{
		CommandType type;
		Task* taskObj;
		int index;
	};

	//Stores each operation performed in a stack for undo operation
	stack < Logic::Input> undoStack;
	//Stores undo operations in a stack to perform redo operation
	stack <Input> redoStack;
	//Variable to hold each operation along with operation performed to enable undo/ redo
	Input userStruct;
	//executes all the operations
    bool execute(string,Task*, Task*);
	//determines the command type
	CommandType determineCommand(string);

	void deleteExpiredTasks() ;
	
	void setRedoStack(CommandType,Task*,int);
	void setUndoStack(CommandType,Task*,int);
	string getUndoStack();
	//retrieves current time
	tm* getCurrentTime();
	//updates the home screen with the edited task list
	void updateHomeScreen();
	//writes the modified list to file
	void updateTaskFile();
	//sets the search list
	void setSearchObj(Task*);

public:
	Logic();
	int logicMain();
        
	bool addTask(Task*);
	bool search(Task*);
	void editTask(int);
	bool findToDelete(Task*);
	void deleteTask(int);
	bool findToEdit(Task*, Task*);


	bool createAlternateKeyword(Task *) ;	

	bool isUserIndexValid(int, vector<int>) ;
	
	bool undoTask ();
	bool redoTask();
	
};

#endif
