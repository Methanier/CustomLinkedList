/*
	Charles Cozart
	CSC382
	Tests for LinkedListClass
*/

#include<cstdlib>
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Employee.h"

using namespace std;

//Function Templates
bool AutoTestDefaultConstructor();
bool AutoTestConstructorWithListParameter();
bool AutoTestDestructor();
bool AutoTestInsert();
bool AutoTestContains();
bool AutoTestFind();
bool AutoTestDelete();
void RunAutoTests();
void RunManualTest();
void UserOptions();
bool CreateEmptyLinkedList(int &);
void InsertToList(int &);
Employee* CreateEmployee();
Employee* DefaultEmployee();
void DeleteFromList(int &);
void ChooseListToAddTo();
void ChooseListToPrint();
void ChooseListToSearch();
void ChooseListToDeleteFrom();
void PrintIntList();
void PrintStrList();
void PrintFloatList();
void PrintEmpList();

//LinkedLists for manual testing
LinkedList<int> *manualTestint;
LinkedList<string> *manualTestString;
LinkedList<float> *manualFloatList;
LinkedList<Employee> *manualEmployeeList;


int main()
{
	UserOptions();	
}

//Runs Automatic test on default Constructor
bool AutoTestDefaultConstructor()
{
	bool result = false;

	LinkedList<int> *testList = new LinkedList<int>();

	if (testList != nullptr)
		result = true;
	
	return result;
}

//Runs Automatic test on copy constructor
bool AutoTestConstructorWithListParameter()
{
	bool result = false;

	LinkedList<int> *testOne = new LinkedList<int>();

	int one = 1;
	int two = 2;
	int three = 3;

	testOne->Insert(one);
	testOne->Insert(two);
	testOne->Insert(three);

	LinkedList<int> *testTwo = new LinkedList<int>(*testOne);

	for (int i = 0; i < testOne->Size(); i++)
	{
		if (testOne->AtIndex(i) == testTwo->AtIndex(i))
		{
			result = true;
		}
		else
		{

			result = false;
		}
	}

	return result;
}

//Runs test on destructor
bool AutoTestDestructor()
{
	bool result = false;

	LinkedList<int> *testOne = new LinkedList<int>();

	int one = 1;
	int two = 2;
	int three = 3;

	testOne->Insert(one);
	testOne->Insert(two);
	testOne->Insert(three);

	testOne->LinkedList::~LinkedList();

	if (testOne->Size() == 0 && testOne->Begin() == nullptr && testOne->End() == nullptr)
	{
		result = true;
	}
	
	return result;
}

//Runs auto test on insert
bool AutoTestInsert()
{
	bool result = false;

	LinkedList<int> *test = new LinkedList<int>();

	int one = 1;

	test->Insert(one);

	if (test->Size() > 0 && test->AtIndex(0) == one)
		result = true;

	return result;
}

//Runs auto test on contains function
bool AutoTestContains()
{
	bool result = false;

	LinkedList<int> *test = new LinkedList<int>();

	int one = 1;
	int two = 2;
	int three = 3;
	int zero = 0;

	test->Insert(one);
	test->Insert(two);
	test->Insert(three);
	test->Insert(zero);

	if (test->Contains(three))
		result = true;

	return result;
}

//Runs test on find function
bool AutoTestFind()
{
	bool result = false;

	LinkedList<int> *test = new LinkedList<int>();

	int one = 1;
	int two = 2;
	int three = 3;

	test->Insert(one);
	test->Insert(two);
	test->Insert(three);

	if (test->Find(two) == two)
		result = true;
	

	return result;
}

//Runs test on delete function
bool AutoTestDelete()
{
	bool result = false;

	LinkedList<int> *test = new LinkedList<int>();

	int one = 1;
	int two = 2;
	int three = 3;
	int zero = 0;

	test->Insert(one);
	test->Insert(two);
	test->Insert(three);
	test->Insert(zero);

	test->Delete(zero);

	if (!test->Contains(zero))
	{
		result = true;
	}

	return result;
}

