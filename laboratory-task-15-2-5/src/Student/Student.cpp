#include "Student.hpp"
Student::Student():name(""),course(0), group(0), recordBookNumber(0)
{
}

Student::Student(std::string name, size_t course, size_t group, size_t recordBookNumber):name(name),
course(course), group(group), recordBookNumber(recordBookNumber)
{
}

Student::Student(const Student& other):name(other.name), course(other.course), group(other.group), 
recordBookNumber(other.recordBookNumber)
{
}

Student::~Student()
{}



std::string Student::getName() const
{
	return this->name;
}


size_t Student::getCourse() const
{
	return this->course;
}

size_t Student::getGroup() const
{
	return this->group;
}

size_t Student::getRecordBookNumber() const
{
	return this->recordBookNumber;
}

void Student::setCourse(size_t timeCourse)
{
	this->course = timeCourse;
}

void Student::setGroup(size_t timeGroup)
{
	this->group = timeGroup;
}


std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
	out << rhs.name << '\t' << rhs.course << '\t' << rhs.group << '\t' << rhs.recordBookNumber << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Student& rhs)
{
	in >> rhs.name >> rhs.course >> rhs.group >> rhs.recordBookNumber;
	return in;
}