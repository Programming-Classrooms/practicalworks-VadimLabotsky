
#include <iostream>

using std:: cout;
using std::cin;
int main()
{
    int64_t number1, number2, number;
    number1 = 0;
    number2 = 1;
    cout << "Please, enter natural number.\n";
    cin >> number;
    while (number <= 0)
    {
        cout << "ERROR! Please, enter natural number!!! \n ";
        cin >> number;
    }
    while (number >= number1)
    {
        number1 = number1 + number2;
        number2 = number1 - number2;
        number = number - 1;
        cout << number1 << '\t';
    }
    return 0;
}
