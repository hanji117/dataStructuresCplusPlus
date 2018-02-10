//- Make sure PURPOSE and PARAMETER comments are given                         
//  DO NOT DELETE my descriptions but USE them.                                
//- Make sure all if-then-else are commented describing which case it is       
//- Make sure all local variables are described fully with their purposes      
//EMACS HINT:                                                                  
//  control-K cuts and control-Y pastes                                        
//  Esc X replace-str does string replacements                                 
//  Esc > goes to the end of the file; Esc < to the beginning                  
//  Tab on each line will indent perfectly for C++                             
// ====================================================                        
//HW#: HW3P3 slist                                                             
//Your name: Edgar Cruz                                                        
//Complier:  g++                                                               
//File type: slist implementation file                                         
//=====================================================                        
#include <iostream>//needed for NULL
#include "slist.h"


/*
PURPOSE: Initializes Front, Rear, and Count. Inherited from llist.
*/
slist::slist()   // constructor which is the same as the llist one
{
  //  llist();//calling linked lists's constructor.
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

/*
PURPOSE: search through the list to see if any node contains the key.
         If so, return its position (>=1). Otherwise, return 0.
PARAMETER: provide the key(Key) to be searched
ALGORITHM: Create a pointer P and make it point to the node that Front
           is pointing to. P will search through the linked list for the 
           key using a for loop since we know how many nodes we have.
           if P->Elem is equal to Key then return the position i. Otherwise,
           go to the next node. If P searched through the linked list
           and didn't find the Key return 0.
*/
int slist:: search(el_t Key)
{
 
  Node *P = Front;//P points to the node that Front is pointing to.
  for(int i = 1; i <= Count; i++) // Count has the number of nodes in the 
  {           //linked list. Go inside the for loop if the condition is true. 
    if (P->Elem == Key)//if P->Elem is equal to Key return i.
      return i; // i is the position.

    P= P->Next;//P points to the Node "Next" is pointing to.
  }
  return 0;//if the key is not found return 0.
}

/*
PURPOSE: go to the Ith node (if I is between 1 and Count) and
         replace the element there with the new element.
         If I was an illegal value, throw OutOfRange
PARAMETER: provide the new element(Elem) and the postion number(I).
ALGORITHM: If the position(I) is less than 1 or I is greater than Count
           throw OutOfRange. Else I is a valid number. Make a variable called
           OldNum of type el_t to hold a removed element. Call deleteIth and 
           addbeforeIth.
*/
void slist::replace(el_t Elem,  int I)
{
  if(I < 1 || I > Count)//If I is less than 1 or I is greater than 
    //Count throw OutOfRange.
    throw OutOfRange();
  else//I is a valid number
  {
    el_t OldNum;//to hold a removed element
   
    deleteIth(I, OldNum);//call deleteIth to delete the Ith node. Pass the position 
    //and provide a holder(OldNum) for the removed element.
    addbeforeIth(I, Elem);//call addbeforeIth to add a node before 
	                  //the Ith position from the linked list. Pass the position
    //and provide the new element(Elem) to replace the old element.
  }
}

/*
PURPOSE: overloading =. The operator =  does not work well with pointers        
PARAMETER: provide a list object (OtherOne).
ALGORITHM: Create a variable x of type el_t to hold a removed element.
           Compare the address of the 2nd linked list (OtherOne)
           with the address of the 1st linked list also known as the receiver object(this->)
           (just "this" contains the address of the 1st linked list) 
           and if they are not the same go inside the if statement. 
           The 1st linked list object (this->) needs to be emptied first.
           While the 1st linked list object is not empty continue to delete the 
	   Rear node. Create a pointer P. Make it point to the node that Front is 
	   pointing to in the 2nd linked list. While P is not equal to NULL 
	   go inside of the while loop. The 1st linked list(this->)(. is included)
	   calls addRear with p->Elem passed in it's parameter. (It's copying the
           2nd linked list's elements into the 1st linked list. The pointer 
           addresses will not be copied).Then P will point to the 
	   node "Next" is pointing to. Once you get out of the while loop
           return the 1st linked list.
*/
/*
MyList1 == 1st linked list == receiver object(this->)
MyList2 == 2nd linked list == OtherOne

To allow  MyList1 = MyList2; in the client...

Below, MyList1 will become the receiver object (this->) and MyList2 will 
be the OtherOne.
*/

// Note that OtherOne is being passed by reference
// The resulting List will be returned by reference
slist& slist::operator=(const slist& OtherOne)
{
  el_t x;//To hold a removed element. 
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if the addresses are not the same
  {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  

      // this-> object has to be built up by allocating new cells (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // This uses a loop which repeats until 
	                 //you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  //this-> is like saying "L1."addRear(P->Elem).
	  P = P->Next;               // Go to the next node in OtherOne   
	} 
   }// end of if              
  return *this;    // return the result unconditionally.
} 





/*                                                                                        
PURPOSE: Our own copy constructor for linked lists: To allow list                         
         objects to be passed by value and returned. The regular                          
         copy constructor does not work well with pointers.                               
PARAMETER: provide a list object (Original).
ALGORITHM: Create a pointer P. Make it point to the node that Front is             
           pointing to in the 2nd linked list (Original). While P is not equal to NULL     
           go inside of the while loop. The 1st linked list(this->)(. is included)           
           calls addRear with p->Elem passed in it's parameter. (It's copying the            
           2nd linked list's elements into the 1st linked list. The pointer                  
           addresses will not be copied). Then P will point to the                            
           node "Next" is pointing to.                                                      
*/
    // Note that the Original is being passed to the constructor by reference
    // to create a new object this-> as a copy of the Original
    slist::slist(const slist& Original)
    {
	//  this->'s data members need to be initialized first

	//  this-> object has to be built up by allocating new cells
	//  and copying the values from Original into each cell as we did with 
	//  operator= above. To do this,

      //	copy here the (**) lines in Operator Overloading of =.


	  // this-> object has to be built up by allocating new cells (**)
	  Node* P;  // local pointer for Original
        P = Original.Front;
        while (P != NULL)  // This uses a loop which repeats 
	               //until you reach the end of Original. 
	  {
	    this->addRear(P->Elem);    //P’s element is added to this->
	    P = P->Next;               // Go to the next node in Original   
	  } 
	  //  Nothing to return.
    }




