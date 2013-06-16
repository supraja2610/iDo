#include "gtest/gtest.h" //include to use Google Unit test's stuff

#include <string>

#include "CommandProcessor.h"
#include "Logic.h"


using namespace std;

************************************************************************/

* We write test cases here */

************************************************************************/

TEST(basic_test, cmdProcessor)

{
	CommandProcessor cp;
	Task *newTask = new TimedTask;
	string op = cp.cmdProcessor("meeting [start] 30.08.93 9.25 boss at office", newTask).c_str();
	
	ASSERT_EQ(0, strcmp("add",op.c_str()));
	ASSERT_EQ(0, strcmp("meeting boss at office ", newTask->getDesc().c_str()));
	ASSERT_EQ(30, newTask->getEnd()->tm_mday);
	ASSERT_EQ(8, newTask->getEnd()->tm_mon);
	ASSERT_EQ(1993, newTask->getEnd()->tm_year);
	ASSERT_EQ(9, newTask->getEnd()->tm_hour);
	ASSERT_EQ(25, newTask->getEnd()->tm_min);
	delete newTask;

}

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
	
	strcpy(keyword, "ad");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("add", keyword));

	strcpy(keyword, "del");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("delete", keyword));

	strcpy(keyword, "modi");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("edit", keyword));

	strcpy(keyword, "fin");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("search", keyword));

	strcpy(keyword, "und");
	cp.actualKeyWord(keyword);
	ASSERT_EQ(0, strcmp("undo", keyword));

	strcpy(keyword, "qui");
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
	ASSERT_TRUE(cp.isTime(time));
	strcpy(time, "wednesday");
	ASSERT_TRUE(cp.isTime(time));
	strcpy(time, "tomorrow");
	ASSERT_TRUE(cp.isTime(time));
	strcpy(time, "yesterday");
	ASSERT_TRUE(cp.isTime(time));
	strcpy(time, "today");
	ASSERT_TRUE(cp.isTime(time));
	strcpy(time, "30.8.93");
	ASSERT_TRUE(cp.isTime(time));
	strcpy(time, "3/13/09");
	ASSERT_FALSE(cp.isTime(time));
	strcpy(time, "32/12/09");
	ASSERT_FALSE(cp.isTime(time));
	strcpy(time, "7.50");
	ASSERT_TRUE(cp.isTime(time));
	strcpy(time, "7.90");
	ASSERT_FALSE(cp.isTime(time));
	strcpy(time, "25.50");
	ASSERT_FALSE(cp.isTime(time));
}

TEST(basic_test, parseDateTime)
{
	CommandProcessor cp;
	char dateTime[100];
	strcpy(dateTime, "30.8.09 7:35");
	cp.parseDateTime(dateTime);
	ASSERT_EQ(0,strcmp(dateTime,"300820090735"));
	strcpy(dateTime, "30/8/90 7.50");
	cp.parseDateTime(dateTime);
	ASSERT_EQ(0,strcmp(dateTime,"300819900750"));
}

TEST(basic_test, addZeroes)
{
	CommandProcessor cp;
	char dateTime[100];
	strcpy(dateTime, "30.8.9");
	cp.addZeroes(dateTime);
	ASSERT_EQ(0,strcmp(dateTime,"300809"));
}
************************************************************************/

* Test function to be called in main */

************************************************************************/

void runTest(int argument_count, char** argument_vars)

{

testing::InitGoogleTest(&argument_count, argument_vars); //initialize GTest

RUN_ALL_TESTS();

std::getchar(); //pause the program after all the testing

}