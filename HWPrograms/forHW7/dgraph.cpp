// ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================
//HW#: HW6 dgraph                                                    
//Your name: Edgar Cruz                                                      
//Complier:  g++                
//File type: dgraph implementation file 
//=====================================
#include "dgraph.h"
#include <fstream>
#include <iostream>
#include <stdio.h>//for Toupper
#include <ctype.h>//for Toupper

using namespace std;
// note that Gtable[i].adjacentOnes is a slist, so you can use
//  any slist function on it


/*
PURPOSE: Constructor initializes countUsed, Gtable[i].vertexName,
         Gtable[i].outDegree, and Gtable[i].visit 
*/
dgraph::dgraph()
{
  countUsed = 0;
  for(int i = 0;i < SIZE ;i++)
  {
    Gtable[i].vertexName = '\0';
    Gtable[i].outDegree = 0;
    Gtable[i].visit = 0;
  }
}

/*
PURPOSE: Destructor deletes all the nodes in the linked list.
*/
dgraph::~dgraph()
{
  //llist's destructor is called automatically
}

/*
PURPOSE: read from the input file table.txt and fill GTable.
ALGORITHM: Create a variable x of type char. Set up ifstream 
           to read from the file "table.txt." Use a while loop to read 
           from the file. Once it can't read from the file anymore 
           you exit the while loop and close the file.
*/
void dgraph::fillTable()
{
  char x;
  //Set up fin stream to read from table.txt
  ifstream fin("table.txt", ios::in);//std?
  while (fin >> Gtable[countUsed].vertexName)  // if I can read the name
  { 
      fin >> Gtable[countUsed].outDegree;
      
      // Then for the outDegree times do the following: (use a for-loop)
      for(int i = 0; i < Gtable[countUsed].outDegree; i++)
      {//same as ar[i].outDegree a part of the Gvertex(Like a node)
	//outDegree is like Front.
	  fin >> x;
	  (Gtable[countUsed].adjacentOnes).addRear(x);
	  // this uses a slist function from HW3
      }//end of for
      
      countUsed++;  // increment the countUsed
  }//end of while
    fin.close();//close fin
}

/*
PURPOSE: displays graph in an easy to read format.
ALGORITHM: Use a for loop to display all of the vertexes and their degree.
           Displays the adjacent vertices in the slist.
*/
void dgraph::displayGraph()
{
  //Hint on displaygraph::

  //Make the following couts better with labels.
  for (int i = 0; i < countUsed; i++)
  { 
/* 
    cout << "Vertex Name: " <<Gtable[i].vertexName << endl;
    cout << "OutDegree: "<< Gtable[i].outDegree << endl;
    cout << "Visit number " << Gtable[i].visit << endl;
    cout << "Adjacent Ones: ";
    (Gtable[i].adjacentOnes).displayAll();
    cout << endl;
*/
    cout << Gtable[i].vertexName << " " << Gtable[i].outDegree << " " 
         << Gtable[i].visit << " "; 
    (Gtable[i].adjacentOnes).displayAll();
    cout << endl;
  }  
}

/*
Instruction on findOutDegree and findAdjacency::
For this HW, you must use a loop.
Do not go through all the slots of the table
Just go through the used slots.
*/

/*
PURPOSE: Returns the out degree of a given vertex - may throw BadVertex
PARAMETER: Pass a vertex (elem) to find it's out degree.
ALGORITHM: Make a for loop to search for the vertex. if its found it's 
           outDegree is returned otherwise BadVertex is thrown.
*/
int dgraph::findOutDegree(char elem)
{
  for (int i = 0; i < countUsed; i++)//Gtable[countUsed].outDegree ;i++)
  {
      if (Gtable[i].vertexName == elem)
	return Gtable[i].outDegree;
  }
  throw BadVertex();//if the vertex is not found
}

/*
PURPOSE: returns the adjacency list of a given vertex - may throw BadVertex
PARAMETER: Pass a vertex (element) to find its adjacency list.
ALGORITHM: Make a for loop to search for the vertex. if its found it's  
           adjacent ones list is returned otherwise BadVertex is thrown.
*/
slist dgraph::findAdjacency(char element)
{
  for (int i = 0; i < countUsed; i++)
  {
      if (Gtable[i].vertexName == element)
	return Gtable[i].adjacentOnes;
  }
  throw BadVertex();//if the vertex is not found
}

/*                                                                           
PURPOSE: It will enter the given visit number for a given vertex. 
         This is to indicate the order in which vertices were visited. 
         Do not use a loop to look for the vertex.
         Convert A to slot 0, B to slot 1 etc.                     
PARAMETER: Pass a counter(count) and a vertex(vertex) 
           to assign a number to the vertex.
ALGORITHM: Convert the vertex into an integer and subtract A from it. 
           Store it in an integer variable called slot. Store the 
           counter count in the array Gtable[slot].visit.      
*/
void dgraph::visit(int count, char vertex)
{
  int slot = int(vertex) - 'A'; //A is 65 on the ascii table
  Gtable[slot].visit = count;
}
/*                                                                           
PURPOSE: returns true if a given vertex was already visited           
         (0 means not visited)                                              
         Do not use a loop to look for a vertex                             
PARAMETER: Pass a vertex(vertex2) to see if it has been visited.             
ALGORITHM: Convert the vertex (vertex2) into an integer and subtract 
           A from it. Store the result in an integer variable called slot.
           If the Gtable[slot].visit is greater than 0 the vertex has
           been visited. Else return false.
*/
bool dgraph::isMarked(char vertex2)
{
  int slot = int(vertex2) - 'A';
  
  if (Gtable[slot].visit > 0)
    return true;
  else 
    return false;

}


