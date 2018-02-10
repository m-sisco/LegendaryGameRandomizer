#ifndef __SETUP_H__
#define __SETUP_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include "HenchmenParser.h"
#include "HeroParse.h"
#include "MastermindParser.h"
#include "VillainParser.h"


using namespace std;

struct UserInput{
	vector<string> heroes;
	string mastermind;
	vector<string> villains;
	string henchmen;

};
class Setup{

public:
	Setup();
	vector<string> chooseHeroes();
	string chooseMastermind();
	vector<string> chooseVillains();
	string chooseHenchmen();
	UserInput setup();
	void chooseGame();
	UserInput game;

private:


};

#endif
