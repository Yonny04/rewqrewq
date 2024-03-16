/*
 * BST.h
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

#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "WordPair.h"


class BST {
   
private:

   // You cannot change the following data members of this class.
   BSTNode * root = nullptr; 
   unsigned int elementCount = 0;        

   // Description: if the conditions are met, this function will delete the node
   void deleteNode(BSTNode* node);
   
   // Description: Recursive insertion into a binary search tree.
   //              Returns true when "anElement" has been successfully inserted into the 
   //              binary search tree. Otherwise, returns false.
   bool insertR(BSTNode * newBSTNode, BSTNode * current);

   // Description: Recursive retrieval from a binary search tree.
   // Exception: Throws the exception "ElementDoesNotExistException" 
   //            if "targetElement" is not found in the binary search tree.
   // Postcondition: This method does not change the binary search tree.
   WordPair & retrieveR(WordPair & targetElement, BSTNode * current) const;

   // Description: Recursive in order traversal of a binary search tree.   
   // Postcondition: This method does not change the binary search tree.
   void traverseInOrderR(void visit(WordPair &), BSTNode * current) const;

   void traverseR_Destroy(BSTNode* current){
      if(current == nullptr){
         return;
      }
      if(current->hasLeft()){
         traverseR_Destroy(current->left);
      }
      if(current->hasRight()){
         traverseR_Destroy(current->right);
      }
      delete current;
   }

   BSTNode* traverseCopyR(BSTNode* node) {
    if (node == nullptr) {
        return nullptr;
    }

    BSTNode* newNode = new BSTNode(node->element);
    newNode->left = traverseCopyR(node->left);
    newNode->right = traverseCopyR(node->right);
    return newNode;
}

   

public:

   // You cannot change the prototype of the public methods of this class.
   // Remember, if you add public methods to this class, our test driver 
   // - the one with which we will mark this assignment - 
   // will not know about them since, in order to create it, we will have 
   // used only the public method prototypes below.

   /* Constructors and destructor */
   BST();                        // Default constructor
   BST(const BST & aBST);        // Copy constructor 
   ~BST();                       // Destructor 
   
   /* Getters and setters */
   
   // Description: Returns the number of elements currently stored in the binary search tree.   
   // Postcondition: This method does not change the binary search tree.
   // Time efficiency: O(1)
   unsigned int getElementCount() const;
   
/*
   getRoot() and setRoot(...) <- are not acceptable getter/setter - can you see why?
   setElementCount(...) <- is not an acceptable setter - can you see why?
*/

   /* BST Operations */

   // Description: Inserts an element into the binary search tree.
   //              This is a wrapper method which calls the recursive insertR( ).
   // Precondition: "newElement" does not already exist in the binary search tree.
   // Exception: Throws the exception "UnableToInsertException" when newElement 
   //            cannot be inserted because the "new" operator failed. 
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the binary search tree.
   // Time efficiency: O(log2 n)   
   void insert(WordPair & newElement);   
   
   // Description: Retrieves "targetElement" from the binary search tree.
   //              This is a wrapper method which calls the recursive retrieveR( ).
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the binary search tree is empty.
   // Exception: Propagates the exception "ElementDoesNotExistException" 
   //            thrown from the retrieveR(...)
   //            if "targetElement" is not found in the binary search tree.
   // Postcondition: This method does not change the binary search tree.
   // Time efficiency: O(log2 n)
   WordPair & retrieve(WordPair & targetElement) const;
   
   // Description: Traverses the binary search tree in order.
   //              This is a wrapper method which calls the recursive traverseInOrderR( ).
   //              The action to be done on each element during the traverse is the function "visit".
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the binary search tree is empty.
   // Postcondition: This method does not change the binary search tree.
   // Time efficiency: O(n)   
   void traverseInOrder(void visit(WordPair &)) const;

}; // end BST
#endif
