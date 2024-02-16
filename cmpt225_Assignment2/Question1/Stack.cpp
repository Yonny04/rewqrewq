#include "Stack.h"
#include <iostream>

bool Stack::isEmpty(){
    return top == nullptr;
}

int Stack::peek(){
    if(isEmpty()){
        return -1;
    }
    return top -> data;
}

void Stack::pop(){
    if(!isEmpty()){         //checking if empty then popping the first 
        StackNode* del = top;
        top = top -> next;
        delete del;
    }
}

void Stack::popAll(){
    while(!isEmpty()){  //iterate till all is empty
        pop();
    }
    return;
}

int Stack::push(int element){
    StackNode* newNode = new StackNode(element);
    if(isEmpty()){
        top = newNode;
    }else{
        StackNode* current = top;
        while(current -> next != nullptr){  //iterating through till empty
            current = current -> next;
        }
        current -> next = newNode; //once found initializing it as a newNode
    }
}
