#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "../Book/Book.hpp"
class Library: public Book
{
private:
	std::vector <Book> books;
public:
	Library();
	Library(std::vector<Book>);
	~Library();

	void addBook(const Book&);
	Book& findBook(const std::string&);
	void deleteBook(const std::string&);
	void printInfo(std::ostream&);
	void addAuthor(const std::string&, const std::string&);
	void eraseAuthor(const std::string&, const std::string&);
	void sortISBN();
	void sortTitle();
};


#endif // !LIBRARY_HPP
