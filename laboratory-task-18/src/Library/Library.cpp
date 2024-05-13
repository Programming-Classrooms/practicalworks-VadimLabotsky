#include"Library.hpp"
Library::Library(): books(0)
{
}

Library::Library(std::vector<Book> timeBooks):books(timeBooks)
{
}

Library:: ~Library ()
{}

void Library::addBook(const Book& book)
{
	books.push_back(book);
}

Book& Library::findBook(const std::string& ISBN)
{
	
	for (Book& book: books)
	{
		if (book.getISBN() == ISBN)
		{
			return book;
		}
	}
	throw std::runtime_error("There isn't this book!\n");
}


void Library::addAuthor(const std::string& ISBN, const std::string& author)
{
	Book& book = findBook(ISBN);
	book.addAuthor(author);

}

void Library::eraseAuthor(const std::string& ISBN, const std::string& author)
{
	Book& book = findBook(ISBN);
	book.eraseAuthor(author);
	
}

void Library::deleteBook(const std::string& ISBN)
{
	books.erase(std::remove_if(books.begin(), books.end(), [ISBN](const Book& book) {return book.getISBN() == ISBN; }), books.end());
}

void Library::printInfo(std::ostream& fout )
{
	for (Book book: books)
	{
		book.print(fout);
	}
}

void Library::sortISBN()
{
	std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {return a.getISBN() < b.getISBN(); });
}

void Library::sortTitle()
{
	std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {return a.getTitle() < b.getTitle(); });
}
