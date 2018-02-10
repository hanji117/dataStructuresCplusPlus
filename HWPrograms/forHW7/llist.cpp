//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

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
//HW#: HW3P1 llist
//Your name: Edgar Cruz
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 
/*
  PURPOSE: Constructor initializes Front, Rear, and Count.
  ALGORITHM: 
            - initialize Front and Rear to be NULL and Count = 0.
            - This does not create any node.  The new list is empty.
*/
llist::llist()
{
  //cout << "....in the llist constructor" << endl;
  Front = NULL;
  Rear = NULL;
  Count = 0;
}


/*  
PURPOSE: Destructor deletes all the nodes in the linked list.
ALGORITHM:  
          - Please place a cout in this function 
            "calling the llist desctructor."
          - Create a variable elem of type el_t.
          - while the list is not empty, call deleteFront 
	    repeatedly to delete all nodes.

*/
llist::~llist()
{ 
  //cout << "....in the llist destructor" << endl;
  el_t elem; //local variable to be passed into deleteFront()
  while (!isEmpty())
    deleteFront(elem);// elem will receive the front nodes 
                      // deleted element.
}


/*
PURPOSE: Checks to see if the linked list is empty.
ALGORITHM: 
  - return true if Front and Rear are both pointing to NULL and Count is 0.
    Else false is returned.
  - (all 3 conditions must be checked)
*/
bool llist::isEmpty()
{
  //This if else statement checks to see if the linked list is empty.
  //If all them are true then true is returned else false is returned.
  if(Front == NULL && Rear == NULL && Count == 0)
    return true;
  else 
    return false;
}


/*
PURPOSE: To print all the nodes elements that are in the linked list.
ALGORITHM:
  - Special case: if the list is empty, display [ empty ] .
  - Regular: 
    displays each element of the list horizontally starting from Front in [ ].
    Create a temporary pointer and give it the address that the front 
    pointer contains. While the temporary pointer is not equal to NULL 
    cout the element of the current node that temp is pointing to, and
    then temp points to the node that next is pointing to 
    (temp receives the address of that node).
*/
void llist::displayAll()
{
  //This checks to see if the linked list is empty. If it is cout 
  //[ empty ].
  if (isEmpty())
    cout << "[empty]";
  else //If the linked list is not empty, this will 
  {    //display the elements from the linked list.  
    Node* temp = Front; // temp points to the front node.
    cout << "[";
    while (temp != NULL)//while the temporary pointer is not NULL 
    {                   //go inside the loop.
	cout << temp -> Elem << " ";//cout the element from the node
	                            //that temp is pointing to.
	              
	temp = temp -> Next;//temp gets the address of the next node.
    }

    cout << "]"; 
  }
}
  
/*
PURPOSE: To add a node at the rear of the linked list.
PARAMETER: Provide the element (NewNum) to be added.
ALGORITHM: 2 cases:
  - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum in the
    Elem field of the new node and Count is updated.
  - Regular: adds a new node at the rear and puts NewNum in the Elem field
    of this new node. Count is updated.
*/
void llist::addRear(el_t NewNum) 
{//If the linked list is empty then go inside the special case.
  if (isEmpty())// special case
    {//The case where this is the first node.
      Front = new Node;//Front points to a new Node.
      Rear = Front;//Rear points to the node Front is pointing to.
      Rear-> Next = NULL;//This Node points to nothing.
      Rear -> Elem = NewNum;//Put the element in the current Node.
      Count++;//increment count
    }
    else//Else if the linked list is not empty then go inside the Regular case.
    {   //This adds a Node to the rear
	 //Regular case:
         Rear->Next = new Node;//Rear->Next refers to the Next
	 // field of the Node.The "Next" pointer points to a new Node.
         Rear = Rear->Next; //The Rear pointer gets the new Nodes 
	 //address by doing Rear = Rear->Next because
	 //Next is pointing to the new Node.
         Rear->Elem = NewNum;//Rear->Elem refers to the element field of the 
	 //Node. NewNum is stored in that field.
         Rear->Next = NULL;//the last nodes next pointer is 
	 //pointing to nothing.
	 Count++;//increment count
    }
}

