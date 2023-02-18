// Salary Calculator 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Salary_Calculator.h"
using namespace std;

//Creating function to handle pay frequency determination.
int payFrequency(int payCycle) {

	//Asking for pay frequency.
	cout << "\nPlease select if you are paid weekly or bi-weekly. Enter 1 for weekly and 2 for bi-weekly: ";
	cin >> payCycle;

	//Switch statement nested inside a while loop to handle pay frequency and errors from invalid entries.
	while (switchLoop == false) {
		switch (payCycle) {
		case 1:
			switchLoop = true;
			weeklyPay = true;
			break;
		case 2:
			switchLoop = true;
			biweeklyPay = true;
			break;
		default:
			switchLoop = false;
			cout << "Error. Please enter 1 for weekly pay or 2 for bi-weekly pay." << endl;
			cout << "\nPlease select if you are paid weekly or bi-weekly. Enter 1 for weekly and 2 for bi-weekly.";
			cin >> payCycle;
		}
	}
	return 0;
}

//Creating function to handle overtime calculations.
double overtimeCalculator(double overtimeTotalWage) {

	//Calculating overtime hours and displaying them.
	overtimeHourlyWage = hourlyWage * overtimeMulti;
	cout << "\nYour overtime hourly wage is: $" << overtimeHourlyWage << ".";

	//Calculating overtime total wage for a week and displaying it.(
	if (weeklyPay == true) {
		overtimeTotalWeek = overtimeHourlyWage * overtimeHours;
		cout << "\nYour total wages from overtime in a week is: $" << overtimeTotalWeek << ".";
	}
	else if (biweeklyPay == true) {
		overtimeTotalWeek = overtimeHourlyWage * overtimeHours;
		overtimeTotalBiweekly = overtimeTotalWeek * 2;
		cout << "\nYour total wages from overtime in two weeks is: $" << overtimeTotalBiweekly << ".";
	}

	//Calculating overtime total wage for a month and displaying it.
	overtimeTotalMonth = overtimeTotalWeek * 4;
	cout << "\nYour total wages from overtime in a month is: $" << overtimeTotalMonth << ".";

	//Calculating overtime total wage for a year and displaying it.
	overtimeTotalAnnual = overtimeTotalMonth * 12;
	cout << "\nYour total wages from overtime in a year is: $" << overtimeTotalAnnual << ".";

	return 0;
}
//Creating function to handle wage calculations.
double wageCalculator(double annualWage) {

	//Creating a blank line for ease of reading.
	cout << "\n";

	//Calculating weekly wages with overtime, displaying result and checking if pay frequency is weekly.
	if (weeklyPay == true) {
		weeklyWage = hourlyWage * hoursWorkedWeek;
		weeklyWageOT = weeklyWage + overtimeTotalWeek;
		cout << "\nYou make $" << weeklyWage << " per week, and $" << weeklyWageOT << " per week with overtime.";

		//Calculating monthly wages with overtime and displaying result.
		monthlyWage = weeklyWage * 4;
		monthlyWageOT = monthlyWage + overtimeTotalMonth;
		cout << "\nYou make $" << monthlyWage << " per month, and $" << monthlyWageOT << " per month with overtime.";

		//Calculating annual wages with overtime and displaying the result.
		annualWage = monthlyWage * 12;
		annualWageOT = annualWage + overtimeTotalAnnual;
		cout << "\nYou make $" << annualWage << " per year, and $" << annualWageOT << " per year with overtime.";

		//Initializing variables to factor overtime into hourly wage. Dividing annual wage by 52 weeks, dividing that number by hoursWorkedWeek.
		double trueWageS1 = annualWageOT / 52;
		double trueWageS2 = trueWageS1 / hoursWorkedWeek;
		//Displaying result.
		cout << "\nWith overtime consideration, your 'true' hourly wage is: $" << trueWageS2 << " an hour.";
	}
	//Calculating bi-weekly wages with overtime, displaying result, and checking if pay frequency is bi-weekly.
	else if (biweeklyPay == true) {

		weeklyWage = hourlyWage * hoursWorkedWeek;
		biweeklyWage = weeklyWage * 2;
		weeklyWageOT = weeklyWage + overtimeTotalWeek;
		biweeklyWageOT = weeklyWageOT * 2;
		cout << "\nYou make $" << biweeklyWage << " every 2 weeks, and $" << biweeklyWageOT << " every 2 weeks with overtime.";

		//Calculating monthly wages with overtime and displaying result.
		monthlyWage = weeklyWage * 4;
		monthlyWageOT = monthlyWage + overtimeTotalMonth;
		cout << "\nYou make $" << monthlyWage << " per month, and $" << monthlyWageOT << " per month with overtime.";


		//Calculating annual wages with overtime and displaying the result.
		annualWage = monthlyWage * 12;
		annualWageOT = annualWage + overtimeTotalAnnual;
		cout << "\nYou make $" << annualWage << " per year, and $" << annualWageOT << " per year with overtime.";

		//Initializing variables to factor overtime into hourly wage. Dividing annual wage by 52 weeks, dividing that number by hoursWorkedWeek.
		double trueWageS1 = annualWageOT / 52;
		double trueWageS2 = trueWageS1 / hoursWorkedWeek;
		//Displaying result.
		cout << "\nWith overtime consideration, your 'true' hourly wage is: $" << trueWageS2 << " an hour.";
	}
	return 0;
}
//Creating function to handle tax calculations.
double taxCalculator(double wageTax) {

	//Spacer.
	cout << endl;

	//Calculating Maine state tax due with if else if statements and displaying tax rate.
	if (annualWageOT > 0 && annualWageOT < 22450) {
	maineStateTax = 0.058;

	cout << "\nYour Maine state tax rate is 5.8%.";
	}
	else if (annualWageOT > 22450 && annualWageOT < 53150) {
	maineStateTax = 0.0675;

	cout << "\nYour Maine state tax rate is 6.75%.";
	}
	else if (annualWageOT > 53150) {
	maineStateTax = 0.0715;

	cout << "\nYour Maine state tax rate is 7.15%.";
	}

	//Calculating federal tax with if else if statements.
	if (annualWageOT > 0 && annualWageOT < 10275) {
		incomeTax = 0.10;

		cout << "\nYour federal tax rate is 10%.";
	}
	else if (annualWageOT > 10275 && annualWageOT < 41775) {
		incomeTax = 0.12;

		cout << "\nYour federal tax rate is 12%.";
	}
	else if (annualWageOT > 41775 && annualWageOT < 89075) {
		incomeTax = 0.22;

		cout << "\nYour federal tax rate is 22%.";
	}
	else if (annualWageOT > 89075 && annualWageOT < 17050) {
		incomeTax = 0.24;

		cout << "\nYour federal tax rate is 24%.";
	}
	else if (annualWageOT > 17050 && annualWageOT < 215950) {
		incomeTax = 0.32;

		cout << "\nYour federal tax rate is 32%.";
	}
	else if (annualWageOT > 215950 && annualWageOT < 323925) {
		incomeTax = 0.35;

		cout << "\nYour federal tax rate is 35%.";
	}
	else if (annualWageOT > 323925) {
		incomeTax = 0.37;

		cout << "\nYour federal tax rate is 37%.";
	}
	//Spacer for ease of reading.
	cout << endl;

	//Checking pay cycle.
	if (weeklyPay == true) {
		//Initializing variables for weekly tax calculations.
		double firstWTax = weeklyWageOT * incomeTax;
		double secondWTax = weeklyWageOT * maineStateTax;
		double thirdWTax = weeklyWageOT * socialSecurityTax;
		double fourthWTax = weeklyWageOT * medicareTax;
		double weeklyTax = firstWTax + secondWTax + thirdWTax + fourthWTax;
		double weeklyTakeHome = weeklyWageOT - weeklyTax;

		//Diplaying result.
		cout << "\nYou pay $" << weeklyTax << " every week in taxes, with a take home amount of $" << weeklyTakeHome << " after taxes.";
	}
	else if (biweeklyPay == true) {
		//Initializing variables for biweekly tax calculations.
		double firstBWTax = biweeklyWageOT * incomeTax;
		double secondBWTax = biweeklyWageOT * maineStateTax;
		double thirdBWTax = biweeklyWageOT * socialSecurityTax;
		double fourthBWTax = biweeklyWageOT * medicareTax;
		double biweeklyTax = firstBWTax + secondBWTax + thirdBWTax + fourthBWTax;
		double biweeklyTakeHome = biweeklyWageOT - biweeklyTax;

		//Diplaying result.
		cout << "\nYou pay $" << biweeklyTax << " every two weeks in taxes, with a take home amount of $" << biweeklyTakeHome << " after taxes.";

	}
	//Initializing variables for monthly tax calculations.
	double firstMTax = monthlyWageOT * incomeTax;
	double secondMTax = monthlyWageOT * maineStateTax;
	double thirdMTax = monthlyWageOT * socialSecurityTax;
	double fourthMTax = monthlyWageOT * medicareTax;
	double monthlyTax = firstMTax + secondMTax + thirdMTax + fourthMTax;
	double monthlyTakeHome = monthlyWageOT - monthlyTax;

	//Diplaying result.
	cout << "\nYou pay $" << monthlyTax << " every month in taxes, with a take home amount of $" << monthlyTakeHome << " after taxes.";

	//Initializing variables for annual tax calculations.
	double firstATax = annualWageOT * incomeTax;
	double secondATax = annualWageOT * maineStateTax;
	double thirdATax = annualWageOT * socialSecurityTax;
	double fourthATax = annualWageOT * medicareTax;
	double annualTax = firstATax + secondATax + thirdATax + fourthATax;
	double annualTakeHome = annualWageOT - annualTax;

	//Displaying result.
	cout << "\nYou pay $" << annualTax << " every year in taxes, with a take home amount of $" << annualTakeHome << " after taxes.";
	//Spacer.
	cout << endl;

	//Asking for user input for wage deductions.
	cout << "\nDo you have any wage deductions per pay cycle?? Please enter 1 for Yes or 2 for No: ";
	cin >> deductionChoice;

		//Nesting switch statment inside of while statement to handle choice loop and check for pay cycle.
	while (deductionLoop == false) {
		switch (deductionChoice) {
		case 1:
			deductionLoop = true;
			//Asking for user input on deductions and calculating weekly, monthly, and annual deductions.
			cout << "\nPlease enter your deductions: ";
			cin >> deductions;

			//Calculating weeklyTakeHome to aid in calculations.
			weeklyTakeHome = weeklyWageOT - weeklyTax;
			//Calculating weekly deductions.
			wTakeHomeDeduct = weeklyTakeHome - deductions;
			//Calculating monthlyTakeHome to aid in calculations.
			monthlyTakeHome = monthlyWageOT - monthlyTax;
			//Calculating monthly deductions.
			mDeductions = deductions * 4;
			mTakeHomeDeduct = monthlyTakeHome - mDeductions;
			//Calculating annualTakeHome to aid in calculations.
			annualTakeHome = annualWageOT - annualTax;
			//Calculating annual deductions.
			aDeductions = mDeductions * 12;
			aTakeHomeDeduct = annualTakeHome - aDeductions;

			//Displaying result.
			cout << "\nYour weekly deductions are: $" << deductions << " bringing your weekly take home to: $" << wTakeHomeDeduct << ".";
			cout << "\nYour monthly deductions are: $" << mDeductions << " bringing your monthly take home to: $" << mTakeHomeDeduct << ".";
			cout << "\nYour annual deductions are: $" << aDeductions << " bringing your annual take home to: $" << aTakeHomeDeduct << ".";
			break;
		case 2:
			deductionLoop = true;
			cout << "\nOperating with 0 deductions.";
			break;
		default:
			deductionLoop = false;
			cout << "\nError, invalid input. Please enter either a 1 for Yes or a 2 for No: ";
			cin >> deductionChoice;
		}
	}
	return 0;
}
//Main function to handle user input
int main() {

	//Legal disclaimer with spacer.
	cout << "THIS APP IN NO WAY ACTS AS TAX OR FINANCIAL ADVISE. THIS PROJECT IS MADE TO PURELY GIVE A GUESS-TEMATE TO BETTER PLAN FINANCIALLY.";
	cout << endl;
	//Calling payFrequency function to handle cycle determination.
	payFrequency(payCycle);

	//Asking for user input for wage.
	cout << "Please enter your hourly wage: ";
	cin >> hourlyWage;
	//Debug to ensure variable is working.
	//cout << "You entered: " << hourlyWage;

	//Asking for useer input for hours.
	cout << "\nPlease enter in your hours worked in one week: ";
	cin >> hoursWorkedWeek;
	//Debug to ensure variable is working.
	//cout << "You entered: " << hoursWorkedWeek;

	//If statement to initiate overtime hours.
	if (hoursWorkedWeek > 40) {
		overtimeHours = hoursWorkedWeek - 40;
		cout << "\nYou have " << overtimeHours << " hour(s) in overtime.";
		//Debug to ensure variable is working.
		//cout << "\nYou have " << overtimeHours << " hours in overtime.";
	}
	else {
		overtimeHours = 0;
		cout << "\nYou have " << overtimeHours << " hour(s) in overtime.";
	}
	//Calling calculator functions.
	overtimeCalculator(overtimeTotalWeek);
	wageCalculator(annualWage);
	taxCalculator(wageTax);
	//Spacer.
	cout << "\n";
}