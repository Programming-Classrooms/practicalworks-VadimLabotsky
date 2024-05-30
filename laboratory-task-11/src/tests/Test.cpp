#include <stdexcept>
#include <gtest/gtest.h>

#include"../class/All/All.hpp"
#include"./class/AllNumbers/AllNumbers.hpp"
#include"../class/AllSurnames/AllSurnames.hpp"
#include"../class/Employee/Employee.hpp"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCheckFile, FileIsNotOpen) {
	std::ifstream fin("src/File/worstFile.txt");
	EXPECT_ANY_THROW(checkFile(fin));
}


TEST(TestCheckFile, FileIsNotExist) {
	std::ifstream fin("src/File/NotExistFile.txt");
	EXPECT_ANY_THROW(checkFile(fin), std::ios_base::failure);
}

TEST(TestCheckFile, FileIsEmpty) {
	std::ifstream fin("../File/emptytFile.txt");
	EXPECT_ANY_THROW(checkFile(fin), std::ios_base::failure);
}


TEST(GetDelimetersTest, DelimetersAreReturnedCorrectly) {
	std::ifstream fin("src/File/delims.txt");
	std::string expectedDelims = "!., ?";
	EXPECT_EQ(getDelimeters(fin), expectedDelims);
	fin.close();
}

TEST(ChekTest, BasicTest) 
{
	EXPECT_TRUE(chek(5, 3));
	EXPECT_FALSE(chek(2, 7)); 
}

TEST(EnterElementsForAllNumberTest, BasicTest)
{
	int32_t numbers[] = { -5, 10, 25, 7, -15, 8, 99, 42 };
	size_t numNumbers = sizeof(numbers);
	int32_t* allNumbers = new int32_t[numNumbers];
	for (size_t i = 0; i < numNumbers; ++i) {
		allNumbers[i] = numbers[i];
	}
	size_t count = numNumbers;
	size_t count1 = numNumbers;
	std::string message = "Enter a number: ";
	enterElementsForAllNumber(allNumbers, count, count1, message);

	for (size_t i = count1; i < count; ++i) {
		EXPECT_GE(allNumbers[i], 0);
		EXPECT_LT(allNumbers[i], 100);
	}

	delete[] allNumbers; 
}

TEST(RemoveNegativeOrDoubleDigitTest, BasicTest)
{
	int32_t numbers[] = { -5, 10, 25, 7, -15, 8, 99, 42 };
	size_t numNumbers = sizeof(numbers) / sizeof(numbers[0]);
	int32_t* allNumbers = new int32_t[numNumbers];
	for (size_t i = 0; i < numNumbers; ++i) {
		allNumbers[i] = numbers[i];
	}
	removeNegativeOrDoubleDigit(allNumbers, numNumbers);
	for (size_t i = 0; i < numNumbers; ++i) {
		EXPECT_GE(allNumbers[i], 0);
		EXPECT_LT(allNumbers[i], 10);
	}

	delete[] allNumbers;
}

TEST(isNumderTest,GoodTest) {
	std::string number = "1223";
	EXPECT_EQ(isNumber(number), true);
}

TEST(isNumderTest, BadTest) {
	std::string number = "!.,?";
	EXPECT_EQ(isNumber(number), false);
}

TEST(ResultsTest, GoodTest) {
	std::string delims = " .,!";
	std::string line = "bjhfuh -1 hvnd 2 jdfgniu jfigu";
	std::string result = "";
	std::string result1 = "-1 2 ";
	size_t count = 0;
	std::ifstream fin("src/File/testNumbers.txt");
	findNumber(line, delims, fin, result, count);
	EXPECT_STREQ(result.c_str(), result1.c_str());
}

TEST(ResultsTest, BadTest) {
	std::string delims = "!.,?";
	std::string line = "";
	std::string result = "";
	std::string result1 = "";
	size_t count = 0;
	std::ifstream fin("src/File/testNumbers.txt");
	findNumber(line, delims, fin, result, count);
	EXPECT_STREQ(result.c_str(), result1.c_str());
}


