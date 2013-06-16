#ifndef TIMED_H
#define TIMED_H
#include "Task.h"



class TimedTask : public Task
{
public:
	TimedTask();
	TimedTask(string, tm*, tm*);
	string getDesc();
	tm* getStart();
	tm* getEnd();
	void setDesc(string desc);
	void setStart(tm* start);
	void setEnd(tm* end);
	bool TimedTask::operator==(Task* t1);
	void operator=(Task* t1);

};
#endif