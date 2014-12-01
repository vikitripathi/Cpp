#include<cstdio>
#include<iostream> //preprocessor like #define  to declare constants
using namespace std;
int main()
{
cout<<"\nHello World,\n The Parameter is \n\n"<<endl;
cout<<"\nHello World,\nWelcome to my first C ++ program on Ubuntu Linux\n\n"<<endl;
int m;
cout<<m<<endl;//uninitialised variables treatment in cpp
cout<<"-------------"<<endl;
printf("File :%s\n", __FILE__ );//ANSI C defines a number of macros
printf("Date :%s\n", __DATE__ );//ANSI C defines a number of macros
printf("Time :%s\n", __TIME__ );//ANSI C defines a number of macros
printf("Line :%d\n", __LINE__ );//ANSI C defines a number of macros
printf("ANSI :%d\n", __STDC__ );//ANSI C defines a number of macros
return(0);
}
/*
#define MAX_ARRAY_LENGTH 20

This directive tells the CPP to replace instances of MAX_ARRAY_LENGTH with 20. Use #define for constants to increase readability.

#include <stdio.h>
#include "myheader.h"

These directives tell the CPP to get stdio.h from System Libraries and add the text to the current source file.
 The next line tells CPP to get myheader.h from the local directory and add the content to the current source file.
 */

/*
The C Preprocessor is not part of the compiler, but is a separate step in the compilation process. In simplistic terms,
 a C Preprocessor is just a text substitution tool and they instruct compiler to do required pre-processing before actual 
 compilation. We'll refer to the C Preprocessor as the CPP.

All preprocessor commands begin with a pound symbol (#). It must be the first nonblank character, and for readability, 
a preprocessor directive should begin in first column. 
 */