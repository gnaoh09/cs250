#include<iostream>
#include <sstream>
#include<fstream> 
#include <vector>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
string currentLine, pieces;
vector<string> piecesContainer;
vector<size_t> maxLength(10, 0);
int k = 0, nowString;
vector<vector<string>> twoDVector;
void PrintTable(){
     vector<string> Headers = {"Company", "Level", "Name(Last/Mid/First)", "Birthdate", "ID", "Origin", "Residence", "Email", "Phone", "JobTaken"};
    for (int j = 0; j < Headers.size(); ++j) // column
    {
        int st = (int)Headers[j].length();
        int nt = (int)maxLength[j];
        int et = nt - st;
        string headerSpace(abs(et), ' ');
        cout << Headers[j] << headerSpace << "  |  ";
    }
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 3; i < k; ++i) // row
    {
        for (int j = 0; j < 10; ++j) // column
        {

            if (j < twoDVector[i].size()) // condition to avoid error printing
            {
                nowString = (int)maxLength[j] - (int)twoDVector[i][j].length();

                string spacing(abs(nowString), ' ');
                replace(twoDVector[i][j].begin(), twoDVector[i][j].end(), '_', ' ');
                cout << twoDVector[i][j] << spacing << "  |  ";
            }
        }
        cout << endl;}
}

void Function1(){ 

        ifstream ScanFile("information.txt");
    while (getline(ScanFile, currentLine))
    {
        stringstream currentStream(currentLine);
        while (currentStream >> pieces)
        {
            piecesContainer.push_back(pieces);
        }
        twoDVector.push_back(piecesContainer); // Add the entire row to twoDVector

        if (k >= 3) // get string length from line 4
        {
            for (int s = 0; s < 10; s++)
            {
                if (piecesContainer[s].length() > maxLength[s])
                {
                    maxLength[s] = piecesContainer[s].length();
                }
            };
        }
        k++;
        piecesContainer.clear();
    }
    ScanFile.close();
    PrintTable();
    
    ifstream inputFile("information.txt");                                  //Count number of employee
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
     
    }
    int lineCount = 0;
    string line;
    while (getline(inputFile, line)) {
        lineCount++;
    }
    inputFile.close();
    cout << "Total number of employees is: " << lineCount -3 << endl;  //The number of line without information is 3
  
}
void MenuSeletion();
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
struct Employee {
    string no;
    string day, month, year;
    string name;
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
};
void Function3(){
    ifstream inputFile("1.12.txt");                            //Print data 
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
    }
    string search_term;
    cout << "Enter the ID to search for: ";
    getline(cin, search_term);                             //Searching for ID
            cout <<"---------------------------------------------------------------------------------------------------------------------" <<endl;
            cout << "No.         Name                           Day of work                  Start Time               End Time" << endl;
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
        cout << "Employee not found in the file." << endl;
    }
    
    
    ifstream file("1.12.txt");
    vector<Employee> employees;
    double shortfallinMonth  = 0;
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
        double shortfallMinutes = (expectedWorkMinutes - actualWorkMinutes) / 60.0;
        cout << "This employee has a time shortfall of each day is " << round(shortfallMinutes) << " hours.\n";
            shortfallinMonth = shortfallinMonth + shortfallMinutes;
        }
     }
     if(shortfallinMonth < 0){
        cout << "This employee has worked " << round(abs(shortfallinMonth)) << " hours more in a month";
     }
     else{
        cout <<"This employee has worked " << round(abs(shortfallinMonth)) << " hours less in a month";
     }
    

    file.close(); 
}
void Function4(){

    ifstream inputFile("information.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
    }
    
    string search_term;
    cout << "Enter the Work unit's name to search for: ";
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
            replace(line.begin(), line.end(),'_',' ');
            cout << line << " " << endl;
            found = true;       
        }
    }
    inputFile.close();

    if (!found) {
        cout << "Work unit not found in the file." << endl;
    }
}   
void Menu()
{
    cout << "......WELCOME TO BKCORPORATION.......\n";
    cout << "1) BkCorporation's basic information.\n";

    cout << "2) Search for employee's profile.\n";

    cout << "3) Employee's status.\n";

    cout << "4) Unit's information.\n";

    cout << "5) Update new employee list.\n";

    cout << "6) Update employee's profile.\n";

    cout << "7) Exit program.\n";
}


int main(){
    Menu();
    MenuSeletion();
}
void exitFunc()
{
    char choice, nextChar;
    cin >> choice;
    if (cin.get(nextChar) && nextChar == '\n')
    {
        // The input contains only one character
        cout << "You entered a single character: " << choice << endl;
    }
    else
    {
        // The input contains more than one character
        cout << "Invalid input. Please enter exactly one character." << endl;
        exitFunc();
    }

    char choosed = tolower(choice);
    if (choosed == 'y')
    {
        main();
    }
    else if (choosed == 'n')
    {
        return;
    }
    else
    {
        cout << "INVALID! enter again: ";
        exitFunc();
    }
};
void MenuSeletion()
{
    int allowedLength = 1;
    string input;
    cout << "Enter your choice: \n";
    cin >> input;
    
    if (input.length() > allowedLength)
    {
        cout << "Invalid input! Please enter a valid choice.\n";
        main();
    };

    if (!isdigit(input[0]))
    {
        cout << "Invalid input! Please enter a valid choice.\n";
        main();
    };
    int number = input[0] - '0';
    cout << "You entered: " << number << "\n";

    if (number <= 7 && number > 0)
    {
        switch (number)
        {
        case 1:
            Function1();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 2:
            Function2();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 3:
            Function3();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 4:
            Function4();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 5:
            cout << "Add new employee to the list:\n";
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 6:
            cout << "Update employee's profile:\n";
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 7:
            cout << "Exit program....";
            exit(0);
        }
    }
    else
    {
        cout << "Wrong option!,\nPlease enter a valid choice!\n";
        main();
    }
}

