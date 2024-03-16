/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: Feb. 2024
 */
 
#include "BST.h"
#include "WordPair.h"
#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;


// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver 
// - the one with which we will mark this assignment - 
// will not know about them since, in order to create it, we will have 
// used only the public method prototypes below.


/* Constructors and destructor */

    // Default constructor
    BST::BST() {}

    //Copy constructor
    BST::BST(const BST& aBST) {
    this->elementCount = aBST.elementCount;
    root = traverseCopyR(aBST.root);
}

    // Destructor 
    BST::~BST() {
    traverseR_Destroy(root);
}            
   
/* Getters and setters */

   // Description: Returns the number of elements currently stored in the binary search tree.   
   // Postcondition: This method does not change the binary search tree.
   // Time efficiency: O(1)
   unsigned int BST::getElementCount() const {     

     return this->elementCount;

   }
   

/* BST Operations */

   // Description: Inserts an element into the binary search tree.
   //              This is a wrapper method which calls the recursive insertR( ).
   // Precondition: "newElement" does not already exist in the binary search tree.
   // Exception: Throws the exception "UnableToInsertException" when newElement 
   //            cannot be inserted because the "new" operator failed. 
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the binary search tree.
   // Time efficiency: O(log2 n)   
   void BST::insert(WordPair & newElement) {
      BSTNode* newNode = new BSTNode(newElement);
         if (root == nullptr) {
             root = newNode;
             elementCount++;
         } else {
             if (!insertR(newNode, root)) {
                 // If insertR returns false, it means the element already exists
                 delete newNode; // Since we couldn't insert it, delete the allocated memory
                 throw ElementAlreadyExistsException();
             }
         }
     }

   
   // Description: Recursive insertion into a binary search tree.
   //              Returns true when "anElement" has been successfully inserted into the 
   //              binary search tree. Otherwise, returns false.
   // Description: Recursive insertion into a binary search tree.
   //              Returns true when "newBSTNode" has been successfully inserted into the
   //              binary search tree. Otherwise, returns false.
   bool BST::insertR(BSTNode * newBSTNode, BSTNode * current) {
      if (newBSTNode->element == current->element) {
              // Element already exists
              return false;
          } else if (newBSTNode->element < current->element) {
              if (current->left == nullptr) {
                  // Insert new node on the left
                  current->left = newBSTNode;
                  elementCount++;
                  return true;
              } else {
                  return insertR(newBSTNode, current->left);
              }
          } else { // newBSTNode->element > current->element
              if (current->right == nullptr) {
                  // Insert new node on the right
                  current->right = newBSTNode;
                  elementCount++;
                  return true;
              } else {
                  return insertR(newBSTNode, current->right);
              }
          }
      }

   
   // Description
   // Description: Retrieves "targetElement" from the binary search tree.
   //              This is a wrapper method which calls the recursive retrieveR( ).
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the binary search tree is em`pty.
   // Exception: Propagates the exception "ElementDoesNotExistException" 
   //            thrown from the retrieveR(...)
   //            if "targetElement" is not found in the binary search tree.
   // Postcondition: This method does not change the binary search tree.
   // Time efficiency: O(log2 n)
   WordPair& BST::retrieve(WordPair & targetElement) const {

     if (elementCount == 0)  
        throw EmptyDataCollectionException("Binary search tree is empty.");

     WordPair& translated = retrieveR(targetElement, root);

     return translated;
   }


   // Description: Recursive retrieval from a binary search tree.
   // Exception: Throws the exception "ElementDoesNotExistException" 
   //            if "targetElement" is not found in the binary search tree.
   // Postcondition: This method does not change the binary search tree.
   WordPair& BST::retrieveR(WordPair & targetElement, BSTNode * current) const {
      if (current == nullptr) {
              // Element not found in the binary search tree
              throw ElementDoesNotExistException("Element not found in the binary search tree.");
          }

          if (targetElement == current->element) {
              // Found the target element
              return current->element;
          } else if (targetElement < current->element) {
              // Search in the left subtree
              return retrieveR(targetElement, current->left);
          } else {
              // Search in the right subtree
              return retrieveR(targetElement, current->right);
          }
      }
         
   
   // Description: Traverses the binary search tree in order.
   //              This is a wrapper method which calls the recursive traverseInOrderR( ).
   //              The action to be done on each element during the traverse is the function "visit".
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the binary search tree is empty.
   // Postcondition: This method does not change the binary search tree.
   // Time efficiency: O(n)     
   void BST::traverseInOrder(void visit(WordPair &)) const {
    //  cout<<"test for Traverse"<<endl;
     if (elementCount == 0)  
       throw EmptyDataCollectionException("Binary search tree is empty.");

     traverseInOrderR(visit, root);
     
     return;
   }

   // Description: Recursive in order traversal of a binary search tree.   
   // Postcondition: This method does not change the binary search tree. 
   void BST::traverseInOrderR(void visit(WordPair &), BSTNode* current) const { 
   
	  if (current == nullptr) {      //if current node is empty
         return;
      }
      traverseInOrderR(visit,current->left);
      visit(current->element);
      traverseInOrderR(visit,current->right);
	  
   }