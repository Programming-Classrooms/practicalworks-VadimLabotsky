#include "../class/Professor/Professor.hpp"
#include "../class/Student/Student.hpp"
#include "../class/Person/Person.hpp"
int main()
{
	const size_t MAX_SIZE = 100;
	Person* peoples[MAX_SIZE];
	size_t count = 0;
	size_t choice = 0;
	do
	{
		std::cout << "1. Enter a student\n";
		std::cout << "2. Enter teacher\n";
		std::cout << "3. Print a list of students\n";
		std::cout << "4. Display a list of teachers\n";
		std::cout << "5. Finish work\n";
		std::cout << "Select action: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			char fullName[100];
			size_t group = 0, course = 0;
			std::cout << "Enter the student's last name, first name and patronymic!\n";
			std::cin.ignore();
			std::cin.getline(fullName, 100);
			std::cout << "Enter course and group!\n ";
			std::cin >> course >> group;
			peoples[count] = new Student(fullName, course, group);
			++count;
			break;
		}
		case 2:
		{
			char fullName[100], department[100];
			std::cout << "Enter the last name, first name and patronymic of the teacher!\n";
			std::cin.ignore();
			std::cin.getline(fullName, 100);
			std::cout << "Enter the name of the department!\n";
			std::cin.getline(department, 100);
			peoples[count] = new Professor(fullName, department);
			++count;
			break;
		}
		case 3:
		{
			for (size_t i = 0; i < count; i++)
			{
				if (dynamic_cast <Student*> (peoples[i]))
				{
					peoples[i]->print(std::cout);
				}
			}
			break;
		}
		case 4:
		{
			for (size_t i = 0; i < count; i++)
			{
				if (dynamic_cast <Professor*> (peoples[i]))
				{
					peoples[i]->print(std::cout);
				}
			}
			break;
		}

		case 5:
		{
			break;
		}
		default:
		{
			std::cout << "Invalid choice. Try again.\n";
		}
		}

	} while (choice != 5);

	return 0;
}
