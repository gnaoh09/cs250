#include<iostream>
#include<fstream> 
#include <string>
using namespace std;
int main(){
    //Print all information
    string data, fulldata;    
    int data2;
    ifstream infile;
    infile.open("information.txt");
    cout << "Reading from the file" << endl;
    while (getline(infile, fulldata))
    {
        cout << fulldata << endl;
    }
    infile.close();
    
	//Count number of employee
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
    cout << "Total number of employees is: " << lineCount - 7 << endl;  //The number of line without information is 7

    return 0;



}






	
