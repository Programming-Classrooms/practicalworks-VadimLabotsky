#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>
#include <iomanip>
#include <string>
class Student
{
private:
	std::string fIO;
	size_t group;
	size_t course;
public:
	Student();
	Student(std::string, size_t,size_t);
	Student(const Student&);
	~Student();
	std::string getFIO() const;
	size_t getGroup() const;
	size_t  getCourse() const;
	bool operator<(const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, Student);
};


#endif // !STUDENT_HPP

