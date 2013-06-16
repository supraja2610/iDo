#include "gtest/gtest.h" //include to use Google Unit test's stuff
#include <exception>

#include <string>

#include "CommandProcessor.h"
#include "Logic.h"
#include "UI.h"

using namespace std;

/************************************************************************/

/* We write test cases here */

/************************************************************************/

TEST(basic_test, removeLastSpace) {

	CommandProcessor testObj ;
	string result = testObj.removeLastSpace("abcd efgh ") ;
	ASSERT_EQ(result,"abcd efgh") ;

	result = testObj.removeLastSpace("abcd efgh") ;
	ASSERT_EQ(result,"abcd efgh") ;
}

//cannot add keywords already in use
TEST(basic_test, createAlternateKeywordFalse1) {

	CommandProcessor testObj ;
	Logic logicTestObj ;
	Task * testTask = new FloatingTask ;
	//trying to add 'delete' as an alternative keyword for 'exit'
	testTask->setDesc("exit delete") ;
	bool returnVal ;
	returnVal = logicTestObj.createAlternateKeyword(testTask) ;
	ASSERT_EQ(returnVal, false) ;
    delete testTask ;

}

//cannot add 'space' or empty string as alternate keyword
TEST(basic_test, createAlternateKeywordFalse2) {
	CommandProcessor testObj ;
	Logic logicTestObj ;
	Task * testTask = new FloatingTask ;
	//trying to add space as an alternative keyword for search
	testTask->setDesc("search ") ;
	bool returnVal ;
	returnVal = logicTestObj.createAlternateKeyword(testTask) ;
	ASSERT_EQ(returnVal, false) ;
    delete testTask ;
}

TEST(basic_test, UIconvertToString) {
	UI testObj ;
	char * charArray = "test character array" ;
	string stringArray = "test character array" ;
	string result ;
	result = testObj.convertToString(charArray) ;
	ASSERT_EQ(result, stringArray) ;
}


TEST(basic_test, UImakeConvertiblemakePrintable) {
	UI testObj ;
	tm * testPointer = new tm ;
	testPointer->tm_hour = 10 ;
	testPointer->tm_min = 30 ;
	testPointer->tm_mon = 12 ;
	testPointer->tm_year = 2013 ;
	testPointer->tm_mday = 10 ;

	testObj.makeConvertible(testPointer) ;
	char * timeInString = asctime(testPointer) ;

	string result = testObj.makePrintableTimeString(timeInString) ;

	ASSERT_EQ(result, "Dec 10 10:30 2013") ;
	delete testPointer ;

}

TEST(basic_test, UIchangeBackTimePointer) {
	UI testObj ;
	tm * testPointer = new tm ;
	testPointer->tm_hour = 10 ;
	testPointer->tm_min = 30 ;
	testPointer->tm_mon = 12 ;
	testPointer->tm_year = 2013 ;
	testPointer->tm_mday = 10 ;

	testObj.makeConvertible(testPointer) ;
	time_t testTime = mktime(testPointer) ;
	testObj.changeBackTimePointer(testPointer) ;
	testTime = mktime(testPointer) ;

	ASSERT_EQ(-1, mktime(testPointer)) ;
	ASSERT_EQ(2013, testPointer->tm_year) ;

	delete testPointer ;
	
}

TEST(basic_test, cmdProcessor)

{
	CommandProcessor cp;
	Task* newTask = new TimedTask, *editTask = new TimedTask;

	string op = cp.cmdProcessor("meeting start 30.08.93 9.25 boss at office", newTask, editTask).c_str();
	
	ASSERT_EQ(0, strcmp("add",op.c_str()));
	ASSERT_EQ(0, strcmp("meeting boss at office ", newTask->getDesc().c_str()));
	ASSERT_EQ(30, newTask->getStart()->tm_mday);
	ASSERT_EQ(8, newTask->getStart()->tm_mon);
	ASSERT_EQ(1993, newTask->getStart()->tm_year);
	ASSERT_EQ(9, newTask->getStart()->tm_hour);
	ASSERT_EQ(25, newTask->getStart()->tm_min);
	

}
// checks if a string is converted properly to int array
TEST(basic_test, intProcessor)
{
	CommandProcessor cp;
	int a[] = {1, 2, 6, 4, 8, 10, 13, 15};
	vector<int> results = cp.intProcessor("1 2 6 4 8 10 13 15");
	for(int i = 0; i < results.size(); i++)
	ASSERT_EQ( a[i], results[i]);
}

TEST(basic_test, cmdType)
{
	CommandProcessor cp;
	char keyword[100];
	
	strcpy(keyword, "add");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("add", keyword));

	strcpy(keyword, "delete");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("delete", keyword));

	strcpy(keyword, "edit");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("edit", keyword));

	strcpy(keyword, "search");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("search", keyword));

	strcpy(keyword, "undo");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("undo", keyword));

	strcpy(keyword, "exit");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("exit", keyword));

}

TEST(basic_test, trim)
{
	CommandProcessor cp;
	char toTrim[100];
	strcpy(toTrim, "[abcdefg]");
	cp.trim(toTrim);
	ASSERT_EQ(0, strcmp("abcdefg", toTrim));
}

