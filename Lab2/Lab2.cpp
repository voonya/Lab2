#include "func.h"
#include <iostream>
#include <string>


using namespace std;


int main()
{
    string directory_name = "files";
    cout << "Input directory name: ";
    cin >> directory_name;
    process_file(directory_name);
    return 0;
}


