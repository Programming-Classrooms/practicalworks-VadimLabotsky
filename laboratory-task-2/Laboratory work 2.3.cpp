/*Написать программу, которая для заданного натурального числа : Находит в последовательности, состоящей из цифр подряд
записанных натуральных чисел, цифру с заданным номером.*/

#include <iostream>
#include <cmath>


int32_t getDigit(int32_t number, int32_t position)
{
    int32_t divisor = 1;
    divisor = std::pow(10, position);
    return (number / divisor) % 10;
}

int32_t findDigitInSequence(int32_t n, int32_t digitPosition)
{
    int32_t currentNumber = 1;
    int32_t currentPosition = 0;
    while (currentPosition < digitPosition)
    {
        int32_t numDigits = 1;
        int32_t temp = currentNumber;
        while (temp >= 10) 
        {
            temp /= 10;
            numDigits++;
        }
        currentPosition += numDigits;
        currentNumber++;
        if (currentPosition >= digitPosition) 
        {
            return getDigit(currentNumber - 1, numDigits - (currentPosition - digitPosition));
        }
    }
    return -1; 
}
int main() 
{
    int32_t temp = 0, digitPosition = 0;
    std::cout << "Enter the number of the digit you want to find: ";
    std::cin >> digitPosition;
    temp = digitPosition;
    int32_t digit = findDigitInSequence(temp, digitPosition);
    if (digit != -1)
    {
        std::cout << "The digit with the number " << digitPosition << " in the sequence of natural numbers is equal to " << digit << std::endl;
    }
    else 
    {
        std::cout << "Digit with number " << digitPosition << " was not found in the natural sequence"<< std::endl;
    }
    return 0;
}

