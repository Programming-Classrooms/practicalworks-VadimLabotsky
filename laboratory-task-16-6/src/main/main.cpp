#include "../Train/Train.hpp"
#include <vector>
#include <algorithm>
#include <exception>

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
void readInfo(std::vector <Train>& trains)
{
	std::ifstream fin("src/file/Train.txt");
	checkFile(fin);
	std::string type;
	Train train;
	while (fin >> train)
	{
		trains.push_back(train);
	}
	fin.close();	
}
void inputInfo(std::vector <Train> trains)
{
	for (Train train:trains)
	{
		std::cout << train;
	}
	std::cout << "\n\n";
}
void inputInfoTime(std::vector <Train> trains)
{
	bool flag = false;
	std::cout << "Пожалуйста, введите нужный вам временной диапазон\n";
	Time time1, time2;
	std::cin >> time1 >> time2;
	std::cout << "Отображение информации обо всех поездах из данного " << time1 << '\t' << time2 << " временного диапазона!\n";
	for (Train train : trains)
	{
		if (train.getDepartureTime() >= time1 && train.getDepartureTime() <= time2)
		{
			std::cout << train;
			flag = true;
		}
		
	}
	if (!flag)
	{
		std::cout << "В этот период поездов нет " << time1 << '\t' << time2 << "!\n";
	}
	std::cout << "\n\n";
}
void inputInfoNameOfDestination(std::vector <Train> trains)
{
	bool flag = false;
	std::string nameOfDestination;
	std::cout << "Пожалуйста, введите название пункта назначения!\n";
	std::cin >> nameOfDestination;
	std::cout << "Отображение информации обо всех поездах, направляющихся в заданный пункт назначения " << nameOfDestination <<"!\n";
	for (Train train : trains)
	{
		if (train.getNameOfDestination() == nameOfDestination)
		{
			std::cout << train;
			flag = true;
		}

	}
	if (!flag)
	{
		std::cout << "Поездов в данный пункт назначения нет!\n";
	}
	std::cout << "\n\n";
}
void inputInfoNameOfDestinationFast(std::vector <Train> trains)
{
	bool flag = false;
	std::string nameOfDestination;
	std::cout << "Пожалуйста, введите название пункта назначения!\n";
	std::cin >> nameOfDestination;
	std::cout << "Отображение информации обо всех скорых поездах, направляющихся в заданный пункт назначения " << nameOfDestination << "!\n";
	for (Train train : trains)
	{
		if (train.getNameOfDestination() == nameOfDestination && train.getTypeOfTrain() == Type::Скорый)
		{
			std::cout << train;
			flag = true;
		}

	}
	if (!flag)
	{
		std::cout << "Поездов в данный пункт назначения нет или скорых поездов в данный пункт назначения нет!\n";
	}
	std::cout << "\n\n";
}
void inputInfoNameOfDestinationFastTravelTime(std::vector <Train> trains)
{
	bool flag = false;
	std::vector <Train> fastTrain;
	std::string nameOfDestination;
	std::cout << "Пожалуйста, введите название пункта назначения!\n";
	std::cin >> nameOfDestination;
	std::cout << "Самый быстрый поезд, следующий в заданный	пункт назначения " << nameOfDestination << "!\n";
	for (Train train : trains)
	{
		if (train.getNameOfDestination() == nameOfDestination)
		{
			fastTrain.push_back(train);
			flag = true;
		}

	}
	if (!flag)
	{
		std::cout << "Поездов в данный пункт назначения нет!\n\n\n";
		return;
	}
	std::sort(fastTrain.begin(), fastTrain.end(), [](const Train& a, const Train& b) {
		return a.getTravelTime() <= b.getTravelTime(); });
	std::cout << fastTrain[0];
	std::cout << "\n\n";
}
int main()
{
	try
	{
		
		std::vector<Train> trains;
		readInfo(trains);
		std::cout << "Вывод информации после чтения из файла!\n";
		inputInfo(trains);
		std::cout << "Вывод информации после сортировки!\n";
		std::sort(trains.begin(), trains.end(), [](const Train& a, const Train& b) {
			return a.getDepartureTime() <= b.getDepartureTime();
			});
		inputInfo(trains);
		inputInfoTime(trains);
		inputInfoNameOfDestination(trains);
		inputInfoNameOfDestinationFast(trains);
		inputInfoNameOfDestinationFastTravelTime(trains);
	}
	catch (const std::ios_base::failure& ex)
	{
		std::cerr << ex.what();
	}
	return 0;
}