//Runs all auto tests
void RunAutoTests()
{
	bool defaultConstructor = AutoTestDefaultConstructor();

	if (defaultConstructor)
	{
		cout << "Default Constructor Works " << endl;
	}
	else
	{
		cout << "Fail on default constructor " << endl;
	}

	bool listCopyConstructor = AutoTestConstructorWithListParameter();

	if (listCopyConstructor)
	{
		cout << endl << "Copy constructor works" << endl;
	}
	else
	{
		cout << endl << "Fail on copy constructor" << endl;
	}

	bool destuctor = AutoTestDestructor();

	if (destuctor)
	{
		cout << endl << "Destuctor works" << endl;
	}
	else
	{
		cout << endl << "Fail on destructor" << endl;
	}

	bool insert = AutoTestInsert();

	if (insert)
	{
		cout << endl << "Insert works" << endl;
	}
	else
	{
		cout << endl << "Fail on insert" << endl;
	}

	bool contains = AutoTestContains();

	if (contains)
	{
		cout << endl << "Contains works" << endl;
	}
	else
	{
		cout << endl << "Fail on contains" << endl;
	}

	bool find = AutoTestFind();

	if (find)
	{
		cout << endl << "Find works" << endl;
	}
	else
	{
		cout << endl << "Fail on find" << endl;
	}

	bool deleteData = AutoTestDelete();

	if (deleteData)
	{
		cout << endl << "Delete works" << endl;
	}
	else
	{
		cout << endl << "Fail on delete" << endl;
	}
}

//Input options for running manual tests
void RunManualTest()
{
	int userInput = -1;

	while (userInput != 9)
	{
		cout << endl;
		cout << "Manual Testing Choose an option" << endl;
		cout << "1. Create List of integers" << endl;
		cout << "2. Create List of string" << endl;
		cout << "3. Create List of floats" << endl;
		cout << "4. Create List of Employee class" << endl;
		cout << "5. Add to a List" << endl;
		cout << "6. Print a List" << endl;
		cout << "7. Search a List" << endl;
		cout << "8. Delete from a List" << endl;
		cout << "9.  Previous Menu" << endl;

		string inputString;

		try {
			getline(cin, inputString);

			userInput = stoi(inputString);

			switch (userInput)
			{
			case 1:
				if (CreateEmptyLinkedList(userInput))
					cout << "Successfully created list of integers" << endl;
				break;
			case 2:
				if (CreateEmptyLinkedList(userInput))
					cout << "Successfully created list of strings" << endl;
				break;
			case 3:
				if (CreateEmptyLinkedList(userInput))
					cout << "Successfully created list of floats" << endl;
				break;
			case 4:
				if (CreateEmptyLinkedList(userInput))
					cout << "Successfully created list of Employees" << endl;
				break;
			case 5:
				ChooseListToAddTo();
				break;
			case 6:
				ChooseListToPrint();
				break;
			case 7:
				ChooseListToSearch();
				break;
			case 8:
				ChooseListToDeleteFrom();
				break;
			case 9:
				UserOptions();
				break;
			default:
				cout << "Invalid Input. Please select an option" << endl;
				RunManualTest();
				break;
			}
		}
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			RunManualTest();
		}
		
	}
}

//User Options for application startup
void UserOptions()
{
	int input = -1;

	while (input != 3)
	{
		cout << "Choose an Option Below!" << endl;
		cout << "1. Run Manual Testing of LinkedList Class" << endl;
		cout << "2. Run Automatic Testing of LinkedList Class" << endl;
		cout << "3. Exit Application" << endl;

		string inputString;

		try
		{
			getline(cin, inputString);

			input = stoi(inputString);

			if (input == 1)
			{
				RunManualTest();
			}
			else if (input == 2)
			{
				RunAutoTests();
			}
			else if (input != 3)
			{
				cout << "Invalid Input please select an option" << endl << endl;
				UserOptions();
			}
		}
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			UserOptions();
		}
	}
	exit(0);
}

