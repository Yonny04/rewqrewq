/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *                  - Its data structure (CDT) is not expandable. This signifies that 
 *                    when this data collection becomes full, you do not have to resize 
 *                    its data structure (not in this Assignment 1). 
 *
 * Author: AL and <Yoonsang You>
 * Last modified on: Feb.2 2024
 */

#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profi le class

using std::cout;
using std::endl;

// Default constructor.
MyADT::MyADT() {

    for (int i = 0; i < MAX_ALPHA; i++) {
          elementCount[i] = 0;        // sets a default count
          elements[i] = new Profile[MAX_ELEMENTS];
            for (int j = 0; j < MAX_ELEMENTS; j++) {
                 elements[i][j] = Profile();
            }
    }
} 

// Copy constructor
MyADT::MyADT(const MyADT& rhs){

    elementCount[MAX_ALPHA] = rhs.elementCount[MAX_ALPHA];  //copy
        for (int i = 0; i < MAX_ALPHA; i++) {
            elements[i] = new Profile[MAX_ELEMENTS];  
                for (int j = 0; j < rhs.elementCount[i]; j++) {
                    elements[i][j] = rhs.elements[i][j];  //copy
            }
        }

}
    
// Destructor
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   for (int i=0; i < MAX_ALPHA; i++){
      delete[] elements[i];  // deletes the element
   }
}  


// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {
   int sum; // variable to store the total amount of elements

   for (int i=0; i < MAX_ALPHA; i++){
      sum += elementCount[i]; // iterating through all the arrays and adding to sum
   }
   return sum;
}

// Description: Convert a char value to int
// Precondition: Input letter must be in lowercase
// Postcondition: returns the ASCII value of letter 
unsigned int MyADT::charToNum(Profile letter) {

   int c = (letter.getUserName().at(0));  // get the letter at index 0 from profile letter
   return (c - 'a');  // subtract it by the ASCII value of 'a' to return a int value
}


// Description: Inserts an element in the data collection MyADT.
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull, otherwise "false".
bool MyADT::insert(const Profile& newElement) {
   unsigned int index = charToNum(newElement);

   if (elementCount[index] >= MAX_ELEMENTS) {   // to check if the elementCount is greater than the Max_Element
      return false;    // if above condition is true, return false
   }
   for (unsigned int i = 0; i < elementCount[index]; ++i) {
           if (elements[index][i] == newElement) { // Checking if element already exists, therefore cannot insert
               return false;
           }
   }

   unsigned int insertIndex = 0;
   while (insertIndex < elementCount[index] && elements[index][insertIndex] < newElement) {  // edge case to insure insertIndex is less than elementCount AND elements is less than newElement
       insertIndex++;
   }

   for (unsigned int i = elementCount[index]; i > insertIndex; --i) {
       elements[index][i] = elements[index][i - 1];      // shifting elements in the array to the right
   }

   elements[index][insertIndex] = newElement;      // performs the insertion and increments the elementCount of the array
   elementCount[index]++;

   return true;
}  


// Description: Removes an element from the data collection MyADT. 
// Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
//                Returns "true" when the removal is successfull, otherwise "false".  

bool MyADT::remove(const Profile& toBeRemoved) {
    bool check = false; // returns value of true or false

       if (search(toBeRemoved) == nullptr) { // checks if toBeRemoved exists in data structure by calling the search method (below)
          return check; // if its a nullptr (already remove/gone), return false value bc its not work
       }

       unsigned int index = charToNum(toBeRemoved); // gets num of first char of toBeRemoved

       for (unsigned int i = 0; i < elementCount[index]; i++)  // increments till first letter of toBeRemoved is reached
       { 
           if (elements[index][i] == toBeRemoved) { // checks if the current element is equal to the toBeRemoved profile
             check = true;
          }

          if (check) { // if check is true
             elements[index][i] = elements[index][i+1]; // shift the elements to fill the gap left by the removed element
          }

       }

       elementCount[index]--; // decrement the count of elements at the calculated index
       return check;

}


// Description: Removes all elements from the data collection MyADT. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
void MyADT::removeAll() {
   for (int i=0; i < MAX_ALPHA; i++){
      elements[i] = nullptr;     //elements to null
      elementCount[i] = 0; // resets the count
   } 
}   

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
    for (int i = 0; i < MAX_ALPHA; i++) {
        for (int j = 0; j < elementCount[i]; j++) {
            if (elements[i][j] == target) {
                return &elements[i][j];  // Return the address of the found element
            }
        }
    }
    return nullptr;  // Return nullptr if not found
}



// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
void MyADT::print() {
  
    for(int i = 0; i < MAX_ALPHA; i++) // letters
	{
		for(int j = 0; j < elementCount[i]; j++) // all elements of each letter
		{
			cout << elements[i][j].getUserName() << ", " << elements[i][j].getName() << ", " << elements[i][j].getEmail() << elements[i][j].getBirthday() << endl; // all the components of friends book
		}
	}
} 

//  End of implementation file