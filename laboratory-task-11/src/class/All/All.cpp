
#include "All.hpp"

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

std::string getDelimeters(std::ifstream& fin)
{
    std::string delims = "";
    getline(fin, delims);
    return delims;
}

bool chek(size_t count, size_t count1)
{
    if (count > count1)
    {
        return true;
    }
    return false;
}

void removeNegativeOrDoubleDigit(int32_t*& allNumbers, size_t& count) {
    size_t j = 0;
    for (size_t i = 0; i < count; ++i) {
        if (allNumbers[i] >= 0 && allNumbers[i] <=9) {
            ++j;
        }
    }
    int32_t* time = nullptr;
    time = new int32_t[j];
    size_t k = 0;
    for (size_t i = 0; i < count; ++i) {
        if (allNumbers[i] >= 0 && allNumbers[i] <= 9) {
                time[k] = allNumbers[i];
                ++k;
        }
    }
    delete[] allNumbers;
    allNumbers = new int32_t[j];
    for (size_t i = 0; i < j; ++i) {
        allNumbers[i] = time[i];
        
    }
    count = j;
}

void enterElementsForAllNumber(int32_t*& allNumbers, size_t& count, size_t& count1, std::string message)
{
    removeNegativeOrDoubleDigit(allNumbers, count1);

    int32_t* time = new int32_t[count1];
    for (size_t i = 0; i < count1; i++)
    {
        time[i] = allNumbers[i];
    }
    allNumbers = new int32_t[count];
    for (size_t i = 0; i < count; i++)
    {
        allNumbers[i] = time[i];
    }
    for (size_t i = count1; i < count; i++)
    {
        std::cout << message;
        std::cin >> allNumbers[i];
    }
    delete[] time;
}


void enterNewElements(int32_t*& allNumbers, std::string*& allSurnames, size_t& count, size_t count1)
{
    if (!chek(count, count1))
    {
        enterElementsForAllNumber(allNumbers, count, count1, "Please enter numbers.\n");
    }
    
}