TEST(basic_test, istime)
{
	CommandProcessor cp;
	char time[100];
	strcpy(time, "next");
	ASSERT_TRUE(cp.isDateTime(time));
	strcpy(time, "wednesday");
	ASSERT_TRUE(cp.isDateTime(time));
	strcpy(time, "tomorrow");
	ASSERT_TRUE(cp.isDateTime(time));
	strcpy(time, "yesterday");
	ASSERT_TRUE(cp.isDateTime(time));
	strcpy(time, "today");
	ASSERT_TRUE(cp.isDateTime(time));
	strcpy(time, "30.8.93");
	ASSERT_TRUE(cp.isDateTime(time));
	strcpy(time, "3-3-2009");
	ASSERT_TRUE(cp.isDateTime(time));
	strcpy(time, "32/12/09");
	ASSERT_FALSE(cp.isDateTime(time));
	strcpy(time, "7.50");
	ASSERT_TRUE(cp.isDateTime(time));
	strcpy(time, "7.90");
	ASSERT_FALSE(cp.isDateTime(time));
	strcpy(time, "25.50");
	ASSERT_FALSE(cp.isDateTime(time));
}

TEST(basic_test, parseDateTime)
{
	time_t curr;
	time(&curr);
	tm *now = localtime(&curr), *retTime;
	CommandProcessor cp;
	char dateTime[100];
	strcpy(dateTime, "30.8.09 7:35");
	cp.parseDateTime(dateTime);
	ASSERT_EQ(0,strcmp(dateTime,"300820090735"));
	strcpy(dateTime, "next next august");
	cp.parseDateTime(dateTime);
	retTime = cp.stringToTime(dateTime);

	ASSERT_EQ(retTime->tm_year, now->tm_year + 3 + 1900);
	ASSERT_EQ(retTime->tm_mon, 8);
	ASSERT_EQ(retTime->tm_mday, 1);
	ASSERT_EQ(retTime->tm_hour, now->tm_hour);
	ASSERT_EQ(retTime->tm_min, now->tm_min);

	strcpy(dateTime, "next next month");
	cp.parseDateTime(dateTime);
	retTime = cp.stringToTime(dateTime);

	ASSERT_EQ(retTime->tm_year, 1900 + now->tm_year + ((2 + 1 + now->tm_mon) /13 ));
	ASSERT_EQ(retTime->tm_mon, 1);
	ASSERT_EQ(retTime->tm_mday, 1 );
	ASSERT_EQ(retTime->tm_hour, now->tm_hour);
	ASSERT_EQ(retTime->tm_min, now->tm_min);
}

TEST(basic_test, addZeroes)
{
	CommandProcessor cp;
	char dateTime[100];
	strcpy(dateTime, "30.8.9");
	cp.addZeroes(dateTime);
	ASSERT_EQ(0,strcmp(dateTime,"300809"));
}
// checks extreme condition when no undo operation can be performed	
TEST (basic_test, undoTask) {
	Logic testObj;
	bool returnVal;
		try {
			returnVal=testObj.undoTask();
			ASSERT_EQ(returnVal, true);
	}
	catch (string except) {
		
	ASSERT_EQ(except,"No commands to undo yet!");
	}

}
//checks extreme condition when no redo can be performed
TEST (basic_test, redoTask) {
	Logic testObj;
	bool returnVal;
		try {
			returnVal=testObj.redoTask();
			ASSERT_EQ(returnVal,true);
		}
		catch(string except) {
			ASSERT_EQ(except,"No undo to redo yet!");
		}
}
// checks if a task is being added properly
TEST(basic_test, addTask)
{
	Logic testObj;
	TimedTask testTask;
	tm* end = new tm;
	end->tm_hour=21;
	end->tm_min=0;
	end->tm_mon=5;
	end->tm_mday= 11;
	end->tm_year=2012;
	testTask.setDesc("Test");
	testTask.setEnd(end);
	tm* start = new tm;
	start->tm_hour = 20;
	start->tm_min = 0;
	start->tm_mon = 5;
	start->tm_mday = 11;
	start->tm_year = 2012;
	testTask.setStart(start);
	bool returnVal=testObj.addTask(&testTask);
	ASSERT_EQ(returnVal,true);
	returnVal = testObj.search(&testTask);
	delete start;
	delete end;
	ASSERT_EQ(returnVal,true);
	
	

}
//checks if a task is getting properly deleted
TEST (basic_test,deleteTask) {
	Logic testObj;
	TimedTask testTask;
	tm* end = new tm;
	end->tm_hour=21;
	end->tm_min=0;
	end->tm_mon=5;
	end->tm_mday= 11;
	end->tm_year=2012;
	testTask.setDesc("Test");
	testTask.setEnd(end);
	tm* start = new tm;
	start->tm_hour = 20;
	start->tm_min = 0;
	start->tm_mon = 5;
	start->tm_mday = 11;
	start->tm_year = 2012;
	testTask.setStart(start);
	bool returnVal = testObj.findToDelete(&testTask);
	ASSERT_EQ( returnVal, true);
	try {
		returnVal = testObj.search(&testTask);
		delete end;
		delete start;
		ASSERT_EQ(returnVal,true);
	}
	catch (string except) {
		delete end;
		delete start;
		ASSERT_EQ(except,"No matches found");
	}
} 

/************************************************************************/

/* Test function to be called in main */

/************************************************************************/

void runTest(int argument_count, char** argument_vars)

{

testing::InitGoogleTest(&argument_count, argument_vars); //initialize GTest

RUN_ALL_TESTS();

std::getchar(); //pause the program after all the testing

}