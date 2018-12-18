#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::abs;
double WithdrawalFunc(double Withdrawal, double &CurrentBalance)
{	//TEST FOR MAX BALANCE ON WITHDRAWAL
	while (Withdrawal > CurrentBalance)
	{
		cout << "Invalid withdrawal, Amount entered is greater than Current Account Balance\n";
		cin >> Withdrawal;
	}

	CurrentBalance -= abs(Withdrawal);
	
	return Withdrawal;
}