TEST(ArrayAllNumbersTest, NormalInput) {
	std::string input = "1 2 3 4 5";
	size_t count = 5;
	int32_t* allNumbers = new int32_t[count];
	arrayAllNumbers(input, count, allNumbers);
	EXPECT_EQ(allNumbers[0], 1);
	EXPECT_EQ(allNumbers[1], 2);
	EXPECT_EQ(allNumbers[2], 3);
	EXPECT_EQ(allNumbers[3], 4);
	EXPECT_EQ(allNumbers[4], 5);
	delete[] allNumbers;
}

TEST(ArrayAllNumbersTest, EmptyInput) {
	std::string input = "";
	size_t count = 0;
	int32_t* allNumbers = nullptr;
	arrayAllNumbers(input, count, allNumbers);
	EXPECT_EQ(allNumbers, nullptr);
}


TEST(paritySortTest, EmptyArray) {
    int32_t* arr = nullptr;
    size_t count = 0;
    paritySort(arr, count);
    EXPECT_EQ(arr, nullptr);
}

TEST(paritySortTest, SingleElement) {
    int32_t* arr = new int[1];
    arr[0] = 5;
    size_t count = 1;
    paritySort(arr, count);
    EXPECT_EQ(arr[0], 5);
    delete[] arr;
}

TEST(paritySortTest, EvenOddElements) {
    int32_t* arr = new int[6];
    arr[0] = 2;
    arr[1] = 7;
    arr[2] = 4;
    arr[3] = 9;
    arr[4] = 6;
    arr[5] = 3;
    size_t count = 6;
    paritySort(arr, count);
    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 4);
    EXPECT_EQ(arr[2], 6);
    EXPECT_EQ(arr[3], 7);
    EXPECT_EQ(arr[4], 9);
    EXPECT_EQ(arr[5], 3);
    delete[] arr;
}

TEST(IsValidSurnameTest, EmptyStringReturnsFalse) {
    std::string word = "";
    bool result = isValidSurname(word);
    EXPECT_FALSE(result);
}

TEST(IsValidSurnameTest, LowercaseFirstLetterReturnsFalse) {
    std::string word = "smith";
    bool result = isValidSurname(word);
    EXPECT_FALSE(result);
}

TEST(IsValidSurnameTest, NonAlphabeticCharacterReturnsFalse) {
    std::string word = "O'Neil";
    bool result = isValidSurname(word);
    EXPECT_FALSE(result);
}

TEST(IsValidSurnameTest, ValidSurnameReturnsTrue) {
    std::string word = "Johnson";
    bool result = isValidSurname(word);
	EXPECT_TRUE(result);
}

TEST(IsValidResult, GoodTest) {
	std::string delims = "!.,? ";
	std::string line = "Jhfuh 1 vnd 2 Jhfuh 3 jfigu ";
	std::string result = "";
	std::string result1 = "Jhfuh Jhfuh ";
	size_t count = 0;
	std::ifstream fin("src/File/testNames.txt");
	findName(line, delims, fin, result, count);
	EXPECT_STREQ(result.c_str(), result1.c_str());
}

TEST(ArrayAllSurnameTest, CorrectlyFillsArray) {
	std::string result = "Smith Johnson Williams Brown";
	size_t count = 0;
	std::string* allSurnames = new std::string[4]; 

	arrayAllSurname(result, count, allSurnames);
	
	EXPECT_EQ(allSurnames[0], "Smith");
	EXPECT_EQ(allSurnames[1], "Johnson");
	EXPECT_EQ(allSurnames[2], "Williams");
	EXPECT_EQ(allSurnames[3], "Brown");
}

TEST(InsertionSortTest, CorrectlySortsArray) {
	std::string* allSurnames = new std::string[4];
	allSurnames[0] = "Smith";
	allSurnames[1] = "Johnson";
	allSurnames[2] = "Williams";
	allSurnames[3] = "Brown";
	size_t count = 4;

	insertionSort(count, allSurnames);
	for (size_t i = 1; i < count; ++i) {
		EXPECT_LE(allSurnames[i - 1], allSurnames[i]);
	}
}

