#ifndef BOOK_HPP
#define BOOK_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
class Book
{
protected:
	std::string ISBN;
	std::string title;
	std::vector <std::string> authors;
	double price;
	int count;
public:
	Book();
	Book(std::string, std::string, std::vector<std::string>, double, int);
	~Book();
	std::string getISBN() const;
	std::string getTitle() const;
	std::vector <std::string> getAuthors() const;
	double getPrice() const;
	int getCount() const;
	void addAuthor(const std::string&);
	void eraseAuthor(const std::string&);
	void print(std::ostream&);
};

#endif // !BOOK_HPP
