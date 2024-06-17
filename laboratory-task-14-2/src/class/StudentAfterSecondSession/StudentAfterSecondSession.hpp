#ifndef STUDENTAFTERSECONDSESSEION_HPP
#define STUDENTAFTERSECONDSESSEION_HPP
#include "src/class/StudentAfterFirstSession/StudentAfterFirstSession.hpp"

class StudentAfterSecondSession: public StudentAfterFirstSession
{
private:
	size_t allGrades[5];// Массив из 5 оценок за 2 семестр
	StudentAfterSecondSession();//Конструктор по умолчанию
public:
	//Конструкторы
	StudentAfterSecondSession(const std::string & = "", size_t = 0, size_t = 0, size_t = 0, const size_t[] = 0, const size_t[] = 0);
	StudentAfterSecondSession(const StudentAfterSecondSession&);
	//Деструкторы
	~StudentAfterSecondSession();

	//Геттор
	const size_t* getSecondGrades() const;
	//Сетторы
    void setSecondGrades(const size_t[]);
	//Метод высчитывания среднего балла за весь курс
	double calculateAverageGrade() const;
	//Дружественный оператор вывода
	friend std::ostream& operator<<(std::ostream&, const StudentAfterSecondSession&);
};

#endif //STUDENTAFTERSECONSSESSEION_HPP