//Creates an empty list specfied by the user input
bool CreateEmptyLinkedList(int & input)
{
	bool result = false;

	switch(input)
	{
	case 1:
		manualTestint = new LinkedList<int>();
		if (manualTestint != nullptr)
			result = true;
		break;
	case 2:
		manualTestString = new LinkedList<string>();
		if (manualTestString != nullptr)
			result = true;
		break;
	case 3:
		manualFloatList = new LinkedList<float>();
		if (manualFloatList != nullptr)
			result = true;
		break;
	case 4:
		manualEmployeeList = new LinkedList<Employee>();
		if (manualEmployeeList != nullptr)
			result = true;
		break;
	}

	return result;
}

//Inserts to a list specified by user input
void InsertToList(int & input) 
{
	int intToAdd;
	string stringToAdd;
	float floatToAdd;
	int caseInput = -1;

	string inputString;

	try
	{
		cout << endl;
		switch (input)
		{
		case 1:
			if (manualTestint != nullptr)
			{
				cout << "Would you like to insert an integer to the list? y/n" << endl;
				getline(cin, inputString);
				if (inputString == "y" || inputString == "Y")
				{
					cout << endl;
					cout << "Enter an integer to add to the list" << endl;
					getline(cin, inputString);
					intToAdd = stoi(inputString);
					manualTestint->Insert(intToAdd);
					cout << "The number " << intToAdd << " was added to the list" << endl;
					InsertToList(input);
				}
				else if (inputString == "n" || inputString == "N")
				{
					return;
				}
				else
				{
					cout << "Invlaid input please select an option" << endl;
					InsertToList(input);
				}
			}
			else
			{
				cout << "The integer list does not exist. Please initilize one first" << endl;
				ChooseListToAddTo();
			}
			break;
		case 2:
			if (manualTestString != nullptr)
			{
				cout << "Would you like to insert a string to the list? y/n" << endl;
				getline(cin, inputString);
				if (inputString == "y" || inputString == "Y")
				{
					cout << endl;
					cout << "Enter a string to add to the list" << endl;
					getline(cin, inputString);
					stringToAdd = inputString;
					manualTestString->Insert(stringToAdd);
					cout << "The string \"" << stringToAdd << "\" was added to the list" << endl;
					InsertToList(input);
				}
				else if (inputString == "n" || inputString == "N")
				{
					return;
				}
				else
				{
					cout << "Invlaid input please select an option" << endl;
					InsertToList(input);
				}
			}
			else
			{
				cout << "The string list does not exist. Please initilize one first" << endl;
				ChooseListToAddTo();
			}
			break;
		case 3:
			if (manualFloatList != nullptr)
			{
				cout << "Would you like to insert a float to the list? y/n" << endl;
				getline(cin, inputString);
				if (inputString == "y" || inputString == "Y")
				{
					cout << endl;
					cout << "Enter a float to add to the list" << endl;
					getline(cin, inputString);
					floatToAdd = stof(inputString);
					manualFloatList->Insert(floatToAdd);
					cout << "The number " << floatToAdd << " was added to the list" << endl;
					InsertToList(input);
				}
				else if (inputString == "n" || inputString == "N")
				{
					return;
				}
				else
				{
					cout << "Invlaid input please select an option" << endl;
					InsertToList(input);
				}
			}
			else
			{
				cout << "The float list does not exist. Please initialize one first" << endl;
				ChooseListToAddTo();
			}
			break;
		case 4:
			if (manualEmployeeList != nullptr)
			{
				cout << "Would you like to insert an Employee to the list? y/n" << endl;
				getline(cin, inputString);
				if (inputString == "y" || inputString == "Y")
				{
					while (caseInput != 3)
					{
						cout << endl;
						cout << "Select an option" << endl;
						cout << "1. Create Custom Employee" << endl;
						cout << "2. Use Default Employee" << endl;
						cout << "3. Back" << endl;
						getline(cin, inputString);
						caseInput = stoi(inputString);

						switch (caseInput)
						{
						case 1:
							Employee *customEmp;
							customEmp = CreateEmployee();
							manualEmployeeList->Insert(*customEmp);
							break;
						case 2:
							Employee *defaultEmp;
							defaultEmp = DefaultEmployee();
							manualEmployeeList->Insert(*defaultEmp);
							break;
						default:
							cout << "Invalid Input, please select an option" << endl;
							break;
						}
					}
				}
				else if (inputString == "n" || inputString == "N")
				{
					return;
				}
				else
				{
					cout << "Invlaid input please select an option" << endl;
					InsertToList(input);
				}
			}
			else
			{
				cout << "The Employee list does not exist. Please initialize one first" << endl;
				ChooseListToAddTo();
			}
			break;
		default:
			cout << "Invalid input. Please select an option" << endl;
			ChooseListToAddTo();
			break;
		}
	}
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		InsertToList(input);
	}
}

