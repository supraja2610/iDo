#ifndef FILEIO_H
#define FILEIO_H
#include "Task.h"
#include <vector>
#include <fstream>
#include <sstream>



class FileIO
{
	string fileName;
	vector<Task*> taskList;
	static const int MAX_CHAR_IN_LINE = 80 ;
	static const int MAX_NO_LINES = 100 ;
	string convertToString(char * name) ;
	//UI 

public:
	void setFileName(string fileName);
	void setTaskList(vector<Task*>& list);
	void readList();
	void writeList();
	vector<Task*> getTaskList();
	void writeInputLog(string);
	void writeErrorLog(string);
	
	//for use when adding alternate keywords for existing command keywords
	void writeToFile(const char *) ;
	vector<string> readFromFile() ;
	tm* getCurrentTime();
	string makePrintableTimeString(char * timeInAscii);

} ;

#endif