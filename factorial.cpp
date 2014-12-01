#include <iostream>
#include <stdio.h>
using namespace std;
int factorial(unsigned int i)
{
   if(i <= 1)
   {
      return 1;
   }
   return i * factorial(i - 1);
}
int  main()
{
	int i;
	cout <<"enter  the no to find the factorial"<< endl;
    cin >> i;
    printf("Factorial of %d is %d\n", i, factorial(i));
    return 0;
}