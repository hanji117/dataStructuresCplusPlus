//=========================================================                   
//HW#: HW2P2 combine                                  
//Your name: Edgar Cruz                                                        
//Complier:  g++                                                               
//File type: client program                                                    
//=========================================================
#include <iostream>
#include <vector>
using namespace std;

//prototype
void combine(vector <int>  L1,  vector <int>  L2, vector <int> & L3);

/*
PURPOSE OF THE PROGRAM: To combine the elements from vector L1 
                        and vector L2 to produce the sorted 
                        vector L3.
*/

/*
ALGORITHM: Declare 3 integer vectors L1, L2, and L3. Declare integer 
           variables num, elem, and num2. Prompt the user.
           Store the user's input into num (num will receive
           the number of elements the user wants to have in
           each vector. Create a for loop so the user can enter 
           the numbers they want to have in the 1st vector 
           (in ascending order).Skip a line. Create 
           another for loop to fill the 2nd vector with 
           another set of ascending numbers. Call 
           the combine function to combine the two 
           vectors into one vector. Display the elements 
           from the new vector. The elements will be in ascending order.
*/
int main()
{
  vector <int> L1;
  vector <int> L2;
  vector <int> L3;
  int num, elem, num2;

  cout << "How many elements would you like to enter: ";
  cin >> num;
  for(int i = 0; i < num; i++)
  {
    cout << "Enter integer in increasing order: ";
    cin >> elem; 
    L1.push_back(elem);
  }
  cout << endl;

  for(int a = 0; a < num; a++)
  {
    cout << "Enter different numbers in increasing order: ";
    cin >> num2;
    L2.push_back(num2);
 
  }

 combine(L1, L2, L3);

 cout << "The result is ";

 for (int b = 0; b < L3.size(); b++)
   cout << L3[b];

 cout << endl;
  return 0;
}

/*
PURPOSE: To combine the elements from two vectors into one vector.
PARAMETER: vector L1 of type integer, vector L2 of type integer, 
           vector L3 of type integer.
ALGORITHM: Declare two integer variables (iL1 and iL2) and set them 
           equal to 0. They're the indexes of vectors L1 and L2.
           Declare two integer variables (count and count2) and 
           set them equal to 0. They're counters. While count is 
           less than the size of the 1st vector and count2 is 
           less than the the size of the 2nd vector go inside 
           of the while loop. If the 1st vector's index contains a 
           smaller number than the 2nd vector's index go inside and 
           cout comparison, push the 1st vector's number from that 
           index into the 3rd vector, increment the 1st vectors 
           index number,and increment count; else cout comparison
           push the 2nd vectors element at that index into the 3rd 
           vector, increment the 2nd vector's index, and increment
           count2. If count is less than the 1st vector's size
           cout the message. While count is less than the 1st vector's
           size push the remaining element(s) from the 1st vector into 
           the 3rd vector and increment count.
           If count2 is less than the 2nd vector's size cout 
           the message. While count2 is less than the 2nd vector's size
           push the remaining element(s) from the 2nd vector into the 
           3rd vector and increment count2.
 */
void combine(vector <int>  L1,  vector <int>  L2, vector <int> & L3) 
{
 int iL1 = 0;//index for L1
 int iL2 = 0;//index for L2


 int count = 0;
 int count2 = 0;

 while(count < L1.size() && count2 < L2.size())
 {
   if (L1[iL1] < L2[iL2])//if the 1st vector's index contains a smaller number
   //than the 2nd vector's index go inside.
   {
     cout << "comparison" << endl; //a comparison was done
     L3.push_back(L1[iL1]); //The 3rd vector gets the lower num
     iL1 = iL1 + 1;//go to the next index in the 1st vector
     count++;
   }

   else// the 1st vector's index at iL1 was bigger than the 2nd vector's num 
     //at iL2.
   {
     cout << "comparison" << endl; 
     L3.push_back(L2[iL2]);//the 3rd vector gets the lower num
     iL2 = iL2 +1;
     count2++;
   }
 }

 if (count < L1.size())
    cout << "The rest of the first one goes down" <<endl;  
   
 while (count < L1.size())
 {
   L3.push_back(L1[count]);
   count++;
 } 

 if (count2 < L2.size())
   cout << "The rest of the second one goes down" <<endl;

 while (count2 < L2.size())
 {
     L3.push_back(L2[count2]);
     count2++;
 }


 
}
