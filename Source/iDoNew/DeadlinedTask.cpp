#include "DeadlinedTask.h"
// 
DeadlinedTask::DeadlinedTask(){
	DeadlinedTask::startTime = NULL;
	DeadlinedTask::endTime = NULL;
	DeadlinedTask::description = "\0";
}

DeadlinedTask::DeadlinedTask(string desc, tm* end){
	DeadlinedTask::description = desc;
	DeadlinedTask::endTime = end;
	DeadlinedTask::startTime = NULL;
}
string DeadlinedTask::getDesc(){

	return DeadlinedTask::description;
}

tm* DeadlinedTask::getEnd(){

	return DeadlinedTask::endTime;
}

tm* DeadlinedTask::getStart(){

	return DeadlinedTask::startTime;
}

void DeadlinedTask::setDesc(string desc){

	DeadlinedTask::description = desc;
}
void DeadlinedTask::setStart(tm* start){

	DeadlinedTask::startTime = start;
}

void DeadlinedTask::setEnd(tm* end){

	DeadlinedTask::endTime = end;
}

bool DeadlinedTask::operator==(Task* t1){

	if((strcmpi(t1->getDesc().c_str(), this->getDesc().c_str()) == 0) &&
		(t1->getEnd() == this->getEnd()) && 
		(t1->getStart() == this->getStart()))
		return true;
	else return false;
}

void DeadlinedTask::operator=(Task* t1){

	this->description = t1->getDesc().c_str();
	this->endTime = t1->getEnd();
	this->startTime = t1->getStart();
}