#include "List.h"
#include <exception>
#include <functional>

#pragma once
template <typename T>
class HashTable
{
public:

	HashTable<T>();
	HashTable<T>(int capacity, std::function<unsigned long(T)> keySelector);
	~HashTable<T>();

	/// <summary>
	/// Adds item to hash table
	/// </summary>
	void Add(T value);

	/// <summary>
	/// Removes item from hash table and returns it
	/// </summary>
	T Remove(unsigned long key);

	/// <summary>
	/// Returns item for hash key
	/// </summary>
	T Get(unsigned long key);

	/// <summary>
	/// O(1) Checks hash table for existing item
	/// </summary>
	bool Contains(T value);

	/// <summary>
	/// O(1) Checks hash table for existing key
	/// </summary>
	bool ContainsKey(unsigned long key);

	/// <summary>
	/// Returns the count of items in the hash table
	/// </summary>
	int Count() { return _itemTotal; }

	/// <summary>
	/// Returns complete list of items in the hash table
	/// </summary>
	List<T> GetItems();

protected:

	/// <summary>
	/// Supplies primary hash function for the the unsigned long hash code key
	/// </summary>
	int GetIndex(unsigned long hashCodeKey);

private:

	List<T>** _table;
	int _capacity;
	int _itemTotal;
	
	std::function<unsigned long(T)> _keySelector;
};

