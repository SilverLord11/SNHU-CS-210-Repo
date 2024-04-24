// CS-210 5-3 Project Two
// Logan Holt
// 4/7/2024

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "BankBalance.h"

// Function to display a menu without input
void DisplayEmptyMenu() {
    cout << "Initial Investment Output:" << endl;
    cout << "Monthly Deposit:" << endl;
    cout << "Annual Interest:   %5" << endl;
    cout << "Number of years:" << endl;
}

// Function to display a menu with inputs
void DisplayFullMenu(double init, double month, int year) {
    cout << "Initial Investment Output:   $" << init << endl;
    cout << "Monthly Deposit:   $" << month << endl;
    cout << "Annual Interest:   %5" << endl;
    cout << "Number of years:    " << year << endl;
    cout << "Press 1 to continue...." << endl;
}

int main()
{
    // Variables to use the BankBalance Class and its functions
    BankBalance userAccount;
    int input;
    double investInput;
    double depositInput;
    int yearInput;
    int yearNum;
    int i;

    // Displays empty menu
    DisplayEmptyMenu();

    // Gets inputs for initial investment, designated monthly deposits, and the number of years.
    cout << "Enter initial investment" << endl;
    cin >> investInput;
    userAccount.SetInitInvest(investInput);
    cout << endl;

    cout << "Enter monthly deposit" << endl;
    cin >> depositInput;
    userAccount.SetMonthlyDeposit(depositInput);
    cout << endl;

    cout << "Enter number of Years" << endl;
    cin >> yearInput;
    userAccount.SetNumYears(yearInput);
    cout << endl << endl;

    // Displays menu with inputs
    cout << "Your inputs are: " << endl << endl;
    DisplayFullMenu(userAccount.GetInitInvest(), userAccount.GetMonthlyDeposit(), userAccount.GetNumYears());

    // Gets input to continue to bank balance data
    cin >> input;

    switch(input) {
    case 1:
        // Displays yearly earnings without monthly deposit
        cout << "Yearly Balance Without Monthly Deposit" << endl;
        cout << "Year:          Year End Balance:          Year End Earned Interest:" << endl;

        for (i = 0; i < userAccount.GetNumYears(); i++) {
            yearNum = i + 1;
            userAccount.FindBalance(yearNum);
        }

        // Displays yearly earnings with monthly deposit
        cout << "Yearly Balance With Monthly Deposit" << endl;
        cout << "Year:          Year End Balance:          Year End Earned Interest:" << endl;

        for (i = 0; i < userAccount.GetNumYears(); i++) {
            yearNum = i + 1;
            userAccount.FindBalanceWithDeposit(yearNum, userAccount.GetMonthlyDeposit());
        }

        cout << "Thank you for using our interactive program!" << endl;
        // Closes application
        break;

    default:
        // Checks for invalid input
        cout << "invalid command";
        break;

    }

}