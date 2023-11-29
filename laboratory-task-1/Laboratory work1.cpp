#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main()
 {

    double result{}, p{}, s{}, x{};
    const double E = 2.71828182846;
    int64_t k,n;
    

    std::cout << "Please, enter x \n ";
    std::cin >> x;
    std::cout << "Please, enter k \n ";
    std::cin >> k;
    result = (exp (x) - exp(-x) )/ 2;
    p = x;
    s = 0;
    n = 1;
    if (k > 1)
    {
        while (fabs(p) > pow(10, -k))
        {
            s += p;
            p = (p * x * x) / (2 * n * (2 * n + 1));
            ++n;
        }
        std::cout << result <<"  =  " << s;
    }
    else
    {
        std::cout << "Please, enter k > 1";
    }
    
    return 0;
}