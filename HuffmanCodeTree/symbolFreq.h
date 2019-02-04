#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class symbolFreq
{
private:
	string filename;
	map<char, int> sortTable;
public:
	vector < pair<char, int>> finalTable;
	void sortCount(string);
	void sortFinal();
	void printFinal();
};
