/*
    Тема: ОДНОМЕРНЫЕ МАССИВЫ (ЧИСЛОВЫЕ ПОСЛЕДОВАТЕЛЬНОСТИ)
    Использовать статический массив ( + отдельно сделать для динамического массива). Максимальную
    размерность массива задать именованной константой. Реальное количество элементов массива ввести с клавиатуры с
    контролем на выход за границы массива. Массивы должны состоять не менее, чем из одного элемента.
    Предусмотреть два способа заполнения массива: с клавиатуры и с помощью датчика случайных чисел. В последнем случае
    перед заполнением массива ввести границы интервала, которому должны принадлежать элементы массива.
    Вывести результаты расчетов. Если по каким-либо причинам решение задачи невозможно, вывести соответствующее
    сообщение. Дополнительных массивов для преобразования данных использовать нельзя.
    Вариант 31
    В массиве, состоящем из п вещественных элементов, вычислить:
    номер максимального по модулю элемента массива (если таких элементов несколько,найти минимальный номер);
    сумму элементов массива, расположенных до первого положительного элемента.
    Вставить после последнего отрицательного числа заданное число Р.
*/


#include <iostream>
#include <random>
#include <ctime>
#include<iomanip>


void checkLength(int32_t& length)
{
    if (length < 0) {
        std::cout << "ERROR!!!" << '\n';
    }

    if (!static_cast<char>(length)) {
        throw std::exception("You have entered a symbol!");
    }
}

void getLength(int32_t& length)
{
    length = 0;
    bool indicator = false;

    while (!indicator) {
        std::cout << "Enter lenght array = ";
        std::cin >> length;
        checkLength(length);
        indicator = true;
    }
}

void  enterElemOfArrayByManual(double* arr, const int32_t& length)
{
    bool indicator = false;

    for (size_t i = 0; i < length; ++i) {
        
        while (!indicator) {
            std::cout << "Enter element = ";
            std::cin >> arr[i];

            if (!static_cast<char>(arr[i])) {
                throw std::exception("You have entered a symbol!");
            }

            else {
                indicator = true;
                std::cout << "Thank you!!!" << '\n';
                break;
            }
        }
    }
}

void checkBorders(double& leftborder, double& rightborder)
{
    if (!static_cast<char>(leftborder) || !static_cast<char>(rightborder)) {
        throw std::exception("You have entered a symbol!");
    }

    if (leftborder > rightborder) {
        std::swap(leftborder, rightborder);
    }
}

void getAndCheckBorder(double& leftborder, double& rightborder)
{
    bool indicator = false;

    while (!indicator) {
        std::cout << "Enter board valuse = ";
        std::cin >> leftborder >> rightborder;

        checkBorders(leftborder, rightborder);
        indicator = true;
    }
}

void random(double* arr, const int32_t& length, double leftborder, double rightborder, size_t& i)
{
    arr[i] = leftborder + rand() * (rightborder - leftborder) / RAND_MAX;
}

void fillingElemensByRandom(double* arr, const int32_t& length, double leftborder, double rightborder)
{
    for (size_t i = 0; i < length; ++i) {
        
        if (leftborder == rightborder) {
            arr[i] = leftborder;
        }

        else {
            random(arr, length, leftborder, rightborder, i);
        }
    }
}

void printArray(double* arr, int32_t& length)
{
    for (size_t i = 0; i < length; ++i) {
        std::cout << arr[i] << std::setw(9);
    }
}

void menu(double* arr, int32_t& length, double& leftborder, double& rightborder)
{
    int32_t condition = 0;
    bool indicator = false;
    
    while (!indicator) {
       
        std::cout << "Choose enter 1 - enter hands, 2 - random = ";
        std::cin >> condition;
       
        if (condition != 1 && condition != 2) {
            std::cout << "ERROR!!!" << '\n';
            throw std::exception("Incorrect values!");
            break;
        }
       
        if (!static_cast<char>(condition)) {
            throw std::exception("You have entered  symbol somewhere\n");
        }
       
        else {
            indicator = true;
            break;
        }
    }
    
    if (condition == 1) {
        enterElemOfArrayByManual(arr, length);
    }
    
    if (condition == 2) {
        getAndCheckBorder(leftborder, rightborder);
        fillingElemensByRandom(arr, length, leftborder, rightborder);
    }
    system("cls");
    printArray(arr, length);
}

