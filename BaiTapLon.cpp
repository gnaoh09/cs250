#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream inputFile("information.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
    }

    string search_term;
    cout << "Enter the name to search for: ";
    getline(cin, search_term);

    string line;
    int lineCount = 0;
    bool found = false;

    while (getline(inputFile, line)) {
        lineCount++;
        if (line.find(search_term) !=string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    inputFile.close();

    if (!found) {
        cout << "Name not found in the file." << endl;
    }

    
}
