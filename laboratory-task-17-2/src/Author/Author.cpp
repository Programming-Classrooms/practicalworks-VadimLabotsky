#include "Author.hpp"

Author::Author(): surname(""), name(""), patronymic("")
{
}

Author::Author(std::string timeSurname, std::string timeName, std::string timePatronymic): surname(timeSurname), name(timeName), patronymic(timePatronymic)
{
}

Author::Author(const Author& rhs):name(rhs.name), surname(rhs.surname), patronymic(rhs.patronymic)
{
}

Author::~Author()
{
	
}

std::string Author::getSurname() const
{
	return surname;
}

std::string Author::getName() const
{
	return name;
}

std::string Author::getPatronymic() const
{
	return patronymic;
}

bool Author::operator<(const Author& rhs) const
{
	return surname < rhs.surname;
}

std::istream& operator>>(std::istream& fin , Author& rhs)
{
	fin >> rhs.surname >> rhs.name >> rhs.patronymic;
	return fin;
}

std::ostream& operator<<(std::ostream& fout, Author rhs)
{
	fout << rhs.surname << '\t' << rhs.name << '\t' << rhs.patronymic << '\t';
	return fout;
}

