//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile vstack.cpp to make sure there are no syntax errors.
  
//=========================================================
//HW#: HW1P2 vstack
//Your name: Edgar Cruz
//Complier:  g++
//File type: vstack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include "vstack.h"

//PURPOSE:  Constructor does not have to do anything since this is a vector stack.
stack::stack()
{
  //nothing to do
}
  
//PURPOSE: The destructor clears all cells 
stack::~stack()
{ 
  clearIt();
}
  
//PURPOSE: If the vector el is empty then the stack is empty and returns true else 
// false is returned.
bool stack::isEmpty()
{
 if (el.empty())
    return true;
  else 
    return false;
}
      
//PURPOSE: Checks to see if the stack is full, however, since this a vector stack there is 
//         no maximum size now. Thus it will return false since the stack can't be full.
bool stack::isFull()
{
  return false;
}
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to vector el with push_back.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{
  if (isFull()) 
    throw Overflow(); 
  else 
    el.push_back(elem);
}  
 
//PURPOSE: calls the vector's empty() function 
//         and if true, throws an exception (Underflow)
//         Otherwise, removes the top element from the vector stack and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{
 if(el.empty())
   throw Underflow();
 else 
 {
     elem = el[el.size()-1];//el.size()-1 == top
     el.pop_back();
 }

}
 
//PURPOSE: calls the vector's empty function
//         and if true, throws an exception (underflow)
//         Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
{
   if (el.empty()) 
    throw Underflow();
   else 
     elem = el[el.size()-1];
}
 
//PURPOSE: dislayAll calls the vector's empty function 
//         and if true, displays [ empty ].
//         Otherwise, diplays the elements vertically.
 void stack::displayAll()
 {  if (el.empty()) 
      cout << ".[ empty ]." << endl;
    else
      for (int i = el.size()-1; i>=0; i--)//trying to see if the for statement is a  
	cout << el[i] << endl; // single line of code. Ans: Yes seems that way .
  
 cout << "--------------" << endl;
 }
 
 
//PURPOSE: pops all elements from the stack to make it 
//         empty if it is not empty yet.
 void stack::clearIt()
{
   while (!el.empty())//While the vector el is not empty 
   {                  //continue to pop with the vector's 
     el.pop_back();   //pop_back function.             
   }
}
 

