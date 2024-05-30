#include"Bus.hpp"

Bus::Bus(): numberBusRouter(0), driver(""), numberBus(0), markOfBus("")
{}

Bus::Bus(size_t timeNumberBusRouter, std::string timeDriver, size_t timeNumberBus, std::string timeMarkOfBus):numberBusRouter(timeNumberBusRouter),
driver(timeDriver), numberBus(timeNumberBus), markOfBus(timeMarkOfBus)
{}

Bus::Bus(const Bus& rhs):numberBusRouter(rhs.numberBusRouter),
driver(rhs.driver), numberBus(rhs.numberBus), markOfBus(rhs.markOfBus)
{}

Bus::~Bus()
{}

size_t Bus::getNumberBusRouter() const
{
    return this->numberBusRouter;
}
std::string Bus::getDriver() const
{
    return this->driver;
}
size_t Bus::getNumberBus() const
{
    return this->numberBus;
}
std::string Bus::getMarkOfBus() const
{
    return this->markOfBus;
}

void Bus::setNumberBusRouter(size_t timeNumberBusRouter)
{
    this->numberBusRouter = timeNumberBusRouter;
}
void Bus::setDriver(std::string timeDriver)
{
    this->driver = timeDriver;
}
void Bus::setNumberBus(size_t timeNumberBus)
{
    this->numberBus = timeNumberBus;
}
void Bus::setMarkOfBus(std::string timeMarkOfBus)
{
    this->markOfBus = timeMarkOfBus;
}

Bus Bus:: operator=(const Bus& rhs)
{
    if (this != &rhs)
    {
        this->numberBusRouter = rhs.numberBusRouter;
        this->driver = rhs.driver;
        this->numberBus = rhs.numberBus;
        this->markOfBus = rhs.markOfBus;
    }
    return *this;
}

std::istream& operator>>(std::istream& in , Bus& rhs)
{
    in >> rhs.numberBusRouter >> rhs.driver >> rhs.numberBus >> rhs.markOfBus;
    return in;
}

std::ostream& operator<<(std::ostream& out , const Bus& rhs)
{
    out<< std::setw(15) << rhs.numberBusRouter << std::setw(30) << rhs.driver<< std::setw(30) <<  rhs.numberBus << std::setw(30)<< rhs.markOfBus << '\n';
    return out;
}