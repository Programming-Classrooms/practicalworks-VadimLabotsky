#include "../fraction/Fraction.hpp"

int main()
{
  try
  {
    Fraction f1, f2;
    
    std::cin >> f1;
    std::cin >> f2;
    std::cout << "f1 = " << f1;
    std::cout <<"f2 = " << f2;
    std::cout<< "++f1 = " << ++f1;
    std::cout << "f1++ = "<< f1++;
    std::cout << "f1 = " << f1;
    std::cout  << "--f1 = "<< --f1;
    std::cout << "f1-- = " << f1--;
    std::cout << "f1 = " << f1 << '\n';


    std::cout << "f1 + f2 = " << f1 + f2;
    std::cout << "f1 = " << f1;
    std::cout << "f1 - f2 = "<< f1 - f2;
    std::cout << "f1 = " << f1;
    std::cout << "f1 * f2 = "<< f1 * f2;
    std::cout << "f1 = " << f1;
    std::cout<< "f1 / f2 = " << f1 / f2;
    std::cout << "f1 = " << f1;

    std::cout << "f1 + 1 = " << f1 + 1;
    std::cout << "f1 = " << f1;
    std::cout << "1 + f1 = " << 1 + f1;
    std::cout << "f1 = " << f1;
    std::cout << "f1 - 1 = " << f1 - 1;
    std::cout << "f1 = " << f1;
    std::cout << "1 - f1 = " << 1 - f1;
    std::cout << "f1 = " << f1;
    std::cout << "f1 * 1 = "<< f1 * 2;
    std::cout << "f1 = " << f1;
    std::cout << "1 * f1 = "  << 1 * f1;
    std::cout << "f1 = " << f1;
    std::cout << "f1 / 1 = "<< f1 / 1;
    std::cout << "f1 = " << f1;
    std::cout << "2 / f1 = " << 2 / f1;
    std::cout << "f1 = " << f1;

    
    f1 += f2;
    std::cout <<"f1 += f2\n"  << "f1 = "<< f1 << '\n';


    f1 -= f2;
    std::cout <<"f1 -= f2\n"  << "f1 = "<< f1 << '\n';


    f1 *= f2;
    std::cout <<"f1 *= f2\n"  << "f1 = "<< f1 << '\n';


    f1 /= f2;
    std::cout <<"f1 /= f2\n"  << "f1 = "<< f1 << '\n';

    Fraction f3(-1, 2);
    std::cout <<"f3 = - 1/2\n" << "f3^-1 = " <<!f3;
  }
  catch (const std::invalid_argument& ex)
  {
    std::cout << ex.what();
  }
  return 0;
}