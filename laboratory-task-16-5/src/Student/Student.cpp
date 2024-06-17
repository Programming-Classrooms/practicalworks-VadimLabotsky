#include "../Student/Student.hpp"
Student::Student() :fIO("LVD"), group(1), course(1)
{
}

Student::Student(std::string timeFIO, size_t timeGroup, size_t timeCourse):fIO(timeFIO), group(timeGroup), course(timeCourse)
{
}

Student::Student(const Student& rhs):fIO(rhs.fIO), group(rhs.group), course(rhs.course)
{
}

Student::~Student()
{
}

std::string Student::getFIO() const
{
	return fIO;
}
size_t Student::getGroup() const
{
	return group;
}
size_t  Student::getCourse() const
{
	return course;
}	

bool Student::operator<(const Student& rhs)
{
	return fIO < rhs.fIO;
}


std::istream& operator>>(std::istream& fin , Student& rhs)
{
	fin >> rhs.fIO >> rhs.course >> rhs.group;
	return fin;
}

std::ostream& operator<<(std::ostream& fout, Student rhs)
{
	fout << std::setw(4) << rhs.fIO << std::setw(10) << rhs.course << std::setw(10) << rhs.group << "\n";
	return fout;
}