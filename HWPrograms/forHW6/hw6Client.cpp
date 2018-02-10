// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.
//=====================================
//HW#: HW6 dgraph
//Your name: Edgar Cruz
//Complier:  g++
//File type: dgraph client file 
//=====================================
#include <iostream>
#include "dgraph.h"
#include <string>
using namespace std;

/*
PURPOSE: To form fundamental understanding about graphs 
ALGORITHM: Call fillTable function and call displayGraph function. 
           Inside of a while loop call findOutDegree function.
           The user will specify which vertex. Display the returned result.
           Inside of another while loop Call findAdjacency function. 
           The user will specify which vertex. Display the returned list. 
           Catch vertexes that are not found and display an error message. 
*/
int main()
{
  //{ 0.Declare table object
  dgraph table;  
  
  //1.fillTable()
  table.fillTable();
  
  //  2.displayGraph()
  table.displayGraph();
 
  int degree;
  slist l1;
  string ans;
  char vertex;
  //while (the user does not want to stop)
  do{
    cout << "Do you want to find a vertex's degree?" << endl
	 << "If yes enter yes. If no enter no: ";
    cin >> ans;
     }while(ans != "yes" && ans != "no");
  
      while (ans != "no")
      {
	try
	  {
	    //a.the user will specify which vertex     
	    cout << "Please enter a vertex to display it's degree: ";
	    cin >> vertex;
    
	    //b.findOutDegree of the vertex and display the result
	    degree = table.findOutDegree(vertex);
	    cout << degree << endl;
	  }//end of try

             //c.catch exception but do not exit
             catch(dgraph::BadVertex)
             {
                 cerr << "ERROR: Vertex not found" << endl;
             }
	      do{   
              cout << "Do you want to find another vertex's degree?"
                   << "\nIf yes enter yes. If no enter no: ";
              cin >> ans; 
                }while(ans != "yes" && ans != "no");
  
       }  //end of while
    
 do{
    cout << "Do you want to find a vertex's Adjacency?" << endl
	 << "If yes enter yes. If no enter no: ";
    cin >> ans;
   }while(ans != "yes" && ans != "no");

//while (the user does not want to stop)

  while(ans != "no")
  {
     try{
      //    a.the user will specify which vertex
	cout << "Please enter a vertex to display Adjacent Ones: ";
	cin >> vertex;
      //    b.findAdjacency of the vertex and display the result (see Hint)
      l1 = table.findAdjacency(vertex);    
      l1.displayAll();
        }//end of try
     //c.catch exception but do not exit
     catch(dgraph::BadVertex)
       {
	 cerr << "ERROR: Vertex not found" << endl;
       }
     
         do{   
            cout << "Do you want to find another vertex's Adjacency?"
                 << "\nIf yes enter yes. If no enter no: ";
            cin >> ans; 
           }while(ans != "yes" && ans != "no");
   }//end of while 
return 0;
}//end of main

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

l1.diplayAll();//correct
*/
