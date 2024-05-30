#include "Buses.hpp"

Buses::Buses()
{}

Buses::Buses(std::queue <Bus> timeBuses): buses(timeBuses)
{}

Buses::Buses(const Buses& rhs): buses(rhs.buses)
{}

Buses::~Buses()
{
    while(!buses.empty())
    {
       buses.pop();
    }
}

void Buses::copy(std::vector <Bus>& time)
{
    std::queue <Bus> times(buses);
   while (!times.empty())
   {
        time.push_back(times.front());
        times.pop();
   }
}
void Buses::copy()
{
    std::queue <Bus> times(buses);
   while (!times.empty())
   {
        mapBuses.emplace(times.front().getNumberBus(), times.front());
        times.pop();
   }
}


void Buses::sortNumberBus()
{
    std::vector <Bus> busesVector;
    copy(busesVector);
    std::sort(busesVector.begin(), busesVector.end(), [](const Bus a, const Bus& b){return a.getNumberBus() < b.getNumberBus();});
    while(!buses.empty())
    {
       buses.pop();
    }
    for (Bus& bus:busesVector)
    {
        buses.emplace(bus);
    }
    
}
void  Buses::sortNumberBusRouter()
{
    std::vector <Bus> busesVector;
    copy(busesVector);
    std::sort(busesVector.begin(), busesVector.end(), [](const Bus a, const Bus& b){return a.getNumberBusRouter() < b.getNumberBusRouter();});
    while(!buses.empty())
    {
       buses.pop();
    }
    for (Bus& bus:busesVector)
    {
        buses.emplace(bus);
    }
}
std::istream& operator>>(std::istream& in, Buses& rhs)
{
    while(!in.eof())
    {
        Bus bus;
        in >> bus;
        rhs.buses.emplace(bus);
    }
    return in;
}
std::ostream& operator<<(std::ostream& out , const Buses& rhs)
{
    std::queue <Bus> time(rhs.buses);
   
    
   while (!time.empty())
   {
        out << time.front();
        time.pop();
   }
   
    out << "\n\n";
   return out;
    
}