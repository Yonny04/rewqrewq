/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Senka Kuboki
 * Date: 02/15/2024
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;

int perform(int i, int j, TokenType type) { //what the perform function does in each case
   if (type == pltok) {
      return i+j;
   }
   else if (type == mitok) {
      return i-j;
   }
   else if (type == asttok) {
      return i*j;
   }
   else if (type == slashtok) {
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

     while (t.tt != eof || !opstack.isEmpty()) { //while T is not EOF or the operator stack is non empty
        if (t.tt == integer) { //if T is a number:
           numstack.push(t); //push T to the number stack
           t = S.getnext(); //get the next Token
        }
        else if (t.tt == lptok) { //else if T is a left parenthesis
           opstack.push(t); //push T to the operator stack
           t = S.getnext(); //get the next token
        }
        else if (t.tt == rptok) { //else if T is a right parenthesis
           if (opstack.peek().tt == lptok) { //if the top of the operator stack is a left parenthesis
              opstack.pop(); //pop it from the operator stack
              t = S.getnext(); //get the next token
           }
           else {
              Token result1; //create token for result to push at end
              result1.tt = integer; //token type is integer
              result1.val = perform(numstack.pop().val, numstack.pop().val, opstack.pop().tt);
              //pop the top two numbers and the top operator and perform the operation
              numstack.push(result1); //push the result to the number stack
           }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof) { //else if T is +, - or EOF
           if (!opstack.isEmpty()) {  //if the operator stack is nonempty
              if (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok) {
              //and the top is one of +, -, *, /
                 Token result2; //create token for result to push at end
                 result2.tt = integer; //token type is integer
                 result2.val = perform(numstack.pop().val, numstack.pop().val, opstack.pop().tt);
                 // pop the top two numbers and the top operator and perform the operation
                 numstack.push(result2); //push the result to the number stack
              }
              else {
                 opstack.push(t); //push T to the operator stack
                 t = S.getnext(); //get the next token
              }
           }
           else {
              opstack.push(t); //push T to the operator stack
              t = S.getnext(); //get the next token
           }
        }
        else if (t.tt == asttok || t.tt == slashtok) { //else if T is * or /
           if (!opstack.isEmpty()) { //if the operator stack is nonempty
              if (opstack.peek().tt == asttok || opstack.peek().tt == slashtok) { //and the top is one of *, /:
                 Token result3; //create token for result to push at end
                 result3.tt = integer; //token type is integer
                 result3.val = perform(numstack.pop().val, numstack.pop().val, opstack.pop().tt);
                 // pop the top two numbers and the top operator and perform the operation
                 numstack.push(result3); //push the result to the number stack
              }
              else {
                 opstack.push(t); //push T to the operator stack
                 t = S.getnext(); //get the next token
              }
           }
           else {
              opstack.push(t); //push T to the operator stack
              t = S.getnext(); //get the next token
           }
        }
     } //end of while loop. equation is done

    int resultfinal; //print the final answer to the equation.
    resultfinal = numstack.pop().val;
    cout << resultfinal << endl;
    // End pretty printer coding demo.

    return 0;
}