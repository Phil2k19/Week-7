double InterestRate(double &CurrentBalance , double AIR, double MonthlyBalance)
{
	double ActualInterest = (CurrentBalance + MonthlyBalance) / 2 * AIR;	//Average multiplied by Annual rate
	CurrentBalance += ActualInterest;
	return ActualInterest;
}
