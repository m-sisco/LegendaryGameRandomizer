#include "VillainParser.h"

VillainParser::VillainParser(){

}

void VillainParser::parse(string file){

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

vector<string> VillainParser::tokenize(string line){
	vector<string> villain;
	char *cstr = new char[line.length() + 1];
	strcpy(cstr, line.c_str());
	char *tok;
	tok = strtok(cstr, ",");

	while (tok != NULL){
		string s(tok);
		villain.push_back(s);
		tok = strtok(NULL, ",");
	}

	return villain;

}

void VillainParser::populate(vector<string> villain){
	villains.push_back(villain[1]);
}


	
