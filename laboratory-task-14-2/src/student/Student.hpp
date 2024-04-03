#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>

class Student 
{
protected:
    const std::string name;// имя
    const size_t id;// id
    size_t course;// курс
    size_t group;// группа
    const size_t recordBookNumber;// номер зачётной книжки
    static size_t count;// счётчик для id
private:
    Student();// Конструктор по умолчанию
public:
    // Конструкторы
    Student(const std::string& = "",  size_t = 0, size_t = 0, size_t = 0);// Конструктор со значениями
    Student(const Student&);
    // Деструктор
    ~Student();

    //Геттеры
    size_t getId() const;
    const std::string& getName() const;
    size_t getCourse() const;
    size_t getGroup() const;
    size_t getRecordBookNumber() const;

    //Сетторы
    void setCourse(size_t);
    void setGroup(size_t);

    //Дружественный оператор вывода
    friend std::ostream& operator<<(std::ostream&, const Student&);
};

#endif // STUDENT_HPP
