
// CS311 : This is the BST implementation file template by Rika Yoshii
// INSTRUCTIONS:
//** Look for ** comments to complete this file for HW4
// Try not to delete the ** comments
// Make sure all { } match. Doing Tab on each line helps.

// =========================================================
//HW#: HW4 BST
//Your name: Edgar Cruz
//Complier:  g++
//File type: Implementation file
//================================================================

using namespace std;

#include <iostream>
#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
   Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;    
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{   
  if (V != NULL) 
    {
      dtraverse(V->Left);         // visit left sub tree of V
      dtraverse(V->Right);       //  visit right sub tree of V
      delete V;                  //  deletes V
    }
}


// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is the pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
    if (V != NULL)
    {
        INorderTraversal(V->Left);// ** traverse left sub-tree of V recursively
        cout << V->Elem << " " << endl;//** display V's element and do endl; 
        INorderTraversal(V->Right);// ** traverse right sub-tree of V recursively
    }
}

// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
  cout << "Elements in the PRE order:" << endl;
  PREorderTraversal(Root);  // start pre-order traversal from the root
}

// PURPOSE: Does PRE order traversal from V recursively
// PARAM: V is the pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
    if (V != NULL)
    {
      cout << V->Elem << " " << endl; // ** display V's element and do endl; 
      PREorderTraversal(V->Left);// ** traverse left sub-tree of V recursively
      PREorderTraversal(V->Right);// ** traverse right sub-tree of V recursively

    }
}

// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively) to demonstrate
// the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E)
{
  // Set up a new vertex first
  Vertex *N;         // N will point to the new vertex to be inserted
  N = new Vertex;    // a new vertex is created
  N->Left  = NULL;   // make sure it does not
  N->Right = NULL;   // point to anything
  N->Elem  = E;      // put element E in it

  cout << "Trying to insert " << E << endl; 
  
  // Special case: we have a brand new empty tree
  if (Root == NULL)
  {
      Root = N;      // the new vertex is added as the root
      cout << "...adding " << E << " as the root" << endl; 
  }
  // the tree is not empty
  else
  {
      Vertex *V;       // V will point to the current vertex
      Vertex *Parent;  // Parent will point to V's parent
 
      V = Root;        // start with the root as V    
 
     // go down the tree until you cannot go any further
      while (V != NULL)
      {   
	  if (N->Elem == V->Elem) // the element already exists
	  {
	      cout << "...error: the element already exists" << endl;
	      return;  
	  }
	  else     
	    if (N->Elem < V->Elem)  // what I have is smaller than V
	    {
	        cout << "...going to the left" << endl; 
		Parent = V; // **change Parent to be V to go down
		V = V->Left; // **change V to be V's Left 
	    }
	    else      // what I have is bigger than V
	    {
	        cout << "...going to the right" << endl;
		Parent = V;   // **change Parent to be V to go down
		V = V->Right; // **change V to be V's Right 
	    }
      }//end of while

      // reached NULL -- Must add N as the Parent's child        

      if (N->Elem < Parent->Elem)
      {  
        Parent->Left = N;// ** Parent's Left should point to the same place as N 
	  cout << "...adding " << E << " as the left child of " 
	       << Parent->Elem << endl;
      } 
      else 
      {
          // ** Parent's Right should point to the same place as N 
	  Parent->Right = N;
	  cout << "...adding " << E << " as the right child of " 
	       << Parent->Elem << endl;  
      }
    }// end of normal case
}//end of InsertVertex



// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{
  cout << "Trying to delete " << E << endl;
  
  Vertex *V;              // the current vertex
  Vertex *Parent = NULL;  // its parent
  
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
  {
      cout << "...deleting the lonely root" << endl;
      delete Root; 
      Root = NULL;
      return; 
  }  // only the Root was there and deleted it
  
 
    //** if what you want to delete is the root with one child
    //** change the root to the child and return - this could be left or the 
    //right child.
  //Root and right child.
  if((E == Root -> Elem) && (Root ->Left == NULL) && (Root -> Right !=NULL))
  {
    V= Root;//V points to the node "Root"
    Root = Root->Right;//Root goes into the Right field and whatever
    //Right is pointing to goes into Root.
      delete V;
      V = NULL;
      return;
  }//end of deleting the root

  //Root and left child.
  if((E == Root -> Elem) && (Root ->Left != NULL) && (Root -> Right == NULL))
  {
    V = Root;
    Root= Root ->Left;//Accessing the Left field of Root and whatever it's 
    //pointing to goes into Root.
    delete V;
    V = NULL;
    return;
  }// end of deleting the root
 
  //Otherwise deleting something else

  V = Root;  // start with the root to look for E
  
  while (V != NULL)
  { 
      if (E == V->Elem)   // found it
      {
	cout << "...removing " << V->Elem << endl;
        remove(V, Parent);	  // ** call remove here to remove V
	return; 
      }
      if (E < V->Elem)
      {  cout << "...going to the left" << endl;
	    Parent = V;	    // ** update Parent and V here to go down 
	    V = V->Left;
      }
      else if(E > V-> Elem)
      {  cout << "...going to the right" << endl;
	    Parent = V;// ** update Parent and V here to go down
	    V= V->Right;//V points to whatever V->Right is pointing to.
      }
      
  }// end of while
  
  // reached NULL  -- did not find it
  cout << "Did not find the key in the tree." << endl;
  return;
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer "Parent"
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *Parent)
{
  if (V->Left == NULL && V->Right == NULL)// ** if V is a leaf (case 1)
  {
	cout << ".. removing a leaf" << endl;
	if (Parent-> Elem < V->Elem)	// ** if V is a right child of the Parent
	  Parent->Right = NULL;// ** delete V and also make Parent's right NULL 
	
	else // V is a left child of the Parent
	  Parent->Left= NULL;// ** delete V and also make Parent's left NULL
	
	delete V;
	return;
  }//end of leaf case

    // ** if V has just the right child (case 2)
  if (V->Left == NULL && V->Right != NULL)
  {
      cout << "removing a vertex with just the right child" << endl;
      if(Parent-> Elem < V->Elem)// ** Make Parent left or right point to the right child and delete V
	Parent->Right = V->Right; //(You need if then else to determine left or right)
      else 
	Parent->Left = V->Right;
      
      delete V;
      return;
    }// end of V with right child       
  
  if (V->Left != NULL && V->Right ==NULL) // ** if V has just the left child
  {
      cout << "removing a vertex with just the left child" << endl;
      if (Parent->Elem < V->Elem) // ** Make Parent left or right point to the right child and delete V
	Parent ->Right = V->Left;// (You need if then else to determine left or right)
      else
	Parent ->Left = V->Right;

	  delete V;
	return;
  }//condition 3
  if(V->Left !=NULL && V->Right !=NULL)
  {
    V->Elem = findMax(V->Left);

    return;
  }//end of V with two children
}// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
//PARAMETER: Provide a pointer of type Vertex.
elem_t BST::findMax(Vertex *V)
{
  Vertex *Parent = NULL;
  elem_t max;

     while(V->Right != NULL)     
// ** while the right child of V is still available
     {
     // ** update Parent and V to go to the right
	    Parent = V;
	    V=V->Right;

     }
     max = V->Elem;
     Parent->Right = NULL;
     delete V;
     return max;

}// end of FindMax

