#include <iostream>
#include <random>
#include<exception>
#include <ctime>
#include <iomanip>
int32_t enter_row()
{
	int32_t row = 0;

	bool a = false;
	while (a == false)
	{
		std::cout << "Enter row matrix = \n";
		std::cin >> row;
		if (row < 0)
		{

			std::cout << "ERROR!!!" << '\n';
		}
		if (!static_cast<char>(row)) {
			throw std::exception("Symbol");
			
		}
		else
		{
			a = true;
			std::cout << "Thank you!!!" << '\n';
			break;
		}
	}

	return row;
}

std::int32_t enter_column()
{
	std::int32_t column = 0;


	bool a = false;
	while (a == false)
	{
		std::cout << "Enter column matrix = \n";
		std::cin >> column;
		if (column < 0)
		{
			std::cout << "ERROR!!!" << '\n';
		}
		if (!static_cast<char>(column)) {
			throw std::exception("Symbol");
		}
		else
		{
			a = true;
			std::cout << "Thank you!!!" << '\n';
			break;

		}
	}




	return column;
}
void swap_bordes(int32_t& leftborder, int32_t& rightborder)
{
	std::int32_t help = rightborder;
	rightborder = leftborder;
	leftborder = help;
}
void  allocates_memory_for_a_two_dimensional_array(int64_t**& mtrx, const int32_t& row, const int32_t& column)
{
	mtrx = new int64_t * [row];
	for (int64_t i = 0; i < row; ++i) {

		mtrx[i] = new int64_t[column];

	}
}
int64_t  enter_matrix(int64_t** mtrx, const int32_t& row, const int32_t& column)
{

	for (int64_t i = 0; i < row; ++i)
	{

		std::cout << "Enter row " << i + 1 << '\n';

		for (int64_t j = 0; j < column; ++j)
		{
			std::cout << "Enter elements massive ";
			std::cin >> mtrx[i][j];
			std::cout << '\t';
		}
		std::cout << '\n';
	}
	std::cout << "Thank you!!!" << '\n';
	return 0;
}
void enter_and_check_border(int32_t& leftborder, int32_t& rightborder)
{
	while (leftborder == rightborder)
	{
		std::cout << "Enter board valuse = ";
		std::cin >> leftborder >> rightborder;
		if (leftborder > rightborder)
		{
			swap_bordes(leftborder, rightborder);
		}

	}

}


void fill_matrix_is_random(int64_t** mtrx, const int32_t& row, const int32_t& column, int32_t leftborder, int32_t rightborder)
{
	srand(time(NULL));
	for (std::size_t i = 0; i < row; ++i)
	{


		for (std::size_t j = 0; j < column; ++j)
		{
			mtrx[i][j] = (leftborder + rand() % ((rightborder - leftborder + 1)));//ÌÀÒÐÈÖÀ ÈÇ 0 È 1
		}
	}
}
void output_mtrx(int64_t** mtrx, const int32_t& row, const int32_t& column)
{

	std::cout << '\n';
	for (std::size_t i = 0; i < row; ++i)
	{
		for (std::size_t j = 0; j < column; ++j)
		{
			std::cout << std::setw(4) << mtrx[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void choice_enter_matrix(int64_t** mtrx, const int32_t row, const int32_t column, int32_t& leftborder, int32_t& rightborder)
{
	std::int32_t condition = 0;

	bool a = false;
	while (a == false)
	{
		std::cout << "Choose enter 1 - enter hands, 2 - random = ";
		std::cin >> condition;

		if (condition != 1 && condition != 2)
		{

			std::cout << "ERROR!!!" << '\n';
		}
		if (!static_cast<char>(condition)) {
			throw std::exception("User input symbol somewhere\n");
		}
		else
		{
			a = true;
			std::cout << "Thank you!!!" << '\n';
			break;
		}
	}
	if (condition == 1)
	{
		enter_matrix(mtrx, row, column);
	}
	if (condition == 2)
	{
		enter_and_check_border(leftborder, rightborder);
		fill_matrix_is_random(mtrx, row, column, leftborder, rightborder);

	}
	system("cls");
	std::cout << "Our matrix is:\n";
	output_mtrx(mtrx, row, column);
}


bool check_no_negative_elements(std::int64_t** mtrx, const std::int32_t& fix_index, const std::int32_t& column) {
	for (std::size_t j = 0; j < column; ++j) {
		if (mtrx[fix_index][j] < 0) {
			return false;
		}
	}
	return true;
}

void product_in_some_row(std::int64_t** mtrx, const std::int32_t& column, const std::int32_t& row)
{
	std::int32_t product = 0;
	for (std::size_t i = 0; i < row; ++i)
	{
		if (check_no_negative_elements(mtrx, i, column))
		{
			product = 1;
			for (std::int64_t j = 0; j < column; ++j)
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

int64_t  max_elements_in_matrix(int64_t**& mtrx, const int32_t& row, const int32_t& column, int32_t& column_max_elements_matrix, int32_t& row_max_elements_matrix) {
	std::int32_t max_elements = 0;
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
void swap_max_elements_in_row(int64_t**& mtrx, const int32_t& row, const int32_t& column, int32_t& row_max_elements_matrix)
{
	for (size_t j = 0; j < column; j++)
	{
		std::swap(mtrx[0], mtrx[row_max_elements_matrix]);
	}

	std::swap(mtrx[0], mtrx[row_max_elements_matrix]);
}
void swap_max_elements_in_column(int64_t**& mtrx, const int32_t& row, const int32_t& column, int32_t& column_max_elements_matrix)
{
	for (size_t j = 0; j < row; j++)
	{
		std::swap(mtrx[j][0], mtrx[j][column_max_elements_matrix]);
	}

}
void chek_and_swap_max_elements(int64_t** mtrx, const int32_t& row, const int32_t& column, int32_t& column_max_elements_matrix, int32_t& row_max_elements_matrix)
{
	max_elements_in_matrix(mtrx, row, column, column_max_elements_matrix, row_max_elements_matrix);
	if (row_max_elements_matrix != -1 && column_max_elements_matrix != -1)
	{
		if (row_max_elements_matrix == 0 && column_max_elements_matrix == 0)
		{
			std::cout << "Max elements in its plase!\n";
		}
		swap_max_elements_in_row(mtrx, row, column, column_max_elements_matrix);
		swap_max_elements_in_column(mtrx, row, column, column_max_elements_matrix);
		std::cout << "Our matrix after the transformation:\n";
		output_mtrx(mtrx, row, column);

	}
	else
	{
		std::cout << "There aren't positeve elements in matrix!\n";
	}
}
void delete_matrix(int64_t**& mtrx, const int32_t& row, const int32_t& column)
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
		std::int32_t row = enter_row();
		std::int32_t column = enter_column();
		std::int32_t leftborder = 0, rightborder = 0;
		std::int64_t** mtrx{ nullptr };
		std::int32_t column_max_elements_matrix = -1;
		std::int32_t row_max_elements_matrix = -1;
		allocates_memory_for_a_two_dimensional_array(mtrx, row, column);
		choice_enter_matrix(mtrx, row, column, leftborder, rightborder);
		product_in_some_row(mtrx, column, row);
		chek_and_swap_max_elements(mtrx, row, column, column_max_elements_matrix, row_max_elements_matrix);
		delete_matrix(mtrx, row, column);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}





	return 0;
}