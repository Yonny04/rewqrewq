/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Senka Kuboki
 * Date: 02/15/2024
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Destructor
Queue::~Queue() {
   delete [] elements;
}

// Description: Copy Constructor
Queue::Queue(const Queue& otherQueue) {
    // Copy otherQueue's properties
    capacity = otherQueue.capacity;
    elementCount = otherQueue.elementCount;
    frontindex = otherQueue.frontindex;
    backindex = otherQueue.backindex;

    // Allocate new array and copy elements
    elements = new int[capacity];
    for (unsigned int i = 0; i < capacity; ++i) {
        elements[i] = otherQueue.elements[i];
    }
}

 //assignment overload operator
Queue& Queue::operator=(const Queue& otherQueue) {
    if (this == &otherQueue) // Self-assignment check
        return *this;

    // Copy elements from otherQueue to this queue
    delete[] elements; // Delete current elements

    // Copy otherQueue's properties
    capacity = otherQueue.capacity;
    elementCount = otherQueue.elementCount;
    frontindex = otherQueue.frontindex;
    backindex = otherQueue.backindex;

    // Allocate new array and copy elements
    elements = new int[capacity];
    for (unsigned int i = 0; i < capacity; ++i) {
        elements[i] = otherQueue.elements[i];
    }

    return *this;
}

// Description: Constructor
Queue::Queue() {
   elements = new int[INITIAL_CAPACITY]; //create a new array "element" with initial capacity 6.
}

// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
//    elementCount++;
//    elements[backindex] = newElement;
//    backindex = (backindex + 1) % capacity;
   if (elementCount == capacity) {
      int newCapacity = capacity * 2; //the old capacity
      int *newElements = new int[newCapacity]; //create new bigger array with new capacity
      for (unsigned int i = 0; i < capacity; ++i) { //copy elements from old array to new bigger array
         newElements[i] = elements[frontindex]; //insert old front element to new index 0
         frontindex = (frontindex + 1) % capacity; //increment the frontindex to be the next one in queue
      }
      frontindex = 0; //new front index is back to 0
      backindex = capacity; //update the new backindex
      capacity = newCapacity; //update the capacity
      delete[] elements; //delete old elements
      elements = newElements; //update new elements
   }
   elements[backindex] = newElement; //insert new element
   backindex = (backindex + 1) % capacity; //update backindex
   elementCount++; //increment elementcount

    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
//    elementCount--;
//    frontindex = (frontindex + 1) % capacity;
      frontindex = (frontindex + 1) % capacity;
      elementCount--;
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    return elements[frontindex];
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}