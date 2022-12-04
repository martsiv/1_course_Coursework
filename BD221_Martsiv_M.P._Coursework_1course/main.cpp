#include "accounting.h"


int main()
{
	unsigned nEmployees{};
	Employees** employees = nullptr;
	
	//cout << "Enter the number of employees: ";
	//nEmployees = verificateNum(1, MaxEmployees);
	//createDataBase(employees, nEmployees);
	forExampleDB(employees, nEmployees); //Для перевірки

	enum class Menu { Fill, View, Add, Delete, Search, Correction, Selection, Calculate, TableReport, VolReport, Exit };
	const int menuItems = 10;
	Employees* exampleEmp{};
	int i_tmp{};
	int i_department{};
	int i_month{};
	int i_menu{};
	char c_menu{};
	char returnName[BUF * 2]{};
	do
	{
		if (!nEmployees)
		{
			cout << "No employees, add employee!\n";
			addEmployee(employees, nEmployees);
		}
		printMenu();
		cout << "Enter your choise - ";
		while (!(cin >> c_menu) || ((c_menu - 48 < 0) || (menuItems < c_menu - 48) && c_menu != 'q' && c_menu != 'Q'))
			continue;
		if (c_menu == 'Q' || c_menu == 'q')
			i_menu = 10;
		else
			i_menu = int(c_menu) - 48;

		switch (Menu(i_menu))
		{
		case Menu::Fill:
			fillDataBase(employees, nEmployees);
			break;
		case Menu::View:
			sortEmployees(employees, nEmployees);
			system("cls");
			printDataBase(employees, nEmployees);
			system("PAUSE");
			system("cls");
			break;
		case Menu::Add:
			addEmployee(employees, nEmployees);
			break;
		case Menu::Delete:
			sortEmployees(employees, nEmployees);
			if (searchAndDeleteEmployee(employees, nEmployees))
				cout << "Done!\n";
			else
				cout << "We haven`t fired any employees\n";
			break;
		case Menu::Search:
			sortEmployees(employees, nEmployees);
			searchEmployee(employees, nEmployees);
			break;
		case Menu::Correction:
			system("cls");
			sortEmployees(employees, nEmployees);
			cout << "Let`s find an employee to correct his position\n";
			exampleEmp = searchEmployee(employees, nEmployees);
			if (exampleEmp)
			{
				cout << "Enter new position: \n";
				for (size_t i = 1; i <= PositionsNum; i++)
					cout << i << " - " << printPosition(Position(i)) << endl;
				cout << endl;
				i_tmp = verificateNum(1, PositionsNum);
				correctiosPosition(*exampleEmp, Position(i_tmp));
			}
			break;
		case Menu::Selection:
			sortEmployees(employees, nEmployees);
			cout << "\n1 - Show the department's timesheet for the month\n"
				<< "2 - Show a summary of the employee's work for the year\n"
				<< "0 - return to menu\n";
			i_tmp = verificateNum(0, 2);
			if (i_tmp == 1)
			{
				cout << "To look at the time sheet report enter the department and month\n";
				for (int i = 1; i <= DepartmentNum; i++)
					cout << i << " - " << printDepartament(Department(i)) << endl;
				cout << "Enter the department: ";
				i_department = verificateNum(1, DepartmentNum);
				cout << "Enter the month: ";
				i_month = verificateNum(1, months);
				i_month--;
				timeSheetDepartmentByMonth(employees, nEmployees, Department(i_department), i_month);
				system("PAUSE>nul");
			}
			else if (i_tmp == 2)
			{
				cout << "Let`s find an employee to print time sheet\n";
				exampleEmp = searchEmployee(employees, nEmployees);
				if (exampleEmp)
				{
					cout << "Summary of " << returnFullName(*exampleEmp, BUF) << ". Position - " << printPosition((*exampleEmp).position) << endl;
					cout << "\t\t\t";
					for (size_t i = 0; i < months; i++)
					{
						strncpy_s(returnName, printMonth(Months(i)), 3);
						cout << returnName << '\t';
					}
					cout << "Total\n";
					timeSheetEmployeeByYear(*exampleEmp);
					system("PAUSE>nul");
				}
			}
			system("cls");
			break;
		case Menu::Calculate:
			cout << "\nTotal and average numbers of non-working days by department\n";
			for (int i = 1; i <= DepartmentNum; i++)
				cout << i << " - " << printDepartament(Department(i)) << endl;
			cout << "Enter department: ";
			i_department = verificateNum(1, DepartmentNum);
			calculateNonWorkingDaysByDepartment(employees, nEmployees, Department(i_department));
			system("PAUSE>nul");
			system("cls");
			break;
		case Menu::TableReport:
			system("cls");
			totalTimeSheet(employees, nEmployees);
			cout << "1 - Save to file\n"
				<< "2 - Return to menu\n";
			i_menu = verificateNum(1, 2);
			if (i_menu == 1)
			{
				string fname;
				cout << "Enter file name: ";
				cin >> fname;
				if (!saveTotalTimeSheet(employees, nEmployees, fname))
					cout << "Done!\n";
				else
					cout << "Write error!\n";
			}
			system("PAUSE>nul");
			system("cls");
			break;
		case Menu::VolReport:
			cout << "Let's find an employee to get the Employee Report for the month\n";
			exampleEmp = searchEmployee(employees, nEmployees);
			if (exampleEmp)
			{
				cout << "Enter month number: ";
				i_month = verificateNum(1, months);
				i_month--;
				cout << "Employee report for the " << printMonth(Months(i_month)) << ":\n";
				timeSheetEmployeeByMonth(*exampleEmp, i_month);
				system("PAUSE>nul");
				system("cls");
			}
			break;
		case Menu::Exit:
			cout << "Goodbye\n";
			break;
		}
	} while (i_menu != 10);
	deleteDataBase(employees, nEmployees);
}