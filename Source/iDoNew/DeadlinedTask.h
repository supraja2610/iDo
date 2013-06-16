#ifndef DEADLINED_H
#define DEADLINED_H
#include "Task.h"

class DeadlinedTask :public Task
{
public:
	DeadlinedTask();
	DeadlinedTask(string, tm*);
	string getDesc();
	tm* getStart();
	tm* getEnd();
	void setDesc(string desc);
	void setStart(tm* start);
	void setEnd(tm* end);
	bool DeadlinedTask::operator==(Task* t1);
	void operator=(Task* t1);
};
#endif
//deadline stored in Start time