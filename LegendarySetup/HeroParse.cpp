#include "HeroParse.h"

HeroParse::HeroParse(){

}

void HeroParse::parse(string file){

	ifstream ifs;
	ifs.open(file.c_str());
	if (ifs.is_open()){
		string line;
		while(getline(ifs, line)){
			populate(tokenize(line));

		}
	}
	ifs.close();
}

vector<string> HeroParse::tokenize(string line){
	vector<string> hero;
	char *cstr = new char[line.length() + 1];
	strcpy(cstr, line.c_str());
	char *tok;
	tok = strtok(cstr, ",");

	while (tok != NULL){
		string s(tok);
		hero.push_back(s);
		tok = strtok(NULL, ",");
	}

	return hero;

}

void HeroParse::populate(vector<string> hero){
	heroes.push_back(hero[1]);
}


	
