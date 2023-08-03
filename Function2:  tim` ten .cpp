#include<iostream>
#include <sstream>
#include<fstream> 
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
void Function2();
int main() {
    Function2();
}
    
    
    
    
    
    
    
    
void Function2(){   
    ifstream inputFile("information.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
    }

    string search_term;
    cout << "Enter the employee's name to search for: ";
    getline(cin, search_term);
    replace(search_term.begin(), search_term.end(),' ', '_');
    string line; 
    bool found = false;
    int i;
    int start = 0; 
    int end = 40;   
    string range;   
    while (getline(inputFile, line )) {
        
        range = line.substr(start, end - start + 1);       //Choose a range
        if (range.find(search_term) !=string::npos) {      //Read a range of data
                replace(line.begin(), line.end(),'_',' ');
                cout << line << " " << endl;
            found = true;       
        }
    }
    inputFile.close();

    if (!found) {
        cout << "Employee not found in the file." << endl;
    }
}
