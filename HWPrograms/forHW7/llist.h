//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Edgar Cruz
// Compiler:  g++ 
// File type: header file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef char el_t ;  // elements will be **

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected://Searchable List must have access to the data members of the base
  //class(llist). But the clients should not access these data members.Thus protected.
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};   // thrown when there are no nodes to delete. Linked
  //list is empty.
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  /*
  PURPOSE: Returns true if the linked list is empty else false. 
  */
  bool isEmpty();
  
  /*
  PURPOSE: If it's empty [empty] will be displayed. Otherwise
           displays all of the nodes elements that are in
           the linked list. 
  */  
  void displayAll();
  
  /*
  PURPOSE: Adds a node to the front of the linked list.
  PARAMETER: Pass an element to be added to the front
             of the linked list.
  */  
  void addFront(el_t);
  
  /*
  PURPOSE: Adds a node to the rear of the linked list.
  PARAMETER: Pass an element to be added to the rear 
             of the linked list.
  */    
  void addRear(el_t);

  /*
  PURPOSE: To remove a node from the front of the linked list.
  PARAMETER: Provide variable to receive the deleted front node's 
             element (pass by ref)
  */  
  void deleteFront(el_t&);
  
  /*
  PURPOSE:To remove a node from the rear of the linked list.
  PARAMETER: Provide variable to receive the deleted rear node's 
             element (pass by ref)
  */    
  void deleteRear(el_t&);
  
  /*
  PURPOSE: To delete the Node at a selected position from the linked list.
  PARAMETER:  Provide the Node postion to be deleted. Provide a holder for the 
  element (pass by ref)
  */    
  void deleteIth(int, el_t&);

  /*
  PURPOSE: To add a Node before a selected position from the linked list.
  PARAMETER: Provide the position to have a new Node placed before it.
  Provide the element to be added.
  */      
  void addbeforeIth(int, el_t);
    
};
