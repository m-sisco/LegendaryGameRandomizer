#include "HenchmenParser.h"

HenchmenParser::HenchmenParser(){

}

void HenchmenParser::parse(string file){

	ifstream ifs;
	ifs.open(file.c_str());
	if (ifs.is_open()){
		string line;
		getline(ifs, line);
		while(getline(ifs, line)){
			populate(tokenize(line));

		}
	}
	ifs.close();
}

vector<string> HenchmenParser::tokenize(string line){
	vector<string> henchmen;
	char *cstr = new char[line.length() + 1];
	strcpy(cstr, line.c_str());
	char *tok;
	tok = strtok(cstr, ",");

	while (tok != NULL){
		string s(tok);
		henchmen.push_back(s);
		tok = strtok(NULL, ",");
	}

	return henchmen;

}

void HenchmenParser::populate(vector<string> henchmen){
	henchmens.push_back(henchmen[1]);
}


	
