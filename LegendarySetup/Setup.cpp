#include "Setup.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;
Setup::Setup(){

}

vector<string> Setup::chooseHeroes(){
	HeroParse hero;
	hero.parse("Hero List - Sheet1.csv");
	string ans;
	int num = 0;
	vector<string> heroes;

	cout << "Would you like to preset one or more heroes? (Y/N)" << endl;
	cin >> ans;
	if (ans == "Y"){
		cout << "Would you like a list of options? (Y/N)" << endl;
		cin >> ans;
		if (ans == "Y"){
			for (int i = 0; i < hero.heroes.size(); i++){
				cout << hero.heroes[i] << endl;		
			}
		
		}
		cout << "How many heroes?" << endl;
		cin >> num;
	}


	for (int i = 0; i < num; i++){
		cout << "Hero " << i + 1 << "? Do not include spaces" << endl;
		string b;
		cin >> b;
		heroes.push_back(b);

	}
	return heroes;

}


string Setup::chooseMastermind(){
	MastermindParser master;
	master.parse("Mastermind List - Sheet1.csv");
	string ans;
	string mastermind;

	cout << "Would you like to preset your mastermind? (Y/N)" << endl;
	cin >> ans;
	if (ans == "Y"){
		cout << "Would you like a list of options? (Y/N)" << endl;
		cin >> ans;
		if (ans == "Y"){
			for (int i = 0; i < master.masterminds.size(); i++){
				cout << master.masterminds[i] << endl;
			}
		
		}
	
		VillainParser vill;
		vill.parse("Villain List - Sheet1.csv");
		cout << "Mastermind? Do not include spaces" << endl;
		cin >> mastermind;
		int num;
		for(int i = 0; i < master.masterminds.size(); i++){
			if(mastermind == master.masterminds[i]){
				cout << "equal" << endl;
				num = i;
			}
		}
		int v = stoi(master.vil[num]);
		game.villains.push_back(vill.villains[v]);

	}

	return mastermind;

}

vector<string> Setup::chooseVillains(){
	VillainParser vils;
	vils.parse("Villain List - Sheet1.csv");
	string ans;
	int num = 0;
	vector<string> villains;

	cout << "Would you like to preset one or more villains? (Y/N)" << endl;
	cin >> ans;
	if (ans == "Y"){
		cout << "Would you like a list of options? (Y/N)" << endl;
		cin >> ans;
		if (ans == "Y"){
			for (int i = 0; i < vils.villains.size(); i++){
				cout << vils.villains[i] << endl;
			}
		}
		cout << "How many villains? (Note: You can only choose 1 villain if a mastermind was chosen)" << endl;
		cin >> num;
	}


	for (int i = 0; i < num; i++){
		cout << "Villain " << i + 1 << "? Do not include spaces" << endl;
		string b;
		cin >> b;
		villains.push_back(b);

	}

	if(num == 2){
		MastermindParser master;
		master.parse("Mastermind List - Sheet1.csv");
		cout << "Choose a mastermind corresponding to a chosen villain. Your choices are:" << endl;
		
		for (int i = 0; i < master.masterminds.size(); i++){
			if (i == 7){
				continue;
			}
			cout << "Mastermind: " << master.masterminds[i];
			cout << "	";
			int num = stoi(master.vil[i]) - 1;
			cout << "Villain: " << vils.villains[num] << endl;


		}

		cout << "Choose one" << endl;

		cin >> game.mastermind;

		

	}
	return villains;
}

string Setup::chooseHenchmen(){
	HenchmenParser hench;
	hench.parse("Henchmen List - Sheet1.csv");
	string ans;
	string henchmen;

	cout << "Would you like to preset your henchmen? (Y/N)" << endl;
	cin >> ans;
	if (ans == "Y"){
		cout << "Would you like a list of options? (Y/N)" << endl;
		cin >> ans;
		if (ans == "Y"){
			for (int i = 0; i < hench.henchmens.size(); i++){
				cout << hench.henchmens[i] << endl;
			}
		}
	

		cout << "Henchmen? Do not include spaces" << endl;
		cin >> henchmen;
	}
	return henchmen;

}


UserInput Setup::setup(){

	game.heroes = chooseHeroes();
	game.mastermind = chooseMastermind();
	vector<string> vills = chooseVillains();
	for (int i = 0; i < vills.size(); i++){
		game.villains.push_back(vills[i]);
	}

	game.henchmen = chooseHenchmen();
	return game;
}

void Setup::chooseGame(){
	HeroParse hero;
	hero.parse("Hero List - Sheet1.csv");
	MastermindParser master;
	master.parse("Mastermind List - Sheet1.csv");
	VillainParser vils;
	vils.parse("Villain List - Sheet1.csv");
	HenchmenParser hench;
	hench.parse("Henchmen List - Sheet1.csv");
	bool cont = false;
	srand (time(NULL));
	while(game.heroes.size() != 5){

			int r = rand() % 78;
			for(int j = 0; j < game.heroes.size(); j++){
				if(hero.heroes[r] == game.heroes[j]){
					cont = true;
				}
			}
			if (!cont){
				game.heroes.push_back(hero.heroes[r]);
			}
				
	}


	if(game.mastermind.length() == 0){
			int r = rand() % 26;
			game.mastermind = master.masterminds[r];

			game.villains.push_back(vils.villains[stoi(master.vil[r]) - 1]);
				
			
			
	}


	cont = false;
	while(game.villains.size() != 2){
			int r = rand() % 33;
			for(int j = 0; j < game.villains.size(); j++){
				if(vils.villains[r] == game.villains[j]){
					cont = true;
				}
			}
			if (!cont){
				game.villains.push_back(vils.villains[r]);
			} 

			
		
	}

	if(game.henchmen.length() == 0){
			int r = rand() % 13;
			game.henchmen = hench.henchmens[r];

				
			 
			
	}



}


int main(){
	Setup user;
	user.setup();
	user.chooseGame();
	cout << user.game.heroes.size() << endl;

	cout << "Your heroes are:" << endl;
	for(int i = 0; i < user.game.heroes.size(); i++){
		cout << user.game.heroes[i] << endl;
	}

	cout << "Your villains are:" << endl;
	for(int i = 0; i < user.game.villains.size(); i++){
		cout << user.game.villains[i] << endl;
	}

	cout << "Your mastermind is:" << endl;
	cout << user.game.mastermind << endl;

	cout << "Your henchmen is:" << endl;
	cout << user.game.henchmen << endl;
	return 0;
}