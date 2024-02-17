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
    
    if(!isEmpty() && top -> next != nullptr){
        while(current -> next != nullptr){
            current = current -> next;
    }   
        while(current2 -> next != nullptr){
            current2 = current2 -> next;
        }
        delete current;
        current = nullptr;
        current2 -> next = nullptr;
    }  
}