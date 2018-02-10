//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assignment sheet

//=========================================================
//HW#: HW3P3 slist
//Your name: Edgar Cruz
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: This function simply tests the copy constructor of the slist class
//and adds 6 to the rear of copiedList and displays the list
//PARAMETER: list passed by value becomes copiedList
//ALGORITHM: cout "in copy test". call addRear with 6 passed in its parameter 
//           and call displayAll. cout "finished".
void CopyTest(slist copiedList)
{
  cout << "in copy test" << endl;
  copiedList.addRear(6);
  copiedList.displayAll();
  cout << "finished" << endl;
}

/*
PURPOSE of the Program: To test an overloaded operator (=) and a copy 
                        constrtuctor.
Algorithm/Design: Create 2 slist objects (L1 and L2). Create a variable 
                  called temp of type int to hold a removed element.
                  Create a variable called counter that will be used
		  to display the test line number. Call addFront, 
		  CopyTest, displayAll, and deleteRear.
*/ 
int main()
{
  slist L1, L2;//the linked lists.
  int temp;//to hold a removed element.
  int counter = 1;//used to display test line number.

 //1.Create a 5 element list with  1,2,3,4,5 (L1)
  cout << counter << ". Create a 5 element list with  1,2,3,4,5 (L1)" << endl;
  counter++;
  L1.addFront(5);
  L1.addFront(4);
  L1.addFront(3);
  L1.addFront(2);
  L1.addFront(1);

  //2.Pass the list to a client function called CopyTest to 
  //test your copy constructor.
  cout << counter<< ". Pass the list to a client function called CopyTest to test your copy constructor. "<< endl; counter++;
  CopyTest(L1);

  cout << "-- After copytest --- " << endl;
  //3.Display L1 (this should still be a 5 element list)
  cout << counter << ". Display L1 (this should still be a 5 element list)"  
       << endl; counter++;
  L1.displayAll();
  cout << "-- Testing operator overloading ---" << endl;

  //4.Do L1 = L1;
  cout << counter << ". Do L1 = L1" << endl; counter++;
  L1 = L1;

  //5.Display L1    (this should still be 1 2 3 4 5)
  cout << counter << ". Display L1 " << endl; counter++;
  L1.displayAll();

  //6.Create a 4 element list L2 with 7,8,9,10.
  cout << counter << ". Create a 4 element list L2 with 7, 8, 9, 10."<< endl; counter++;
  L2.addFront(10);
  L2.addFront(9);
  L2.addFront(8);
  L2.addFront(7);

  //7.Display L2
  cout << counter << ". Display L2 "<< endl; counter++;
  L2.displayAll();

  //8.Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << counter << ". Do L2 = L1;" << endl; counter++;
  L2 = L1;

  //9.Display L2.
  cout << counter << ". Display L2" << endl; counter++;
  L2.displayAll();

  //10.Remove a rear node from L1. (This should not affect L2).
  cout << counter << ". Remove a rear node from L1. (This should not affect L2)."
       << endl; counter++;
  L1.deleteRear(temp);

  //11.Display L1.   (L1 is 1,2,3,4)
  cout << counter << ". Display L1. "<< endl; counter++;
  L1.displayAll();

  //12.Display L1 again. (4 elements . just to make sure)
  cout << counter<< ". Display L1 again." << endl; counter++;
  L1.displayAll();

  //13.Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << counter << ". Display L2 again." << endl; counter++;
  L2.displayAll();

}//end of program

