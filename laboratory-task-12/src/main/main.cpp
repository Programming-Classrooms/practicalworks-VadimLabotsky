#include "../String/String.hpp"

int main()
{
	try
	{
		String s;
		std::string time;
		std::cout << "Please enter string!\n";
		std::cin >> time;
		String str(time);
		std::cout << str;
		char* c = new char[2];
		c[0] = 'n';
		c[1] = '\0';
		String str1("abcdef");
		String str2;
		str2 = str1 + str;
		std::cout  << str2;
		String str3;
		str3 = str1 +  c;
		std::cout << str;
		str1 += str;
		std::cout << str1;
		str += c;
		std::cout << str;
		if (str1 == str2) {
			std::cout << "True" << '\n';

		}
		else {
			std::cout << "False" << '\n';
		}
		if (str1 != str2) {
		
			std::cout << "False" << '\n';
		}
		else {
			std::cout << "True" << '\n';
		}
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << ex.what();
	}
	return 0;
}
