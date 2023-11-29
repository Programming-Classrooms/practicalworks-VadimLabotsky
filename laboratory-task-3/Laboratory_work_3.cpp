#include <iostream>
#include <random>
#include <ctime>
int64_t length_arrow()
{
	int64_t length = 0;
	while (length <= 0)
	{
		std::cout << "Enter lenght array = ";
		std::cin >> length;
		std::cout << "Thank you!!!" << '\n';
	}
	return length;
}

void swap_(double& leftborder, double& rightborder)
{
	int64_t help = rightborder;
	rightborder = leftborder;
	leftborder = help;
}
int64_t enterNumber(double* arr, const int64_t& length)
{
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << "Ener element = ";
		std::cin >> arr[i];
	}
	std::cout << "Thank you!!!" << '\n';
	return 0;
}
int64_t checkborder(double& leftborder, double& rightborder)
{

	while (leftborder == rightborder)
	{
		std::cout << "Enter board valuse = ";
		std::cin >> leftborder >> rightborder;
		if (leftborder > rightborder)
		{
			swap_(leftborder, rightborder);
		}

	}
	return 0;
}

void randomNum(double* arr, const int& length, double leftborder, double rightborder)
{
	
	
	for (size_t i = 0; i < length; ++i)
	{
		arr[i] = leftborder + rand() * (rightborder - leftborder) / RAND_MAX;
	}
}
void output_array(double* arr, const int64_t& length)
{
	std::cout << '\n';
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << arr[i] << "    ";
	}
	std::cout << '\n';
}

void choice(double* arr, const int64_t& length, double& leftborder, double& rightborder)
{
	int64_t condition = 0;

	

	while (condition != 1 && condition != 2)
	{
		std::cout << "Choose enter 1 - enter hands, 2 - random = ";
		std::cin >> condition;
		std::cout << "Thank you!!!" << '\n';
	}
	if (condition == 1)
	{
		enterNumber(arr, length);
	}
	if (condition == 2)
	{
		checkborder(leftborder, rightborder);
		randomNum(arr, length, leftborder, rightborder);
		
	}
	system("cls");
	output_array(arr, length);
}


int indez_max_elements(double* arr, const int64_t& length, int64_t& indez_maxelements)
{
	double number_max_ell = abs(arr[0]);
	for (size_t i = 0; i < length; ++i)
	{
		if (number_max_ell < abs(arr[i]))
		{
			number_max_ell = abs(arr[i]);
			indez_maxelements = i;
		}

	}
	return indez_maxelements;
}
double summa_elements(double* arr, const int64_t& length)
{
	double sum = 0;
	for (size_t i = 0; i < length; ++i)
	{
		if (arr[i] < 0 )
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
double intput_p()
{
	double p = 0;
	std::cout << "Please, enter P\n";
	std::cin >> p;
	std::cout << "Thank you!!!" << '\n';
	return p;
}
int lst_num(double* arr, const int64_t& length, int64_t& lst_num_index)
{
	lst_num_index = -1;
	for (size_t i = length - 1; i >= 0; i--)
	{
		if (arr[i] < 0)
		{
			lst_num_index = i;
			break;
		}
	}
	return lst_num_index;
}
void del(double*& arr)
{
	delete[] arr;
}

double* help_assignement_1(double*& arr, const int64_t& length, int64_t& lst_num_index, double& p)
{
	double* new_arr = new double[length+1];

	int cpy = arr[lst_num_index + 1];

	for (size_t i = 0; i < length; ++i) {
		new_arr[i] = arr[i];
	}


	new_arr[lst_num_index + 1] = p;
	for (size_t i = lst_num_index + 2; i < length; ++i) {
		new_arr[i] = arr[i - 1];
	}

	for (size_t i = 0; i < length; ++i) {
		std::cout << new_arr[i] << "    ";
	}
	
	return new_arr;
}

void output_array(double* arr, int64_t& length)
{
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << arr[i] << "    ";
	}

}

void past_after_p(double* arr, int64_t& length, int64_t& lst_num_index, double& p)
{
	double* new_arr = new double[length] {};
	lst_num_index = lst_num(arr, length, lst_num_index);
	double h;
	int64_t l;
	l = lst_num_index;
	h = arr[lst_num_index];
	length++;
	arr = help_assignement_1(arr, length, lst_num_index, p);

}
void chek(double* arr, int64_t& length, int64_t& lst_num_index, double& p)
{
		double* new_arr = new double[length] {};
		lst_num_index = lst_num(arr, length, lst_num_index);
		if (lst_num_index < 0) 
		{
			std::cout << "There are no negative numbers in the array. P was not inserted.\n";
			output_array(arr, length);
			return;
		}
		
		if (lst_num_index >= 0)
		{
			past_after_p(arr, length, lst_num_index, p);
		}
		del(arr);
}



int main()
{
	srand(time(0));
	int64_t length = length_arrow();
	double* arr = new double[length];
	double leftborder{0}, rightborder{0};
	int64_t indez_maxelements{0};
	double sum;
	double p{};
	choice(arr, length, leftborder, rightborder);
	indez_maxelements = indez_max_elements(arr, length, indez_maxelements);
	std::cout << "Max element in array has number = "<< indez_maxelements + 1 << '\n';
	sum = summa_elements(arr, length);
	if (sum < 0)
	{
		std::cout << "Sum of negative numbers = " << sum << '\n';
	}
	else
	{
		std::cout << "There are no negative elements" << '\n';
	
	}
	
	int64_t lst_num_index = lst_num(arr, length, lst_num_index);
	p = intput_p();
	chek(arr,  length,  lst_num_index, p);
	std::cout << '\n';
	return 0;
} 
