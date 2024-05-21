#include "../Queue/Queue.hpp"
#include "../Student/Student.hpp"
int main()
{
	try
	{
		TQueue <int> firstInt;
	firstInt.pushBack(1);
	firstInt.pushBack(2);
	firstInt.pushBack(3);
	firstInt.print(std::cout);
	TQueue <int> secondInt(firstInt);
	secondInt.print(std::cout);
	secondInt.erase(3);
	firstInt = secondInt;
	firstInt.print(std::cout);

	std::cout << "Please enter element!\n";
	char* a = new char[5];
	std::cin.getline(a, 255);
	char* b = new char[5];
	std::cin.getline(b, 255);
	char* c = new char[5];
	std::cin.getline(c, 255);
	TQueue <char*> firstChar;
	firstChar.pushBack(a);
	firstChar.pushBack(b);
	firstChar.pushBack(c);
	firstChar.print(std::cout);
	TQueue <char*> secondChar(firstChar);
	secondChar.print(std::cout);
	secondChar.erase(c);
	firstChar = secondChar;
	firstChar.print(std::cout);


	Student student1("Maksim", 7777777,1,7121);
	Student student2("Alexcandr", 10101010,4,791);
	Student student3("Ilia",78964745, 2,7111);
	TQueue <Student> kripta;
	kripta.pushBack(student1);
	kripta.pushBack(student2);
	kripta.pushBack(student3);
	kripta.print(std::cout);
	TQueue <Student> kriptaSecond(kripta);
	kriptaSecond.print(std::cout);
	kriptaSecond.erase(student3);
	kripta=kriptaSecond;
	kripta.print(std::cout);
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