/*
PURPOSE: To add a Node to the front of the linked list.
PARAMETER: Provide the element(NewNum) to be added.
ALGORITHM: 2 cases:
- Special case: if this is going to be the very first node, you must
   create a new node and make Front and Rear point to it. Place NewNum in the
   element field of the Node and Count is updated.
- Regular: add a new node to the front of the list and 
  Count is updated.
*/
void llist::addFront(el_t NewNum)
{//If the linked list is empty then go inside the special case.
  if (isEmpty())//Special case:
    {//The case where this is the first node.
    Front = new Node;//Front points to a new Node.
    Rear = Front;//Rear points to the Node Front is pointing to.
    Front->Elem = NewNum;//NewNum is placed in the Elem field of the Node.
    Rear->Next=NULL;//This Node points to nothing.
    Count++;//Increment count.
  }

  else//else if the linked list is not empty go inside here
    //Regular case:
  {
    Node *x;//Create a pointer x.
    x = new Node;//pointer x points to a new Node.
    x->Next = Front;//x->Next refers to the Next field of the Node.
    //"Next" is a pointer that points to the Node that Front is pointing to.
    Front = x;//Front points to the node that x is pointing to.
    Front->Elem = NewNum;//Store NewNum in the element field of the node that 
    //Front is pointing to.
    Count++;//increment count
  }
}
/*
PURPOSE: To delete a Node from the front of the linked list.
PARAMETER: Provide a holder (OldNum) for the element (pass by ref)
ALGORITHM: 3 cases:
- Error case: if the List is empty, throw Underflow
- Special case: if currently only one Node,
   give back the front node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the front node element through OldNum (pass by reference)
  and also removes the front node.  Count is updated.
*/
void llist::deleteFront(el_t& OldNum)
{//If the linked list is empty throw Underflow.
  if (isEmpty())//error case
     throw Underflow();
  //Else if there is only one node in the linked list 
  //go inside the special case.
  else if (Count == 1)//special case
    {//The case where there is only 1 node to delete.
    OldNum = Front->Elem;//The Nodes element is stored in OldNum.
    delete Front;//Delete the node that front is pointing to.
    Front = NULL;//Make Front point to nothing.
    Rear = NULL;//Make Rear point to nothing.
    Count--;//Decrement count.
  }
  //Else if there is  more than 1 Node in the linked list
  //go inside the regular case.
  else
  { //Regular case:

    OldNum = Front->Elem;//The Nodes element is stored in OldNum.
    Node *Second;// A pointer called Second is created.
    Second = Front->Next; //Second points to what "Next" is pointing to.
    delete Front;//Delete the Node Front is pointing to.
    Front = Second;//Front gets the address of the Node Second is pointing to.
    Count--;//Decrement Count.
  }
}
/*
PURPOSE: To delete the rear Node.
PARAMETER: Provide a holder(OldNum)for the element(pass by ref)
ALGORITHM:  3 cases:
- Error case: if empty, throw Underflow
- Special case: if currently only one node,
   give back the rear node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
*/
void llist::deleteRear(el_t& OldNum)
{//If the linked list is empty throw Underflow.
  if (isEmpty())//error case
  {
    throw Underflow();
  }
//Else if the linked list has only 1 Node go inside the special case
  else if (Count == 1)//special case
  {//The case where 1 node will be deleted.
    OldNum = Front->Elem;//The Nodes element is stored in OldNum.
    delete Rear;
    Rear = NULL;
    Front = NULL;
    Count--;
  }
//Else if the linked list has more than 1 node go inside the Regular case.
  else
  {  //Regular case:
	
    OldNum = Rear->Elem;//The nodes element is stored in OldNum.
    Node *p = Front;//A pointer called p is created and it points to the 
    //Node that Front is pointing to.
    //Make p go to the one right before rear (using while)-this does not 
    //work if you have only one Node.
    while(p->Next != Rear)//the condition will get p to the 2nd to last node.
    {//Move p to the next node.
      p = p->Next;//p points to the node that "Next" is pointing to.
    }
    delete Rear;//Delete the Node that Rear is pointing to.
    Rear = p;//Rear points to the Node that p is pointing to.
    Rear->Next = NULL;//"Next" points to nothing.
    Count--;//Decrement count.
  }
}

