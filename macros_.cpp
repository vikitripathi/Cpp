#include <iostream>
#include <stdio.h>
#define  message_for(a, b) printf(#a " and " #b ": We love you!\n")//#a is stringize operator
     // \ is macro continuation operator 

    /*
    The token-pasting operator (##) within a macro definition combines two arguments. 
    It permits two separate tokens in the macro definition to be joined into a single token.
     */  
#define tokenpaster(n) printf ("token" #n " = %d", token##n)

#define square(x) ((x) * (x))


#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif

using namespace std;

int main(){
	int token34=40;
	tokenpaster(34);
	cout<<"\n"<<endl;
	cout<<message_for(1,2) << endl;
	cout<< MESSAGE<< endl;
	cout<<square(10)<< endl;
	return 0;
}