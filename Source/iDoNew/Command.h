#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>
#include <vector>
#include "Task.h"
#include "Sort.h"
#include "Search.h"
#include "FileIO.h"
#include "UI.h"

using namespace std ;

//abstract Command class

//how about instead the Command class can have all functions - add, delete, findtodelete etc.

class Command 
{
	
protected:
	vector<Task*> tasksInvolved ;
	//indices of the tasksInvolved in the MAIN list
	//this is set where? in cmd processor? nooo cannot
	//needs to be done in the execute() part so that when u want to undo an 'add' u can do so
	//for delete, u want to add again if u want to undo, so u just insert and the old index using vector
	vector<int> taskIndices ;
	//state after the command, state before the command - each in one vector 
	//in execute, store new state in 'after' vector
	//in undo, assign 'before vector to 'current' vector 
	FileIO fileHandler ; 
	Search searcher ;

public:

	//pure virtual functions, Command class cannot be instantiated
	virtual bool execute(vector<Task*>, UI) = 0 ;
	virtual bool undo(vector<Task*>, UI) = 0 ; 
	virtual vector<Task*> getTasksInvolved() = 0 ;
	virtual vector<int> getTaskIndices() = 0  ;
	virtual void setTasksInvolved(vector<Task*>) = 0 ;
	virtual void setTaskIndices(vector<int>) = 0 ;

	//getters and setters for these
} ;


#endif