//Creates a custom object of type Employee
Employee* CreateEmployee()
{
	string empName;
	int empID;
	float empSalary;
	bool validInput = false;

	string inputString;

	while (!validInput)
	{
		try
		{
			cout << endl;
			cout << "Enter the Employee Name" << endl;
			getline(cin, inputString);
			empName = inputString;

			cout << endl << "Enter Employee ID number" << endl;
			getline(cin, inputString);
			empID = stoi(inputString);

			cout << endl << "Enter Employee salary" << endl;
			getline(cin, inputString);
			empSalary = stof(inputString);
			validInput = true;
		}
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			validInput = false;
		}
	}

	Employee *temp = new Employee(empName, empID, empSalary);

	return temp;

}

//Creates an Employee object using default constructor
Employee* DefaultEmployee()
{
	Employee *temp = new Employee();

	return temp;
}

//Deletes from a specified list based on user input
void DeleteFromList(int & input)
{
	string inputString;
	int deleteInt;
	string deleteStr;
	float deleteFloat;
	Employee *deleteEmployee;

	try
	{
		cout << endl;
		switch (input)
		{
		case 1:
			cout << "Would you like to remove a value from the integer list? y/n" << endl;
			getline(cin, inputString);

			if (inputString == "y" || inputString == "Y")
			{
				cout << "Enter the integer value you want to remove" << endl;
				getline(cin, inputString);
				deleteInt = stoi(inputString);

				if (!manualTestint->Contains(deleteInt))
				{
					cout << "The value entered was not in the list" << endl;
					DeleteFromList(input);
				}
				else
				{
					manualTestint->Delete(deleteInt);
					cout << deleteInt << " was removed from the list" << endl;
					DeleteFromList(input);
				}
			}
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTest();
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
				DeleteFromList(input);
			}
			break;
		case 2:
			cout << "Would you like to remove a value from the string list? y/n" << endl;
			getline(cin, inputString);

			if (inputString == "y" || inputString == "Y")
			{
				cout << "Enter the string value you want to remove" << endl;
				getline(cin, inputString);
				deleteStr = inputString;

				if (!manualTestString->Contains(deleteStr))
				{
					cout << "The value entered was not found in the list" << endl;
					DeleteFromList(input);
				}
				else
				{
					manualTestString->Delete(deleteStr);
					cout << "\"" << deleteStr << "\" was removed from the list" << endl;
					DeleteFromList(input);
				}
			}
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTest();
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
				DeleteFromList(input);
			}
			break;
		case 3:
			cout << "Would you like to remove a value from the float list? y/n" << endl;
			getline(cin, inputString);

			if (inputString == "y" || inputString == "Y")
			{
				cout << "Enter the float value you want to remove" << endl;
				getline(cin, inputString);
				deleteFloat = stof(inputString);

				if (!manualFloatList->Contains(deleteFloat))
				{
					cout << "The value entered was not found in the list" << endl;
					DeleteFromList(input);
				}
				else
				{
					manualFloatList->Delete(deleteFloat);
					cout << deleteFloat << " was removed from the list" << endl;
					DeleteFromList(input);
				}
			}
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTest();
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
				DeleteFromList(input);
			}
			break;
		case 4:
			cout << "Would you like to remove a value from the Employee list? y/n" << endl;
			getline(cin, inputString);

			if (inputString == "y" || inputString == "Y")
			{
				deleteEmployee = CreateEmployee();

				if (!manualEmployeeList->Contains(*deleteEmployee))
				{
					cout << "The Employee was not found in the list" << endl;
					DeleteFromList(input);
				}
				else
				{
					manualEmployeeList->Delete(*deleteEmployee);
					cout << "The following employee was removed from the list" << deleteEmployee->ToString() << endl;
					DeleteFromList(input);
				}
			}
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTest();
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
				DeleteFromList(input);
			}
			break;
		}
	}
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		DeleteFromList(input);
	}
}

