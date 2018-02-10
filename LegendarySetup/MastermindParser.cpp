#include "MastermindParser.h"

MastermindParser::MastermindParser(){

}

void MastermindParser::parse(string file){

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

vector<string> MastermindParser::tokenize(string line){
	vector<string> mastermind;
	char *cstr = new char[line.length() + 1];
	strcpy(cstr, line.c_str());
	char *tok;
	tok = strtok(cstr, ",");

	while (tok != NULL){
		string s(tok);
		mastermind.push_back(s);
		tok = strtok(NULL, ",");
	}

	return mastermind;

}

void MastermindParser::populate(vector<string> mastermind){
	masterminds.push_back(mastermind[1]);
	vil.push_back(mastermind[3]);
}


	
