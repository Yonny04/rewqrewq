/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Yoonsang You
 * Date: Feb 12, 2024
 */
 
class Stack {

    private:
        
        // Description:  Nodes for a singly-linked list - Do not modify!
        class StackNode {
            public:
                int data;
                StackNode * next;
        };

        StackNode* top;
        

    public:

        Stack();

        bool isEmpty();

        int peek();

        void pop();

        void popAll();

        int push(int number);   

};