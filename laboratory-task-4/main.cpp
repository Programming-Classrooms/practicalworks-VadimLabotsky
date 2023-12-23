/*
    При решении следующих задач использовать динамический массив. При необходимости заполнения массива предусмотреть
    два способа: ввод с клавиатуры и заполнение с помощью датчика случайных чисел. В последнем случае перед заполнением
    массива ввести границы интервала, которому должны принадлежать элементы массива. Вывести результаты расчетов. Если
    по каким-либо причинам решение задачи невозможно, вывести соответствующее сообщение.
    Вариант 5
    В целочисленной прямоугольной матрице найти:
    - произведение элементов в тех строках, которые не содержат отрицательных элементов;
    - переставить строки и столбцы матрицы так, чтобы в левом верхнем углу
    - матрицы оказался максимальный положительный элемент матрицы.
*/


#include <iostream>
#include <random>
#include <exception>
#include <ctime>
#include <iomanip>


void getRowAndColumn(int32_t& row, int32_t& column)
{
    bool indicator = false;
    while (!indicator) {
        std::cout << "Enter row and column matrix = \n";
        std::cin >> row >> column;
        if (row < 0 || column < 0) {
            std::cout << "ERROR!!!" << '\n';
        }
        if (!static_cast<char>(row) || !static_cast<char>(column)) {
            throw std::exception("You have entered a symbol!");
        }
        else {
            indicator = true;
            std::cout << "Thank you!!!\n";
            break;
        }
    }
}

void  allocatesMemoryForMatrix(int64_t** mtrx, const int32_t& row, const int32_t& column)
{
    mtrx = new int64_t * [row];
    for (size_t i = 0; i < row; ++i) {
        mtrx[i] = new int64_t[column];
    }
}

int64_t  enterMatrix(int64_t** mtrx, const int32_t& row, const int32_t& column)
{
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            std::cout << "You enter elements matrix whose number is " << i << " " << j << '\n';
            std::cin >> mtrx[i][j];
        }
        std::cout << '\n';
    }
    std::cout << "Thank you!!!" << '\n';
    return 0;
}

void enterAndCheckBorder(int32_t& leftborder, int32_t& rightborder)
{
    bool indicator = false;
    while (!indicator) {
        std::cout << "Please, enter board valuse!\n";
        std::cin >> leftborder >> rightborder;
        if (!static_cast<char>(leftborder) || !static_cast<char>(rightborder)) {
            throw std::exception("You have entered a symbol!");
        }
        else {
            indicator = true;
            std::cout << "Thank you!!!" << '\n';
            break;
        }
        if (leftborder > rightborder) {
            std::swap(leftborder, rightborder);
        }
    }
}

void mtrxFillRand(int64_t** mtrx, const int32_t& row, const int32_t& column, int32_t leftborder, int32_t rightborder)
{
    srand(time(NULL));
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            if (leftborder == rightborder) {
                mtrx[i][j] = leftborder;
            }
            else {
                mtrx[i][j] = (leftborder + rand() % ((rightborder - leftborder + 1)));
            }
        }
    }
}

