/*
    Написать программу, которая для заданного натурального числа :
    18.Находит в последовательности, состоящей из цифр подряд записанных натуральных чисел, цифру с заданным номером.
*/

#include <iostream>


void getDigitPosition(int32_t& digitPosition)
{
    bool indicator = false;

    while (!indicator) {
        std::cout << "Please, enter natural number.\n";
        std::cin >> digitPosition;

        if (digitPosition <= 0) {
            throw std::exception("ERROR!!!");
        }
        if (!static_cast<char>(digitPosition)) {
            throw std::exception("You have entered a symbol!");
        }
        else {
            indicator = true;
            break;
        }
    }
}

int32_t findDigitInSequence(int32_t digitPosition) {
    int32_t sequenceLength = 0;
    int32_t currentNumber = 1;
    int32_t number =  digitPosition * 3;

    while (sequenceLength < digitPosition) {
        int tempNumber = currentNumber;
        while (tempNumber > 0) {
            sequenceLength++;
            if (sequenceLength == digitPosition) {
                return tempNumber % 10;
            }
            tempNumber /= 10;
        }
        currentNumber++;
    }

    return -1;
}

int main() {
    try {
        int32_t number = 0;
        int32_t digitPosition = 0;

        getDigitPosition(digitPosition);

        int32_t digit = findDigitInSequence(digitPosition);

        if (digit != -1) {
            std::cout << "The digit with the number " << digitPosition << "  in the sequence of natural numbers is equal to"<< " : " << digit << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}

