/*
  Тема: ОДНОМЕРНЫЕ МАССИВЫ (ЧИСЛОВЫЕ ПОСЛЕДОВАТЕЛЬНОСТИ)
Использовать статический массив ( + отдельно сделать для динамического
массива). Максимальную размерность массива задать именованной константой.
Реальное количество элементов массива ввести с клавиатуры с контролем на выход
за границы массива. Массивы должны состоять не менее, чем из одного элемента.
Предусмотреть два способа заполнения массива: с клавиатуры и с помощью
датчика случайных чисел. В последнем случае перед заполнением массива ввести
границы интервала, которому должны принадлежать элементы массива.
Вывести результаты расчетов. Если по каким-либо причинам решение задачи
невозможно, вывести соответствующее сообщение.
Дополнительных массивов для преобразования данных использовать нельзя.
Вариант 31
В массиве, состоящем из п вещественных элементов, вычислить:
номер максимального по модулю элемента массива (если таких элементов несколько,
найти минимальный номер);
сумму элементов массива, расположенных до первого положительного элемента.
Вставить после последнего отрицательного числа заданное число Р.
*/

#include <iostream>
#include <random>
#include <ctime>
#include<iomanip>


void getLength(int32_t& length)
{
  length = 0;
  bool indicator = false;
  while (!indicator)
  {
    std::cout << "Enter lenght array = ";
    std::cin >> length;
    if (length < 0)
    {
      std::cout << "ERROR!!!" << '\n';
    }
    if (!static_cast<char>(length))
    {
      throw std::exception("You have entered a symbol!");

    }
    else
    {
      indicator = true;
      std::cout << "Thank you!!!" << '\n';
      break;
    }
  }
}

void  enterElementsByHands(double* arr, const int32_t& length)
{
  bool indicator = false;
  for (size_t i = 0; i < length; ++i)
  {
    while (!indicator)
    {
      std::cout << "Enter element = ";
      std::cin >> arr[i];
      if (!static_cast<char>(arr[i]))
      {
        throw std::exception("You have entered a symbol!");
      }
      else
      {
        indicator = true;
        std::cout << "Thank you!!!" << '\n';
        break;
      }
    }
  }
}

void getAndCheckBorder(double& leftborder, double& rightborder)
{
  bool indicator = false;
  while (!indicator)
  {
    std::cout << "Enter board valuse = ";
    std::cin >> leftborder >> rightborder;
    if (!static_cast<char>(leftborder) || !static_cast<char>(rightborder))
    {
      throw std::exception("You have entered a symbol!");

    }
    else
    {
      indicator = true;
      std::cout << "Thank you!!!" << '\n';
      break;
    }
    if (leftborder > rightborder)
    {
      std::swap(leftborder, rightborder);
    }
  }
}

void getElemensByRandom(double* arr, const int32_t& length, double leftborder, double rightborder)
{
  for (size_t i = 0; i < length; ++i)
  {
    if (leftborder == rightborder)
    {
      arr[i] = leftborder;
    }
    else
    {
      arr[i] = leftborder + rand() * (rightborder - leftborder) / RAND_MAX;
    }
  }
}

void printArray(double* arr, const int32_t& length)
{
  std::cout << '\n';
  for (size_t i = 0; i < length; ++i)
  {
    std::cout << arr[i] << std::setw(9);
  }
  std::cout << '\n';
}

void menu(double* arr, const int32_t& length, double& leftborder, double& rightborder)
{
  int32_t condition = 0;
  bool indicator = false;
  while (!indicator)
  {
    std::cout << "Choose enter 1 - enter hands, 2 - random = ";
    std::cin >> condition;

    if (condition != 1 && condition != 2)
    {

      std::cout << "ERROR!!!" << '\n';
    }
    if (!static_cast<char>(condition)) {
      throw std::exception("You have entered  symbol somewhere\n");
    }
    else
    {
      indicator = true;
      std::cout << "Thank you!!!" << '\n';
      break;
    }
  }
  if (condition == 1)
  {
    enterElementsByHands(arr, length);
  }
  if (condition == 2)
  {
    getAndCheckBorder(leftborder, rightborder);
    getElemensByRandom(arr, length, leftborder, rightborder);

  }
  system("cls");
  printArray(arr, length);
}
int indezMaxElements(double* arr, const int32_t& length, size_t& indezMaxNumber)
{
  double number_max_ell = abs(arr[0]);
  for (size_t i = 0; i < length; ++i)
  {
    if (number_max_ell < abs(arr[i]))
    {
      number_max_ell = abs(arr[i]);
      indezMaxNumber = i;
    }
  }
  return indezMaxNumber;
}

