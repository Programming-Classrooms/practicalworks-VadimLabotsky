#include "../class/List/List.hpp"
#include "../class/Student/Student.hpp"
void printStudent(Student student) {
	student.print(std::cout);
}

int main()
{
	Student Vadim("Vadim", 1, 7121, 123456);
	Student Maksim("Maksim", 1, 7121, 123457);
	Student Vlad("Vlad", 1, 7121, 123455);
	Student Ivan("Ivan", 1, 7121, 123455);
	List <Student> list;
	list.insertFirst(Vadim);
	list.insertLast(Vlad);
	list.insertFirst(Maksim);
	list.print();
	list.deleteByInfo(Vadim);
	list.deleteFirst();
	list.deleteLast();
	list.print();
	if (list.searchByInfo(Vadim) == -1)
	{
		std::cout << "List is empty!\n";
	}
	else if (list.searchByInfo(Vadim) == 0)
	{
		std::cout << "This element not exists!\n";
	}
	else
	{
		std::cout << "This element exists!\n" << list.searchByInfo(Vadim) << '\n';
	}
	list.insertFirst(Vadim);
	list.insertLast(Vlad);
	list.insertFirst(Maksim);
	if (list.searchByInfo(Vadim) == -1)
	{
		std::cout << "List is empty!\n";
	}
	else if (list.searchByInfo(Vadim) == 0)
	{
		std::cout << "This element not exists!\n";
	}
	else
	{
		std::cout << "This element exists!\n" << list.searchByInfo(Vadim) << '\n';
	}
	if (list.searchByInfo(Ivan) == -1)
	{
		std::cout << "List is empty!\n";
	}
	else if (list.searchByInfo(Ivan) == 0)
	{
		std::cout << "This element not exists!\n";
	}
	else
	{
		std::cout << "This element exists!\n" << list.searchByInfo(Ivan) << '\n';

	}
	list.viewWithCallBackFunction(printStudent);
	return 0;

}


