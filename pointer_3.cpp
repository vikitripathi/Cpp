#include <iostream>

using namespace std;
const int MAX = 3;

int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;

   // let us have array address in pointer.
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;

      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;

      // point to the next location
      ptr++;//increase pf +4 in address location as integer is of size 4 byte
   }
   return 0;
}
/*
It is always a good practice to assign the pointer NULL to a pointer variable in case you do not have exact address
to be assigned. This is done at the time of variable declaration. A pointer that is assigned NULL is called a null pointer.
 */

// int  *ptr = NULL;
