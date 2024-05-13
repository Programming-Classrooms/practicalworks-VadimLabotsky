#include "Book.hpp"

Book::Book(): numberUDK(0), yearOfPublication(0)
{
}

Book::Book(size_t timeNumberUDK, std::set<Author> timeAuthors, int timeYearOfPublication): numberUDK(timeNumberUDK), authors(timeAuthors), yearOfPublication(timeYearOfPublication)
{
}

Book::~Book()
{
	authors.clear();
}

int Book::getYearOfPublication() const
{
	return yearOfPublication;
}

size_t Book::getNumberUDK() const
{
	return numberUDK;
}

std::set<Author> Book::getAuthors() const
{
	return authors;
}

std::istream& operator>>(std::istream& fin, Book& rhs)
{
	size_t size;
	Author author;
	fin >> rhs.numberUDK >> size;

	for (size_t i = 0; i < size; i++)
	{
		fin >> author;
		rhs.authors.insert(author);
	}
	fin >> rhs.yearOfPublication;
	return fin;

}

std::ostream& operator<<(std::ostream& fout, Book rhs)
{
	fout << rhs.numberUDK << '\t';

	for (Author author : rhs.authors)
	{
		fout << author;
	}
	fout << rhs.yearOfPublication <<"\n\n";
	return fout;
}

