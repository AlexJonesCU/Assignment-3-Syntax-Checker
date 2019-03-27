#include <iostream>
#include <string>


//#include "GenStack."

using namespace std;

class SyntaxChecker
{
  public:
    //constructors and destructors
    SyntaxChecker(); //constructor
    SyntaxChecker(int num); //overloaded constructor
    ~SyntaxChecker(); //destructor

    //functions

    void reading(string fileName);
  //  void check(string fileName);
    void delimiterCheck();


    //local variables
  
    int lineNumber;
    int errorLine;
    string deliminators;
    string fileString;
    bool isOK;
    //char charArray[100];

    //array to store data in stack
    char *checkerArray; //this makes a pointer - declaring a pointer to a char
};
