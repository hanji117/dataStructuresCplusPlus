// delete
// insert
// in order 

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
// PARAM: V is te pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
  if (V != NULL)
    {
      INorderTraversal(V->Left);// ** traverse left sub-tree of V recursively
      cout << V->Elem << " "; // ** display V's element and do endl; 
      INorderTraversal(V->Right);        // ** traverse right sub-tree of V recursively
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
      cout << V->Elem << " ";       // ** display V's element and do endl; 
      PREorderTraversal(V->Left);        // ** traverse left sub-tree of V recursively
      PREorderTraversal(V->Right);        // ** traverse right sub-tree of V recursively

    }
}

// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively) to demonstrate
// the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E){
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
    { cout << "...error: the element already exists" << endl;
      return;  
    }
  else     
     if (N->Elem < V->Elem)  // what I have is smaller than V
     { cout << "...going to the left" << endl; 
  Parent =V; // **change Parent to be V to go down
  V=V->Left; // **change V to be V's Left 
      }
     else      // what I have is bigger than V
       { cout << "...going to the right" << endl;
  Parent=V;   // **change Parent to be V to go down
  V=V->Right; // **change V to be V's Right 
         }
  }//end of while
      // reached NULL -- Must add N as the Parent's child        
      if (N->Elem < Parent->Elem)
  {  
    Parent->Left = N;
    // ** Parent's Left should point to the same place as N 
    cout << "...adding " << E << " as the left child of " 
         << Parent->Elem << endl;
  } // ** Parent's Right should point to the same place as N 
      else 
  {
    Parent->Right =N;
    cout << "...adding " << E << " as the right child of " 
        << Parent->Elem << endl;  
  }
    }// end of normal case
}

// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E){
  cout << "Trying to delete " << E << endl;

  Vertex *V;              // the current vertex
  Vertex *Parent = NULL;  // its parent
  
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL)){
    cout << "...deleting the lonely root" << endl;
    delete Root; 
    Root = NULL;
    return; 
  } // only the Root was there and deleted it

  /*
    Condition for if the element is the root and only 
    has a leaf Node to the right change the root to the 
    child and return - this could be the left or the right child 
  */
  if((E == Root->Elem) && (Root->Left == NULL) && (Root->Right!= NULL)){ 
    V = Root;
    Root=Root->Right; // Move root to the right 
    delete V; // delete original root and return
    return;
  }// end of deleting the root
  
  // Condition for if the element is the root and only has a leaf Node to the left
  if ((E == Root->Elem) && (Root->Left != NULL) && (Root->Right == NULL)){
    V = Root;
    Root = Root->Left; // Move root to the left
    delete V; // delete original root and return
    return;
  }

  // Condition for if the root has leaf Node to both left and right
  if ((E == Root->Elem) && (Root->Left != NULL) && (Root->Right != NULL)){
    Root->Elem = findMax(Root->Left); // Replaces the element with max of Left sub tree
    return; // return
  }// Otherwise deleting something else
  
  V = Root;  // start with the root to look for E
  
  while (V != NULL){ // This while loops goes to find the appropriate element to deletez
    if (E == V->Elem){ // if element found, use remove function to delete it
      remove(V, Parent);
      return;
    }
    if (E < V->Elem){ // if element is smaller, then move the tree down left
      Parent = V;
      V = V->Left;
    } 
    else if(E > V->Elem){ // if element is bigger, move the tree down right
      Parent = V;
      V = V->Right;
    }   
    // Process repeats until whole tree is traversed
  } 
  return;
}


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *Parent){
  /* CASE 1: V is a leaf  */
  if (V->Left == NULL && V->Right == NULL){ // condition if there is no leaf node
    if (Parent->Elem < V->Elem) 
      Parent->Right = NULL; // Parent Node will be set accordingly
    else
      Parent->Left = NULL;
    
    delete V; // delete original
    return; // return
  }
  /*   Case 2: it has just one child, bypass it*/
  if (V->Left == NULL && V->Right != NULL){ // condition for only right leaf node
    if (Parent->Elem < V->Elem)
      Parent->Right = V->Right; // Parent node will be set accordingly
    else
      Parent->Left = V->Right;
    
    delete V; // delete original and return
    return;
  }
  
  if (V->Left != NULL && V->Right == NULL){ // condition for only left leaf node
    if (Parent->Elem < V->Elem)
      Parent->Right = V->Left; // parent node will be set accordingly
    else
      Parent->Left = V->Right;
    
    delete V; // delete original and return
    return;
  }
  
  if (V->Left != NULL && V->Right != NULL){ // condition 3
    V->Elem = findMax(V->Left); // Element will be replaced by the max of the left sub tree
    return; // return
  }
  
}

// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V){
  Vertex *Parent = NULL; 
  elem_t max;
  
  while (V->Right != NULL){ // Keep shifting right until NULL to find the max value
    Parent = V; // Have parent follow behind
    V = V->Right;
  }

  max = V->Elem; // hold the max value 
  Parent->Right = NULL; // set the parent->right to NULL
  delete V; // delete the original
  V = NULL; // set V to NULL
  return max; // return the max value
}


