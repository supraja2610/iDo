#include "Sort.h"

 
Sort::Sort(){

	Sort::order = 'a';
	Sort::criteria = "time";
}

void Sort::setInputList(vector<Task*> list){

	Sort::inputList = list;
}

void Sort::setCriteria(string criteria){

	Sort::criteria = criteria.c_str();
}

void Sort::setOrder(char order){

	Sort::order = order;
}

vector <Task*> Sort::executeSort(){
	
	if(strcmpi(Sort::criteria.c_str(), "time") == 0){
		if(tolower(Sort::order) == 'a')
			sortByTimeAsc();
		else if(tolower(Sort::order) == 'd')
				sortByTimeDesc();
	}
	else if(strcmpi(Sort::criteria.c_str(), "description") == 0){
			if(tolower(Sort::order) == 'a')
				Sort::sortByDescripAsc();
			else if(tolower(Sort::order) == 'd')
					Sort::sortByDescripDesc();
	}
	return inputList;
}

void Sort::sortByDescripAsc(){

	for(int i = 0; i < Sort::inputList.size() - 1; i++){
		for(int j = 0; j < Sort::inputList.size() - 1 - i; j++){
			if(strcmpi(Sort::inputList[j]->getDesc().c_str(), Sort::inputList[j + 1]->getDesc().c_str()) > 0) {
				Task *temp = Sort::inputList[j];
				Sort::inputList[j] = Sort::inputList[j + 1];
				Sort::inputList[j + 1] = temp;
			}
		}
	}
}

void Sort::sortByDescripDesc(){

	for(int i = 0; i < Sort::inputList.size() - 1; i++){
		for(int j = 0; j < Sort::inputList.size() - 1 - i; j++){
			if(strcmpi(Sort::inputList[j]->getDesc().c_str(), Sort::inputList[j + 1]->getDesc().c_str()) < 0) {
				Task *temp = Sort::inputList[j];
				Sort::inputList[j] = Sort::inputList[j + 1];
				Sort::inputList[j + 1] = temp;
			}
		}
	}
}
 
void Sort::sortByTimeAsc(){
	bool isGreater = false;
	for(int i = 0; i < Sort::inputList.size() - 1; i++){
		for(int j = 0; j < Sort::inputList.size() - 1 - i; j++){
			//if first parameter greater than second parameter
			if( ! inputList[j]->getEnd()) {
				isGreater = true;
			}
			else if (! inputList[j+1]->getEnd()) {
				isGreater = false;
			}
			else {
				isGreater = isFirstGreater(*(inputList[j]->getEnd()),*(inputList[j+1]->getEnd()));
			}
			if(isGreater) {
				Task *temp = Sort::inputList[j];
				Sort::inputList[j] = Sort::inputList[j + 1];
				Sort::inputList[j + 1] = temp;
			}
		}
	}
//	return inputList;
}
 
void Sort::sortByTimeDesc() {
	for(int i = 0; i < Sort::inputList.size() - 1; i++){
		for(int j = 0; j < Sort::inputList.size() - 1 - i; j++){
			//if first parameter less than second parameter
			if(!isFirstGreater(*(inputList[j]->getEnd()),*(inputList[j+1]->getEnd()))) {
				Task *temp = Sort::inputList[j];
				Sort::inputList[j] = Sort::inputList[j + 1];
				Sort::inputList[j + 1] = temp;
			}
		}
	}
}
 
bool Sort::isFirstGreater(tm t1, tm t2) {

t1.tm_isdst=-1;
t1.tm_year-=1900;
t1.tm_sec=0;
t1.tm_wday=0;
t1.tm_mon-=1;
t1.tm_yday=0;

t2.tm_isdst=-1;
t2.tm_year-=1900;
t2.tm_sec=0;
t2.tm_wday=0;
t2.tm_mon-=1;
t2.tm_yday=0;
bool returnVal=false;
if( difftime(mktime(&t1),mktime(&t2))>0)
	returnVal = true;
else
	returnVal = false;
return returnVal;
}

