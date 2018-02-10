#ifndef __MASTERMINDPARSER_H__
#define __MASTERMINDPARSER_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>


using namespace std;

class MastermindParser {
public:
	MastermindParser();
	void parse(string file);
	vector<string> tokenize(string line);
	void populate(vector<string> mastermind);
	vector<string> masterminds;
	vector<string> vil;

private:


};
#endif