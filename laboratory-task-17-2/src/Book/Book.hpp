#ifndef BOOK_HPP
#define BOOK_HPP
#include "../Author/Author.hpp"
#include <set>
class Book: public Author
{
private:
	int yearOfPublication;
	size_t numberUDK;
	std::set <Author> authors;
public:
	Book();
	Book(size_t, std::set <Author>, int);
	~Book();
	int getYearOfPublication() const;
	size_t getNumberUDK() const;
	std::set<Author> getAuthors() const;

	friend std::istream& operator>>(std::istream&, Book&);
	friend std::ostream& operator<<(std::ostream&, Book);
};


#endif // !BOOK_HPP

