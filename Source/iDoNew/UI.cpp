#include "UI.h"

const string UI::MESSAGE_NEXT_COMMAND = "Enter Command: " ;
const string UI::MESSAGE_WELCOME = "\t\t\t\t ****iDo****" ;

const string UI::MESSAGE_HELP = "Valid Commands: add, delete, search, edit, undo, redo, alternate, exit, view." ;
const string UI::MESSAGE_INVALID = "Invalid command entered!" ;

const string UI::TABLE_FIELDS = "No. Task Description                     From/At           To               " ;

const string UI::MESSAGE_ALTERNATE_SUCCESS = "Successfully added alternate keyword." ;
const string UI::MESSAGE_ALTERNATE_FAIL = "Unable to add alternate to keyword." ;

const string UI::MESSAGE_ADDED =  "Successfully added task to schedule." ;
const string UI::MESSAGE_INVALID_ADD = "Unable to add task to schedule." ;

const string UI::MESSAGE_DELETED = "Deleted task(s) from schedule." ;
const string UI::MESSAGE_INVALID_DELETE = "Unable to delete/Task(s) matching entered description not found." ;

const string UI::MESSAGE_EDITED = "Edited task in schedule." ;
const string UI::MESSAGE_INVALID_EDIT = "Unable to edit/Task(s) matching entered description not found." ;

const string UI::MESSAGE_SEARCH_SUCCESS = "The above tasks matched the entered description." ;
const string UI::MESSAGE_INVALID_SEARCH = "No tasks matching the entered description were found!" ; 

const string UI::MESSAGE_EXIT = "Exiting iDo now." ;
const string UI::MESSAGE_UNDONE = "Command successfully undone." ;
const string UI::MESSAGE_UNDO_FAIL = "Undo not possible." ;

const string UI::MESSAGE_REDO = "Successfully redone.";
const string UI::MESSAGE_REDO_FAIL = "Redo not possible";
const string UI::MESSAGE_TODAY = "Today's Schedule: " ;
const string UI::MESSAGE_NO_TASK = "You have no tasks scheduled for today";

 
string UI::convertToString(char * sentence) {

	string strOfSentence ;
	stringstream ss ;
	ss << sentence ;
	strOfSentence = ss.str() ;
	return strOfSentence ;
}

string UI::makePrintableTimeString(char * timeInAscii) {

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

	/*
	int lastLetterIndex = timeString.size() - 2 ; 

	//dont want 3 letters and space at the beginning
	int dayOfWeekSize = 3 ;
	int firstLetterIndex = dayOfWeekSize + 1 ;
	int sizeOfNewSentence = lastLetterIndex - firstLetterIndex + 1 ;

	string tempString = timeString.substr(firstLetterIndex, sizeOfNewSentence) ;
	timeString = tempString ; */

	return timeString ;

}

void UI::makeConvertible(tm * timePointer) {
	
	timePointer->tm_year -= 1900;
	timePointer->tm_mon -= 1;
	timePointer->tm_isdst = -1;
	timePointer->tm_wday = 0;
	timePointer->tm_yday = 0;
	timePointer->tm_sec = 0;

}

void UI::changeBackTimePointer(tm * timePointer) {

	timePointer->tm_mon += 1;
    timePointer->tm_year += 1900;
}

void UI::goToNextLineBeginning(int yIncrement) {
	currentCursor.X = 2 ;
	currentCursor.Y++ ;
	currentCursor.Y += yIncrement ;
	placeCursorAt(currentCursor.X, currentCursor.Y) ;
}

void UI::goToDescriptionBeginning() {
	currentCursor.X = 6 ;
	placeCursorAt(currentCursor.X, currentCursor.Y) ;
}

void UI::goToFromBeginning() {
	currentCursor.X = 43 ;
	placeCursorAt(currentCursor.X, currentCursor.Y) ;
}

void UI::goToToBeginning() {
	currentCursor.X = 61 ;
	placeCursorAt(currentCursor.X, currentCursor.Y) ;
}

