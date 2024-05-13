#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <exception>
#include "../Student/Student.hpp"

void checkFile(std::ifstream& fin)
{
    if (!fin.good())
    {
        throw std::ios_base::failure("File does not exist.\n");
    }
    if (!fin)
    {
        throw std::ios_base::failure("File is not opened.\n");
    }
    if (fin.peek() == EOF)
    {
        throw std::ios_base::failure("File is empty.\n");
    }
}
void readInfo(std::vector<Student>& students)
{
    std::ifstream fin("src/files/Students.txt");
    checkFile(fin);
    Student student;
    while (fin >> student) {
        students.push_back(student);
    }
    fin.close();
}

void printInfo(std::ofstream& fout, std::vector <Student> students)
{
    for (const auto& student : students) {
        fout << student;
    }
}
int main()
{
    try
    {
       
        std::vector<Student> students;
        readInfo(students);
        std::sort(students.begin(), students.end());

        std::ofstream fioFile("src/files/Fio.txt");
        printInfo(fioFile, students);
        fioFile.close();

        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            if (a.getCourse() == b.getCourse()) {
                return a.getGroup() < b.getGroup();
            }
            return a.getCourse() < b.getCourse();
            });

        std::ofstream groupsFile("src/files/Groups.txt");
        printInfo(groupsFile, students);
        groupsFile.close();
    }
    catch (const std::ios_base::failure& ex)
    {
        std::cerr << ex.what();
    }
    return 0;
}

