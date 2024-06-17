#include "../Library/Library.hpp"
#include "../Book/Book.hpp"

int main()
{
	try
	{
		Book book1("A", "Title1", { "Author1", "Author2" }, 10.99, 5);
		Book book2("B", "Title4", { "Author3" }, 15.99, 3);
		Book book3("C", "Title3", { "Author1", "Author4" }, 12.99, 4);
		
		

		Library library;
		library.addBook(book1);
		library.addBook(book3);
		library.addBook(book2);

		library.printInfo(std::cout);

		std::cout << "Please enter the book ISBN, information about which you want to see!\n";
		std::string ISBN;
		std::cin >> ISBN;
		Book time = library.findBook(ISBN);
		time.print(std::cout);


		std::cout << "Please enter the book ISBN you want delete!\n";
		std::cin >> ISBN;
		library.deleteBook(ISBN);
		library.printInfo(std::cout);

		std::cout << "Please enter the book ISBN and surname of the author, whose you want to add this book!\n";
		std::string author;
		std::cin >> ISBN >> author;
		library.addAuthor(ISBN, author);
		library.printInfo(std::cout);

		std::cout << "Please enter the book ISBN and surname of the author, whose you want to remove from this book!\n";	
		std::cin >> ISBN >> author;
		library.eraseAuthor(ISBN, author);
		library.printInfo(std::cout);

		std::cout << "Sort by ISBN\n";
		library.sortISBN();
		library.printInfo(std::cout);

		std::cout << "Sort by title\n";
		library.sortTitle();
		library.printInfo(std::cout);
	}
	catch (const std::runtime_error& ex)
	{
		std::cerr << ex.what();
	}
	
	return 0;
}