//Function for user to select which list to insert items in
void ChooseListToAddTo()
{
	int input;
	string inputString;

	try
	{
		cout << endl;
		cout << "Chose a list to Add items to" << endl;
		cout << "1. Integer List" << endl;
		cout << "2. String List" << endl;
		cout << "3. Float List" << endl;
		cout << "4. Employee List" << endl;
		cout << "5. Previous Menu" << endl;
		getline(cin, inputString);
		input = stoi(inputString);

		if (input == 5)
			RunManualTest();
		else
			InsertToList(input);
	}
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		ChooseListToAddTo();
	}

	
}

//Function for user to choose which list to print
void ChooseListToPrint()
{
	string inputString;
	int input;

	try
	{
		cout << endl;
		cout << "Select a list to print" << endl;
		cout << "1. Integer List" << endl;
		cout << "2. String List" << endl;
		cout << "3. Float List" << endl;
		cout << "4. Employee List" << endl;
		cout << "5. Previous Menu" << endl;
		getline(cin, inputString);
		input = stoi(inputString);

		switch (input)
		{
		case 1:
			PrintIntList();
			break;
		case 2:
			PrintStrList();
			break;
		case 3:
			PrintFloatList();
			break;
		case 4:
			PrintEmpList();
			break;
		case 5:
			RunManualTest();
			break;
		default:
			cout << "Invalid Input, please select an option" << endl;
			ChooseListToPrint();
			break;
		}
	}
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		ChooseListToPrint();
	}
	
}

//Function for user to choose which list to find objects in
void ChooseListToSearch()
{
	string inputString;
	int input;

	int intToFind;
	string stringToFind;
	float floatToFind;
	Employee *empToFind;

	try
	{
		cout << endl;
		cout << "Select a list to search" << endl;
		cout << "1. Integer List" << endl;
		cout << "2. String List" << endl;
		cout << "3. Float List" << endl;
		cout << "4. Employee List" << endl;
		cout << "5. Previous Menu" << endl;

		getline(cin, inputString);
		input = stoi(inputString);

		switch (input)
		{
		case 1:
			cout << "Would you like to search for an integer? y/n" << endl;
			getline(cin, inputString);
			if (inputString == "y" || inputString == "Y")
			{
				cout << "Enter the integer you want to find" << endl;
				getline(cin, inputString);
				intToFind = stoi(inputString);

				int temp = manualTestint->Find(intToFind);

				if (temp == intToFind)
				{
					cout << intToFind << " is in the list" << endl;
					ChooseListToSearch();
				}
				else
				{
					cout << intToFind << " was not found" << endl;
					ChooseListToSearch();
				}
			}
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTest();
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
				ChooseListToSearch();
			}
			break;
		case 2:
			cout << "Would you like to search for a string? y/n" << endl;
			getline(cin, inputString);
			if (inputString == "y" || inputString == "Y")
			{
				cout << "Enter the string you want to find" << endl;
				getline(cin, inputString);
				stringToFind = inputString;

				string temp = manualTestString->Find(stringToFind);

				if (temp == stringToFind)
				{
					cout << "\"" << stringToFind << "\" is in the list" << endl;
					ChooseListToSearch();
				}
				else
				{
					cout << "\"" << stringToFind << "\" was not found" << endl;
					ChooseListToSearch();
				}
			}
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTest();
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
				ChooseListToSearch();
			}
			break;
		case 3:
			cout << "Would you like to search for a float? y/n" << endl;
			getline(cin, inputString);
			if (inputString == "y" || inputString == "Y")
			{
				cout << "Enter the float you want to find" << endl;
				getline(cin, inputString);
				floatToFind = stof(inputString);

				float temp = manualFloatList->Find(floatToFind);

				if (temp == floatToFind)
				{
					cout << floatToFind << " is in the list" << endl;
					ChooseListToSearch();
				}
				else
				{
					cout << floatToFind << " was not found" << endl;
					ChooseListToSearch();
				}
			}
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTest();
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
				ChooseListToSearch();
			}
			break;
		case 4:
			cout << "Would you like to search for a string? y/n" << endl;
			getline(cin, inputString);
			if (inputString == "y" || inputString == "Y")
			{
				empToFind = CreateEmployee();

				Employee temp = manualEmployeeList->Find(*empToFind);

				if (temp == *empToFind)
				{
					cout << "\"" << stringToFind << "\" is in the list" << endl;
					ChooseListToSearch();
				}
				else
				{
					cout << "\"" << stringToFind << "\" was not found" << endl;
					ChooseListToSearch();
				}
			}
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTest();
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
				ChooseListToSearch();
			}
			break;
		case 5:
			RunManualTest();
			break;
		default:
			cout << "Invalid input, please select an option" << endl;
			ChooseListToSearch();
			break;
		}
	}
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		ChooseListToSearch();
	}
}

