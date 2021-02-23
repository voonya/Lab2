
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


int main()
{
    string directory_name = "files";
    cout << "Input directory name: ";
    cin >> directory_name;
    process_file(directory_name);
    return 0;
}
