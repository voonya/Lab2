#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>


using namespace std;

struct Team {
	string nametag;
	int points;
};

void calc_points(string path, vector<Team>& teams) {
	ifstream inFile(path);
	if (!inFile.is_open()) {
		cout << "Can`t open the file!";
	}
	else {
		while (!inFile.eof()) {
			string line;
			getline(inFile, line);
			//teams.push_back(parse(line));
		}
	}
	inFile.close();
}