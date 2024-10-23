#ifndef IT230_PROJECT1_MYSET_H
#define IT230_PROJECT1_MYSET_H
#include <string>

/*
#ifdef USE_EXPORT_KEYWORD
export
#endif
*/

namespace mySet
{

    // TODO implement is_arithmetic_v
    template<typename T>
    class MySet
    {
    private:
        T* items;
        int size;
        bool sorted;

        void swap(T* item1, T* item2);
        void grow();
        void shrink();
    public:
        int capacity;

        int getSize() const;
        double median();

        MySet();
        MySet(int capacity);
        ~MySet();

        T & operator[](size_t index);

        size_t find(T match);
        bool insert(T item);
        bool insertAt(size_t index, T item);
        void remove(T item);
        void removeAt(size_t index);
        void clear();

        std::string toString();

        void bubbleSort(bool bidrectional);
        void insertionSort(bool verbose);
        void selectionSort();
        void oddEven();

    };

}

/*#ifndef USE_EXPORT_KEYWORD
#include "mySet.cpp"
#endif
*/
#endif //IT230_PROJECT1_MYSET_H
