#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
 
// function declaration:
double getAverage(int arr[], int size);
//double getAverage(int *arr,int size);  understand the relation b/w pointer and array!!!

int main ()
{
   // an int array with 5 elements.
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;

   // pass pointer to the array as an argument.
   avg = getAverage( balance, 5 ) ;
 
   // output the returned value 
   cout << "Average value is: " << avg << endl; 
    
   return 0;
}

double getAverage(int arr[], int size)
{
  int    i, sum = 0;       
  double avg;          

  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
   }

  avg = double(sum) / size;

  return avg;
}

/*
C++ does not allow to pass an entire array as an argument to a function. However, You can pass a pointer to an array 
by specifying the array's name without an index.
 */

/*
An array name is a constant pointer to the first element of the array. Therefore, in the declaration:

double balance[50];

balance is a pointer to &balance[0], which is the address of the first element of the array balance


 */