/*
PURPOSE: To delete the Node at a selected position from the linked list.
PARAMETER: Provide the Node position(I) to be deleted.
           Provide a holder(OldNum)for the element(pass by ref).
ALGORITHM: 4 cases:
- Error case: 
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or 
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>
*/
void llist::deleteIth(int I, el_t& OldNum)
{//If I is greater than Count or less then 1 throw OutOfRange.
  if(I > Count || I < 1)//Error case
  throw OutOfRange();
  //Else if I equals 1 call deleteFront.
  else if(I == 1)//Special case
    deleteFront(OldNum);//This case deletes the first Node.
  //Else if I equals Count call deleteRear.
  else if (I == Count)//Special case
    deleteRear(OldNum);//This case deletes the last Node.
  else //Regular case:
  {//Pointer P will point to the Ith node.
    Node* P = Front;//P points to the node that Front is pointing to.
    Node* q = Front;//q points to the node that Front is pointing to.

    for(int K = 1; K<=I-2;K++)//This will make P point to the node 
      //that comes before the Ith position. ex. Ith = 3 . P points to 2.
    {
      //P points to the next Node.
      P = P->Next; //P points to the Node "Next" is pointing to.
    }

    for(int Z = 1; Z<= I-1; Z++)//This will make q point to the Ith position.
      q= q->Next;//q points to the Node "Next" is pointing to.

    Node* P2 ;//P2 will point to the node that comes after the Ith position.
    OldNum = q -> Elem;//Store Elem into OldNum.
    P2 = q-> Next;//P2 points to the node that "Next" is pointing to.
    delete q;//delete the node that q is pointing to.
    q = NULL;//Make the q pointer point to nothing (NULL)
    P -> Next = P2;  // "Next" points to the Node P2 is pointing at.
    Count--;//Decrement Count
  }
}

/*
PURPOSE: To add a node before a selected position from the linked list.
PARAMETER:Provide the position(I) to have a new Node placed before it.
          Provide the element(NewNum) to be added.
ALGORITHM: 4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>
*/
void llist::addbeforeIth(int I, el_t newNum)
{//If I is greater than count+1 or I is less than 1 throw OutOfRange.
  if(I > Count +1 || I < 1)//Error case
    throw OutOfRange();
  //If I equals 1 go inside 
  else if(I == 1)//Special case
    addFront(newNum);//This case calls addFront 
  //to add a new Node before the selected position.
  else if(I == Count+1)//Special case
    addRear(newNum);// This case Calls addRear to add a 
  //new Node before the seleceted position.
  else//Regular case
  {
    Node* P= Front;//P points to the Node that Front is pointing to.
    for(int K = 1; K <= I-2; K++)//This will take you to the Node 
      // that comes before the Ith postion.
    {//P points to the next Node.
	P= P->Next;//P points to the Node that "Next" is pointing to.  
    }
    
    Node* q = Front;//q points to the Node that Front is pointing to.
    for(int a = 1; a <= I -1; a++)//This will take you to the Ith position.
    {//P2 points to the next Node.
      q = q->Next;//P2 points to the Node that "Next" is pointing to.
    }
    Node *r;//r will point to a new Node.
    r = new Node;// r points to a new Node.
    r -> Elem = newNum;//The element(newNum) is stored in the Elem field of
    //the Node that r is pointing to.
    P -> Next = r; //"Next" points to the Node that r is pointing to.
    r -> Next = q;//"Next" points to the Node that q is pointing to.
    Count++;//Increment Count.
  }
}

