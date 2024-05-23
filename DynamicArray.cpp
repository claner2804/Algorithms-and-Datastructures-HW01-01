//
// Created by clane on 23.05.2024.
//

#include "DynamicArray.h"
#include <iostream>



// Constructor for the DynamicArray class
// Initializes size to 0, capacity to 1, and allocates memory for an array of size 1
DynamicArray::DynamicArray() {
    size = 0;
    capacity = 1;
    arr = new int[capacity];
}



// Destructor for the DynamicArray class
// Deallocates the memory allocated for the array
DynamicArray::~DynamicArray() {
    delete[] arr;
}



// Method to add a new element to the dynamic array
// If the array is full (size == capacity), it doubles the capacity of the array
// Then, it adds the new element to the end of the array and increments the size
void DynamicArray::add(int value) {
    if (size == capacity) {
        resize(capacity * 2); // double the current capacity
    }
    arr[size++] = value;
}




// Method to print all elements in the dynamic array and its size
void DynamicArray::printDynamicArray() {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nSize: " << size << "\n";
}



// Overloaded array subscript operator
// If the index is greater than or equal to the capacity, it doubles the capacity until it's enough to accommodate the index
// If the index is greater than or equal to the size, it updates the size to be one more than the index
// Returns a reference to the element at the given index
int& DynamicArray::operator[](int index) {
    while (index >= capacity) {
        resize(capacity * 2); // double the current capacity
    }
    if (index >= size) {
        size = index + 1;
    }
    return arr[index];
}



// Method to resize the dynamic array
// Allocates a new array with the given capacity, copies the elements from the old array to the new one
// Deallocates the old array and updates the arr pointer to point to the new array
// Also updates the capacity to the new capacity
void DynamicArray::resize(int newCapacity) {
    int *newArr = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}