#include "AllSurnames.hpp"


bool isValidSurname(const std::string& word)
{
    if (word.empty() || !isupper(word[0])) {
        return false;
    }

    for (char c : word) {
        if (!isalpha(c)) {
            return false;
        }
    }

    return true;
}

void findName(std::string line, std::string& delims, std::ifstream& file, std::string& result, size_t& count)
{
    while (std::getline(file, line)) {
        size_t start = 0;
        size_t end = 0;

        while ((start = line.find_first_not_of(delims, end)) != std::string::npos) {
            end = line.find_first_of(delims, start);
            std::string word = line.substr(start, end - start);
            if (isValidSurname(word)) {
                result += word;
                ++count;
                result += " ";
            }
        }
    }
}

void arrayAllSurname(std::string& result, size_t& count, std::string*& allSurnames)
{
    size_t i = 0;
    std::stringstream ss(result);

    while (ss >> allSurnames[i])
    {
        ++i;
    }
}

void insertionSort(size_t& count, std::string*& allSurnames)
{
    for (int i = 1; i < count; i++)
    {
        int j = i - 1;
        while (j >= 0 && allSurnames[j] > allSurnames[j + 1])
        {
            std::swap(allSurnames[j], allSurnames[j + 1]);
            j--;
        }
    }
}

