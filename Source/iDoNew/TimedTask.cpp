#include "TimedTask.h"
 
TimedTask::TimedTask(){
	TimedTask::description = "\0";
	TimedTask::endTime = NULL;
	TimedTask::startTime = NULL;
}
TimedTask::TimedTask(string desc, tm *start, tm *end){
	TimedTask::description = desc;
	TimedTask::endTime = end;
	TimedTask::startTime = start;
}
string TimedTask::getDesc(){

	return TimedTask::description;
}

tm* TimedTask::getEnd(){

	return TimedTask::endTime;
}

tm* TimedTask::getStart(){

	return TimedTask::startTime;
}

void TimedTask::setDesc(string desc){

	TimedTask::description = desc;
}
void TimedTask::setStart(tm* start){

	TimedTask::startTime = start;
}

void TimedTask::setEnd(tm* end){

	TimedTask::endTime = end;
}

bool TimedTask::operator==(Task* t1){

	if((strcmpi(t1->getDesc().c_str(), this->getDesc().c_str()) == 0) &&
		(t1->getEnd() == this->getEnd()) && 
		(t1->getStart() == this->getStart()))
		return true;
	else return false;
}

void TimedTask::operator=(Task* t1){

	this->description = t1->getDesc().c_str();
	this->endTime = t1->getEnd();
	this->startTime = t1->getStart();
}