#include <iostream>

int64_t getDigit(int64_t number, int64_t  position) {
    int64_t  divisor = 1;
    for (int64_t  i = 1; i < position; i++) {
        divisor *= 10;
    }
    return (number / divisor) % 10;
}

int64_t findDigitInSequence(int64_t n, int64_t digitPosition) {
    int64_t currentNumber = 1;
    int64_t currentPosition = 0;

    while (currentPosition < digitPosition) {
        int64_t numDigits = 1;
        int64_t temp = currentNumber;
        while (temp >= 10) {
            temp /= 10;
            numDigits++;
        }
        currentPosition += numDigits;
        currentNumber++;

        if (currentPosition >= digitPosition) {
            return getDigit(currentNumber - 1, numDigits - (currentPosition - digitPosition));
        }
    }

    return -1; 
}

int main() 

{

    int64_t temp, digitPosition;
    std::cout << "Enter the number of the digit you want to find: ";
    std::cin >> digitPosition;
    temp = digitPosition;

    int64_t digit = findDigitInSequence(temp, digitPosition);

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
