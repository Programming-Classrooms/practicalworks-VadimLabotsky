#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <numeric>

int getRandomNumber(int leftBorder, int rightBorder) {
    int time = leftBorder + (std::rand() % (rightBorder - leftBorder +1));
    return time;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << '\t';
        }
        std::cout << '\n';
    }
}

int main() 
{
    try {
        int rows = 0, cols = 0, leftBorder = 0, rightBorder = 0;
        std::cout << "Enter the number of rows and columns in the matrix!\n";
        std::cin >> rows >> cols;
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Number of rows and columns must be positive.\n");
        }
        std::cout << "Enter the minimum and maximum values for the elements!\n";
        std::cin >> leftBorder >> rightBorder;
        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = getRandomNumber(leftBorder, rightBorder);
            }
        }
        std::cout << "Original matrix!\n";
        printMatrix(matrix);
        int maxElement = matrix[0][0];
        size_t maxRow = 0, maxCol = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (matrix[i][j] > maxElement) {
                    maxElement = matrix[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }
        matrix.erase(matrix.begin() + maxRow);
        for (auto& row : matrix) {
            row.erase(row.begin() + maxCol);
        }
        std::cout << "Matrix after removing row and column with the maximum element!\n";
        printMatrix(matrix);
        std::sort(matrix.begin(), matrix.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return std::accumulate(a.begin(), a.end(), 0) < std::accumulate(b.begin(), b.end(), 0);
        });
        std::cout << "Matrix after sorting rows by the sum of elements:" << std::endl;
        printMatrix(matrix);

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
