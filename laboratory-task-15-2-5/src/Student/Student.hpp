#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <fstream>
class Student 
{
private:
    std::string name;
    size_t course;
    size_t group;
    size_t recordBookNumber;
public:
    Student();
    Student(std::string = "",  size_t = 0, size_t = 0, size_t = 0);
    Student(const Student&);
    ~Student();

    size_t getId() const;
    std::string getName() const;
    size_t getCourse() const;
    size_t getGroup() const;
    size_t getRecordBookNumber() const;

    void setCourse(size_t);
    void setGroup(size_t);

    friend std::istream& operator>>(std::istream&, Student&);
    friend std::ostream& operator<<(std::ostream&, const Student&);
};

#endif // STUDENT_H
