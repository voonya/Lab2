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
			Team current = parse(line);
			teams.push_back(current);
		}
	}
	inFile.close();
}

void process_file(string directory_name) {
	vector<Team> teams;
	string path = filesystem::current_path().string() + "/" + directory_name;
	for (const auto& entry : filesystem::directory_iterator(path)) {		//iterating the files in directory
		string path_file = entry.path().string();
		string filename = path_file.substr(path_file.rfind(char(92)) + 1, path_file.length());
		if (filename != "results.csv") {       //checking not to process file results
			calc_points(path_file, teams);
		}
	}
	for (int i = 0; i < teams.size() - 1; i++) {   //sort vector
		for (int j = 0; j < teams.size() - i - 1; j++) {
			if (teams[j].points < teams[j + 1].points) {
				swap(teams[j], teams[j + 1]);
			}
		}
	}
	ofstream results;
	results.open(path + "/results.csv", ios::trunc);
	//write in file in csv-format
	for (int i = 0; i < teams.size() - 1; i++) { 
		results << teams[i].nametag << "," << teams[i].points << '\n';
	}
	results.close();
}