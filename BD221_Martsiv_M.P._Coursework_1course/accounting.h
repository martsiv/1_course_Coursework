#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int BUF = 15;
const int DepartmentNum = 6;
const int PositionsNum = 4;
const int MaxEmployees = 99;
const int months = 12;
const int daysInMonths[months]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MaxHoursWork = 180;

enum class Department { None, Accounting, Economic, Legal, Office, Production, TechnicalSupport };
enum class Months { January, February, March, April, May, June, July, August, September, October, November, December };
enum class Position { None, Manager, SeniorSpecialist, MiddleSpeciasils, JuniorSpecialist };

struct FullName
{
	char firstName[BUF] = "None";
	char lastName[BUF] = "None";
};
struct Employees
{
	Department departmen = Department::None;
	FullName name;
	Position position = Position::None;
	union
	{
		unsigned nSubordinates;
		unsigned hoursWorked[months]{};
	};
	unsigned nonWorkingDays[months]{};
};

void createDataBase(Employees**& employees, unsigned& size);
void deleteDataBase(Employees**& employees, unsigned& size);
int verificateNum(int leftRange, int rightRange);
void printMenu(void);
const char* printDepartament(Department depart);
const char* printMonth(Months months);
const char* printPosition(Position position);
void enterFullname(FullName& name, int size);
void enterDepartament(Department& department);
void enterPosition(Position& position);
void enterSubordinates(unsigned& nSubordinates);
void enterHoursWorked(unsigned hoursWorkedPerMonth[]);
void enterNonWorkingDays(unsigned nonWorkingDays[]);
void enterEmployee(Employees& employee);
void fillDataBase(Employees** employees, unsigned nEmployees);
void printName(const FullName& name);
void printEmployee(const Employees& employees);
void printDataBase(Employees** employees, unsigned nEmployees);
void addEmployee(Employees**& employees, unsigned& nEmployees);
Employees** searchByNameAllResult(Employees** employees, unsigned nEmployees, const char* word, unsigned& counterOut);
Employees* searchByNameOneResult(Employees** employees, unsigned nEmployees);
Employees* searchEmployee(Employees** employees, unsigned nEmployees);
void deleteEmployee(Employees**& employees, unsigned& nEmployees, Employees* toDelete);
bool searchAndDeleteEmployee(Employees**& employees, unsigned& nEmployees);
void correctiosPosition(Employees& employee, Position newPosition); //не змінює відпрацьований час, в мейні реалізація
char* returnFullName(const Employees& employee, int sizeName);
void sortByName(Employees** employees, unsigned nEmployees);
void sortEmployees(Employees** employees, unsigned nEmployees);
int timeSheetDepartmentByMonth(Employees** employees, unsigned nEmployees, Department department, int month, bool returnOnly = 0);
void timeSheetEmployeeByYear(Employees& employees);
void calculateNonWorkingDaysByDepartment(Employees** employees, unsigned nEmployees, Department department);
int howManyEmployeesInDepartment(Employees** employees, unsigned nEmployees, Department department);
void totalTimeSheet(Employees** employees, unsigned nEmployees);
int saveTotalTimeSheet(Employees** employees, unsigned nEmployees, string fname);
void timeSheetEmployeeByMonth(Employees& employees, int month);

void forExampleDB(Employees**& employees, unsigned& nEmployees);