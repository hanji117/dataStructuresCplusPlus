//INSTRUCTION                                                                   
//Look for ** to complete this program                                          
//The string output should match my hw1queueDemo.out                            
//except for the trace messages                                                 

//=========================================================                     
//HW#: HW1P1 queue                                                              
//Your name: Edgar Cruz                                                         
//Complier:  g++                                                                
//File type: client program                                                     
//===========================================================                   

using namespace std;

#include <cstdlib>
#include <iostream>
#include <string>
#include "queue.h"

//Purpose of the program: To display 25 strings of A B and C in a patterned for\
m.                                                                              
//Algorithm: 3 add functions, 1 getSize, 1 getFront, 1 getRear, and 1           
//           displayAll function outside of the while loop. Then a              
//           While loop with 1 remove, 3 add, 1 getSize, 1 getFront, 1 getRear,
//           and 1 displayAll function inside.                                  
int main()
{
  queue myQueue; // myQueue is the queue object                                 
  el_t elem = "A";//el_t is a string (from queue.h)                             

  myQueue.add(elem);
  elem = "B";
  myQueue.add(elem);
  elem = "C";
  myQueue.add(elem);

  cout << "Count = " << myQueue.getSize();
  cout << " Front = " << myQueue.getFront();
  cout << " Rear = " << myQueue.getRear() << endl;
  cout << "[ ";
  myQueue.displayAll();//void function                                          
  cout << "]" << endl;

  while(!myQueue.isEmpty())// loop -- indefinitely                                    
    {
      try
	{
	  myQueue.remove(elem);//remove parameter pass by ref                           
	  cout << elem << endl;
	  el_t newElem = elem + "A";
	  myQueue.add (newElem);      //add function is not pass by ref                 
	  el_t newElem2 = elem + "B";
	  myQueue.add(newElem2);
	  el_t newElem3 = elem + "C";
	  myQueue.add(newElem3);
	  cout << "Count = " << myQueue.getSize();
	  cout << " Front = " << myQueue.getFront();
	  cout << " Rear = " << myQueue.getRear() << endl;
	  cout << "[ ";
	  myQueue.displayAll();//void function                                          
	  cout << "]" << endl;
	}//this closes try                                                              

      catch (queue::Overflow)
	{
	  cerr << "Cannot add" << endl;
	  exit(1);
	}
    }//end of while                                                                     
  return 0;
}

