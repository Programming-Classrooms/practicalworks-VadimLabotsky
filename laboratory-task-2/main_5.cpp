/*
    Написать программу, которая для заданного натурального числа:
    5. вычисляет сумму первых чисел Фибоначчи,не превосходящую  заданного числа N;
*/


#include <iostream>
#include <iomanip>


void getNumber(int32_t& number)
{
    bool indicator = false;

    while (!indicator) {
        std::cout << "Please, enter natural number.\n";
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

void summaNumberFibonachi(int32_t& number)
{
    int32_t number1 = 0;
    int32_t number2 = 1;
    int64_t summaNumber = 0;

    while (number >= number1) {
        number1 += number2;
        number2 = number1 - number2;
        --number;
        summaNumber += number1;
    }

    std::cout << summaNumber;
}

int main()
{
    try {
        int32_t number1 = 0;
        int32_t number2 = 1;
        int32_t number = 0;
        int64_t summaNumber = 0;

        getNumber(number);
        summaNumberFibonachi(number);
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}

