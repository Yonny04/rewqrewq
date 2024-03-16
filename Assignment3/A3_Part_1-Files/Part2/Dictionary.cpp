/*
 * Dictionary.cpp
 * 
 * Description: Dictionary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements are not allowed.
 *              
 * Author: Senka Kuboki
 * Date of last modification: 03/15/2024
 */

#include "Dictionary.h"
#include <iostream>
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "Dictionary.h"

using std::cout;
using std::endl;
using std::nothrow;

/* Constructors and destructor */

   // Default constructor
   Dictionary::Dictionary() {
      keyValuePairs = new BST(); }

   // Destructor
   Dictionary::~Dictionary() {
       delete keyValuePairs;
       keyValuePairs = nullptr;
   }

/* Dictionary Operations */
   unsigned int Dictionary::getElementCount() const {
      return keyValuePairs->getElementCount();
   }

   void Dictionary::put(WordPair & newElement) {
       try {
           keyValuePairs->insert(newElement);
       }
       catch (UnableToInsertException & exception) {
           throw UnableToInsertException("in put().");
       }
       catch (ElementAlreadyExistsException & exception) {
          throw ElementAlreadyExistsException("in put().");
       }
   }

   WordPair & Dictionary::get(WordPair & targetElement) const {
       try {
           return keyValuePairs->retrieve(targetElement);
       }
       catch (EmptyDataCollectionException & exc) {
          throw EmptyDataCollectionException("in get().");
       }
       catch (ElementDoesNotExistException & exc) {
          throw ElementDoesNotExistException("in get().");
       }
   }

   void Dictionary::displayContent(void visit(WordPair &)) const {
       try {
           keyValuePairs->traverseInOrder(visit);
       }
       catch (EmptyDataCollectionException & exc) {
          throw EmptyDataCollectionException("in displayContent().");
       }
   }