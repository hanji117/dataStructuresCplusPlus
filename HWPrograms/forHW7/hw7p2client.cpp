//=========================================================               
//HW#: HW7P2 Implementation DFS of a Graph                  
//Your name: Edgar Cruz                                                   
//Complier:  g++                                                          
//File type: client program                                               
//===========================================================  
#include "stack.h"
#include "dgraph.h"
#include "slist.h"
#include <iostream>
using namespace std;

/*
PURPOSE: To be able to implement DFS of a graph.
ALGORITHM: Create dgraph, stack, and slist objects. myDgraph, myStack, mySlist
           respectively. Fill the dgraph object (myDgraph) by calling the 
           fillTable function. Display it by calling the displayGraph 
           function. Start with the vertex A and count at 1. Call the visit
           function to indicate that A has been visited. Find vertex A's 
           adjacency by calling findAdjacency (myDgraph.findAdjacency(vertex))
           and storing it in mySlist. Display it by doing mySlist.displayAll();
           While mySlist is not empty continue to delete from the rear and 
           pushing it onto myStack. Display the stack. While the stack is not 
           empty pop the vertex from the stack and check to see if it has 
           been marked. If it hasn't then indicate that it has been visited
           and find it's adjacency. Store those vertex's into the slist. 
	   Display the slist and while the slist is not empty delete from the 
           rear and push the vertex onto the stack. When you get out of 
           the while loop display the stack. 
	   Otherwise, the vertex has already been visited and display the 
	   remaining vertexs in the stack. Once you get out of the while
	   loop display the graph.
*/
int main()
{
  dgraph myDgraph;
  stack myStack;
  slist mySlist;
  
  myDgraph.fillTable();
  myDgraph.displayGraph();

  char vertex = 'A';
  int count = 1;
  myDgraph.visit(count, vertex);  
  cout << "Visited " << vertex << endl;

  mySlist = myDgraph.findAdjacency(vertex);
  cout << "pushing ";
  mySlist.displayAll();
  cout << endl;
  
  while (!mySlist.isEmpty())
  {
    mySlist.deleteRear(vertex);
    myStack.push(vertex);
  }
  cout << "stack is:" << endl;
  myStack.displayAll();

  while(!myStack.isEmpty())
  {
      myStack.pop(vertex);
      
      if (!myDgraph.isMarked(vertex))
      {
	  cout << "Visited " << vertex << endl;//the top vertex
                                           //from the stack 
	  count++;
	  myDgraph.visit(count, vertex);
	  mySlist = myDgraph.findAdjacency(vertex);
          cout << "pushing ";
          mySlist.displayAll();
          cout << endl;
	  char nextVertex;
	  while (!mySlist.isEmpty())
	  {
	      mySlist.deleteRear(nextVertex);
	      myStack.push(nextVertex);
	  }
	  cout << "stack is:" << endl;
	  myStack.displayAll();
       }
       else 
       {
	 cout << "stack is: " << endl;
	 myStack.displayAll();
       }
  }

  myDgraph.displayGraph();

  return 0;
}
