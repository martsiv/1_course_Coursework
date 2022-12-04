#include "accounting.h"

void createDataBase(Employees**& employees, unsigned& size)
{
	if (employees != nullptr)
		cout << "Data Base must be clear! (=nullptr)\n";
	else if (MaxEmployees < size)
		cout << "Too many workers, the company can't afford it!\n";
	else
	{
		employees = new Employees * [size];
		for (size_t i = 0; i < size; i++)
			employees[i] = new Employees;
	}
}
void deleteDataBase(Employees**& employees, unsigned& size)
{
	if (employees == nullptr)
	{
		cout << "The database is already clean\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
		delete employees[i];
	delete[] employees;
	size = 0;
	employees = nullptr;
}
int verificateNum(int leftRange, int rightRange)
{
	int num;
	while (!(cin >> num) || (num < leftRange) || (rightRange < num))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	return num;
}
void printMenu(void)
{
	cout << "\t\tEnterprise accounting\n";
	cout << "0 - Fill the database\n";
	cout << "1 - View the database\n";
	cout << "2 - Add a new employee\n";
	cout << "3 - Delete an employee\n";
	cout << "4 - Search for employees\n";
	cout << "5 - Correction position\n";
	cout << "6 - Selection from the database\n";
	cout << "7 - Calculation of non-working days\n";
	cout << "8 - Table report: time sheet\n";
	cout << "9 - Voluntary report for a month\n";
	cout << "Q - Exit program\n";
}
const char* printDepartament(Department depart)
{
	if (depart == Department::Accounting)
		return "Accounting";
	else if (depart == Department::Economic)
		return "Economic";
	else if (depart == Department::Legal)
		return "Legal";
	else if (depart == Department::Office)
		return "Office";
	else if (depart == Department::Production)
		return "Production";
	else if (depart == Department::TechnicalSupport)
		return "Technical Support";
	else
		return "None";
}
const char* printMonth(Months months)
{
	if (months == Months::January)
		return "January";
	else if (months == Months::February)
		return "February";
	else if (months == Months::March)
		return "March";
	else if (months == Months::April)
		return "April";
	else if (months == Months::May)
		return "May";
	else if (months == Months::June)
		return "June";
	else if (months == Months::July)
		return "July";
	else if (months == Months::August)
		return "August";
	else if (months == Months::September)
		return "September";
	else if (months == Months::October)
		return "October";
	else if (months == Months::November)
		return "November";
	else if (months == Months::December)
		return "December";
	else
		return "None";
}
const char* printPosition(Position position)
{
	if (position == Position::Manager)
		return "Manager";
	else if (position == Position::SeniorSpecialist)
		return "Senior Specialist";
	else if (position == Position::MiddleSpeciasils)
		return "Middle Speciasils";
	else if (position == Position::JuniorSpecialist)
		return "Junior Specialist";
	else
		return "None";
}
void enterFullname(FullName& name, int size)
{
	bool isOK = 1;
	do
	{
		cout << "\nEnter fullname\n";
		cout << "Firstname(" << BUF << " symbols): ";
		cin.get(name.firstName, size);
		while (cin.fail() || cin.get() != '\n')
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cin.get(name.firstName, size);
		}

		cout << "Lastname(" << BUF << " symbols): ";
		cin.get(name.lastName, size);
		while (cin.fail() || cin.get() != '\n')
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cin.get(name.lastName, size);
		}
		printName(name);
		cout << "Is everything correct? (y, n) Fullname\n";
		char c_tmp;
		while (!(cin >> c_tmp) || !(c_tmp == 'y' || c_tmp == 'Y' || c_tmp == 'n' || c_tmp == 'N'))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (c_tmp == 'y' || c_tmp == 'Y')
			isOK = 1;
		else if (c_tmp == 'n' || c_tmp == 'N')
			isOK = 0;
	} while (!isOK);
}
void enterDepartament(Department& department)
{
	bool isOK = 1;
	do
	{
		cout << "\nChoose a department:\n";
		if (isOK)
		{
			for (int i = 1; i <= DepartmentNum; i++)
				cout << i << " - " << printDepartament(Department(i)) << endl;
		}
		int i_tmp = verificateNum(1, DepartmentNum);
		department = Department(i_tmp);
		cout << "Is everything correct? Department: \"" << printDepartament(department) << "\"? (y, n)\n";
		char c_tmp;
		while (!(cin >> c_tmp) || !(c_tmp == 'y' || c_tmp == 'Y' || c_tmp == 'n' || c_tmp == 'N'))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (c_tmp == 'y' || c_tmp == 'Y')
			isOK = 1;
		else if (c_tmp == 'n' || c_tmp == 'N')
			isOK = 0;
	} while (!isOK);
}
void enterPosition(Position& position)
{
	bool isOK = 1;
	do
	{
		cout << "\nChoose a position:\n";
		if (isOK)
		{
			for (int i = 1; i <= PositionsNum; i++)
				cout << i << " - " << printPosition(Position(i)) << endl;
		}
		int i_tmp = verificateNum(1, DepartmentNum);
		position = Position(i_tmp);
		cout << "Is everything correct? Position: \"" << printPosition(position) << "\"? (y, n)\n";
		char c_tmp;
		while (!(cin >> c_tmp) || !(c_tmp == 'y' || c_tmp == 'Y' || c_tmp == 'n' || c_tmp == 'N'))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (c_tmp == 'y' || c_tmp == 'Y')
			isOK = 1;
		else if (c_tmp == 'n' || c_tmp == 'N')
			isOK = 0;
	} while (!isOK);
}
void enterSubordinates(unsigned& nSubordinates)
{
	bool isOK = 1;
	do
	{
		cout << "\nEnter the number of subordinates:\n";
		nSubordinates = verificateNum(0, MaxEmployees);
		cout << "Is everything correct? Subordinates: \"" << nSubordinates << "\"? (y, n)\n";
		char c_tmp;
		while (!(cin >> c_tmp) || !(c_tmp == 'y' || c_tmp == 'Y' || c_tmp == 'n' || c_tmp == 'N'))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (c_tmp == 'y' || c_tmp == 'Y')
			isOK = 1;
		else if (c_tmp == 'n' || c_tmp == 'N')
			isOK = 0;
	} while (!isOK);
}
void enterHoursWorked(unsigned hoursWorkedPerMonth[])
{
	bool isOK = 1;
	do
	{
		cout << "\nEnter the hours of operation per month:\n";
		for (size_t i = 0; i < months; i++)
		{
			cout << printMonth(Months(i)) << " : ";
			hoursWorkedPerMonth[i] = verificateNum(0, MaxHoursWork);
		}
		cout << endl;
		for (size_t i = 0; i < months; i++)
		{
			cout << printMonth(Months(i)) << " : " << hoursWorkedPerMonth[i] << '\t';
		}
		cout << "\nIs everything correct? (y, n)\n";
		char c_tmp;
		while (!(cin >> c_tmp) || !(c_tmp == 'y' || c_tmp == 'Y' || c_tmp == 'n' || c_tmp == 'N'))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (c_tmp == 'y' || c_tmp == 'Y')
			isOK = 1;
		else if (c_tmp == 'n' || c_tmp == 'N')
			isOK = 0;
	} while (!isOK);
}
void enterNonWorkingDays(unsigned nonWorkingDays[])
{
	bool isOK = 1;
	do
	{
		cout << "\nEnter all non-working days for the month:\n";
		for (size_t j = 0; j < months; j++)
		{
			cout << printMonth(Months(j)) << " : ";
			nonWorkingDays[j] = verificateNum(0, daysInMonths[j]);
		}
		cout << endl;
		for (size_t i = 0; i < months; i++)
		{
			cout << printMonth(Months(i)) << " : " << nonWorkingDays[i] << '\t';
		}
		cout << "\nIs everything correct? (y, n)\n";
		char c_tmp;
		while (!(cin >> c_tmp) || !(c_tmp == 'y' || c_tmp == 'Y' || c_tmp == 'n' || c_tmp == 'N'))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (c_tmp == 'y' || c_tmp == 'Y')
			isOK = 1;
		else if (c_tmp == 'n' || c_tmp == 'N')
			isOK = 0;
	} while (!isOK);
}
void enterEmployee(Employees& employee)
{
	enterDepartament(employee.departmen);
	enterFullname(employee.name, BUF);
	enterPosition(employee.position);
	if (employee.position == Position::Manager)
		enterSubordinates(employee.nSubordinates);
}
void fillDataBase(Employees** employees, unsigned nEmployees)
{
	system("cls");
	cout << "Fill data base\n";
	cout << "Enter basic employee data(1) or performance indicators(2)? (0 - return)\t";
	int tmp = verificateNum(0, 2);
	if (!tmp)
		return;
	else if (tmp == 1)
	{
		for (unsigned i = 0; i < nEmployees; i++)
		{
			cout << "\n\tEmploye #" << i + 1 << " :\n";
			printEmployee(*employees[i]);
			cout << "1 - enter new data\n"
				<< "2 - go to the next employee\n"
				<< "0 - return to menu\n";
			tmp = verificateNum(0, 2);
			if (!tmp)
				break;
			else if (tmp == 2)
				continue;
			enterEmployee(*employees[i]);
			system("cls");
		}
	}
	else
	{
		for (unsigned i = 0; i < nEmployees; i++)
		{
			cout << "\n\tEmploye #" << i + 1 << " :\n";
			printEmployee(*employees[i]);
			cout << "1 - enter new data\n"
				<< "2 - go to the next employee\n"
				<< "0 - return to menu\n";
			tmp = verificateNum(0, 2);
			if (!tmp)
				break;
			else if (tmp == 2)
				continue;
			enterHoursWorked((*employees[i]).hoursWorked);
			enterNonWorkingDays((*employees[i]).nonWorkingDays);
			system("cls");
		}
	}
}
void printName(const FullName& name)
{
	cout << "  Firstname:\t" << name.firstName << endl
		<< "  Lastname:\t" << name.lastName << endl;
}
void printEmployee(const Employees& employee)
{
	cout << "Depatrment:\t" << printDepartament(employee.departmen) << endl;
	cout << "Fullname:\n";
	printName(employee.name);
	cout << "Position:\t" << printPosition(employee.position) << endl;
	if (employee.position == Position::Manager)
		cout << "Subordinates:\t" << employee.nSubordinates << endl << endl;
}
void printDataBase(Employees** employees, unsigned nEmployees)
{
	for (size_t i = 0; i < nEmployees; i++)
	{
		cout << "\n\tEmploye #" << i + 1 << " :\n";
		printEmployee(*employees[i]);
	}
}
void addEmployee(Employees**& employees, unsigned& nEmployees)
{
	cout << "\nAdd new employee\n";
	Employees** res = new Employees * [nEmployees + 1];
	for (size_t i = 0; i < nEmployees; i++)
		res[i] = employees[i];
	res[nEmployees] = new Employees;
	++nEmployees;
	delete[] employees;
	employees = res;
	enterEmployee(*employees[nEmployees - 1]);
}
Employees** searchByNameAllResult(Employees** employees, unsigned nEmployees, const char* word, unsigned& counterOut)
{
	if (employees == nullptr || nEmployees <= 0 || !word)
	{
		cout << "Check the passed parameters!\n";
		return nullptr;
	}
	Employees** res;
	if (nEmployees == 1)
	{
		if (strstr((**employees).name.firstName, word) || strstr((**employees).name.lastName, word))
		{
			res = new Employees*;
			*res = *employees;
			counterOut = 1;
			return res;
		}
		else
		{
			counterOut = 0;
			return nullptr;
		}
	}
	else
	{
		res = searchByNameAllResult(employees + 1, nEmployees - 1, word, counterOut);
		if (strstr((**employees).name.firstName, word) || strstr((**employees).name.lastName, word))
		{
			if (!res)
			{
				res = new Employees*;
				*res = *employees;
			}
			else if (res)
			{
				Employees** tmp = new Employees * [counterOut + 1];
				tmp[0] = *employees;
				for (size_t j = 0; j < counterOut; j++)
					tmp[j + 1] = res[j];
				if (counterOut == 1)
					delete res;
				else
					delete[] res;
				res = tmp;
			}
			counterOut++;
		}
		return res;
	}
}
Employees* searchByNameOneResult(Employees** employees, unsigned nEmployees)
{
	int i_tmp;
	char c_tmp[BUF];
	unsigned sizeResult;
	Employees** res;
	cout << "Enter the name: ";
	do
	{
		cin >> c_tmp;
		res = searchByNameAllResult(employees, nEmployees, c_tmp, sizeResult);
		if (res == nullptr)
		{
			cout << "We couldn't find eny employee.\nSet - 0 To try again\nSet - 1 to Exit\n";
			int answer = verificateNum(0, 1);
			if (answer)
				return nullptr;
		}
	} while (res == nullptr);
	cout << "All result:\n";
	printDataBase(res, sizeResult);
	cout << "Enter the index or enter 0 - if you have not found an employee: ";
	i_tmp = (verificateNum(0, sizeResult) - 1);
	if (i_tmp == -1)
		return nullptr;
	return res[i_tmp];
}
Employees* searchEmployee(Employees** employees, unsigned nEmployees)
{
	cout << "\nSearch by name(0) or by index(1)?: ";
	int answer = verificateNum(0, 1);
	int i_tmp;

	if (!answer)
	{
		return searchByNameOneResult(employees, nEmployees);
	}
	else
	{
		printDataBase(employees, nEmployees);
		cout << "Enter the index: or enter 0 - if you have not found an employee: ";
		i_tmp = (verificateNum(0, nEmployees) - 1);
		if (i_tmp == -1)
			return nullptr;
		return employees[i_tmp];
	}
}
void deleteEmployee(Employees**& employees, unsigned& nEmployees, Employees* toDelete)
{
	Employees** res = new Employees * [nEmployees - 1];
	for (size_t i = 0, j = 0; i < nEmployees; i++)
	{
		if (employees[i] != toDelete)
		{
			res[j] = employees[i];
			j++;
		}
	}
	delete toDelete;
	--nEmployees;
	delete[] employees;
	employees = res;
}
bool searchAndDeleteEmployee(Employees**& employees, unsigned& nEmployees)
{
	cout << "\nLet's find an employee whose data needs to be deleted\n";
	Employees* candidat = searchEmployee(employees, nEmployees);
	if (candidat)
	{
		deleteEmployee(employees, nEmployees, candidat);
		return 1;
	}
	else
		return 0;
}
void correctiosPosition(Employees& employee, Position newPosition)
{
	if (int(newPosition) < 0 || PositionsNum < int(newPosition))
	{
		cout << "You have wrong new position\n";
		return;
	}
	if (employee.position == newPosition)
	{
		cout << "You have chosen the same position\n";
		return;
	}
	if (employee.position != Position::Manager && newPosition != Position::Manager)
		employee.position = newPosition;
	else
	{
		employee.position = newPosition;
		if (employee.position == Position::Manager)
			enterSubordinates(employee.nSubordinates);
		else
		{
			for (int i = 0; i < months; i++)
				employee.hoursWorked[i] = 0;
		}
	}
}
char* returnFullName(const Employees& employee, int sizeName)
{
	int SIZE = sizeName * 2;
	char* result = new char [SIZE] {};
	strcpy_s(result, SIZE, employee.name.firstName);
	strcat_s(result, SIZE, " ");
	strcat_s(result, SIZE, employee.name.lastName);
	return result;
}
void sortByName(Employees** employees, unsigned nEmployees)
{
	if (!nEmployees)
		return;
	char** fullNames = new char* [nEmployees];
	for (size_t i = 0; i < nEmployees; i++)
	{
		fullNames[i] = new char[BUF * 2];
		fullNames[i] = returnFullName(*employees[i], BUF);
	}

	bool swapped;
	int counter = 0;
	Employees* tmp{};
	do
	{
		swapped = 0;
		for (size_t i = 0; i < nEmployees - 1 - counter; i++)
		{
			int result = _stricmp(fullNames[i], fullNames[i + 1]);
			if (0 < result)
			{
				swapped = 1;			//свопаємо в основному масиві
				tmp = employees[i];
				employees[i] = employees[i + 1];
				employees[i + 1] = tmp;
				//свопаємо в масиві де відображаються повні імена
				char* c_tmp = fullNames[i];
				fullNames[i] = fullNames[i + 1];
				fullNames[i + 1] = c_tmp;
			}
		}
		counter++;
	} while (swapped);
	for (size_t i = 0; i < nEmployees; i++)
		delete[] fullNames[i];
	delete[] fullNames;
}
void sortEmployees(Employees** employees, unsigned nEmployees)
{
	// сортує по підрозділу
	bool swapped;
	unsigned counter = 0;
	Employees* tmp{};
	do
	{
		swapped = 0;
		for (size_t j = 0; j < nEmployees - 1 - counter; j++)
		{
			if (employees[j + 1]->departmen < employees[j]->departmen)
			{
				swapped = 1;
				tmp = employees[j];
				employees[j] = employees[j + 1];
				employees[j + 1] = tmp;
			}
		}
		counter++;
	} while (swapped);
	//пошук діапазону в межах одного підрозділу і в ньому сортування по імені
	counter = 0;
	for (int i = 0; i <= DepartmentNum; i++)
	{
		int leftRange = counter;
		while (counter < nEmployees && employees[counter]->departmen == Department(i))
			counter++;
		if (leftRange != counter)
			sortByName(employees + leftRange, counter - leftRange);
	}
}
int timeSheetDepartmentByMonth(Employees** employees, unsigned nEmployees, Department department, int month, bool returnOnly)
{
	if (month < 0 || months <= month)
	{
		cout << "Month data is wrong\n";
		return 0;
	}
	int counterEmployees = 0;
	int counterNonWorkingDays = 0;
	if (!returnOnly)
		cout << "\n\tTime sheet of the " << printDepartament(department) << " department for the " << printMonth(Months(month)) << endl;
	for (size_t i = 0; i < nEmployees; i++)
	{
		if (department == employees[i]->departmen || department == Department::None)
		{
			if (!returnOnly)
			{
				cout << returnFullName(*employees[i], BUF) << ". Position : " << printPosition((*employees[i]).position) << endl;
				if (employees[i]->position != Position::Manager)
					cout << "\t\tWorked hours:   \t" << (*employees[i]).hoursWorked[month] << " hours" << endl;
				cout << "\t\tNon-working days:\t" << (*employees[i]).nonWorkingDays[month] << " days" << endl;
			}
			counterEmployees++;
			counterNonWorkingDays += (*employees[i]).nonWorkingDays[month];
		}
	}
	if (!counterEmployees && !returnOnly)
		cout << "There are no employees in this department\n";
	return counterNonWorkingDays;
}
void timeSheetEmployeeByYear(Employees& employees)
{
	int counterTotalNonWorkingDays = 0;
	int counterTotalTime = 0;
	if (employees.position != Position::Manager)
	{
		cout << "Worked hours:   \t";
		for (size_t i = 0; i < months; i++)
		{
			cout << employees.hoursWorked[i] << "\t";
			counterTotalTime += employees.hoursWorked[i];
		}
	}
	if (counterTotalTime)
		cout << counterTotalTime;
	cout << "\nNon-working days:\t";
	for (size_t i = 0; i < months; i++)
	{
		cout << employees.nonWorkingDays[i] << "\t";
		counterTotalNonWorkingDays += employees.nonWorkingDays[i];
	}
	cout << counterTotalNonWorkingDays;
	cout << endl;
}
void calculateNonWorkingDaysByDepartment(Employees** employees, unsigned nEmployees, Department department)
{
	int counterEmployees;
	if (department == Department::None)
		counterEmployees = nEmployees;
	else
		counterEmployees = howManyEmployeesInDepartment(employees, nEmployees, department);
	int summaryNonWorkingDays[months]{};
	int counterTotal = 0;
	double averageVal = 0;
	cout << "Non-working days:\nSummary:\t\t";
	for (int i = 0; i < months; i++)
	{
		summaryNonWorkingDays[i] = timeSheetDepartmentByMonth(employees, nEmployees, department, i, 1);
		counterTotal += summaryNonWorkingDays[i];
		cout << summaryNonWorkingDays[i] << "\t";
	}
	cout << counterTotal << " \n";
	cout << "Average:\t\t";
	for (int i = 0; i < months; i++)
	{
		if (!summaryNonWorkingDays[i] || !counterEmployees)
			cout << 0 << "\t";
		else
		{
			averageVal = double(summaryNonWorkingDays[i]) / counterEmployees;
			cout << fixed << setprecision(1) << averageVal << "\t";
		}
	}
	if (!counterTotal || !counterEmployees)
		cout << 0 << " \n";
	else
	{
		averageVal = double(counterTotal) / counterEmployees;
		cout << fixed << setprecision(1) << averageVal << " \n";
	}
}
int howManyEmployeesInDepartment(Employees** employees, unsigned nEmployees, Department department)
{
	int counterEmployees = 0;
	for (size_t i = 0; i < nEmployees; i++)
	{
		if (department == employees[i]->departmen)
			counterEmployees++;
	}
	return counterEmployees;
}
void totalTimeSheet(Employees** employees, unsigned nEmployees)
{
	char returnName[BUF * 2]{};
	cout << "\t\t\t\t\tWork time sheet.\n\n";

	cout << "\t|Departments|\t";
	for (size_t i = 0; i < months; i++)
	{
		strncpy_s(returnName, printMonth(Months(i)), 3);
		cout << returnName << '\t';
	}
	cout << "Total\n";
	for (int i = 0; i < 125; i++)
		cout << '-';
	cout << endl;

	for (int i = 1; i <= DepartmentNum; i++)
	{
		cout << "\n\t" << printDepartament(Department(i)) << endl;
		for (size_t j = 0; j < nEmployees; j++)
		{
			if ((*employees[j]).departmen == Department(i))
			{
				cout << returnFullName(*employees[j], BUF) << ". " << printPosition((*employees[j]).position) << endl;
				timeSheetEmployeeByYear(*employees[j]);
			}
		}
		for (int i = 0; i < 125; i++)
			cout << '-';
		cout << endl;
		calculateNonWorkingDaysByDepartment(employees, nEmployees, Department(i));
		for (int i = 0; i < 125; i++)
			cout << '-';
		cout << endl;
	}
	cout << "Total by company\n";
	calculateNonWorkingDaysByDepartment(employees, nEmployees, Department::None);
	for (int i = 0; i < 125; i++)
		cout << '-';
	cout << endl;
}
int saveTotalTimeSheet(Employees** employees, unsigned nEmployees, string fname)
{
	ofstream fout;
	fout.open(fname);
	if (!fout)
		return EXIT_FAILURE;

	char monthShortName[BUF * 2]{};
	fout << "\t\t\t\t\tWork time sheet.\n\n";

	fout << "\t|Departments|\t";
	for (size_t i = 0; i < months; i++)
	{
		strncpy_s(monthShortName, printMonth(Months(i)), 3);
		fout << monthShortName << '\t';
	}
	fout << "Total\n";
	for (int i = 0; i < 125; i++)
		fout << '-';
	fout << endl;

	int counterEmployees;
	int summaryNonWorkingDaysAll[months]{};
	int counterTotal = 0;
	double averageVal = 0;
	for (int i = 1; i <= DepartmentNum; i++)
	{
		counterEmployees = 0;
		int counterTotalNonWorkingDays = 0;
		int counterTotalTime = 0;
		int summaryNonWorkingDays[months]{};
		fout << "\n\t" << printDepartament(Department(i)) << endl;
		for (size_t j = 0; j < nEmployees; j++)
		{
			counterTotalTime = 0;
			counterTotalNonWorkingDays = 0;
			if ((*employees[j]).departmen == Department(i))
			{
				counterEmployees++;
				fout << returnFullName(*employees[j], BUF) << ". " << printPosition((*employees[j]).position) << endl;
				if ((*employees[j]).position != Position::Manager)
				{
					cout << "Worked hours:   \t\t";
					for (size_t i = 0; i < months; i++)
					{
						fout << (*employees[j]).hoursWorked[i] << "\t";
						counterTotalTime += (*employees[j]).hoursWorked[i];
					}
				}
				if (counterTotalTime)
					fout << counterTotalTime << endl;
				fout << "Non-working days:\t\t";
				for (size_t i = 0; i < months; i++)
				{
					fout << (*employees[j]).nonWorkingDays[i] << "\t";
					counterTotalNonWorkingDays += (*employees[j]).nonWorkingDays[i];
					summaryNonWorkingDays[i] += (*employees[j]).nonWorkingDays[i];
					summaryNonWorkingDaysAll[i] += summaryNonWorkingDays[i];
				}
				fout << counterTotalNonWorkingDays;
				fout << endl;
			}
		}
		for (int i = 0; i < 125; i++)
			fout << '-';
		fout << endl;
		counterTotal = 0;
		averageVal = 0;
		fout << "Non-working days:\nSummary:\t\t\t";
		for (int i = 0; i < months; i++)
		{
			counterTotal += summaryNonWorkingDays[i];
			fout << summaryNonWorkingDays[i] << "\t";
		}
		fout << counterTotal << " \n";
		fout << "Average:\t\t\t";
		for (int i = 0; i < months; i++)
		{
			if (!summaryNonWorkingDays[i] || !counterEmployees)
				fout << 0 << "\t";
			else
			{
				averageVal = double(summaryNonWorkingDays[i]) / counterEmployees;
				fout << fixed << setprecision(1) << averageVal << "\t";
			}
		}
		if (!counterTotal || !counterEmployees)
			fout << 0 << " \n";
		else
		{
			averageVal = double(counterTotal) / counterEmployees;
			fout << averageVal << " \n";
		}

		for (int i = 0; i < 125; i++)
			fout << '-';
		fout << endl;
	}
	fout << "Total by company\n";
	counterEmployees = nEmployees;
	fout << "Non-working days:\nSummary:\t\t\t";
	for (int i = 0; i < months; i++)
	{
		counterTotal += summaryNonWorkingDaysAll[i];
		fout << summaryNonWorkingDaysAll[i] << "\t";
	}
	fout << counterTotal << " \n";
	fout << "Average:\t\t\t";
	for (int i = 0; i < months; i++)
	{
		if (!summaryNonWorkingDaysAll[i] || !counterEmployees)
			fout << 0 << "\t";
		else
		{
			averageVal = double(summaryNonWorkingDaysAll[i]) / counterEmployees;
			fout << fixed << setprecision(1) << averageVal << "\t";
		}
	}
	if (!counterTotal || !counterEmployees)
		fout << 0 << " \n";
	else
	{
		averageVal = double(counterTotal) / counterEmployees;
		fout << averageVal << " \n";
	}

	for (int i = 0; i < 125; i++)
		fout << '-';

	fout.close();
	return 0;
}
void timeSheetEmployeeByMonth(Employees& employees, int month)
{
	cout << returnFullName(employees, BUF) << ". Position - " << printPosition(employees.position) << endl;
	int counterTotalNonWorkingDays = 0;
	int counterTotalTime = 0;
	cout << printMonth(Months(month)) << ":\n";
	if (employees.position != Position::Manager)
		cout << "\tWorked hours:\t" << employees.hoursWorked[month] << " hours" << endl;
	counterTotalTime += employees.hoursWorked[month];
	cout << "\tNon-working days:\t" << employees.nonWorkingDays[month] << " days" << endl;
	counterTotalNonWorkingDays += employees.nonWorkingDays[month];

}


void forExampleDB(Employees**& employees, unsigned& nEmployees)
{
	nEmployees = 3;
	createDataBase(employees, nEmployees);
	*employees[0] =
	{
		Department::Legal,
	FullName  {
		"Walter",
	"Gregman",
	},
	Position::Manager,
	1,
		{ 1, 1, 1, 1, 1, 1 , 1, 1, 1, 1, 1, 1}
	};
	*employees[1] =
	{
		Department::Production,
	FullName  {
		"Greg",
	"Harrison",
	},
	Position::Manager,
	1,
		{ 1, 1, 1, 1, 1, 1 , 1, 1, 1, 1, 1, 1}
	};
	*employees[2] =
	{
		Department::Production,
	FullName  {
		"Peter",
	"Samoel",
	},
	Position::Manager,
	1,
		{ 1, 1, 1, 1, 1, 1 , 1, 1, 1, 1, 1, 1}
	};
}
