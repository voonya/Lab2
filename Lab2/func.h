#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
using namespace std;
struct Team;
Team parse(string);
void calc_points(string, vector<Team>&);
void process_file(string);
