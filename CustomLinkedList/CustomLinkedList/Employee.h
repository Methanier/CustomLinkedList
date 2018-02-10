/*
	Charles Cozart
	CSC382
	Custom Employee class used to show LinkedLists workability with custom classes
*/

#include <string>

using namespace std;

class Employee
{
private:

	string name;
	int id;
	float salary;

public:
	Employee() { Init(); }

	Employee(string & n) : name{ n } {}

	Employee(string & n, int & i) : name{ n }, id { i } {}

	Employee(string & n, int & i, float & s) : name{ n }, id{ i }, salary{ s } {}

	string GetName() { return name; }

	int GetID() { return id; }

	float GetSalary() { return salary; }

	void Init() { name = "New Employee"; id = 0; salary = 0; }

	
	const bool & operator==(const Employee & in) const
	{
		bool result = false;

		if (in.name == name && in.id == id && in.salary == salary)
			result = true;

		return result;
	}

	const bool & operator!=(const Employee & in) const
	{
		return !(*this == in);
	}

	string ToString() { string emp = "Name: " + name + "\nID: " + to_string(id) + "\nSalary: " + to_string(salary); return emp; }


};