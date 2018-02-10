//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet
//DO not forget to Tab on each line

//=========================================================
//HW#: HW3P2 slist
//Your name: Edgar Cruz
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"
/*
PURPOSE of the program: To check and see if our slist works properly.
                        To test the new functions(search and replace).
                        Tests to see if inheritance was done correctly.
ALGORITHM: Create an object (slist L). Make a variable foundPos to hold 
           the found position. Make a variable counter to display the 
           test line number. Call addFront, addRear, displayAll, search, 
           and replace.
*/
int main()
{ slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number
try
  {
    //  1)add to front once (element 4)
    cout << counter << ". add to front once (element 4)." << endl; counter++;
    L.addFront(4);

    //  2)add to rear 3 times (elements 6,7,8)
    cout << counter << ". add to rear 3 times (elements 6,7,8)" << endl; counter++;
    L.addRear(6);
    L.addRear(7);
    L.addRear(8);

    //  3)displayAll    - 4 6 7 8
    cout << counter << ". displayAll " << endl; counter++;
    L.displayAll();

    //  4)search for 6, report the result  - found in pos 2
    cout << counter << ". search for 6, report the result" << endl; counter++;
     foundPos = L.search(6);//foundPos is a holder for the position 
                          //the num was found in.
    if (foundPos == 0)//if foundPos the position is 0 then the number wasn't found.
      cout << "The number was not found in the linked list" << endl;
    else //the number was found.
      cout << "found in pos " << foundPos << endl;

    //  5)replace the 6 with 0 using the search result
    cout << counter << ". replace the 6 with 0 using the search result"<< endl; counter++;
    L.replace(0, foundPos);

    //  6)search for 8 and report the result . found in pos 4
    cout << counter << ". search for 8 and report the result." << endl; counter++;
    
    foundPos = L.search(8);//foundPos is a holder for the position the num was found in.
    if (foundPos == 0)//if foundPos is 0 then the number was not found.
      cout << "The number was not found in the linked list" << endl;
    else //the number was found.
      cout << "found in pos " << foundPos << endl;


    //  7)replace the 8 with 2 using the search result
    cout << counter << ". replace the 8 with 2 using the search result" << endl; counter++;
    L.replace(2, foundPos);

    //  8)displayAll                       - 4 0 7 2
    cout << counter << ". displayAll "  << endl; counter++;
    L.displayAll();

    //  9)search for 5 and report the result   - not found
    cout << counter << ". search for 5 and report the result " << endl; counter++;
    foundPos = L.search(5);//foundPos is a holder for the position the num was found in.
    if(foundPos == 0)//if foundPos is 0 then the number was not found
      cout << "not found" << endl;
    else //The number was found
      cout << "The number was found in " << foundPos << endl;
 
    // 10) replace postion 7 with 10
    cout << counter << ". replace position 7 with 10" << endl; counter++;
    L.replace(10, 7);
    }//end of try
 catch(llist::OutOfRange)
    { cerr << "ERROR: Bad position was given" << endl;}

}//end of program
