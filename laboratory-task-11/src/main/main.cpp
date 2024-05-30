#include "../class/Employee/Employee.hpp"

bool compareSurnames(const std::string& a, const std::string& b)
{
    if (a == b) {
        return a.size() > b.size();
    }
    return a < b;
}


template <typename T>
void selectionSort(T*& arr, int size, bool (*compare)(const T&, const T&)) 
{
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (compare(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}
template <typename F>
void printArray(F* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

template <typename T>
void mySort(T*& arr, size_t size)
{
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[j] > arr[i]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
bool compareAscending(T a, T b)
{
    return a < b;
}

size_t getPoiterLast(std::ifstream& fin, struct Employee& employeeLast, struct Employee& employeeFirst)
{
    size_t pointerToLast = 0;

    fin.read(reinterpret_cast<char*>(&employeeFirst), sizeof(Employee));
    while (fin.read(reinterpret_cast<char*>(&employeeLast), sizeof(Employee))) {
        pointerToLast = fin.tellg();
    }

    return pointerToLast;
}

void swapLinesInBinareFile(std::ofstream& fout, size_t pointerToLast, struct Employee employeeLast, struct Employee employeeFirst)
{
    fout.seekp(0);
    fout.write(reinterpret_cast<char*>(&employeeLast), sizeof(employeeLast));
    fout.seekp(pointerToLast - sizeof(employeeLast));
    fout.write(reinterpret_cast<char*>(&employeeFirst), sizeof(employeeFirst));
}

void writeArrOfStructToBin(std::ofstream& fout, Employee* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Employee));
    }
}
int main()
{
    try {
        std::string line = "";
        std::string delims = "";
        std::string word = "";
        std::string result = "";
        size_t count = 0;
        size_t count1 = 0;

        std::ifstream fin("src/File/Numbers.txt");
        checkFile(fin);

        delims = getDelimeters(fin);
        while (std::getline(fin, line))
        {
            findNumber(line, delims, fin, result, count);
            
        }
        int32_t* allNumbers = new int32_t[count];
        arrayAllNumbers(result, count, allNumbers);
        int32_t* arr1 = new int32_t[count];
        for (size_t i = 0; i < count; i++)
        {
            arr1[i] = allNumbers[i];
        }
        printArray(arr1, count);
        paritySort(arr1, count);
        printArray(arr1, count);
        count1 = count;
        fin.close();

        std::ifstream file("src/File/Strings.txt");
        checkFile(file);
        delims = "";
        std::getline(file, delims);
        line = "";
        result = "";
        count = 0;
        findName(line, delims, file, result, count);
        std::string* allSurnames = new std::string[count];
        if (count == 0 )
        {
            throw std::invalid_argument("No valid surnames found in the file.\n");
        }
        arrayAllSurname(result, count, allSurnames);
        printArray(allSurnames, count);
        file.close();

        insertionSort(count, allSurnames);
        printArray(allSurnames, count);
        selectionSort(allSurnames, count, compareSurnames);
        printArray(allSurnames, count);
        enterNewElements(allNumbers, allSurnames, count, count1);

        Employees Kripta(count);
        Kripta.enterEmployees(allSurnames, allNumbers, count);
        Kripta.printEmployees(count);
        Kripta.sortMyArray(count);
        Kripta.printEmployees(count);

        std::ofstream fout("src/File/result.txt");
        Kripta.printInFout(fout, count);
        std::cout << '\n' << '\n';
        mySort(Kripta.arr, count);
    
        std::ofstream filebinaryFout("src/File/result.bin", std::ios::binary);
        writeArrOfStructToBin(filebinaryFout, Kripta.arr, count);
        Employee employeeLast, employeeFirst;
        std::ifstream filebinary("src/File/result.bin", std::ios::binary);
        size_t pointerToLast = getPoiterLast(filebinary, employeeLast, employeeFirst);
        filebinary.close();
        std::ofstream foutWrite("src/File/result.bin", std::ios::binary);
        swapLinesInBinareFile(foutWrite, pointerToLast, employeeLast, employeeFirst);
        foutWrite.close();
    }
    catch (const std::ios_base::failure& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}