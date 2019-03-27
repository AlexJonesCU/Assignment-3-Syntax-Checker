//header - user defined class
#include <iostream>

using namespace std;


class GetFileName
{
  public:
    //constructors and destructors
    GetFileName(); //constructor
    GetFileName(int num); //overloaded constructor
    ~GetFileName(); //destructor

    //functions
    string getName();


    //local variables
    string theName;
    int nameNum;

    //array to store data in stack
    char *fileArray; //this makes a pointer - declaring a pointer to a char
};