//Function for user to choose which list to delete objects from
void ChooseListToDeleteFrom()
{
	string inputString;
	int input;

	try
	{
		cout << endl;
		cout << "Selete a list to delete from" << endl;
		cout << "1. Integer List" << endl;
		cout << "2. String List" << endl;
		cout << "3. Float List" << endl;
		cout << "4. Employee List" << endl;
		cout << "5. Previous Menu" << endl;

		getline(cin, inputString);
		input = stoi(inputString);

		switch (input)
		{
		case 1:
			DeleteFromList(input);
			break;
		case 2:
			DeleteFromList(input);
			break;
		case 3:
			DeleteFromList(input);
			break;
		case 4:
			DeleteFromList(input);
			break;
		case 5:
			DeleteFromList(input);
			break;
		default:
			cout << "Invlaid input, please select an option" << endl;
			ChooseListToDeleteFrom();
			break;
		}
	}
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		ChooseListToDeleteFrom();
	}
}

//Prints the integer list
void PrintIntList()
{
	if (manualTestint == nullptr)
	{
		cout << endl;
		cout << "Integer list has not been created" << endl;
		return;
	}
	else if (manualTestint->Size() == 0)
	{
		cout << endl;
		cout << "Integer list is empty" << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << "Integer List" << endl;
		for (int i = 0; i < manualTestint->Size(); i++)
		{
			cout << "Element " << i << " = " << manualTestint->AtIndex(i) << endl;
		}
	}
}

//Prints the string list
void PrintStrList()
{
	if (manualTestString == nullptr)
	{
		cout << endl;
		cout << "String list has not been created" << endl;
		return;
	}
	else if (manualTestString->Size() == 0)
	{
		cout << endl;
		cout << "String list is empty" << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << "String List" << endl;
		for (int i = 0; i < manualTestString->Size(); i++)
		{
			string display = manualTestString->AtIndex(i);
			cout << "Element " << i << " = " << display << endl;
		}
	}
}

//Prints the float list
void PrintFloatList()
{
	if (manualFloatList == nullptr)
	{
		cout << endl;
		cout << "Float list has not been created" << endl;
		return;
	}
	else if (manualFloatList->Size() == 0)
	{
		cout << endl;
		cout << "Float list is empty" << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << "Float List" << endl;
		for (int i = 0; i < manualFloatList->Size(); i++)
		{
			cout << "Element " << i << " = " << manualFloatList->AtIndex(i) << endl;
		}
	}
}

//Prints the Employee List
void PrintEmpList()
{
	if (manualEmployeeList == nullptr)
	{
		cout << endl;
		cout << "Employee list has not been created" << endl;
		return;
	}
	else if (manualEmployeeList->Size() == 0)
	{
		cout << endl;
		cout << "Employee list is empty" << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << "EmployeeList" << endl;
		for (int i = 0; i < manualEmployeeList->Size(); i++)
		{
			cout << "Element " << i << " = " << manualEmployeeList->AtIndex(i).ToString() << endl;
		}
	}
}





