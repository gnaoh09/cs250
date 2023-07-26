#include <iostream>
#include <iomanip> //Set width
using namespace std;
void MenuSeletion(), Menu(), exitFunc();
int allowedLength = 1;
int main()
{
    Menu();
    MenuSeletion();
}

void MenuSeletion()
{
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
            cout << "BkCorporation's basic information:\n";

            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 2:
            cout << "Search for employee's profile:\n";
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 3:
            cout << "Employee's status:\n";
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 4:
            cout << "Unit's information:\n";
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
void exitFunc()
{
    char choice;
    cin >> choice;
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
