#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line(void);  // This is the constructor (can be parameterized)
      ~Line();  // This is the destructor: declaration
 /*
 A destructor is a special member function of a class that is executed whenever an object of it's class goes out of scope or
  whenever the delete expression is applied to a pointer to the object of that class.
  */

   private:
      double length;
};
 
// Member functions definitions including constructor
Line::Line(void) //use of the operator
{
    cout << "Object is being created" << endl;
}

Line::~Line(){
  cout << "Object is being deleted!!!!" << endl;
}
void Line::setLength( double len )
{
    length = len;
}
 
double Line::getLength( void )
{
    return length;
}
// Main function for the program
int main( )
{
   Line line;
 
   // set line length
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   return 0;
}