double summaNegativElementsArray(double* arr, const int32_t& length)
{
  double sum = 0;
  for (size_t i = 0; i < length; ++i)
  {
    if (arr[i] < 0)
    {
      if (arr[i] < 0)
      {
        sum += arr[i];
      }
    }
    else
    {
      break;
    }
  }
  return sum;
}

double getP()
{
  double p = 0;
  bool indicator = false;
  while (!indicator)
  {
  std::cout << "Please, enter P\n";
  std::cin >> p;
  if (!static_cast<char>(p))
  {
    throw std::exception("You have entered  symbol somewhere\n");
  }
  else
  {
    indicator = true;
    std::cout << "Thank you!!!" << '\n';
    return p;
    break;
  }
  }
}

int lastNegativElements(double* arr, const int32_t& length, size_t& lastNegativIndex)
{
  lastNegativIndex = -1;
  for (size_t i = length - 1; i >= 0; i--)
  {
    if (arr[i] < 0)
    {
      lastNegativIndex = i;
      break;
    }
  }
  return lastNegativIndex;
}

void arrayMemoryClear(double*& arr)
{
  delete[] arr;
}

double* helpAssignement1(double* arr, const int32_t& length, size_t& lastNegativIndex, double& p)
{
  double* new_arr = new double[length + 1];
  double time = arr[lastNegativIndex + 1];
  for (size_t i = 0; i < length; ++i)
  {
    new_arr[i] = arr[i];
  }
  new_arr[lastNegativIndex + 1] = p;
  for (size_t i = lastNegativIndex + 2; i < length; ++i)
  {
    new_arr[i] = arr[i - 1];
  }
  for (size_t i = 0; i < length; ++i)
  {
    std::cout << new_arr[i] << std::setw(9);
  }

  return new_arr;
}

void insertElememtsAfterP(double* arr, int32_t& length, size_t& lastNegativIndex, double& p)
{
  double* new_arr = new double[length] {};
  lastNegativIndex = lastNegativElements(arr, length, lastNegativIndex);
  double LastNegativElements;
  int32_t indexLastNegativElemnts;
  indexLastNegativElemnts = lastNegativIndex;
  LastNegativElements = arr[lastNegativIndex];
  length++;
  arr = helpAssignement1(arr, length, lastNegativIndex, p);

}

void chekOfNegativElements(double* arr, int32_t& length, size_t& lastNegativIndex, double& p)
{
  double* new_arr = new double[length] {};
  lastNegativIndex = lastNegativElements(arr, length, lastNegativIndex);
  if (lastNegativIndex < 0)
  {
    std::cout << "There are no negative numbers in the array. P was not inserted.\n";
    return;
  }

  if (lastNegativIndex >= 0)
  {
    insertElememtsAfterP(arr, length, lastNegativIndex, p);
  }
  arrayMemoryClear(arr);
}

int main()
{
  try
  {
    srand(time(0));
    int32_t length = 0;
    getLength(length);
    double* arr = new double[length];
    double leftborder = 0, rightborder = 0;
    size_t indezMaxNumber = 0;
    double sum = 0;
    double p = 0;
    menu(arr, length, leftborder, rightborder);
    indezMaxNumber = indezMaxElements(arr, length, indezMaxNumber);
    std::cout << "Max element in array has number = " << indezMaxNumber + 1 << '\n';
    sum = summaNegativElementsArray(arr, length);
    if (sum < 0)
    {
      std::cout << "Sum of negative numbers = " << sum << '\n';
    }
    else
    {
      std::cout << "There are no negative elements" << '\n';

    }
    size_t lastNegativIndex = lastNegativElements(arr, length, lastNegativIndex);
    p = getP();
    chekOfNegativElements(arr, length, lastNegativIndex, p);
    std::cout << '\n';
    return 0;
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what();
  }
}
