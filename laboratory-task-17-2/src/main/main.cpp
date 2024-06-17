#include <map>
#include <fstream>
#include <exception>
#include <iomanip>
#include "../Book/Book.hpp"
#include <sstream>
void checkFile(std::ifstream& fin)
{
	if (!fin.good())
	{
		throw std::ios_base::failure("File does not exist.\n");
	}
	if (!fin)
	{
		throw std::ios_base::failure("File is not opened.\n");
	}
	if (fin.peek() == EOF)
	{
		throw std::ios_base::failure("File is empty.\n");
	}
}
void readInfo(std::map<std::string, Book>& library)
{
	std::ifstream fin("src/file/Book.txt");
	std::string nameBook;
	while (fin >> nameBook)
	{
		Book book;
		fin >> book;
		library.emplace(nameBook, book);
	}
}
void printInfo(std::map <std::string, Book>&library)
{
	for (const auto& book:library)
	{
		std::cout << book.first << '\t' << book.second;
	}
	
}
void printInfoElement(std::pair<std::string,Book>  book)
{
	
	std::cout << book.first << '\t' <<  book.second;
}

void printInfoNameBook(std::map <std::string, Book>&  library)
{
	std::string nameBook;
	std::cout << "Пожалуйста введите название книги, информацию о которой Вы бы хотели увидеть!\n";
	std::cin >> nameBook;
	std::map<std::string, Book> ::iterator time;
	time = library.find(nameBook);
	if (time == library.end())
	{
		std::cout << "Нету книги с таким названием!\n";

	}
	else if ((*library.find(nameBook)).first == nameBook)
	{
		printInfoElement(*(library.find(nameBook)));
	}
}

void printInfoAuthor(std::map <std::string, Book>library)
{
	std::string surnameAuthor;
	std::cout << "Пожалуйста введите фамилию автора, который написал книгу, которую Вы ищите!\n";
	std::cin >> surnameAuthor;
	bool flag = false;
	for (auto& book : library)
	{
		for (auto author : book.second.getAuthors())
		{
			if (author.getSurname() == surnameAuthor) {
				printInfoElement(book);
				flag = true;
			}
		}
	}
	if (!flag)
	{
		std::cout << "Нету книг с такой фамилией автора!\n";
	}
}

void printInfoPlusAuthor(std::map <std::string, Book>& library)
{
	std::string nameBook;
	std::cout << "Пожалуйста введите название книги, автора которого Вы бы хотели добавить!\n";
	std::cin >> nameBook;
	std::map<std::string, Book> ::iterator time;
	time = library.find(nameBook);
	if (time == library.end())
	{
		std::cout << "Нету книги с таким названием!\n";
		return;
	}
	else if (time->first == nameBook)
	{
		Author author;
		std::cout << "Пожалуйста введите фамилию, имя, отччество автора, которго Вы бы хотели добавить!\n";
		std::cin >> author;
		time->second.addAuthor(author);
		printInfoElement(*time);
	}
}

void printInfoEraseAuthor(std::map <std::string, Book>&library)
{
	std::string nameBook;
	std::cout << "Пожалуйста введите название книги, автора которой Вы бы хотели удалить!\n";
	std::cin >> nameBook;
	std::map<std::string, Book> ::iterator time;
	time = library.find(nameBook);
	if (time == library.end())
	{
		std::cout << "Нету книги с таким названием!\n";

	}
	else if ((*library.find(nameBook)).first == nameBook)
	{
		Author author;
		std::cout << "Пожалуйста введите фамилию, имя, отчество автора, которого Вы бы хотели удалить!\n";
		std::cin >> author;
		time->second.eraseAuthor(author);
		printInfoElement(*library.find(nameBook));
	}
}
int main()

{
	try
	{
		std::map<std::string, Book> library;
		readInfo(library);
		printInfo(library);
		std::string nameBook;
		std::cout << "Пожалуйста введите название книги, которую Вы бы хотели удалить!\n";
		std::cin >> nameBook;
		if (library.erase(nameBook))
		{
			printInfo(library);
		}
		else
		{
			std::cout << "Нету книги с таким названием!\n";
		}
		printInfoNameBook(library);
		printInfoAuthor(library);
		printInfoPlusAuthor(library);
		printInfoEraseAuthor(library);
		
	}
	catch (const std::ios_base::failure& ex)
	{
		std::cerr << ex.what();
	}
	return 0;
}