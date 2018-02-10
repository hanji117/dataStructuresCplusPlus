//==================================================
//HW#: HW2P1 binary search
//Your name: Edgar Cruz
//Compiler: g++
//File type: client program
//==================================================
#include <cmath>
#include <iostream>
using namespace std;

//prototype
int binarySearch(int L[], int x, int first, int last);

//PURPOSE OF THE PROGRAM: To search for a number
//                        in the hard coded list that the user input 
//                        and it will display either Element not found or 
//                        Found it in position 1 for example.

//ALGORITHM: Set up initial indices.Create a variable findthis. This will
//           store the number the user is searching for. Create an array
//           with 10 slots and hard code odd numbers 1 through 19.
//           Prompt the user. The user will input a value and it will be
//           stored in the variable findthis. Create a function called 
//           binarySearch with the array (myList), the user's input 
//           number (findthis), the first slot position (myfirst), and 
//           the last slot position (mylastnum) in the parameter. Create a 
//           variable resultloc of type int 
//           that will store the binarySearch functions returned
//           slot position that contains the number the user input. Add 1 
//           to resultloc to make it understandable for the user.
//           Store that value in a variable called userFriendlyresult. If
//           the element was not found -1 is returned. After adding 1 to 
//           this the returned index value from binarySearch is 0.
//           If the variable equals 0 cout "Element not found" else
//           cout "Found it in position" userFriendlyresult.
int main()
{
 int myfirst = 0;//set up initial indices
 int mylastnum = 9;
 int findthis; //store user input value
 int myList[10] = {1,3,5,7,9,11,13,15,17,19};
 cout << "What do you want to look for?" << endl;
 cin >> findthis;

 int resultloc =  binarySearch(myList,findthis, myfirst, mylastnum);
 int userFriendlyresult = resultloc +1;
 if (userFriendlyresult == 0)
   cout << "Element not found" << endl;
else
 cout << "Found it in position " << userFriendlyresult  << endl;
 
  return 0;
}
//PURPOSE: To search for the number the user input.
//PARAMATER: array L of type int, the user's input value x of type int,
//           the first slot position called first of type int, and the
//           last slot postion called last of type int.
//ALGORITHM: local variable middle that will store the middle index number
//           of the array. If input x mod 2 equals 0 return -1.
//           This means that x has a remainder of 0 and it's an even num. 
//           If the first index equals the last index and 
//           the user's input value x does not equal what is stored in the 
//           first slot of the array(or the last doesn't matter since 
//           they are the same index) return -1 (This means that the element
//           was not found). Else if x equals L[middle](middle contains the 
//           middle index of the array L) return middle. Else if x is less 
//           than L[middle] then last is assigned middle - 1. Else if 
//           x is greater than L[middle] then first is assigned middle + 1.
//           return BinarySearch(L,x,first, last) is a recursive call. 

int binarySearch(int L[], int x, int first, int last)
{
  //the function - note that floor means round down
  int middle = floor((first + last)/2);                                     
  
  if(x%2 == 0)//if input value is an even number
    return -1;//element was not found
//note that if first ==last, there is only one element left.
  else if (first == last && x != L[first])
    return -1;
  else if (x == L[middle])//Compare with the middle entry
    return middle;//found x at location middle
  else if (x < L[middle])
    last = middle - 1;//go to first half
  else if (x > L[middle])
    first = middle +1;//go to second half
  return binarySearch(L, x, first, last);//recursive call
}
