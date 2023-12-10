/*Написать программу, которая для заданного натурального числа : 2. удаляет из записи числа все цифры, кратные минимальной цифре;*/

#include <iostream>


int main()
{
  int32_t number, min = 9, lastNumber = 0, timeNumber = 0, modifiedNumber = 0;
  double x = 0.1;
  std::cout << "Input number\n";
  std::cin >> number;
  while (number <= 0)
  {
    std::cout << "ERROR! Please, enter natural number!!! \n ";
    std::cin >> number;
  }
  timeNumber = number;
  while (number)
  {
    lastNumber = number % 10;
    if (lastNumber < min)
    {
      min = lastNumber;
    }
    number /= 10;
  }
  number = timeNumber;
  while (number > 0)
  {
    int32_t lastDigit = number % 10;
    number /= 10;
    if (lastDigit % min != 0)
    {
      x *= 10;
    }
    if (lastDigit % min != 0)
    {
      modifiedNumber = modifiedNumber + (lastDigit * x);
    }
  }
  number = timeNumber;
  system("cls");
  std::cout << number << '\n';
  std::cout << "Modified number\n" << modifiedNumber;
  return 0;
}
