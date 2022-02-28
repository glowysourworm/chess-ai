#include <exception>

#pragma once
template <typename T>
class List
{
public:

	List<T>() { _count = 0; }
	List<T>(int capacity);
	List<T>(T* array, int arrayLength);
	~List<T>();

	void Add(T element);
	void Insert(int index, T element);
	T RemoveAt(int index);

	int Count();

	T Get(int index);

private:

	T* _list;
	int _capacity;
	int _tail;		// Current index of the list (inclusive)
};