int UI::printDescription(string description) {

	int letterCountOnCurrentLine = 0 ;
	int printedCount = 0 ;
	int index = 0 ;
	int currentlyAt = 0 ;
	int yIncrement = 0 ;

	int taskLineNo = currentCursor.Y ;
	
	int size = description.size() ;
	
	while(printedCount < size) {
		for(index = currentlyAt ; index < size ; index++) {
			if(description[index] == ' ') {
				break ;
			}
		}
		if(index == size || description[index] == ' ') {
			int wordSize = index - currentlyAt + 1 ;
			letterCountOnCurrentLine += wordSize ;

			if(letterCountOnCurrentLine > 36) {
				yIncrement++ ;
				letterCountOnCurrentLine = 0 ;
				goToNextLineBeginning(0) ;
				goToDescriptionBeginning() ;
				letterCountOnCurrentLine += wordSize ;
			}

				string partialDescription = description.substr(currentlyAt, wordSize) ;
				cout << partialDescription ;
				printedCount += wordSize ;
				currentlyAt = index + 1 ;
			}
			
		}
	currentCursor.Y = taskLineNo ;
	placeCursorAt(currentCursor.X, currentCursor.Y) ;
	return yIncrement ;
}

int UI::displayFloatingTask(string description) {
	goToDescriptionBeginning() ;
	int yIncrement = 0 ;
	
	if(description.size() <= 36) {
		yIncrement = 0 ;
		cout << description ;
	}

	else {
		yIncrement = printDescription(description) ;
	}

	return yIncrement ;
}

int UI::displayTimedTask(tm * & startTime, tm * & endTime, string description) {

	makeConvertible(startTime) ;
	makeConvertible(endTime) ;

	goToDescriptionBeginning() ;
	int yIncrement = 0 ;
	int size = description.size() ;
	
	if(size <= 36) {
		yIncrement = 0 ;
		cout << description ;
	}

	else {
		yIncrement = printDescription(description) ;
	}
	
	string sTime = makePrintableTimeString(asctime(startTime)) ;
	string eTime = makePrintableTimeString(asctime(endTime)) ;

	goToFromBeginning() ;
	cout << sTime ; 
	
	goToToBeginning() ;
	cout << eTime ;

    changeBackTimePointer(startTime) ;
	changeBackTimePointer(endTime) ;	

	return yIncrement ;
}

int UI::displayDeadlineTask(tm * & deadline, string description) {

	makeConvertible(deadline) ;

	goToDescriptionBeginning() ;
	int yIncrement = 0 ;
	int size= description.size() ;
	
	if(size <= 36) {
		yIncrement = 0 ;
		cout << description ;
	}
	
	else {
		yIncrement = printDescription(description) ;
	}
	
	string printableDeadline = makePrintableTimeString(asctime(deadline)) ;
	goToFromBeginning() ;
	cout << printableDeadline ; 

    changeBackTimePointer(deadline) ;

	return yIncrement ;
}

void UI::displayHomeScreen(vector<Task*> tasksToDisplay) {

	system("cls") ;
	cout << MESSAGE_WELCOME ;

	if(!ifstream("task.txt")){
		UI::helpScreen() ;
	}

	int taskNo = 0 ;
 
	vector<Task*>::iterator it = tasksToDisplay.begin() ;

	currentCursor.X = TABLE_START_POSITION_X ;
	currentCursor.Y = TABLE_START_POSITION_Y ;

	placeCursorAt(currentCursor.X, currentCursor.Y) ;
	int yIncrement = 0 ;
	tm* current =  UI::getCurrentTime();
	string time = UI::makePrintableTimeString (asctime(current));
	cout << MESSAGE_HELP ; 
	UI::goToNextLineBeginning(0) ;
	cout << MESSAGE_TODAY << time;
	UI::goToNextLineBeginning(1);
	if(tasksToDisplay.size() == 0) {
		cout << MESSAGE_NO_TASK << endl;
	}
	else {
	cout << UI::TABLE_FIELDS ; 

	for( ; it != tasksToDisplay.end() ; it++) {
	 
		taskNo++ ;
		goToNextLineBeginning(yIncrement) ;
		cout << taskNo ;

		tm * startTime = (*it)->getStart() ;
		tm * endTime = (*it)->getEnd() ;
		string description = (*it)->getDesc() ;

		if(startTime != NULL && endTime != NULL) {
			yIncrement = displayTimedTask(startTime, endTime, description) ;
		}
		
		else if(startTime == NULL && endTime != NULL) {
			yIncrement = displayDeadlineTask(endTime, description) ;
		}

		else if(startTime != NULL && endTime == NULL) {
			yIncrement = displayDeadlineTask(startTime, description) ;
		}

	 //floating tasks
		else if(startTime == NULL && endTime == NULL) {
			yIncrement = displayFloatingTask(description) ;
		}
  }
	goToNextLineBeginning(0) ;
	}
}

