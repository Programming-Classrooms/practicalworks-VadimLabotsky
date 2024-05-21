#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include <string>
#include <list>
template <typename T>
class TQueue
{
private:
	std::list<T> elements;
public:
	TQueue();
	TQueue(const TQueue&);
	~TQueue();
	TQueue<T>& operator=(const TQueue<T>&);
	auto operator[](int);
	void pushBack(const T&);
	void erase(const T&);
	void print(std::ostream&) const;
	auto get(size_t);
	int find(const T&) const;
};

#include "Queue.inl"

#endif // !QUEUE_HPP

