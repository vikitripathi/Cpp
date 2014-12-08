/*
Created by  : Abhishek Dutt
Organisation: IMG IIT-R Sre
 */

#include <iostream>
#include <ctime>
#include <stdio.h> /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
#include <cmath>

using namespace std;

// Returns a pointer to a newly created 2d array the array2D has size [height x width]

    int create2DArray(unsigned height, unsigned width)
    {
      srand(time(0));
      int** array2D = 0;
      array2D = new int*[height];
      int p=rand() % 5;
      return p;
    }

int main ()
{
  
  printf("Creating a 2D array2D\n");
      printf("\n");

      int height = 15;
      int width = 10;
      int my2DArray = create2DArray(height, width);
      printf("Array sized [%i,%i] created.\n\n", height, width);

      // print contents of the array2D
      printf("Array contents: \n");

      cout<<my2DArray<<endl;

         
      return 0;

}