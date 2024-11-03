#include "mySet.h"

#include <iostream>
#include <stdexcept>


namespace mySet
{
    static const size_t npos = -1;

    template<Numeric T>
    int MySet<T>::getSize() const
    {
        return size;
    }

    template<Numeric T>
    double MySet<T>::median()
    {
        this->bubbleSort(false);

        if(size % 2 == 0)
        {
            double el1 = items[(size - 1) / 2];
            double el2 = items[size / 2];

            return (el1 + el2) / 2;
        }

        return items[(size - 1) / 2];
    }

    template<Numeric T>
    MySet<T>::MySet()
    {
        size = 0;
        capacity = 4;
        items = new T[capacity];
    }

    template<Numeric T>
    MySet<T>::MySet(int capacity) : capacity(capacity)
    {
        items = new T[capacity];
        size = capacity;
    }

    template<Numeric T>
    MySet<T>::~MySet()
    {
        delete[] items;
    }

    template<Numeric T>
    T & MySet<T>::operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("index is out of range");
        }
        return items[index];
    }

    template<Numeric T>
    void MySet<T>::grow()
    {
        T* tempArray = new T[capacity == 0 ? 1 : capacity * 2];

        for(int i = 0; i < capacity; i++)
        {
            tempArray[i] = items[i];
        }

        capacity = capacity == 0 ? 1 : capacity * 2;
        delete [] items;
        items = tempArray;
    }

    template<Numeric T>
    void MySet<T>::shrink()
    {
        T* tempArray = new T[capacity / 2];

        for(size_t i = 0; i < size; i++)
        {
            tempArray[i] = items[i];
        }

        delete [] items;
        capacity /= 2;
        items = tempArray;
    }

    template<Numeric T>
    size_t MySet<T>::find(T match)
    {
        if(sorted == false)
        {
            for(size_t i = 0; i < size - 1; i++)
            {
                if(items[i] == match) return i;
            }
        }

        if(sorted)
        {
            int left = 0;
            int right = capacity - 1;

            while(right >= left)
            {
                int mid = left + (right - left) / 2;

                if(items[mid] == match)
                {
                    return mid;
                }
                if(items[mid] > match)
                {
                    right = mid - 1;
                }
                else if(items[mid] < match)
                {
                    left = mid + 1;
                }
            }
        }
        return npos;

    }

    template<Numeric T>
    bool MySet<T>::insertAt(size_t index, T item)
    {
        if(index < 0 || index > capacity)
        {
            throw std::out_of_range("Index out of range.");
        }

        if(capacity == 0)
        {
            items = new T[1];
            capacity++;
        }

        // Checks for duplicates
        for(size_t i = 0; i < size; i++)
        {
            if(items[i] == item)
            {
                return false;
            }
        }

        // Value was not found in the set
        if(find(item) == npos)
        {
            if(size + 1 >= capacity)
            {
                grow();
            }

            for(size_t i = capacity - 1; i > index; i--)
            {
                items[i] = items[i - 1];
            }

            items[index] = item;
            size++;
        }
        return true;
    }

    template<Numeric T>
    bool MySet<T>::insert(const T item)
    {
        return insertAt(size, item);
    }

    template<Numeric T>
    void MySet<T>::remove(T item)
    {
        size_t index = find(item);
        if(index != npos)
        {
            removeAt(index);
        }
    }

    template<Numeric T>
    void MySet<T>::removeAt(const size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }

        for(size_t i = index; i < size - 1; ++i)
        {
            // std::cout << "Set before removal: " << this->toString() << std::endl;
            items[i] = items[i + 1];
            // std::cout << "Set after removal: " << this->toString() << std::endl << std::endl;
        }

        if(--size < capacity / 4)
        {
            shrink();
        }
    }

    template<Numeric T>
    void MySet<T>::clear()
    {
        size = 0;
        delete [] items;
        items = new T[capacity];
    }

    template<Numeric T>
    std::string MySet<T>::toString()
    {
        std::string s;

        for(int i = 0; i < size; i++)
        {
            s += std::to_string(items[i]) + ", ";
        }

        return s.substr(0, s.size() - 2);
    }

    template<Numeric T>
    void MySet<T>::swap(T* item1, T* item2)
    {
        T temp = *item1;
        *item1 = *item2;
        *item2 = temp;
    }

    template<Numeric T>
    void MySet<T>::bubbleSort(bool bidirectional)
    {
        bool sorted = false;
        size_t unsortedUntilIndex = size - 1;
        size_t startingIndex = 0;
        while(sorted == false)
        {
            sorted = true;

            for(size_t i = startingIndex; i < unsortedUntilIndex; i++)
            {
                if(items[i] > items[i + 1])
                {
                    swap(&items[i], &items[i + 1]);
                    sorted = false;
                }
            }
            unsortedUntilIndex--;

            if(bidirectional)
            {
                for(size_t j = unsortedUntilIndex; j > startingIndex; j--)
                {
                    if(items[j] < items[j - 1])
                    {
                        swap(&items[j], &items[j - 1]);
                        sorted = false;
                    }
                }
                startingIndex++;
            }
        }
    }

    template<Numeric T>
    void MySet<T>::insertionSort(bool verbose)
    {

        int copyCount = 0;
        int comparisonCount = 0;

        for(int i = 1; i < size; i++)
        {
            T temp = items[i];
            if(verbose) copyCount++;
            size_t j = i - 1;

            for(; j >= 0 && items[j] > temp; j--)
            {
                if(j == npos)
                {
                    break;
                }
                comparisonCount++;
                items[j + 1] = items[j];

            }
            if(j == npos)
            {
                items[0] = temp;
            }
            else
            {
                items[j + 1] = temp;
            }
        }

        if(verbose)
        {
            std::cout << "Set sorted. Total copies made: " << copyCount << ". Total comparisons made: " << comparisonCount
        << ". Size: " << size << std::endl;
        }
    }

    template<Numeric T>
    void MySet<T>::selectionSort()
    {
        for(int i = 0; i < size - 1; i++)
        {
            int minIndex = i;
            for(int j = i + 1; j < size; j++)
            {
                if (items[j] < items[minIndex])
                {
                    minIndex = j;
                }
            }

            if(minIndex != i)
            {
                swap(&items[i], &items[minIndex]);
            }

        }
    }
    
    template<Numeric T>
    void MySet<T>::oddEven()
    {
        bool sorted = false;

        while(sorted == false)
        {
            sorted = true;

            for(int i = 1; i < size - 1; i += 2)
            {
                if(items[i] > items[i + 1])
                {
                    swap(&items[i], &items[i + 1]);
                    sorted = false;
                }
            }

            for(int i = 0; i < size - 1; i += 2)
            {
                if(items[i] > items[i + 1])
                {
                    swap(&items[i], &items[i + 1]);
                    sorted = false;
                }
            }
        }
    }

    template class MySet<int>;
    template class MySet<float>;
    template class MySet<bool>;


}

