#include "Stack.h"
#include <iostream>


Stack::Stack(){
    top = nullptr;
}

bool Stack::isEmpty(){
    return top == nullptr;
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


bool Stack::push(int element){
    StackNode* current = new StackNode();
    StackNode* current2 = top;
    current -> data = element;
    current -> next = nullptr; //new node is at the top

    if(isEmpty()){
        top = current;
        return true;
    }
    else{
        while (current2 -> next != nullptr){
            current2 = current2 -> next;
        }
        current2 -> next = current;
        current -> next = nullptr;
        return true;
    }
    return false;
}

void Stack::pop(){  //O(n)

    StackNode* current = top;
    StackNode* current2 = top;
    
    if (top->next == nullptr) { //case for when the head is top //store top   
      top = nullptr; //only applies for when head is top so we don't lose track of top
   }
   else { // if top is not at head
      while (current->next != nullptr) { //make sure pointing at top
      current = current->next;
      }

      while (current2->next != current) {
         current2 = current2->next; //keep moving through stack until pointing at one before top
      }
      delete current; //get rid of the node
      current = nullptr;
      current2->next = nullptr; //point new top to nullptr
   }
}