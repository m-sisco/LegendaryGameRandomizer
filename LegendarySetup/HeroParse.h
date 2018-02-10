#ifndef __HEROPARSE_H__
#define __HEROPARSE_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>


using namespace std;

class HeroParse {
public:
	HeroParse();
	void parse(string file);
	vector<string> tokenize(string line);
	void populate(vector<string> hero);
	vector<string> heroes;

private:


};
#endif