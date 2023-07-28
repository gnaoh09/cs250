#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
string name;
cout <<"Nhap ten ct con: ";
getline(cin, name);
string data, fulldata;    
fstream infile;

if(name == "BKEntertainment"){
    infile.open("BKE.txt");
    while (getline(infile, fulldata))
    {
        cout << fulldata << endl;
    }
    infile.close();
	}

else if(name == "BKCorporation"){
    infile.open("BKC.txt");
    while (getline(infile, fulldata))
    {
        cout << fulldata << endl;
    }
    infile.close();
	}

else if(name == "BKFinance"){
    infile.open("BKF.txt");
    while (getline(infile, fulldata))
    {
        cout << fulldata << endl;
    }
    infile.close();
	}

else if(name == "BKFood"){
    infile.open("BKFd.txt");
    while (getline(infile, fulldata))
    {
        cout << fulldata << endl;
    }
    infile.close();
	}

else if(name == "BKHumanResource"){
    infile.open("BKHR.txt");
    while (getline(infile, fulldata))
    {
        cout << fulldata << endl;
    }
    infile.close();
	}

else if(name == "BKTech"){
    infile.open("BKT.txt");
    while (getline(infile, fulldata))
    {
        cout << fulldata << endl;
    }
    infile.close();
	}



}