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

//Purpose of the program: To display 25 strings of A B and C in a particular
//                        patterned form.
//Algorithm: 3 add functions outside of the while loop. Then a
//           while loop with 1 remove and 3 add functions inside. 
//           catch is inside of the while loop too (when the queue
//           is full an error is thrown and catch catches it).
int main()
{
  queue myQueue; // myQueue is the queue object 
  el_t elem = "A";//el_t is a string (from queue.h)

  myQueue.add(elem);
    elem = "B";
  myQueue.add(elem);
  elem = "C";
  myQueue.add(elem);
  
  while(!myQueue.isEmpty())// loop -- indefinitely
  {
      try
      {
	myQueue.remove(elem);//remove parameter pass by ref
        cout << elem << endl;

       	el_t newElem = elem + "A"; // newElem gets the result of elem + A. 
	myQueue.add (newElem);      //add function is not pass by ref
	el_t newElem2 = elem + "B";//newElem2 gets the result of elem + B.
	myQueue.add(newElem2);
	el_t newElem3 = elem + "C";//newElem3 gets the result of elem + C.
	myQueue.add(newElem3);

      }//this closes try

      catch (queue::Overflow)
      {
	cerr << "Cannot add" << endl;
	exit(1);
      }
  }//end of while
  return 0;
}

