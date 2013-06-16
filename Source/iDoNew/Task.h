#ifndef TASK_H
#define TASK_H
#include <iostream>
using namespace std;
#include <time.h>

class Task
{
protected:
	string description;
	tm* startTime, *endTime;
public:
	virtual string getDesc() = 0;
	virtual tm* getStart() = 0;
	virtual tm* getEnd() = 0;
	virtual void setDesc(string desc) = 0;
	virtual void setStart(tm* start) = 0;
	virtual void setEnd(tm* end) = 0;
	virtual bool operator==(Task* t1) = 0;
	virtual void operator=(Task* t1) = 0;
};

#endif