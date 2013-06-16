#include "FileIO.h"
#include "FloatingTask.h"
#include "DeadlinedTask.h"
#include "TimedTask.h"


const int MAX_INPUT_SIZE = 100;
const string TASK_LOG_FILE_NAME = "Input.txt";
const string ERROR_LOG_FILE_NAME = "Error.txt";

 
vector<Task*> FileIO::getTaskList(){

	return FileIO::taskList;

}

 
vector<string> FileIO::readFromFile() {

	ifstream fin(fileName, ios::in) ;
	char line[MAX_CHAR_IN_LINE] ;
	string strLine ;
	vector<string> fileContents ;
	while(fin.getline(line, MAX_CHAR_IN_LINE)) {
		strLine = convertToString(line) ;
		fileContents.push_back(strLine) ;
	}

    fin.close() ;
	return fileContents ;
}

void FileIO::writeToFile(const char * word) {
	
	ofstream fout(fileName, ios::app|ios::out) ;
	
	fout << word << endl ; 

	fout.close() ;
}
 
void FileIO::setFileName(string fileName){
	this->fileName = fileName.c_str();
}
void FileIO::setTaskList(vector<Task*>& list){
	this->taskList = list;
}
 void FileIO::readList(){
	ifstream fin(FileIO::fileName);
	char fileInput[MAX_INPUT_SIZE];
	string day, month, year, hour, min;
	int check = 1;
	string description;
	tm *start = new tm, *end = new tm;
	while(fin.getline(fileInput, MAX_INPUT_SIZE)){
		if(check == 1){
			description = fileInput;
			check = 2;
		}
		else if(check == 2){
			day = fileInput;
			if(strcmpi(day.c_str(), "0") == 0){
				delete start;
				start = NULL;
				check = 7;
			}
			else{
				
				start->tm_mday = atoi(day.c_str());
				check = 3;
			}

			
		}
		else if(check == 3){
			month = fileInput;
			start->tm_mon = atoi(month.c_str());
			check = 4;
		}
		else if(check == 4){
			year = fileInput;
			start->tm_year = atoi(year.c_str());
			check = 5;
		}
		else if(check == 5){
			hour = fileInput;
			start->tm_hour = atoi(hour.c_str());
			check = 6;
		}
		else if(check == 6){
			min = fileInput;
			start->tm_min = atoi(min.c_str());
			check = 7;

		}
		else if(check == 7){
			day = fileInput;
			if(strcmpi(day.c_str(), "0") == 0){
				delete end;
				end = NULL;
				check = 12;
			}
			else{
				
				end->tm_mday = atoi(day.c_str());
				check = 8;
			}
			
		}
		else if(check == 8){
			month = fileInput;
			end->tm_mon = atoi(month.c_str());
			check = 9;
		}
		else if(check == 9){
			year = fileInput;
			end->tm_year = atoi(year.c_str());
			check = 10;
		}
		else if(check == 10){
			hour = fileInput;
			end->tm_hour = atoi(hour.c_str());
			check = 11;
		}
		else if(check == 11){
			min = fileInput;
			end->tm_min = atoi(min.c_str());
			check = 12;
		}
		if(check == 12){
		Task *newTask;
		if(end == NULL && start == NULL){
			newTask = new FloatingTask(description);
			
		}
		else if(start == NULL){
			newTask = new DeadlinedTask(description, end);
			
		}
		else{
			newTask = new TimedTask(description, start, end);
			
		}
		start = new tm;
		end = new tm;
		taskList.push_back(newTask);
		check = 1;
	  }
	}
	fin.close() ;
}

