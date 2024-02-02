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
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

    
// Default constructor.
MyADT::MyADT() { 
}  

// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs){   



}  
    
// Destructor
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {

   //deletes all that is allocated at the pointer

   for (int i=0; i<getElementCount(); i++){
      delete[] elements[i];
   }
}  


// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {
   int sum; //variable to store the total amount of elements

   for (int i=0; i < getElementCount(); i++){
      sum =+ elementCount[i]; //iterating through all the arrays and adding to sum
   }
   return sum;
}


// Description: Inserts an element in the data collection MyADT.
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull, otherwise "false".
bool MyADT::insert(const Profile& newElement) {
   //see if the current element count is full or null
      //if true
         //I am going to push newElement into the pointer of that node
            //i will do a loop to keep on going until the space is occupied
    return false;
}  


// Description: Removes an element from the data collection MyADT. 
// Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
//                Returns "true" when the removal is successfull, otherwise "false".  
bool MyADT::remove(const Profile& toBeRemoved) {
    for (int i = 0; i < getElementCount(); i++) {
        // Compare the search key of the current element with the search key of toBeRemoved
        if (elements[i]->getSearchKey() == toBeRemoved.getSearchKey()) {
            if (*elements[i] == toBeRemoved){
               delete[] elements[i];
            }

            // filling the gap
            for (int j = i; j < getElementCount() - 1; j++) {
                elements[j] = elements[j + 1];
            }

            // Decrementing the element count
            elementCount[i]--;
            return true;  // Return true when removal is successful
        }
    }

    // If no match is found, return false
    return false;
}



// Description: Removes all elements from the data collection MyADT. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
void MyADT::removeAll() {
    
   //  for (int i; i < getElementCount(); i++){
   //    delete[] elementCount[i]; //delete all the old arrays 
   //    elementCount[i] = new Profile[MAX_ELEMENTS];
   //  }
    //deleting all dynamic memory and reset
    //use the delete function
}   

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
    
   
   for (int i=0; i < getElementCount(); i++){         //iterate through to match element to target
     
         if (*elements[i] == target){  //seeing if the two matches
            return elements[i];        //if found, return the pointer
         }
   }
   //otherwise return nullptr
   return nullptr;
}  


// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
void MyADT::print() {
  
    //each alphabet has a value
    //see what bigger and print

} 

//  End of implementation file
