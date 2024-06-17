#include "AllNumbers.hpp"

bool isNumber(std::string word)
{
    size_t wordLen = word.length();
    for (size_t i = 0; i < wordLen; ++i)
    {

        if (!isdigit(word[i]) && word[0] != '-')
        {
            return false;
        }
    }
    return true;
}

void findNumber(std::string line, std::string& delims, std::ifstream& fin, std::string& result, size_t& count)
{

    std::string::size_type begInd = line.find_first_not_of(delims);
    while (begInd != std::string::npos) {
        std::string::size_type endInd = line.find_first_of(delims, begInd);
        if (endInd == std::string::npos) {
            endInd = line.length();
        }
        std::string word = line.substr(begInd, endInd - begInd);
        if (isNumber(word)) {
            for (char digit : word) {
                if (isdigit(digit)) {
                    int index = digit - '0';
                }
            }
            result += word;
            ++count;
            result += " ";

        }
        begInd = line.find_first_not_of(delims, endInd);
    }

}

void arrayAllNumbers(std::string& result, size_t& count, int32_t*& allNumbers)
{
    size_t i = 0;
    std::stringstream ss(result);
    int32_t time = 0;
    while (ss >> time)
    {
        allNumbers[i] = time;
        ++i;
    }

}

void paritySort(int32_t*& arr, size_t count) {
    int32_t* even = new int[count];
    int32_t* odd = new int[count];
    int32_t evenIndex = 0, oddIndex = 0;

    for (size_t i = 0; i < count; i++) {
        if (arr[i] % 2 == 0) {
            even[evenIndex++] = arr[i];
        }
        else {
            odd[oddIndex++] = arr[i];
        }
    }
    size_t index = 0;
    for (size_t i = 0; i < evenIndex; i++) {
        arr[index++] = even[i];
    }
    for (size_t i = 0; i < oddIndex; i++) {
        arr[index++] = odd[i];
    }

    delete[] even;
    delete[] odd;
}