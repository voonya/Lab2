#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
using namespace std;
struct Team;
Team parse(string);    // function of parsing csv line
void calc_points(string, vector<Team>&); // function of calculating points of team and input them in vector
void process_file(string);   // sorting vector and write the information of it in file results
