#include "Search.h"

 
void Search::setInputList(vector<Task*> list){

	Search::inputList = list;
}

vector<Task*> Search::getInputList(){
	return Search::inputList;
}
bool Search::executeSearch(string description){

	for(int i =  0; i < Search::inputList.size(); i++){
		if(strstr(Search::inputList[i]->getDesc().c_str(), description.c_str()) != NULL ){
			Search::searchResults.push_back(Search::inputList[i]);
			Search::resultIndices.push_back(i);
		}
	}
	return true;
}
 
bool Search::executeSearchTime(Task* query) throw(string){
	bool returnVal = true;
	assert(query != NULL);
	tm* currentTime = query->getStart();
	assert ( currentTime != NULL);
	makeConvertible(currentTime);
	for(int i =  0; i < Search::inputList.size(); i++) {
			if(Search::inputList[i]->getStart()) {
				tm* tempTime = Search::inputList[i]->getStart();
				int tempHour = tempTime->tm_hour;
				int tempMin = tempTime->tm_min;
				formatMonYear(tempTime);
				makeConvertible(tempTime);
				if(!difftime(mktime(tempTime),mktime(query->getStart()))) {
					revertToOriginalTime( tempTime, tempHour, tempMin);
					Search::searchResults.push_back(Search::inputList[i]);
					Search::resultIndices.push_back(i);
				}
				else {
					revertToOriginalTime(tempTime,tempHour, tempMin);
				}
				
			}

			else if(Search::inputList[i]->getEnd())	{
				tm* tempTime = Search::inputList[i]->getEnd();
				int tempHour = tempTime->tm_hour;
				int tempMin = tempTime->tm_min;
				formatMonYear(tempTime);
				makeConvertible(tempTime);
				if(!difftime(mktime(tempTime),mktime(query->getStart()))) { 
					revertToOriginalTime(tempTime,tempHour, tempMin);
					Search::searchResults.push_back(Search::inputList[i]);
					Search::resultIndices.push_back(i);
				}
				else {
					revertToOriginalTime(tempTime,tempHour, tempMin);
				}
			}
			else {
				returnVal = false;
			}
	}
	return returnVal;
}
 
bool Search::executeSearch(Task* query){

	for(int i =  0; i < Search::inputList.size(); i++){
		if((Search::inputList[i]) == query){
			Search::searchResults.push_back(Search::inputList[i]);
			Search::resultIndices.push_back(i);
		}
}
	return true;
}
vector<int> Search::getIndices(){
	return Search::resultIndices;
}

vector<Task*> Search::getResults(){
	return Search::searchResults;
}

void Search::clearSearchResults(){
	
	if(searchResults.size() != 0){
		Search::searchResults.clear();
	}
	
	if(resultIndices.size() != 0){
		Search::resultIndices.clear();
	}
}
 
void Search::makeConvertible( tm *time) {
		assert (time != NULL);
		time->tm_sec=0;
		time->tm_isdst=-1;
		time->tm_wday=0;
		time->tm_yday=0;
		time->tm_hour=0;
		time->tm_min=0;

}

void Search::formatMonYear(tm *time) {
	assert (time != NULL);
	time->tm_year-=1900;
	time->tm_mon-=1;

}

void Search::revertToOriginalTime( tm *time, int hour, int min) {
	assert (time != NULL);
	time->tm_mon += 1;
	time->tm_year += 1900;
	time->tm_hour = hour;
	time->tm_min = min;
}