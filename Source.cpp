Description: Write a program that caluclatess the balance of a savings account at the end of a three
month period. Take the balance and annual interest rate. Use a loop to iterate once for every month in the period
perform the following steps.
A. Ask the user for total amount deposited for that month and add it to the balance, dont accept negative numbers.
B. Ask the user for the total amount withdrawn for the month and subtract it from the balance. Do not accept negative
numbers or values greater than balance total.
C. Calculate monthly interest. Which is annual interest divided by 12. Multiply monthly interest by the average of 
the month starting and ending balance. This amount should be added to balance.

For the final iteration the program should display a report that includes:
1. Starting balance at the beginning of the three month period.
2. Total deposits made during the three months
3. Total withdrawals made during the three months
4. Total interests posted to the account during the three months
5. Final balance!
NOTE: You will get the inputs from a file. You WILL accept negative numbers (indicating withdrawals).
1. You will write a deposit function that will add deposits to a balance.
2. You will write a withdrawal function that will test if the amount to withdraw is more than the balance. If it is,
then it will display a message to the user and ignore the withdrawal.
3. In addition, your main function will also keep track of all withdrawals and all deposits made. At the end 
of the three months it will list the balance, total deposits and total withdrawals.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "AccountFunctions.h"
using namespace std;

int main()
{
	int month = 1;			//Loop for 3 months
	ifstream AccountBalance;
	double CurrentBalance, AIR, Deposit, Withdrawal, StartingBalance;
	double TotalDeposits = 0, TotalWithdrawals = 0, TotalInterest = 0, MonthlyBalance = 0;

	cout << fixed << setprecision(2);
	AccountBalance.open("AccountStatistics.txt");
	AccountBalance >> CurrentBalance >> AIR;	//Assigns the balance and Annual int rate 
	AccountBalance.close();
	AIR = AIR / 12;	// Make Annual interest rate a monthly figure!
	cout << "Your current ballance is: " << CurrentBalance << endl;
	while (month <= 3)		//LOOP for 3 months and will hold functions
	{
		StartingBalance = CurrentBalance;				//For INTEREST COMPARISONS
		cout << "Enter your deposit for this month?\n";
		cin >> Deposit; 
		Deposit = DepositFunc(Deposit, CurrentBalance);
		TotalDeposits += Deposit;						//Variable for All Deposit count

		cout << "Enter you withdrawal for this month?\n";
		cin >> Withdrawal;
		Withdrawal= WithdrawalFunc(Withdrawal, CurrentBalance);
		TotalWithdrawals -= Withdrawal;					//Variable for ALL Withdrawal count

		cout << "This Concludes the month" << endl;

		TotalInterest += InterestRate(CurrentBalance, AIR, MonthlyBalance);
		
		cout << "\n" << endl;
		month++;
	}
	cout << "Starting balance at the beginning of the three month period: " << StartingBalance << endl;
	cout << "Absolute TOTAL Deposited is: " << TotalDeposits << endl;
	cout << "Absolute TOTAL Withdrawal is: " << TotalWithdrawals << endl;
	cout << "Absolute TOTAL interest is: " << TotalInterest << endl;
	cout << "Current Balance after 3 month period is: $" << CurrentBalance << endl;
	

	return 0;
}
