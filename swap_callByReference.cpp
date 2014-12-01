#include <iostream>
using namespace std;

// function declaration
void swap(int &x, int &y);

int main ()
{
   // local variable declaration:
   int a = 100;
   int b = 200;
 
   cout << "Before swap, value of a :" << a << endl;
   cout << "Before swap, value of b :" << b << endl;

   /* calling a function to swap the values using variable reference.*/
   swap(a, b);

   cout << "After swap, value of a :" << a << endl;
   cout << "After swap, value of b :" << b << endl;
 
   return 0;
}

// function definition to swap the values.
void swap(int &x, int &y)
{
   int temp;
   temp = x; /* save the value at address x */
   x = y;    /* put y into x */
   y = temp; /* put x into y */
  
   return;
}

/*
The call by reference method of passing arguments to a function copies the reference of an argument into the formal parameter.
Inside the function, the reference is used to access the actual argument used in the call. This means that changes made to the 
parameter affect the passed argument.
 */

/*
References are basically an alias of the referenced variable !!!
 */

/*
int a[3][4] = {  
 {0, 1, 2, 3} ,  
 {4, 5, 6, 7} ,   
 {8, 9, 10, 11}  
};
*/