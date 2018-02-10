// ============ for the dgraph.h file =================================
// INSTRUCTION:
// You need to comment this file completely using the How to Comment file.
// You have seen many examples so far.
// We will check to see how well you have commented it.

// I am using hw3p3.h which is the most up to date slist.h
// You can change it to your "slist.h"

// =======================================================              
// HW#: HW6 dgraph                                                        
// Your name: Edgar Cruz                                                    
// Compiler:  g++                                                           
// File type: header file                                                   
//=======================================================    

#include <iostream>
#include <string>
#include "slist.h"

using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 20;   // for the size of the graph table

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;      //the vertex Name
  int outDegree;	//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
};

class dgraph: public slist
{

private:
  Gvertex Gtable[SIZE];  // a table representing a dgraph
  int  countUsed; // how many slots of the Gtable are actually used

public:

  class BadVertex {};  // thrown when the vertex is not in the graph
 
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
               // initialize countUsed to be 0
  ~dgraph();   // do we have to delete all nodes of slists in table??
	       // Question: If we do not do this, will the llist destructor
               // be called automatically??? Try it.
/*
PURPOSE: read from the input file table.txt and fill GTable.
*/
  void fillTable();  

/*
PURPOSE: displays graph in an easy to read format.
*/ 
  void displayGraph(); 

/* 
PURPOSE: returns the out degree of a given vertex - may throw BadVertex
PARAMETER: Pass a vertex to find it's out degree.
*/
  int findOutDegree(char);  
	
/*
PURPOSE: returns the adjacency list of a given vertex - may throw BadVertex
PARAMETER: Pass a vertex to find its adjacency list.
*/
  slist findAdjacency(char);  



/*

PURPOSE: It will enter the given visit number for a given vertex.
         This is to indicate the order in which vertices were visited.
         Do not use a loop to look for the vertex.
         Convert A to slot 0, B to slot 1 etc.
PARAMETER: Pass a counter and a vertex to assign a number to the vertex.
*/
 void visit(int, char);
 
/*
PURPOSE:  returns true if a given vertex was already visited
	  (0 means not visited)
	  Do not use a loop to look for a vertex
PARAMETER: Pass a vertex to see if it has been visited.
*/
 bool isMarked(char);


};


