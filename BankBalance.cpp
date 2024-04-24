#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "BankBalance.h"

// Sets and Gets initial investment
void BankBalance::SetInitInvest(double input) {
	invest = input;
}

double BankBalance::GetInitInvest() {
	return invest;
}

// Sets and Gets monthly deposit
void BankBalance::SetMonthlyDeposit(double input) {
	monthDeposit = input;
}

double BankBalance::GetMonthlyDeposit() {
	return monthDeposit;
}

// Sets and Gets number of years
void BankBalance::SetNumYears(int input) {
	numYears = input;
}

int BankBalance::GetNumYears() {
	return numYears;
}

// Finds the year end balance without monthly deposits
void BankBalance::FindBalance(int year) {
	int i;

	for (i = 0; i < 12; i++) {
		// If its the beginnning investment, initialize the end balance 
		if (i == 0) {
			endBalance = endBalance + invest;
		}
		else {
			// Finds new balance and the interest earned
			balance1 = endBalance;
			endBalance = endBalance + (endBalance * 0.05);
			balance2 = endBalance;
			balanceDifference = balance2 - balance1;
			yearInterestTotal = yearInterestTotal + balanceDifference;
		}
	}


	// Displays earnings
	cout << "Year " << year << " :       $" << fixed << setprecision(2) << endBalance << "                      $" << fixed << setprecision(2) << yearInterestTotal << endl << endl;
}

void BankBalance::FindBalanceWithDeposit(int year, double deposit) {
	int i;

	for (i = 0; i < 12; i++) {
		// If its the beginnning investment, initialize the end balance
		if (i == 0) {
			endBalance = endBalance + invest;
		}
		else {
			// Finds new balance and the interest earned
			endBalance = endBalance + deposit;
			balance1 = endBalance;
			endBalance = endBalance + (endBalance * 0.05);
			balance2 = endBalance;
			balanceDifference = balance2 - balance1;
			yearInterestTotal = yearInterestTotal + balanceDifference;
		}
	}


	// Displays earnings
	cout << "Year " << year << " :       $" << fixed << setprecision(2) << endBalance << "                      $" << fixed << setprecision(2) << yearInterestTotal << endl << endl;

}