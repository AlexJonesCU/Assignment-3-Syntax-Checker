//header - user defined class
#include <iostream>

using namespace std;

//template <typename E>
class GenStack
{
  public:
    //constructors and destructors
    GenStack(); //constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    //functions
    void push(char d); //push
    char pop();
    char peek(); //AKA top()


    //helper functions
    bool isFull();
    bool isEmpty();

    //local variables
    int size;
    int top;

    //array to store data in stack
    char *myArray; //this makes a pointer - declaring a pointer to a char
};
