//
// Created by clane on 23.05.2024.
//

#ifndef HW01_DYNAMICARRAY_H
#define HW01_DYNAMICARRAY_H


class DynamicArray {

private:
    int *arr;       // Pointer to the dynamic array
    int size;       // Current number of elements in the array
    int capacity;   // Current capacity of the array

public:
    // Constructor for the DynamicArray class
    // Initializes size to 0, capacity to 1, and allocates memory for an array of size 1
    DynamicArray();

    // Destructor for the DynamicArray class
    // Deallocates the memory allocated for the array
    ~DynamicArray();

    // Method to add a new element to the dynamic array
    // If the array is full (size == capacity), it doubles the capacity of the array
    // Then, it adds the new element to the end of the array and increments the size
    void add(int value);

    // Method to print all elements in the dynamic array and its size
    void printDynamicArray();

    // Overloaded array subscript operator
    // If the index is greater than or equal to the capacity, it doubles the capacity until it's enough to accommodate the index
    // If the index is greater than or equal to the size, it updates the size to be one more than the index
    // Returns a reference to the element at the given index
    int& operator[](int index);

    // Method to resize the dynamic array
    // Allocates a new array with the given capacity, copies the elements from the old array to the new one
    // Deallocates the old array and updates the arr pointer to point to the new array
    // Also updates the capacity to the new capacity
    void resize(int newCapacity);
};


#endif //HW01_DYNAMICARRAY_H
