//Header file created to contain var8iables and clean up code.
#pragma once
#define Salary_Calculator

//Initializing variables used for wage calculations.
//Hours.
double hoursWorkedWeek = 0.0;
double overtimeHours = 0.0;

//Wage vairables (hour/week/month/year).
double hourlyWage = 0.0;
double weeklyWage = 0.0;
double biweeklyWage = 0.0;
double monthlyWage = 0.0;
double annualWage = 0.0;

//Overtime variables.
double overtimeHourlyWage = 0.0;
double overtimeTotalWeek = 0.0;
double overtimeTotalBiweekly = 0.0;
double overtimeTotalMonth = 0.0;
double overtimeTotalAnnual;
double weeklyWageOT = 0.0;
double biweeklyWageOT = 0.0;
double monthlyWageOT = 0.0;
double annualWageOT = 0.0;
double overtimeMulti = 1.5;

//Initializing variables for tax rates.
//CHANGE THESE WHEN FUNCTIONALITY TO DETERMINE TAX RATES BASED ON ANNUAL INCOME IS ADDED!
double incomeTax = 0.0;
double maineStateTax = 0.0;
double socialSecurityTax = 0.0;
double medicareTax = 0.0;

//Initializing wageTax variable for tax calculations.
double wageTax = 0.0;
double weeklyTax = 0.0;
double biweeklyTax = 0.0;
double monthlyTax = 0.0;
double annualTax = 0.0;

//Initializing variables for pay frequency determination.
bool weeklyPay = false;
bool biweeklyPay = false;
bool switchLoop = false;
int payCycle = 0;

//Initializing variables for take home calculations.
double weeklyTakeHome = 0.0;
double biweeklyTakeHome = 0.0;
double monthlyTakeHome = 0.0;
double annualTakeHome = 0.0;

//Declaring and initializing variables for deductions.
bool wageDeduction;
bool deductionLoop;
bool pretaxDedLoop;

int deductionChoice;
int pretaxDedChoice;

double deductions = 0.0;
double pretaxDeductions = 0.0;
double pretaxMDeductions = 0.0;
double pretaxADeductions = 0.0;

//Declaring and initializing variables to handle deduction calculations on take home pay.
double wTakeHomeDeduct;
double mTakeHomeDeduct;
double aTakeHomeDeduct;
double mDeductions;
double aDeductions;