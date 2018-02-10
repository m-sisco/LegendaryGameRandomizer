#ifndef __VILLAINPARSER_H__
#define __VILLAINPARSER_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>


using namespace std;

class VillainParser {
public:
	VillainParser();
	void parse(string file);
	vector<string> tokenize(string line);
	void populate(vector<string> villain);
	vector<string> villains;

private:


};
#endif