#include "Book.hpp"


Book::Book():ISBN (""), title(""), authors(0), price(0.0), count (0)
{
}

Book::Book(std::string timeISBN, std::string timeTitle, std::vector<std::string> timeAuthors, double timePrice, int timeCount):
	ISBN(timeISBN), title(timeTitle), authors(timeAuthors), price(timePrice), count(timeCount)
{
}

Book::~Book()
{}

std::string Book::getISBN() const
{
	return ISBN;
}

std::string Book::getTitle() const
{
	return title;
}

std::vector<std::string> Book::getAuthors() const
{
	return authors;
}

double Book::getPrice() const
{
	return price;
}

int Book::getCount() const
{
	return count;
}

void Book::addAuthor(const std::string& author)
{
	authors.push_back(author);
}

void Book::eraseAuthor(const std::string& author)
{
	authors.erase(std::remove(authors.begin(), authors.end(), author), authors.end());
}

void Book::print(std::ostream& fout)
{
	fout << ISBN << '\t' << title << '\t';	
	for (std::string author : authors)
	{
		fout << author << '\t';
	}
	fout << price << '\t' << count << '\n';
}

