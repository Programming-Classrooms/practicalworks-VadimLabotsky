#include "src/class/Tree/Tree.hpp"
#include "src/class/ForestTree/ForestTree.hpp"
#include "src/class/FruitTree/FruitTree.hpp"
#include "src/class/ArrayTree/ArrayTree.hpp"
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
int main()
{
	try
	{

		ArrayTree trees;
		std::ifstream fin("src/Files/trees.txt");
		checkFile(fin);
		fin >> trees;
		trees.print();
		std::cout << trees.countTreeType(Tipe::Coniferous);
		trees.sortArrayByAge();
		trees.print();
		trees.sortArrayByName();
		trees.print();
	}
	catch (const std::ios_base::failure& e) {
		std::cerr << e.what() << '\n';
	}
	catch(const std::runtime_error& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
