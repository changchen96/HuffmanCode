#include "stdafx.h"
#include "symbolFreq.h"
#ifndef SYMBOLFREQ_H
#define SYMBOLFREQ_H
#include <fstream>
#include <algorithm>
map<char, int>::iterator listIterator;
//sorts the letters and the values
bool sortingMethod(const pair<char, int> &a, const pair<char, int> &b)
{
	return (a.second > b.second);
}
//gets each letter and its occurence from the text file
void symbolFreq::sortCount(string filename)
{
	ifstream newFile(filename);
	string givenString;
	givenString.assign((istreambuf_iterator<char>(newFile)), (istreambuf_iterator<char>()));
	//cout << givenString << endl;
	int counter = 0;
	for (size_t i = 0; i < givenString.size(); i++)
	{
		sortTable.insert(pair<char, int>(givenString[i], counter));
		for (listIterator = sortTable.begin(); listIterator != sortTable.end(); listIterator++)
		{
			if (givenString[i] == listIterator->first)
			{
				listIterator->second = listIterator->second + 1;
			}
		}
	}
}
//sorts the letters and their values in the vector
void symbolFreq::sortFinal()
{
	int mapSize = sortTable.size();
	//cout << "Size of map: " << mapSize << endl;
	for (listIterator = sortTable.begin(); listIterator != sortTable.end(); listIterator++)
	{
		char retrievedLetter = listIterator->first;
		int retrievedCounter = listIterator->second;
		finalTable.push_back(make_pair(retrievedLetter, retrievedCounter));
	}
	sort(finalTable.begin(), finalTable.end(), sortingMethod);
}
//prints the vector out for display
void symbolFreq::printFinal()
{
	//cout << "PRINTING FROM VECTOR" << endl;
	for (int b = 0; b < finalTable.size(); b++)
	{
		cout << finalTable[b].first << ":" << finalTable[b].second << endl;
	}
}

#endif

