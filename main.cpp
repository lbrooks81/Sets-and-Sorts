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
        // std::cout << i << std::endl;
        // std::cout << "Size: " << set->getSize() << std::endl;
    }
}

void testSet()
{
    MySet<int>* mySet = new MySet<int>();

    std::cout << "New set ordered with Selection Sort:" << std::endl;
    populateSet(mySet, 50);
    mySet->selectionSort();
    std::cout << mySet->toString() << std::endl << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();

    std::cout << "New set ordered with Bubble Sort:" << std::endl;
    populateSet(mySet, 50);
    mySet->bubbleSort(false);
    std::cout << mySet->toString() << std::endl << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();

    // ! Size is 6 when running, 10 when debugging
    std::cout << "New set ordered with Bidirectional Bubble Sort:" << std::endl;
    populateSet(mySet, 10);
    mySet->bubbleSort(true);
    std::cout << mySet->toString() << std::endl << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Clearing Set..." << std::endl << std::endl;
    mySet->clear();

    std::cout << "New set ordered with Insertion Sort:" << std::endl;
    // ! Size is 18 when running, 30 when debugging
    populateSet(mySet, 30);
    std::cout << "Size: " << mySet->getSize() << std::endl;
    mySet->insertionSort();
    std::cout << mySet->toString() << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;


    // ! Size is only 43 when running, has value 268447333 in it
    mySet->clear();
    std::cout << "New set ordered with Insertion Sort Verbose:" << std::endl;
    populateSet(mySet, 50);
    mySet->insertionSortVerbose();
    std::cout << mySet->toString() << std::endl << std::endl;


    std::cout << "Removing element at index 0..." << std::endl;
    mySet->removeAt(0);

    std::cout << "Set after removal:" << std::endl;
    std::cout << mySet->toString() << std::endl;
    std::cout << "Size: " << mySet->getSize() << std::endl << std::endl;

    std::cout << "Median Element: " << mySet->median() << std::endl << std::endl;


    int initialCapacity = mySet->capacity;
    int initialSize = mySet->getSize();

    std::cout << "Removing Elements..." << std::endl;
    std::cout << "Initial Capacity: " << initialCapacity
    << ". Initial Size: " << initialSize << std::endl;

    for(int i = initialSize - 1; i + 1 >= initialCapacity / 4; i--)
    {
        mySet->removeAt(i);
    }

    std::cout << "Capacity after removal: " << mySet->capacity
    << ". Size after removal: " << mySet->getSize() << std::endl;
}

