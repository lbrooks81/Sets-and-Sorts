/*
 * Name: [Logan Brooks]
 * South Hills Username: [lbrooks81]
 */

#include <iostream>
#include "mySet.h"
#include <time.h>

#ifdef USE_EXPORT_KEYWORD
export
#endif

using namespace mySet;

void testSet();

int main()
{
    testSet();
}

// / Inserts a random integer value from 0 to 100 into the set based on the number of elements the user specifies
void populateSet(MySet<int>* set, int numElements)
{
    for(int i = 0; i < numElements; i++)
    {
        if(set->insert(rand() % 100) == false)
        {
            i--;
        }
    }
}

void testSet()
{
    // Initialize Set
    MySet<int>* mySet = new MySet<int>();


    // Selection Sort
    std::cout << "New set ordered with Selection Sort:" << std::endl;
    populateSet(mySet, 10);
    mySet->selectionSort();
    std::cout << mySet->toString() << std::endl << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();


    // Bubble Sort
    std::cout << "New set ordered with Bubble Sort:" << std::endl;
    populateSet(mySet, 10);
    mySet->bubbleSort(false);
    std::cout << mySet->toString() << std::endl << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();


    // Cocktail Sort
    std::cout << "New set ordered with Bidirectional Bubble Sort:" << std::endl;
    populateSet(mySet, 10);
    mySet->bubbleSort(true);
    std::cout << mySet->toString() << std::endl << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();


    // Insertion Sort
    std::cout << "New set ordered with Insertion Sort:" << std::endl;
    populateSet(mySet, 10);
    mySet->insertionSort(false);
    std::cout << mySet->toString() << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();


    // Insertion Sort Verbose
    std::cout << "New set ordered with Insertion Sort Verbose:" << std::endl;
    populateSet(mySet, 10);
    mySet->insertionSort(true);
    std::cout << mySet->toString() << std::endl << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Median Element: " << mySet->median() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();

    // OddEven Sort
    std::cout << "New set ordered with Odd Even:" << std::endl;
    populateSet(mySet, 10);
    mySet->oddEven();
    std::cout << mySet->toString() << std::endl << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();

    // Insert At
    populateSet(mySet, 10);
    std::cout << "New unordered set: " << std::endl;
    std::cout << mySet->toString() << std::endl;
    std::cout << "Inserting element at index 5..." << std::endl;

    mySet->insertAt(5, 10);
    std::cout << mySet->toString() << std::endl << std::endl;

    // Remove At
    std::cout << "Removing element at index 5..." << std::endl;
    mySet->removeAt(5);

    std::cout << "Set after removal:" << std::endl;
    std::cout << mySet->toString() << std::endl << std::endl;

    // Shrink
    int initialCapacity = mySet->capacity;
    int initialSize = mySet->getSize();

    std::cout << "Removing elements to shrink capacity..." << std::endl;
    std::cout << "Initial Capacity: " << initialCapacity
    << ". Initial Size: " << initialSize << std::endl;

    for(int i = initialSize - 1; i >= initialCapacity / 4 - 1; i--)
    {
        mySet->removeAt(i);
    }

    std::cout << "Set after removal:" << std::endl;
    std::cout << mySet->toString() << std::endl;
    std::cout << "Capacity after removal: " << mySet->capacity
    << ". Size after removal: " << mySet->getSize() << std::endl;
}

