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

void Book::addAuthor(Author author)
{
	authors.insert(author);
}

void Book::eraseAuthor(Author author)
{
	authors.erase(author);
}

std::istream& operator>>(std::istream& fin, Book& rhs)
{
	size_t size;
	Author author;
	fin >> rhs.numberUDK >> rhs.yearOfPublication;
	fin >> size;
	while (size != 0)
	{
		fin >> author;
		rhs.authors.insert(author);
		--size;
	}

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
