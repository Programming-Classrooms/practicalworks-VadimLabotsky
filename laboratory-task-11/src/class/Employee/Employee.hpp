#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "../AllNumbers/AllNumbers.hpp"
#include "../AllSurnames/AllSurnames.hpp"
#include "../All/All.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
struct Employee
{
	std::string surname = "";
	size_t children = 0;
	bool operator < (const Employee& a) {
		return this->children < a.children;
	}
	bool operator > (const Employee& b) {
		return this->children > b.children;
	}
	bool operator == (const Employee& b) {
		return this->children == b.children;
	}
	bool operator != (const Employee& b) {
		return this->children != b.children;
	}
	bool operator >= (const Employee& a) {
		return this->children >= a.children;
	}
	bool operator <= (const Employee& a) {
		return this->children <= a.children;
	}
};

struct Employees
{
	size_t size;
	Employee* arr;
	Employees();
	Employees(size_t);
	Employee* enterEmployees(std::string*, int32_t*, size_t);
	void printEmployees(size_t);
	void sortMyArray(size_t);
	void printInFout(std::ofstream&, size_t);
};
int compare(const void*, const void*);
#endif // !EMPLOYEE_H

