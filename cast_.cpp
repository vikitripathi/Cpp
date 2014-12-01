#include <stdio.h>

main()
{
   int sum = 17, count = 5;
   double mean;

   mean = (double) sum / count;
   /*
   It should be noted here that the cast operator has precedence over division, so the value of sum is first converted to type 
   double and finally it gets divided by count yielding a double value.
   Type conversions can be implicit which is performed by the compiler automatically, 
   or it can be specified explicitly through the use of the cast operator.
    */
   printf("Value of mean : %f\n", mean );

}