void UI::feedback(bool result, string command) {

	currentCursor.Y += 2 ;
	placeCursorAt(currentCursor.X, currentCursor.Y) ;

	if(result == true) {
		displayTrueFeedback(command) ;
	}
}

void UI::displayTrueFeedback(string command) {

	if(command == "add") {
		cout << MESSAGE_ADDED ;
	}

	else if(command == "delete") {
		cout << MESSAGE_DELETED ;
	}

	else if(command == "edit") {
		cout << MESSAGE_EDITED ;
	}
    else if(command == "search") {
		cout << MESSAGE_SEARCH_SUCCESS ;
    }
	else if(command == "exit") {

		cout << MESSAGE_EXIT ; 
		currentCursor.Y++ ;
		placeCursorAt(currentCursor.X, currentCursor.Y) ;
		system("pause") ;
	}
	else if(command == "alternate") {
		cout << MESSAGE_ALTERNATE_SUCCESS ;
	}
	else if(command == "undo") {
		cout << MESSAGE_UNDONE ;
	}
	else {
		cout<<MESSAGE_REDO;
	}

 }

/*void UI::displayFalseFeedback(string command) {
	
    if(command == "add") {
		cout << MESSAGE_INVALID_ADD ;
	}

	else if(command == "delete") {
		cout << MESSAGE_INVALID_DELETE ;
	}

	else if(command == "search") {
		cout << MESSAGE_INVALID_SEARCH ;
    }

	else if(command == "edit") {
		cout << MESSAGE_INVALID_EDIT ;
	}

	else if(command == "alternate") {
		cout << MESSAGE_ALTERNATE_FAIL ;
	}

	else if(command == "undo") {
		cout << MESSAGE_UNDO_FAIL ;

	}

	else if(command == "exit") {
		cout << MESSAGE_EXIT ;
		currentCursor.Y++ ;
		placeCursorAt(currentCursor.X, currentCursor.Y) ;
		system("pause") ;
	}
	else if(command == "redo") {
		cout<<MESSAGE_REDO_FAIL;
	}
	else
		{
		cout << MESSAGE_INVALID ;
	}

 }*/


void UI::placeCursorAt(int x, int y) {
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
    cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(hConsole, cursorPosition);
	
}

string UI::getUserInput() {

	//currentCursor.Y++ ;
    //placeCursorAt(currentCursor.X, currentCursor.Y) ;
    //cout << MESSAGE_HELP ;
	
	currentCursor.Y += 2 ;
	placeCursorAt(currentCursor.X, currentCursor.Y) ;
	cout << MESSAGE_NEXT_COMMAND ;

	getline(cin, userInput) ;
	return userInput ;

}

void UI::printThis(string messageToUser) {
	currentCursor.Y++ ;
    placeCursorAt(currentCursor.X, currentCursor.Y) ;
	cout << messageToUser ;
}

 
tm* UI::getCurrentTime()	{
	time_t now;
	struct tm *current;
	time(&now);
	current = localtime(&now);
	return current;
}

 
void UI::helpScreen()	{
		cout << "\n\n\n\n\n\n";
		cout << "    Welcome to iDo!!\n    Listed below is the format in which the commands are to be used.\n\n";
		cout << "    add:  <description> start <start time> end <end time>\n";
		cout << "    delete:	delete <partial description>\n";
		cout << "    edit:  edit <partial description> [new] <new description>\n";
		cout << "    search:	search <partial description>\n";
		cout << "    alternate:  alternate <existing keyword> <new key word>\n\n";
		cout << "    Press any key to continue...\n";
		std::getchar();
		system("cls") ;
		cout << MESSAGE_WELCOME ;
}