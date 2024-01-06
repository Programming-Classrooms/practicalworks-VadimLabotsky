/*
    Написать программу, которая для заданного натурального числа:
    5. вычисляет сумму первых чисел Фибоначчи,не превосходящую  заданного числа N;
*/


#include <iostream>
#include <iomanip>


int main()
{
    int32_t number1 = 0;
    int32_t number2 = 1;
    int32_t number = 0;
    std::cout << "Please, enter natural number.\n";
    std::cin >> number;
    while (number <= 0) {
        std::cout << "ERROR! Please, enter natural number!!!\n ";
        std::cin >> number;
    }
    while (number >= number1) {
        number1 += number2;
        number2 = number1 - number2;
        --number;
        std::cout << number1 << std::setw(4);
    }
    return 0;
}

