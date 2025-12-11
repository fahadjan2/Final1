#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    map <string, int> flights;
    
    //File Opening
    ifstream file;
    file.open("data.txt");
    //File Populating
    string line;
    while (file >> line) {
        flights[line]++;
    }
    file.close();

    for (auto pair : flights) {
        cout << pair.first << ": " << pair.second << endl;
    }
}