TEST(EmployeeTest, LessThanOperator) {
	Employee emp1;
	emp1.children = 3;

	Employee emp2;
	emp2.children = 5;

	EXPECT_TRUE(emp1 < emp2);
	EXPECT_FALSE(emp2 < emp1);
	Employee emp3;
	emp3.children = 3;

	Employee emp4;
	emp4.children = 3;

	EXPECT_TRUE(emp3 == emp4);
	EXPECT_FALSE(emp3 != emp4);
}

TEST(EmployeesTest, ConstructorCreatesObject) {
	Employees employees;

	EXPECT_NE(employees.arr, nullptr);

	EXPECT_EQ(employees.size, 10);
}

TEST(EmployeesTest, EnterEmployeesTest) {
	std::string* allSurnames = new std::string[4];
	allSurnames[0] = "Smith";
	allSurnames[1] = "Johnson";
	allSurnames[2] = "Williams";
	allSurnames[3] = "Brown";
	int32_t* children = new int32_t[4];
	children[0] = 3;
	children[1] = 1;
	children[2] = 4;
	children[3] = 2;
	size_t numEmployees = 4;
	Employee* arr = new Employee[numEmployees];
	Employees result(numEmployees);
	result.enterEmployees(allSurnames, children, numEmployees);
	for (size_t i = 0; i < numEmployees; i++) {
		EXPECT_EQ(result.arr[i].surname, allSurnames[i]);
		EXPECT_EQ(result.arr[i].children, children[i]);
	}
}

TEST(EmployeesTest, PrintEmployeesTest) {
	std::string* allSurnames = new std::string[4];
	allSurnames[0] = "Smith";
	allSurnames[1] = "Johnson";
	allSurnames[2] = "Williams";
	allSurnames[3] = "Brown";
	int32_t* children = new int32_t[4];
	children[0] = 3;
	children[1] = 1;
	children[2] = 4;
	children[3] = 2;
	size_t numEmployees = 4;
	Employees arr(numEmployees);
	for (size_t i = 0; i < numEmployees; i++) {
		arr.arr[i].surname = allSurnames[i];
		arr.arr[i].children = children[i];
	}
	testing::internal::CaptureStdout();
	arr.printEmployees(numEmployees);
	std::string output = testing::internal::GetCapturedStdout();
	for (size_t i = 0; i < numEmployees; i++) {
		EXPECT_NE(output.find(allSurnames[i]), std::string::npos);
		EXPECT_NE(output.find(std::to_string(children[i])), std::string::npos);
	}
}

TEST(EmployeesTest, SortMyArrayTest) {
	size_t numEmployees = 4;
	Employees employees(numEmployees);
	employees.arr[0].surname = "Smith";
	employees.arr[1].surname = "Johnson";
	employees.arr[2].surname = "Williams";
	employees.arr[3].surname = "Brown";
	employees.arr[0].children = 3;
	employees.arr[1].children = 1;
	employees.arr[2].children = 4;
	employees.arr[3].children = 2;
	employees.sortMyArray(numEmployees);
	for (size_t i = 1; i < numEmployees; i++) {
		EXPECT_LE(employees.arr[i - 1].surname, employees.arr[i].surname);
	}
}


TEST(EmployeesTest, PrintInFoutTest) {
	const std::string testFileName = "src/File/test_employees.txt";
	std::ofstream testFile(testFileName);

	size_t numEmployees = 4;
	Employees employees(numEmployees);
	employees.arr[0].surname = "Smith";
	employees.arr[1].surname = "Johnson";
	employees.arr[2].surname = "Williams";
	employees.arr[3].surname = "Brown";
	employees.arr[0].children = 3;
	employees.arr[1].children = 1;
	employees.arr[2].children = 4;
	employees.arr[3].children = 2;
	employees.printInFout(testFile, numEmployees);
	testFile.close(); 
	std::ifstream inputFile(testFileName);
	std::string line;
	size_t lineCount = 0;
	while (std::getline(inputFile, line)) {
		EXPECT_EQ(line, employees.arr[lineCount].surname + " " + std::to_string(employees.arr[lineCount].children));
		lineCount++;
	}
	inputFile.close();
	std::remove(testFileName.c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}