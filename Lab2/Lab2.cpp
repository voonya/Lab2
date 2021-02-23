//#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

using namespace std;

struct Team {
	int points;
	string nametag;
};
Team parse(string);
void calc_points(string, vector<Team>&);

int main()
{
    //string directory_name;
    //cout << "Input directory name: ";
   // cin >> directory_name;

    //process_file(directory_name);
    vector<Team> teams;
    calc_points("premier.csv", teams);

    return 0;
}


Team parse(string line) {
	int points = 0;
	string name_tag = line.substr(0, line.find(","));
	Team current;
	current.nametag = name_tag;
	line.erase(0, line.find(",") + 1);
	int pos = line.find(",");
	while (pos != string::npos && line != "") {
		string game;
		if (pos != string::npos) {
			game = line.substr(0, line.find(","));
			line.erase(0, line.find(",") + 1);
		}
		else {
			game = line;
			line = "";
		}
		int pointsTeam = stoi(game.substr(0, game.find(":")));
		int pointsEnemy = stoi(game.substr(game.find(":") + 1, game.length() - game.find(":") - 1));
		if (pointsTeam > pointsEnemy) {
			points += 3;
		}
		else if (pointsTeam == pointsEnemy) {
			points++;
		}
		pos = line.find(",");
	}
	current.points = points;
	return current;
}

void calc_points(string path, vector<Team>& teams) {
	ifstream inFile(path);
	if (!inFile.is_open()) {
		cout << "Can`t open the file!";
	}
	else {
		string number_of_teams;
		inFile >> number_of_teams;
		inFile.ignore();
		while (!inFile.eof()) {
			string line;
			getline(inFile, line);
			Team current =  parse(line);
			
			cout << current.nametag << " " << current.points << endl;
			teams.push_back(current);
		}
	}
	inFile.close();
}