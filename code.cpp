#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map <string, int> flights;
    
    ifstream file;
    file.open("data.txt");
    string line;
    while (file >> line) 
        flights[line]++;
    file.close();

    cout << "All airport traffic counts:" << endl;
    for (auto pair : flights) 
        cout << pair.first << ": " << pair.second << endl;
    cout << endl;

    vector<string> airports;
    int highestTraffic = 0;
    for (auto pair : flights) {
        if (pair.second > highestTraffic) {
            highestTraffic = pair.second;
            airports.clear();
            airports.push_back(pair.first);
        } else if (pair.second == highestTraffic) {
            airports.push_back(pair.first);
        }
    }
    cout << "Busiest airport(s) with count " << highestTraffic << ":" << endl;
    for (string value : airports) 
        cout << value << " " << highestTraffic << endl;
    
}