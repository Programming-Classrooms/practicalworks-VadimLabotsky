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
        std::cout << "Сортировка по номеру автобуса!\n";
        buses.sortNumberBus();
        std::cout << buses;
        buses.sortNumberBusRouter();
        std::cout << "Сортировка по номеру маршрута!\n";
        std::cout << buses;
        size_t time;
        std::cout << "Пожалуйста введите номер маршрута, информацию о котором вы хотите увидеть!\n";
        std::cin >> time;
        buses.copyMap();
        buses.find(time);
        std::string mark;
        std::cout << "Пожалуйста введите марку автобуса, информацию о водителя котором вы хотите увидеть!\n";
        std::cin >>  mark;
        buses.print(mark);
        std::cout << "Пожалуйста введите номер маршрута, информацию о котором вы хотите удалить!\n";
        std::cin >> time;
        buses.erase(time);
    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}