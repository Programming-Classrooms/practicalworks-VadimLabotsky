#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <string>
#include <fstream>
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

void readInfo(std::map<std::string, size_t>& book)
{
	std::ifstream fin("src/file/Word.txt");
	checkFile(fin);
	size_t count = 0;
	std::string word = "";
	while (fin >> word)
	{
		++book[word];
	}
}

void printInfo(std::map<std::string, size_t> book)
{
	for (auto word: book)
	{
		std::cout << word.first << "\t" << word.second << '\n';
	}
}
int main()
{
	try
	{
		std::map<std::string, size_t> book;
		readInfo(book);
		printInfo(book);
	}
	catch (const std::ios_base::failure& ex)
	{
		std::cerr << ex.what();
	}
	
	return 0;
}
