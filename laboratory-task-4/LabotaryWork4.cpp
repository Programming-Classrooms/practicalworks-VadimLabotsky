#include <iostream>
#include <random>
#include<exception>
#include <ctime>
#include <iomanip>


void getRowAndColumn(int32_t& row, int32_t& column)
{
	bool indicator = false;
	while (!indicator)
	{
		std::cout << "Enter row and column matrix = \n";
		std::cin >> row >> column;
		if (row < 0 || column < 0)
		{
			std::cout << "ERROR!!!" << '\n';
		}
		if (!static_cast<char>(row) || !static_cast<char>(column)) {
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
void swapBordes(int32_t& leftborder, int32_t& rightborder)
{
	int32_t help = rightborder;
	rightborder = leftborder;
	leftborder = help;
}
void  allocatesMemoryForArray(int64_t**& mtrx,const int32_t& row, const int32_t& column)
{
	mtrx = new int64_t* [row];
	for (size_t i = 0; i < row; ++i) {

		mtrx[i] = new int64_t[column];

	}
}
int64_t  enterMatrix(int64_t** mtrx, const int32_t& row, const int32_t& column)
{

	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			std::cout << "You enter elements massive whose number is " << i <<" " << j << '\n';
			std::cin >> mtrx[i][j];
			std::cout << std::setw(4);
		}
		std::cout << '\n';
	}
	std::cout << "Thank you!!!" << '\n';
	return 0;
}
void enterAndCheckBorder(int32_t& leftborder, int32_t& rightborder)
{
	bool indicator = false;
	while (leftborder == rightborder && !indicator)
	{
		std::cout << "Enter board valuse = ";
		std::cin >> leftborder >> rightborder;
		if (!static_cast<char>(leftborder) || !static_cast<char>(rightborder)) {
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
			swapBordes(leftborder, rightborder);
		}
	}
}
void mtrxFillRand(int64_t** mtrx, const int32_t& row, const int32_t& column, int32_t leftborder, int32_t rightborder)
{
	srand(time(NULL));
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			mtrx[i][j] = (leftborder + rand() % ((rightborder - leftborder + 1)));
		}
	}
}
void printMatrix(int64_t** mtrx, const int32_t& row, const int32_t& column)
{
	std::cout << '\n';
	for (size_t i = 0; i < row; ++i)
	{
		for (std::size_t j = 0; j < column; ++j)
		{
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
		enterMatrix(mtrx, row, column);
	}
	if (condition == 2)
	{
		enterAndCheckBorder(leftborder, rightborder);
		mtrxFillRand(mtrx, row, column, leftborder, rightborder);
	}
	system("cls");
	std::cout << "Our matrix is:\n";
	printMatrix(mtrx, row, column);
}
bool checkNoNegativeElements(int64_t** mtrx, size_t& fix_index, const int32_t& column) {
	for (size_t j = 0; j < column; ++j) {
		if (mtrx[fix_index][j] < 0) {
			return false;
		}
	}
	return true;
}
void productInRow (int64_t** mtrx, const int32_t& column, const int32_t& row)
{
	int32_t product = 0;
	for (std::size_t i = 0; i < row; ++i)
	{
		if (checkNoNegativeElements(mtrx, i, column))
		{
			product = 1;
			for (std::size_t j = 0; j < column; ++j)
			{
				product *= mtrx[i][j];
			}
			std::cout << "Row number in " << i + 1 << " row =  " << ' ' << product << ' ' << '\n';
		}
		else
		{
			std::cout << "Negativ elements in " << i + 1 << " row!\n";
		}
		product = 0;
	}
}

int64_t  maxElementsInMatrix(int64_t** mtrx,  const int32_t& row, const int32_t& column, size_t& column_max_elements_matrix, size_t& row_max_elements_matrix) {
	int32_t max_elements = 0;
	column_max_elements_matrix = -1;
	row_max_elements_matrix = -1;
	for (std::size_t i = 0; i < row; ++i)
	{
		for (std::size_t j = 0; j < column; ++j)
		{
			if (mtrx[i][j] > max_elements)
			{
				max_elements = mtrx[i][j];
				row_max_elements_matrix = i;
				column_max_elements_matrix = j;
			}
		}
	}
	return max_elements;
}
void swapMaxElementsInRow(int64_t** mtrx, const int32_t& row, const int32_t& column, size_t& row_max_elements_matrix)
{
	for (size_t j = 0; j < column; j++)
	{
		std::swap(mtrx[0], mtrx[row_max_elements_matrix]);
	}
	std::swap(mtrx[0], mtrx[row_max_elements_matrix]);
}
void swapMaxElementsInColumn(int64_t** mtrx, const int32_t& row, const int32_t& column, size_t& column_max_elements_matrix)
{
	for (size_t j = 0; j < row; j++)
	{
		std::swap(mtrx[j][0], mtrx[j][column_max_elements_matrix]);
	}

}
void chekAndSwapMaxElements(int64_t** mtrx, const int32_t& row, const int32_t& column, size_t& column_max_elements_matrix, size_t& row_max_elements_matrix)
{
	maxElementsInMatrix(mtrx, row, column, column_max_elements_matrix, row_max_elements_matrix);
	if (row_max_elements_matrix != -1 && column_max_elements_matrix != -1)
	{
		if (row_max_elements_matrix == 0 && column_max_elements_matrix == 0)
		{
			std::cout << "Max elements in its plase!\n";
		}
		swapMaxElementsInRow(mtrx, row, column, column_max_elements_matrix);
		swapMaxElementsInColumn(mtrx, row, column, column_max_elements_matrix);
		std::cout << "Our matrix after the transformation:\n";
		printMatrix(mtrx, row, column);
	}
	else
	{
		std::cout << "There aren't positeve elements in matrix!\n";
	}
}
void deleteMatrix(int64_t**& mtrx, int32_t& row, int32_t& column)
{
	for (int64_t i = 0; i < row; ++i)
	{
		delete[] mtrx[i];
	}
	delete[] mtrx;
}

int main()
{
	try {
		std::int32_t row = 0;
		std::int32_t column = 0;
		getRowAndColumn(row, column);
		std::int32_t leftborder = 0, rightborder = 0;
		std::int64_t** mtrx{ nullptr };
		std::size_t column_max_elements_matrix = -1;
		std::size_t row_max_elements_matrix = -1;
		allocatesMemoryForArray(mtrx, row, column);
		menu(mtrx, row, column, leftborder, rightborder);
		productInRow(mtrx, column, row);
		chekAndSwapMaxElements(mtrx, row, column, column_max_elements_matrix, row_max_elements_matrix);
		deleteMatrix(mtrx, row, column);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
	return 0;
}
