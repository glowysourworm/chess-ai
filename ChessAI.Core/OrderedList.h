#include "List.h"
#include <functional>
#include <exception>

#pragma once
template <typename T>
class OrderedList
{

public:

    OrderedList();
    OrderedList(int capacity, std::function<int(T, T)> comparer);
    ~OrderedList();

    int Count();

    /// <summary>
    /// O(log n) - adds item to the list in order
    /// </summary>
    void Add(T item);

    /// <summary>
    /// O(log n) - checks for item in the list
    /// </summary>
    bool Contains(T item);

    /// <summary>
    /// O(log n) - removes item from the list
    /// </summary>
    void Remove(T item);

    /// <summary>
    /// O(1) - returns the item at the specified index
    /// </summary>
    T Get(int index);

protected:

    const int UnsuccessfulSearch = -1;

    /// <summary>
    /// Default comparer for two list items - returns "Equal"
    /// </summary>
    static int DefaultComparer(T item1, T item2) { return 0; }

private:

    /// <summary>
    /// Uses binary search to lookup index of item
    /// </summary>
    int GetInsertIndex(T item);

    /// <summary>
    /// Implements binary search - includes the insert index if the item is not found
    /// </summary>
    int OrderedList<T>::BinarySearch(T searchItem, int& insertIndex)

private:

    List<T>* _list;
    std::function<int(T, T)> _comparer;
};

