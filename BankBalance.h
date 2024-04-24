#pragma once
class BankBalance
{
public:
	// Functions to set and get necessary variables.
	void SetInitInvest(double input);

	double GetInitInvest();

	void SetMonthlyDeposit(double input);

	double GetMonthlyDeposit();

	void SetNumYears(int input);

	int GetNumYears();

	// Functions to return the year end balance
	void FindBalance(int year);

	void FindBalanceWithDeposit(int year, double deposit);

private:
	// Variables to find year end balance
	double invest;
	double monthDeposit;
	double balance1 = 0;
	double balance2 = 0;
	double endBalance = 0;
	double balanceDifference = 0;
	double yearInterestTotal = 0;
	int numYears;

};

