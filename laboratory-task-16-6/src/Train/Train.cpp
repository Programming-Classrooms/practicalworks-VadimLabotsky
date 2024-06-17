#include "Train.hpp"

Train::Train():trainNumber(0), nameOfDestination(""), typeOfTrain(Type::Скорый), departureTime(0,0), travelTime(0)
{
}

Train::Train(size_t timeTrainNumber, std::string timeNameOfDestination, Type timeTypeOfTrain, Time timeDepartureTime, size_t timeTravelTime):
	trainNumber(timeTrainNumber), nameOfDestination(timeNameOfDestination), typeOfTrain(timeTypeOfTrain), departureTime(timeDepartureTime),
	travelTime(timeTravelTime)
{
}

Train::Train(const Train& rhs):trainNumber(rhs.trainNumber), nameOfDestination(rhs.nameOfDestination), typeOfTrain(rhs.typeOfTrain),
departureTime(rhs.departureTime), travelTime(rhs.travelTime)
{
}

Train::~Train()
{
}

Time Train::getDepartureTime() const
{
	return departureTime;
}

std::string Train::getNameOfDestination() const
{
	return nameOfDestination;
}

size_t Train::getTravelTime() const
{
	return travelTime;
}

Type Train::getTypeOfTrain() const
{
	return typeOfTrain;;
}

bool Train::operator<=(const Train& rhs)
{
	if (travelTime <= rhs.travelTime)
	{
		return true;
	}
	return false;
}



std::istream& operator>>(std::istream& in, Train& rhs)
{
	std::string type;
	in >> rhs.trainNumber >> rhs.nameOfDestination >> type >> rhs.departureTime >> rhs.travelTime;
	if (type == "Скорый") {
		rhs.typeOfTrain = Type::Скорый;
	}
	else {
		rhs.typeOfTrain = Type::Пассажирский;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, Train rhs)
{
	out << std::setw(5) << rhs.trainNumber << std::setw(25) << rhs.nameOfDestination << std::setw(20);
	
	if (rhs.typeOfTrain == Type::Скорый)
	{
		out << "Скорый" << std::setw(10);
	}
	else
	{
		out << "Пассажирский" << std::setw(10);
	}
	out << rhs.departureTime << std::setw(10) << rhs.travelTime << '\n';
	return out;
}
