#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      double length;
      void setWidth( double wid );
      double getWidth( void );
 
   private:
      double width; //or defined default
};
 
// Member functions definitions
double Box::getWidth(void)
{
    return width ;
}
 
void Box::setWidth( double wid )
{
    width = wid;
}
 
// Main function for the program
int main( )
{
   Box box;
 
   // set box length without member function
   box.length = 10.0; // OK: because length is public
   cout << "Length of box : " << box.length <<endl;
 
   // set box width without member function
   // box.width = 10.0; // Error: because width is private
   box.setWidth(10.0);  // Use member function to set it. 
   //why use this design pattern ?? of getters and setters
   //it's not that data would be safe rather we can validate(process) the data while using getters and setters <<---
   cout << "Width of box : " << box.getWidth() <<endl;
 
   return 0;
}

/*
Practically, we define data in private section and related functions in public section 


A protected member variable or function is very similar to a private member but it provided 
one additional benefit that they can be accessed in child classes which are called derived classes.
 */



/*
use of getters and setter design paradigm->



There are actually many good reasons to consider using accessors rather than directly exposing fields of a class - beyond just the argument of encapsulation and making future changes easier.

Here are the some of the reasons I am aware of:

    Encapsulation of behavior associated with getting or setting the property - this allows additional functionality (like validation) to be added more easily later.
    Hiding the internal representation of the property while exposing a property using an alternative representation.
    Insulating your public interface from change - allowing the public interface to remain constant while the implementation changes without affecting existing consumers.
    Controlling the lifetime and memory management (disposal) semantics of the property - particularly important in non-managed memory environments (like C++ or Objective-C).
    Providing a debugging interception point for when a property changes at runtime - debugging when and where a property changed to a particular value can be quite difficult without this in some languages.
    Improved interoperability with libraries that are designed to operate against property getter/setters - Mocking, Serialization, and WPF come to mind.
    Allowing inheritors to change the semantics of how the property behaves and is exposed by overriding the getter/setter methods.
    Allowing the getter/setter to be passed around as lambda expressions rather than values.
    Getters and setters can allow different access levels - for example the get may be public, but the set could be protected.


 */