void FileIO::writeList(){
	ofstream fout(FileIO::fileName);
	string day, month, year, hour, min;
	char buffer[MAX_INPUT_SIZE];

	for(int i = 0; i < FileIO::taskList.size(); i++){
		fout.write(FileIO::taskList[i]->getDesc().c_str(), strlen(FileIO::taskList[i]->getDesc().c_str())).put('\n');
		if(FileIO::taskList[i]->getStart() == NULL){
			fout.write("0", 1).put('\n');
		}
		else{
			itoa(FileIO::taskList[i]->getStart()->tm_mday, buffer, 10);
			day = buffer;
			fout.write(day.c_str(), strlen(day.c_str())).put('\n');
			itoa(FileIO::taskList[i]->getStart()->tm_mon, buffer, 10);
			month = buffer;
			fout.write(month.c_str(), strlen(month.c_str())).put('\n');
			itoa(FileIO::taskList[i]->getStart()->tm_year, buffer, 10);
			year = buffer;
			fout.write(year.c_str(), strlen(year.c_str())).put('\n');
			itoa(FileIO::taskList[i]->getStart()->tm_hour, buffer, 10);
			hour = buffer;
			fout.write(hour.c_str(), strlen(hour.c_str())).put('\n');
			itoa(FileIO::taskList[i]->getStart()->tm_min, buffer, 10);
			min = buffer;
			fout.write(min.c_str(), strlen(min.c_str())).put('\n');
		}

		if(FileIO::taskList[i]->getEnd()==NULL){
			fout.write("0", 1).put('\n');
		}

		else {
			itoa(FileIO::taskList[i]->getEnd()->tm_mday, buffer, 10);
			day = string(buffer);
			fout.write(day.c_str(), strlen(day.c_str())).put('\n');
			itoa(FileIO::taskList[i]->getEnd()->tm_mon, buffer, 10);
			month = string(buffer);
			fout.write(month.c_str(), strlen(month.c_str())).put('\n');
			itoa(FileIO::taskList[i]->getEnd()->tm_year, buffer, 10);
			year = string(buffer);
			fout.write(year.c_str(), strlen(year.c_str())).put('\n');
			itoa(FileIO::taskList[i]->getEnd()->tm_hour, buffer, 10);
			hour = string(buffer);
			fout.write(hour.c_str(), strlen(hour.c_str())).put('\n');
			itoa(FileIO::taskList[i]->getEnd()->tm_min, buffer, 10);
			min = string(buffer);
			fout.write(min.c_str(), strlen(min.c_str())).put('\n');
		}
	}


	fout.close();

}
 
void FileIO::writeErrorLog (string log) {
	ofstream filePtr(ERROR_LOG_FILE_NAME, ios::app) ;
	tm* current = getCurrentTime() ; 
	string time = makePrintableTimeString(asctime(current)) ;
	filePtr << time << "\t" << log << endl ;
}
void FileIO::writeInputLog (string log) {
	ofstream filePtr(TASK_LOG_FILE_NAME, ios::app) ;
	tm* current = getCurrentTime() ; 
	string time = makePrintableTimeString(asctime(current)) ;
	filePtr << time << "\t" << log << endl ;
}
tm* FileIO::getCurrentTime()	{
	time_t now;
	struct tm *current;
	time(&now);
	current = localtime(&now);
	return current;
}
 
string FileIO::convertToString(char * sentence) {

	string strOfSentence ;
	stringstream ss ;
	ss << sentence ;
	strOfSentence = ss.str() ;
	return strOfSentence ;
}

string FileIO::makePrintableTimeString(char * timeInAscii) {

	string timeString = convertToString(timeInAscii) ;
	string timeStringPart1 ;
	string timeStringPart2 ;

	//isolate timeStringPart2

	int secondZeroOfMinute = 15 ;
	int lastLetterIndex = secondZeroOfMinute ; 

	int dayOfWeekSize = 3 ;
	int firstLetterIndex = dayOfWeekSize + 1 ;
	
	int sizeOfNewSentence = lastLetterIndex - firstLetterIndex + 1 ;
	timeStringPart1 = timeString.substr(firstLetterIndex, sizeOfNewSentence) ;

	//isolate timeStringPart2
	firstLetterIndex = lastLetterIndex + 4 ;
	lastLetterIndex = timeString.size() - 2 ;
	
	sizeOfNewSentence = lastLetterIndex - firstLetterIndex + 1 ;
	timeStringPart2 = timeString.substr(firstLetterIndex, sizeOfNewSentence) ;
	
	timeString = timeStringPart1 + timeStringPart2 ;
	return timeString ;

}