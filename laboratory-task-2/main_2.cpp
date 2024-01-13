/*

    Написать программу, которая для заданного натурального числа :
    2. удаляет из записи числа все цифры, кратные минимальной цифре;
*/


#include <iostream>


void getNumber(int32_t& number)
{
    bool indicator = false;

    while (!indicator) {
        std::cout << "Input number\n";
        std::cin >> number;

        if (number < 0) {
            std::cout << "ERROR!!!" << '\n';
        }
        if (!static_cast<char>(number)) {
            throw std::exception("You have entered a symbol!");
        }
        else {
            indicator = true;
            break;
        }
    }
}

void minDigitInNumber(int32_t& number, int32_t& min)
{
    int32_t lastNumber = 0;
    int32_t timeNumber = number;

    while (number) {
        lastNumber = number % 10;
        if (lastNumber < min) {
            min = lastNumber;
        }
        number /= 10;
    }

    number = timeNumber;
}

void removesDigitsFromAMultipleMin(int32_t& number, int32_t& min)
{
    int32_t lastNumber = 0;
    int32_t timeNumber = 0;
    int32_t modifiedNumber = 0;
    int32_t lastDigit = 0;
    double x = 0.1;

    while (number > 0) {
        lastDigit = number % 10;
        number /= 10;
        if (lastDigit % min != 0) {
            x *= 10;
        }
        if (lastDigit % min != 0) {
            modifiedNumber = modifiedNumber + (lastDigit * x);
        }
    }

    modifiedNumber = number;
    std::cout << "Modified number\n" << modifiedNumber;
}

int main()
{
    try {
        int32_t number = 0;
        int32_t min = 9;
        int32_t lastNumber = 0;
        int32_t timeNumber = 0;
        int32_t modifiedNumber = 0;
        int32_t lastDigit = 0;
        double x = 0.1;

        getNumber(number);
        removesDigitsFromAMultipleMin(number, min);
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}

