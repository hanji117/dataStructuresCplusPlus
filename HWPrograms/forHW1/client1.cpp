//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Edgar Cruz
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string.h>
#include <cstdlib>
#include "stack.h"

//Purpose of the program: This program reads a postfix expression from the 
//                        keyboard and evaluates the expression.
//Algorithm: if else statements inside a while loop.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression

  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result;  
 
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)

	  if(item >= '0' && item <= '9')
          {
	    int num = item - '0';
	    postfixstack.push(num);
	  }

	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if((item == '+') || (item == '-') || (item == '*'))
	  {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') 
		result = box2-box1;
	      if (item == '+') 
	        result = box2 + box1;
	      if (item == '*')
                result = box2 * box1;
	      
	      postfixstack.push(result);
	  }
	  else
             throw "invalid item in the expression!";
      } // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow)
      {
	  cerr << "expression too long."<< endl; 
          exit(1);
      }
      catch (stack::Underflow) // for too few operands
      {
          cerr << "Too few operands." << endl;
	  exit(1);
      }
      catch (char const* errorcode) // for invalid item
      {
          cerr << errorcode << endl; 
	  exit(1);
      }
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
 
    postfixstack.pop(result);
    cout << result << endl;
  
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  if (!postfixstack.isEmpty())
    cout << "Incomplete expression!" << endl;
 
  return 0;
}// end of the program
