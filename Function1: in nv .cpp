#include<iostream>
#include <sstream>
#include<fstream> 
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
void Function1();

int main(){

    Function1();

    return 0;
}











void Function1(){ 
    int i = 0;
    string data, line, token;                                                      //Print all information
    ifstream infile;
    infile.open("information.txt");
    while (getline(infile, line))
    {
        if (i >= 3){
            vector<string> components;
            stringstream ss(line);
            while (ss >> token)
            {
                components.push_back(token);
            };

            for (int j = 0; j < components.size(); j++)
            {
                replace(components[j].begin(), components[j].end(),'_',' ');
                cout << components[j] << "   ";
            };
            cout << endl;
        };
        i++;
    }
    infile.close();

	                                                                        
    ifstream inputFile("information.txt");                                  //Count number of employee
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
     
    }
    int lineCount = 0;
   
    while (getline(inputFile, line)) {
        lineCount++;
    }
    inputFile.close();
    cout << "Total number of employees is: " << lineCount - 9 << endl;  //The number of line without information is 7
}
    
