#ifndef __HENCHMENPARSER_H__
#define __HENCHMENPARSER_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>


using namespace std;

class HenchmenParser {
public:
	HenchmenParser();
	void parse(string file);
	vector<string> tokenize(string line);
	void populate(vector<string> henchmen);
	vector<string> henchmens;

private:


};
#endif