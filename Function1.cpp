#include<iostream>
#include<fstream> 
#include <string>
using namespace std;
int main(){
    string data, fulldata;
    int data2;
    ifstream infile;
    infile.open("information.txt");

    cout << "Reading from the file" << endl;
    while (getline(infile, fulldata))
    {
        cout << fulldata << endl;
    }
    // close the opened file.
    infile.close();

    ifstream inputFile("information.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    int lineCount = 0;
    string line;

    while (getline(inputFile, line)) {
        lineCount++;
    }

    inputFile.close();

    cout << "Number of lines in the file: " << lineCount - 7<< endl;

    return 0;



}






	