int32_t indexMaxElements(double* arr, const int32_t& length, size_t& indezMaxNumber)
{
    double number_max_ell = abs(arr[0]);

    for (size_t i = 0; i < length; ++i) {
       
        if (number_max_ell < abs(arr[i])) {
            number_max_ell = abs(arr[i]);
            indezMaxNumber = i;
        }
    }
    return indezMaxNumber;
}

double summaNegativElementsArray(double* arr, const int32_t& length)
{
    double sum = 0;

    for (size_t i = 0; i < length; ++i) {
        
        if (arr[i] < 0) {
            
            if (arr[i] < 0) {
                sum += arr[i];
            }
        }
       
        else {
            break;
        }
    }

    return sum;
}

double getUserNumber()
{
    double userNumber = 0;
    bool indicator = false;

    while (!indicator) {
        std::cout << "Please, enter P\n";
        std::cin >> userNumber;

        if (!static_cast<char>(userNumber)) {
            throw std::exception("You have entered  symbol somewhere\n");
        }

        else {
            indicator = true;
            std::cout << "Thank you!!!" << '\n';
            return userNumber;
            break;
        }
    }
}

int64_t lastNegativeElement(double* arr, const int32_t& length, size_t& lastNegativeIndex)
{
    lastNegativeIndex = -1;
    for (size_t i = length - 1; i >= 0; --i) {

        if (arr[i] < 0) {
            lastNegativeIndex = i;
            break;
        }

    }

    return lastNegativeIndex;
}

void arrayMemoryClear(double*& arr)
{
    delete[] arr;
}

double* helpAssignement1(double* arr, const int32_t& length, size_t& lastNegativeIndex, double& userNumber)
{
    double* newArr = new double[length + 1];
    double time = arr[lastNegativeIndex + 1];

    for (size_t i = 0; i < length; ++i) {
        newArr[i] = arr[i];
    }

    newArr[lastNegativeIndex + 1] = userNumber;

    for (size_t i = lastNegativeIndex + 2; i < length; ++i) {
        newArr[i] = arr[i - 1];
    }

    for (size_t i = 0; i < length; ++i) {
        std::cout << newArr[i] << std::setw(15);
    }

    return newArr;
}

void insertElememtsAfterP(double* arr, int32_t& length, size_t& lastNegativeIndex, double& userNumber)
{
    double* new_arr = new double[length] {};
    lastNegativeIndex = lastNegativeElement(arr, length, lastNegativeIndex);
    double LastNegativElements;
    int32_t indexLastNegativElemnts = lastNegativeIndex;

    LastNegativElements = arr[lastNegativeIndex];
    length++;
    arr = helpAssignement1(arr, length, lastNegativeIndex, userNumber);
}

void chekOfNegativElements(double* arr, int32_t& length, size_t& lastNegativeIndex, double& userNumber)
{
    double* new_arr = new double[length] {};

    lastNegativeIndex = lastNegativeElement(arr, length, lastNegativeIndex);

    if (lastNegativeIndex < 0)
    {
        std::cout << "\nThere are no negative numbers in the array. P was not inserted.\n";
        return;
    }

    if (lastNegativeIndex >= 0)
    {
        insertElememtsAfterP(arr, length, lastNegativeIndex, userNumber);
    }

    arrayMemoryClear(arr);
}

int main()
{
    try {
        srand(time(0));
        int32_t length = 0;
        getLength(length);
        double* arr = new double[length];
        double leftborder = 0, rightborder = 0;
        size_t indexMaxNumber = 0;
        double sum = 0;
        double userNumber = 0;

        menu(arr, length, leftborder, rightborder);

        indexMaxNumber = indexMaxElements(arr, length, indexMaxNumber);

        std::cout << "\nMax element in array has number = " << indexMaxNumber + 1;

        sum = summaNegativElementsArray(arr, length);

        if (sum < 0) {
            std::cout << "\nSum of negative numbers = " << sum << '\n';
        }

        else {
            std::cout << "There are no negative elements" << '\n';

        }

        size_t lastNegativIndex = lastNegativeElement(arr, length, lastNegativIndex);
        userNumber = getUserNumber();
        
        chekOfNegativElements(arr, length, lastNegativIndex, userNumber);
        std::cout << '\n';
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}
