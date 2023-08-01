#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

struct Employee {
    string no;
    string day, month, year;
    string name;
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
};


int main() {
    ifstream inputFile("1.12.txt");                            //Print data 
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
    }
    string search_term;
    cout << "Enter the name to search for: ";
    getline(cin, search_term);                             //Searching for ID
            cout <<"---------------------------------------------------------------------------------------------------------------------" <<endl;
            cout << "No.         Name                           Day of work                              Start Time          End Time" << endl;
            cout <<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    string line;
    bool found = false;
    int i;
    int start1 = 0; 
    int end1 = 10;   
    string range1;   
    while (getline(inputFile, line )) {
        range1 = line.substr(start1, end1 - start1 + 1);       //Choose a range
        if (range1.find(search_term) !=string::npos) {      //Read a range of data
            cout << line << endl;
            found = true;       
        }
    }
    inputFile.close();
    if (!found) {
        cout << "Name not found in the file." << endl;
    }
    
    
    ifstream file("1.12.txt");
    vector<Employee> employees;
    int shortfallinMonth  = 0;
    if (!file) {
        cerr << "Error opening the file.\n";
       
    }
                                                                
    while (std::getline(file, line)) {
        Employee emp;
        std::istringstream iss(line);
        iss >> emp.no >> emp.name >> emp.day >> emp.month >> emp.year;
        iss >> emp.startHour  >> emp.startMinute;
        iss >> emp.endHour >>  emp.endMinute;
        employees.push_back(emp);
    }


        for (const auto& emp : employees) {   
             if (emp.no == search_term) {   // Calculate the time shortfall for each day
        int totalStartMinutes = emp.startHour * 60 + emp.startMinute;
        int totalEndMinutes = emp.endHour * 60 + emp.endMinute;
        int expectedWorkMinutes = 8 * 60;                                   // 8 hours workday
        int actualWorkMinutes = totalEndMinutes - totalStartMinutes;
        int shortfallMinutes = expectedWorkMinutes - actualWorkMinutes;
        cout << "This employee has a shortfall of each day is " << shortfallMinutes << " minutes.\n";
            shortfallinMonth = shortfallinMonth + shortfallMinutes;
        }
     }
     if(shortfallinMonth < 0){
        cout << "This employee has worked more " << abs(shortfallinMonth) << " minutes in a month";
     }
     else{
        cout <<"This employee has worked less " << abs(shortfallinMonth) << " minutes in a month";
     }
    

    file.close(); 
    return 0;
}