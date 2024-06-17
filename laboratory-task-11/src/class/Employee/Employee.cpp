#include"Employee.hpp"
Employees::Employees()
{
	arr = new Employee[10];
	size = 10;
}
Employees::Employees(size_t n)
{
	arr = new Employee[n];
	size = n;
}
Employee* Employees::enterEmployees(std::string* allSurnames, int32_t* allNumbers, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		arr[i].children = allNumbers[i];
		arr[i].surname = allSurnames[i];
	}
	return arr;
}
void Employees::printEmployees(size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		std::cout << arr[i].surname << " " << arr[i].children << '\n';
	
	}
}
int compare(const void* a, const void* b) {

	return ((*(Employee*)a).surname >(*(Employee*)b).surname) ? 1 : -1;
}

void Employees::sortMyArray(size_t count)
{
	qsort(arr, count, sizeof(Employee), compare);
}

void Employees::printInFout(std::ofstream& fout, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		fout << arr[i].surname << " " << arr[i].children << '\n';
	}
}

