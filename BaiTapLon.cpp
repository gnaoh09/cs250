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

    std::ifstream inputFile("information.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    int lineCount = 0;
    std::string line;

    while (std::getline(inputFile, line)) {
        lineCount++;
    }

    inputFile.close();

    std::cout << "Number of lines in the file: " << lineCount - 7<< std::endl;

    return 0;



}






	
