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
    bool found = false;
    int i;
    int start = 0; 
    int end = 25;   
    string range;   
    while (getline(inputFile, line )) {
        range = line.substr(start, end - start + 1);       //Choose a range
        if (range.find(search_term) !=string::npos) {      //Read a range of data
            cout << line << endl;
            found = true;       
        }
    }
    inputFile.close();

    if (!found) {
        cout << "Name not found in the file." << endl;
    }
}   
