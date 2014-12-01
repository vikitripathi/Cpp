#include <iostream>
#include <ctime>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

// function to generate and retrun random numbers. and
// to return a single-dimension array from a function
int * getRandom( )
{
  static int  r[10];

  // set the seed
  srand( (unsigned)time( NULL ) );//you  can fix the seed to have same random no returned!!!
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }

  return r;
}

// main function to call above defined function.
int main ()
{
   // a pointer to an int.
   int *p;

   p = getRandom();
   for ( int i = 0; i < 10; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }

   return 0;
}
/*
C++ does not allow to return an entire array as an 
argument to a function. However, you can return a pointer to an array by specifying the array's name without an index.
 */

/*
C++ does not advocate to return the address of a local variable to outside of the 
function so you would have to define the local variable as static variable.
 */

/*
check more about the pointer and function return !!!
 */