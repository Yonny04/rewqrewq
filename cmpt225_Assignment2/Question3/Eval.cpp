/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Yoonsang You
 * Date: Feb 16, 2024
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;

int perform(int i, int j, TokenType typ) { //what the perform function does in each case
   if (typ == pltok) {
      return i+j;
   }
   else if (typ == mitok) {
      return i-j;
   }
   else if (typ == asttok) {
      return i*j;
   }
   else if (typ == slashtok) {
      return i/j;
   }
   else {
      return -1;
   }
   return -1;
}


int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token


    t = S.getnext();

     while (t.tt != eof || !opstack.isEmpty()) {    //if it is empty
        if (t.tt == integer) {
           numstack.push(t); 
           t = S.getnext(); 
        }
        else if (t.tt == lptok) {   //left parenthesis
           opstack.push(t); 
           t = S.getnext(); 
        }
        else if (t.tt == rptok) {
           if (opstack.peek().tt == lptok) {  //right parenthesis
              opstack.pop();
              t = S.getnext(); 
           }
           else {
              Token result1; 
              result1.tt = integer; 
              result1.val = perform(numstack.pop().val, numstack.pop().val, opstack.pop().tt); //popping the two numbers and operators
              
              numstack.push(result1); //pushing as tokens
           }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof) {       //+ or -  or EOF
           if (!opstack.isEmpty()) {  
              if (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok) {  //implementing peeking and comparing
              
                 Token result2; 
                 result2.tt = integer; 
                 result2.val = perform(numstack.pop().val, numstack.pop().val, opstack.pop().tt);
                
                 numstack.push(result2); 
              }
              else {
                 opstack.push(t); //push T to the operator stack
                 t = S.getnext(); 
              }
           }
           else {
              opstack.push(t); //push T to the operator stack
              t = S.getnext(); 
           }
        }
        else if (t.tt == asttok || t.tt == slashtok) { //for * and /
           if (!opstack.isEmpty()) { 
              if (opstack.peek().tt == asttok || opstack.peek().tt == slashtok) { 
                 Token result3; 
                 result3.tt = integer; 
                 result3.val = perform(numstack.pop().val, numstack.pop().val, opstack.pop().tt);
                 
                 numstack.push(result3); //push the result to the number stack
              }
              else {
                 opstack.push(t); //push T to the operator stack
                 t = S.getnext(); 
              }
           }
           else {
              opstack.push(t); //push T to the operator stack
              t = S.getnext();
           }
        }
     } 

    int resultfinal; //printing all of what was calculated
    resultfinal = numstack.pop().val;
    cout << resultfinal << endl;
    //End pretty printer demo.
    return 0;
}