void printMatrix(int64_t** mtrx, const int32_t& row, const int32_t& column)
{
    std::cout << '\n';
    for (size_t i = 0; i < row; ++i) {
        for (std::size_t j = 0; j < column; ++j) {
            std::cout << std::setw(4) << mtrx[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void menu(int64_t** mtrx, const int32_t& row, const int32_t& column, int32_t& leftborder, int32_t& rightborder)
{
    std::int32_t condition = 0;
    bool indicator = false;
    while (!indicator) {
        std::cout << "Choose enter 1 - enter hands, 2 - random = ";
        std::cin >> condition;
        if (condition != 1 && condition != 2) {
            std::cout << "ERROR!!!" << '\n';
        }
        if (!static_cast<char>(condition)) {
            throw std::exception("You have entered  symbol somewhere\n");
        }
        else {
            indicator = true;
            std::cout << "Thank you!!!" << '\n';
            break;
        }
    }
    if (condition == 1) {
        enterMatrix(mtrx, row, column);
    }
    if (condition == 2) {
        enterAndCheckBorder(leftborder, rightborder);
        mtrxFillRand(mtrx, row, column, leftborder, rightborder);
    }
    system("cls");
    std::cout << "Our matrix is:\n";
    printMatrix(mtrx, row, column);
}

bool checkNoNegativeElements(int64_t** mtrx, size_t& fixIndex, const int32_t& column)
{
    for (size_t j = 0; j < column; ++j) {
        if (mtrx[fixIndex][j] < 0) {
            return false;
        }
    }
    return true;
}

void productInRow(int64_t** mtrx, const int32_t& column, const int32_t& row)
{
    int32_t product = 0;
    for (std::size_t i = 0; i < row; ++i) {
        if (checkNoNegativeElements(mtrx, i, column)) {
            product = 1;
            for (std::size_t j = 0; j < column; ++j) {
                product *= mtrx[i][j];
            }
            std::cout << "Row number in " << i + 1 << " row =  " << ' ' << product << ' ' << '\n';
        }
        else {
            std::cout << "Negativ elements in " << i + 1 << " row!\n";
        }
        product = 0;
    }
}

int64_t  maxElementsInMatrix(int64_t** mtrx, const int32_t& row, const int32_t& column, size_t& columnMaxElementsMatrix, size_t& rowMaxElementsMatrix)
{
    int32_t max_elements = 0;
    columnMaxElementsMatrix = -1;
    rowMaxElementsMatrix = -1;
    for (std::size_t i = 0; i < row; ++i) {
        for (std::size_t j = 0; j < column; ++j) {
            if (mtrx[i][j] > max_elements) {
                max_elements = mtrx[i][j];
                rowMaxElementsMatrix = i;
                columnMaxElementsMatrix = j;
            }
        }
    }
    return max_elements;
}

void swapMaxElementsInRow(int64_t** mtrx, const int32_t& row, const int32_t& column, size_t& rowMaxElementsMatrix)
{
    for (size_t j = 0; j < column; j++) {
        std::swap(mtrx[0], mtrx[rowMaxElementsMatrix]);
    }
    std::swap(mtrx[0], mtrx[rowMaxElementsMatrix]);
}

void swapMaxElementsInColumn(int64_t** mtrx, const int32_t& row, const int32_t& column, size_t& columnMaxElementsMatrix)
{
    for (size_t j = 0; j < row; j++) {
        std::swap(mtrx[j][0], mtrx[j][columnMaxElementsMatrix]);
    }
}

void chekAndSwapMaxElements(int64_t** mtrx, const int32_t& row, const int32_t& column, size_t& columnMaxElementsMatrix, size_t& rowMaxElementsMatrix)
{
    maxElementsInMatrix(mtrx, row, column, columnMaxElementsMatrix, rowMaxElementsMatrix);
    if (rowMaxElementsMatrix != -1 && columnMaxElementsMatrix != -1) {
        if (rowMaxElementsMatrix == 0 && columnMaxElementsMatrix == 0) {
            std::cout << "Max elements in its plase!\n";
        }
        swapMaxElementsInRow(mtrx, row, column, columnMaxElementsMatrix);
        swapMaxElementsInColumn(mtrx, row, column, columnMaxElementsMatrix);
        std::cout << "Our matrix after the transformation:\n";
        printMatrix(mtrx, row, column);
    }
    else {
        std::cout << "There aren't positeve elements in matrix!\n";
    }
}

void deleteMatrix(int64_t**& mtrx, int32_t& row, int32_t& column)
{
    for (int64_t i = 0; i < row; ++i) {
        delete[] mtrx[i];
    }
    delete[] mtrx;
}

int main()
{
    try {
        std::int32_t row = 0;
        std::int32_t column = 0;
        std::int32_t leftborder = 0;
        std::int32_t rightborder = 0;
        std::int64_t** mtrx = 0;
        std::size_t columnMaxElementsMatrix = -1;
        std::size_t rowMaxElementsMatrix = -1;
        getRowAndColumn(row, column);
        allocatesMemoryForMatrix(mtrx, row, column);
        menu(mtrx, row, column, leftborder, rightborder);
        productInRow(mtrx, column, row);
        chekAndSwapMaxElements(mtrx, row, column, columnMaxElementsMatrix, rowMaxElementsMatrix);
        deleteMatrix(mtrx, row, column);
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}

