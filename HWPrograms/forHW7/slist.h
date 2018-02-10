// =======================================================                     
// HW#: HW3P3 slist                                                            
// Your name: Edgar Cruz                                                       
// Compiler:  g++                                                              
// File type: header file                                                      
//=======================================================                      
// Don't forget PURPOSE and PARAMETERS                                         
#ifndef SLIST_H
#define SLIST_H

#include "llist.h"

class slist:public llist//inherits everything that's under protected and 
	      // public from the class llist in llist.h 
{
 public:
 slist();   //constructor which is the same as the llist one
           //constructor to create an slist object
/*
PURPOSE: search through the list to see if any node contains the key.
         If so, return its position (>=1). Otherwise, return 0.
PARAMETER: provide the key to be searched.
*/
 int search(el_t);

/*
PURPOSE: go to the Ith node (if I is between 1 and Count) and
         replace the element there with the new element.
         If I was an illegal value, throw OutOfRange
PARAMETER: provide the new element and the position number.
*/
 void replace(el_t,  int);
/*
PURPOSE: Our own copy constructor for linked lists: To allow list 
         objects to be passed by value and returned. The regular 
         copy constructor does not work well with pointers.
PARAMETER: provide a list object. 
*/
slist(const slist&);

/*
PURPOSE: overloading =. The operator =  does not work well with pointers
PARAMETER: provide a list object.
*/
slist& operator=(const slist& );// =  is overloaded

};
#endif
