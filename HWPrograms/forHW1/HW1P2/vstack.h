// =======================================================
// HW#: HW1P2 stack
// Your name: Edgar Cruz
// Compiler:  g++ 
// File type: header file vstack.h
//=======================================================

#include <vector>

//----- Globally setting up the alias ----------------

typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  vector <el_t>el;       // el is  a vector of el_t's
  
 public:
   // the rest will be exactly the same as HW1P1. Therefore
   // the client should not have to change at all.

  // prototypes to be used by the client                                 
  // Note that no parameter variables are given                                 

  // exception handling classes                                                 
  class Overflow{};   // thrown when the stack overflows                        
  class Underflow{};  // thrown when the stack underflows                       

  stack();   // constructor to create an object                                 
  ~stack();  // destructor  to destroy an object                                

  // PURPOSE: if not full, enters an element at the top;                        
  //          otherwise throws an exception - Overflow                          
  // PARAMETER: pass the element to be pushed                                   
  void push(el_t);

  // PURPOSE: if not empty, removes and gives back the top element;             
  //          otherwise throws an exception - Underflow                         
  // PARAMETER: provide variable to receive the popped element (pass by ref)    
  void pop(el_t&);

  // PURPOSE: if not empty, gives the top element without removing it;          
  //          otherwise, throws an exception - Underflow                        
  // PARAMETER: provide variable to receive the top element (pass by ref)       
  void topElem(el_t&);

  // ** Must add good comments for each function - See Notes1B                  

  //PURPOSE: Returns true if stack is empty else false                          
  bool isEmpty();
  //PURPOSE: Returns true if stack is full else false                           
  bool isFull();
  //PURPOSE: Displays the elements in the stack                                 
  void displayAll();
  //PURPOSE: Clears the stack                                                   
  void clearIt();

};
