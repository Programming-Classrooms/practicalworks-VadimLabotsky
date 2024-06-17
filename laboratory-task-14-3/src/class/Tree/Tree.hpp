#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <string>
#include <cstdlib>
enum class Tipe
{
	Deciduous, 
	Coniferous,

};
class Tree
{
protected:
	std::string name;// Имя
	size_t age; //Возраст
	Tipe tipe;// Тип
public:
	//Конструкторы
	Tree() = default;
	Tree(std::string, size_t, Tipe);
	Tree(const Tree&);

	//Деструкторы
	virtual ~Tree();

	//Геттеры
	std::string getName() const;
	size_t getAge() const;
	Tipe getTypeTree() const;

	//Сеттеры
	void setName(std::string);
	void setAge(size_t);
	void setType(Tipe);

	//Виртуальный метод вывода информации
	virtual void print() const = 0;

};
#endif // TREE_H



