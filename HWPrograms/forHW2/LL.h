/*                                                                              
Edgar Cruz                                                                      
CS 211 lab 11-1, HW 7                                                           
LL class - header file                                                          
===========================================================================     
//PURPOSE: The header file declares functions, variables, and a class.          
//The header file lets the compiler know about the variables and functions      
//that are available and how to use them.                                       
*/

#ifndef LL_H//There may be cases where a header file gets included more         
//than once when compiling a .C file.                           
//e.g. myProg.C includes stack.h and queue.h                    
//stack.h also includes queue.h                                 
//(although we don't do this in cs211)                          
//This causes the compiler to complain about seeing duplicate   
//declarations(class Queue is declared twice).                  
//#ifndef LL_H checks to see if a compiler variable             
//has already been created.                                     

#define LL_H//creates a compiler variable.                                      
#include <string>
using namespace std;//needed for string                                         
typedef int el_t;//the element type, el_t is int for now.                       
// char for palindrome.C , string for dictionary.C                              
struct node//A struct is a user-defined data type that contains                 
//a collection of different data types.                                         
{
  el_t element;//Each field is called a "member" and has a name.                
  node* next;
  node* prev;
  //  node* right;                                                              
  // node* left;                                                                
};

class LL //class syn. category. I made a category called LL.                    
{
 private://Accessible only from within other members of the                     
         //same class(category).                                                
  //Data members below                                                          
  node* front;//Where the front node of the linked list is.                     
              //Will point to the front node.                                   
  node* rear;//Where the rear node of the linked list is.                       
             //Will point to the rear node.                                     
  int count;//How many elements do we have right now?                           
  //Private utility function for error cases below.                             
  void listError(string);
 public:
  LL();//default constructor                                                    
  ~LL();//destructor                                                            

  //HOW TO CALL: Create an LL object (such as LL myLL)                          
  //             and place the isEmpty function after.                          
  //             i.e. myLL.isEmpty()                                            
  //PURPOSE: Returns true if LL is empty else false.                            
  bool isEmpty();

  //HOW TO CALL: Pass an element to be added.                                   
  //PURPOSE: Enters a node at the rear of the Linked list.                      
  void addRear(el_t);
  //HOW TO CALL: Create an LL object (such as LL myLL)                          
  //             and place the deleteFront function after.                      
  //             i.e. myLL.deleteFront()                                        
  //PURPOSE: If empty calls an emergency exit routine.                          
  //         If not empty, removes a node from the front.                       
  el_t deleteFront();

  //HOW TO CALL: Create an LL object (such as LL myLL)                          
  //             and place the displayAll function after.                       
  //             i.e. myLL.displayAll()                                         
  //PURPOSE: If it's empty [ empty ] will be displayed. Else displays           
  //         all the nodes in the LL.                                           
  void displayAll();

  //HOW TO CALL: Create an LL object (such as LL myLL)                           
  //             and place the printAllReverse function after.                   
  //             i.e. myLL.printAllReverse()                                     
  //PURPOSE: Will display the LL in reverse order.                               
  void printAllReverse();

  //HOW TO CALL: Pass a pointer to the parameter.                                
  //PURPOSE: If the pointer is equal to NULL return.                             
  //         Else calls printAllReverse(p-> next) and couts p-> element.         
  void printAllReverse(node* p);

  //HOW TO CALL: Pass an element to be added.                                    
  //PURPOSE: Enters a node at the front of the linked list.                      
  void addFront(el_t el);

  //HOW TO CALL: Create an LL object (such as LL myLL)                           
  //             and place the deleteRear function after.                        
  //             i.e. myLL.deleteRear()                                          
  //PURPOSE: If empty calls an emergency exit routine.                           
  //         If not empty, removes a node from the rear.                         
  el_t deleteRear();

  //HOW TO CALL: Pass an element.                                                
  //PURPOSE: To delete the node that contains the passed element.                
  void deleteNode(el_t);

  //HOW TO CALL: Pass an element.                                                
  //PURPOSE: To delete the nodes that contain the passed element.                
  void deleteNodes(el_t e);//extra credit                                         

  //HOW TO CALL: Pass an element.                                                
  //PURPOSE: To add a new node in ascending order (from least to greatest).      
  void addInOrderAscend(el_t);

  //HOW TO CALL: Pass an element.                                                
  //PURPOSE: To add a new node in descending order (from greatest to least).     
  void addInOrderDescend(el_t); //for extra credit                               
  //HOW TO CALL: Pass an element.                                                
  //PURPOSE: Returns true if the passed element is found in the linked list      
  //         else returns false. If the linked list is empty, returns false.     
  bool search(el_t);
};

#endif //End of the part checked by LL_H. Kind of like a ;                      
//otherwise, an error message is generated.                                     

