#ifndef SEARCH_H
#define SEARCH_H
#include "Task.h"
#include <string>
#include <vector>
#include <time.h>
#include <assert.h>
#include <exception>

class Search
{
	vector<Task*> inputList, searchResults;
	vector<int> resultIndices;
	

	public:
		void setInputList(vector<Task*> list);
		
		bool executeSearch(string criteria);
		bool executeSearch(Task* query);
		vector<int> getIndices ();
		vector<Task*> getResults ();
		vector<Task*> getInputList();
		void clearSearchResults();
		bool executeSearchTime(Task* query);
		//changes the time to facilitate comparision of time
		void makeConvertible(tm*);
		//converts to required month and year format
		void formatMonYear(tm*);
		//changes back to original time
		void revertToOriginalTime( tm *time, int hour, int min);
};
#endif