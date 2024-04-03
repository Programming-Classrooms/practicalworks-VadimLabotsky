#ifndef STUDENTAFTERFIRSTSESSION_HPP
#define STUDENTAFTERFIRSTSESSION_HPP
#include "src/class/Student/Student.hpp"

class StudentAfterFirstSession: public Student
{
protected:
	size_t grades[4];// Масисв из 4 оценок за 1 семестр
private:
	StudentAfterFirstSession();//Конструктор по умолчанию
public:
	//Конструкторы
	StudentAfterFirstSession(const std::string & = "", size_t = 0, size_t = 0, size_t = 0, const size_t[] = 0);
	StudentAfterFirstSession(const StudentAfterFirstSession&);
	//Деструктор
	~StudentAfterFirstSession();
	//Геттр
	const size_t* getGrades() const;
	//Сеттор
	void setGrades(const size_t[]);
	//Метод высчитывания среднего балла за 1 семестр
	double calculateAverageGrade() const;

	//Дружественный оператор вывода
	friend std::ostream& operator<<(std::ostream&, const StudentAfterFirstSession&);
};
#endif//STUDENTAFTERFIRSTSECCION_HPP
