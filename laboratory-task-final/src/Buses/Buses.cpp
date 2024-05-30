#include "Buses.hpp"

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
void Buses::copyMap()
{
    std::queue <Bus> times(buses);
   while (!times.empty())
   {
        mapBuses.emplace(times.front().getNumberBusRouter(), times.front());
        times.pop();
   }
}

void Buses::find(size_t time)
{
    bool flag = false;
    for (size_t i = 0; i < mapBuses.size(); i++)
    {
        if (mapBuses[i].getNumberBusRouter() == time)
        {
            std::cout << mapBuses[i];
            flag = true;
        }
        
    }
    if (!flag)
    {
        std::cout << "Нет таких автобусов!\n";
    }
    
}
void Buses::print(std::string mark)
{
    bool flag = false;
    for (size_t i = 0; i < mapBuses.size(); i++)
    {
        if (mapBuses[i].getMarkOfBus() == mark)
        {
            std::cout << mapBuses[i].getDriver() <<'\n';
            flag = true;
        }
        
    }
    if (!flag)
    {
        std::cout << "Нет таких автобусов!\n";
    }
}
 void Buses::erase(size_t time)
 {
    mapBuses.erase(time);
  
     for (size_t i = 0; i < mapBuses.size(); i++)
    {
        std::cout << mapBuses[i];
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