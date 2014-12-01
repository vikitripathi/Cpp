/*
Most of the C or even Unix function calls return -1 or NULL in case of any error and sets an error code errno is set which is global 
variable and indicates an error occurred during any function call
 */

#include <stdio.h>
#include <stdlib.h>

main()
{
   int dividend = 20;
   int divisor = 0;
   int quotient;
 
   if( divisor == 0){
      fprintf(stderr, "Division by zero! Exiting...\n");
      exit(-1);//return -1
   }
   quotient = dividend / divisor;
   fprintf(stderr, "Value of quotient : %d\n", quotient );

   exit(0);//return 0;
}
/*
It is a common practice to exit with a value of EXIT_SUCCESS in
 case of programming is coming out after a successful operation. Here, EXIT_SUCCESS is a macro and it is defined as 0.
 */