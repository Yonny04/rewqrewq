#include "Stack.h"
#include <iostream>


Stack::Stack(){
    top = nullptr;
}

bool Stack::isEmpty(){
    return top == nullptr;
}

int Stack::peek(){      //O(n)
StackNode* current = top;
    if(!isEmpty() && top -> next != nullptr){
        
        while(current -> next -> next != nullptr){
            current = current -> next;
        }
        return current -> data;
    }
    else if(isEmpty() && top -> next == nullptr){
        return current -> data;
    }
}

void Stack::pop(){  //O(n)

    if(!isEmpty() && top -> next != nullptr){
        StackNode* current = top;
        while(current -> next -> next != nullptr){
            current = current -> next;
    } 
        delete current-> next;
        current -> next = nullptr;
    }  
    else if(isEmpty() && top -> next == nullptr){
        delete top;
        top = nullptr;
    }
}

bool Stack::push(int element){
    StackNode* current = new StackNode();
    if(isEmpty()){
        top = current;
        current -> data = element;
        return true;
    }
    else if(!isEmpty()){
        while (current -> next != nullptr){
            current = current -> next;
        }
        current -> data = element;
        return true;
    }
    return false;
}