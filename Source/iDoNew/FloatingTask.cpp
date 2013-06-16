#include "FloatingTask.h"
 
FloatingTask::FloatingTask(){
	FloatingTask::description = "\0";
	FloatingTask::endTime = NULL;
	FloatingTask::startTime = NULL;
}
FloatingTask::FloatingTask(string desc){
	
	FloatingTask::description = desc;
	FloatingTask::endTime = NULL;
	FloatingTask::startTime = NULL;
}
string FloatingTask::getDesc(){

	return FloatingTask::description;
}

tm* FloatingTask::getEnd(){

	return FloatingTask::endTime;
}

tm* FloatingTask::getStart(){

	return FloatingTask::startTime;
}

void FloatingTask::setDesc(string desc){

	FloatingTask::description = desc;
}
void FloatingTask::setStart(tm* start){

	FloatingTask::startTime = start;
}

void FloatingTask::setEnd(tm* end){

	FloatingTask::endTime = end;
}

bool FloatingTask::operator==(Task* t1){

	if((strcmpi(t1->getDesc().c_str(), this->getDesc().c_str()) == 0) &&
		(t1->getEnd() == this->getEnd()) && 
		(t1->getStart() == this->getStart()))
		return true;
	else return false;
}

void FloatingTask::operator=(Task* t1){

	this->description = t1->getDesc().c_str();
	this->endTime = t1->getEnd();
	this->startTime = t1->getStart();
}