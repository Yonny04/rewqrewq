/*
 * Stack.cpp
 *
 * Description: Stack, SHSL list, where head of list is at bottom of list.
 *
 * Author: Senka Kuboki
 * Date: 02/15/2024
 */


#include <iostream>
#include "Stack.h"

//Default Contructor
Stack::Stack() {

}

//Copy constructor
Stack::Stack(const Stack& rhs) {
   top = rhs.top;
}

//Destructor
Stack::~Stack() {
   while (isEmpty()) {
      pop();
   }
}

bool Stack::isEmpty() {
   if (top == nullptr) {
      return true;
   }
   else {
      return false;
   }
}

bool Stack::push(int i) {
   StackNode *point = new StackNode(); //create new node and point
   point->data = i; //assign value i to the new node
   point->next = nullptr; //make sure new node is at top
   if (isEmpty()) { //if the stack is empty,
      top = point; //make the top new node
      return true;
   }
   else { //if stack is not empty,
      StackNode *point2 = top; //create pointer pointing to top(head)
      while (point2->next != nullptr) {
         point2 = point2->next; //keep moving through stack until pointing to the top
      }
      point2->next = point;
      point->next = nullptr;
      return true;
   }
   return false;
}

int Stack::pop() {
   int j = -1; //make an int to store to-pop data
   StackNode *point = top; //point to the top(head)
   if (isEmpty()) { //if the stack is empty
      return 0;
   }
   else if (top->next == nullptr) { //case for when the head is top
      j = top->data; //store top data in j
      top = nullptr; //only applies for when head is top so we don't lose track of top
   }
   else { // if top is not at head
      while (point->next != nullptr) { //make sure pointing at top
      point = point->next;
      }
      StackNode *point2 = top; //new pointer pointing at top
      while (point2->next != point) {
         point2 = point2->next; //keep moving through stack until pointing at one before top
      }
      j = point->data; //store the data in top to j
      delete point; //get rid of the node
      point = nullptr;
      point2->next = nullptr; //point new top to nullptr
   }

   return j;
}

int Stack::peek() {
   int k = -1; //create int to store the top data
   StackNode *point = top; //point to the top(head)
   if (isEmpty()) { //if empty
      abort();
   }
   else { //otherwise
      while (point->next != nullptr) {
         point = point->next;//make sure pointing at top
      }
      k = point->data; //assign the contents of the top node to an int
      return k;
   }
}