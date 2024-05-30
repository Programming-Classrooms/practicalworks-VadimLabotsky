#include"../Buses/Buses.hpp"



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
        Buses buses;
        std::ifstream fin("src/file/Bus.txt");
        checkFile(fin);
        fin >> buses;
        std::cout << buses;
        buses.sortNumberBus();
        std::cout << buses;
        buses.sortNumberBusRouter();
        std::cout << buses;

    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}