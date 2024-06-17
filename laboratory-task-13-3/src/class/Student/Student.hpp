#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>

class Student
{
private:
    const std::string name;// имя
    size_t course;// курс
    size_t group;// группа
    const size_t recordBookNumber;// номер зачётной книжки
public:
    // Конструкторы
    Student();// Конструктор по умолчанию
    Student(const std::string & = "", size_t = 0, size_t = 0, size_t = 0);// Конструктор со значениями
    Student(const Student&);
    // Деструктор
    ~Student();

    //Геттеры
    const std::string& getName() const;
    size_t getCourse() const;
    size_t getGroup() const;
    size_t getRecordBookNumber() const;

    //Сетторы
    void setCourse(size_t);
    void setGroup(size_t);

    // Дефолтный оператор присваивания
    Student operator=(const Student&);

    // Oператор равно
    bool operator==(const Student&);

    //Метод вывода
    void print(std::ostream&);

    //Дружественный оператор вывода
    friend std::ostream& operator<<(std::ostream&, Student&);
};

#endif // STUDENT_HPP
