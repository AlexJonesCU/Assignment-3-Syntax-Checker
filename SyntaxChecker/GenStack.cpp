//implementation

#include "GenStack.h"
#include <iostream>

using namespace std;

GenStack::GenStack() //default constructor
{
  //initialization of default values
  myArray = new char[128]; //example for if there is no size given
      //with new- need a destructor to give back that memory
      //FOR NEW NEED A DESTRUCTOR
  size = 128;
  top = -1;
}

GenStack::GenStack(int maxSize)
{
  myArray = new char[maxSize]; //"new" allocating memory dynamically- on the heap so more permanent
  size = maxSize;
  top = -1; //it will be empty when created || top is like the counter
}

GenStack::~GenStack()//destructor
{
  delete []myArray; // https://www.geeksforgeeks.org/destructors-c/
}

void GenStack::push(char d)
{
  if (isFull())//if isFull() is true
  {
    cout << "top: " << top << endl;
    cout << "size: " << size << endl;
    cout << "Full" << endl;
  }
  else
  {
    myArray[++top] = d;
  }

}

char GenStack::pop()
{
  if(isEmpty()) //while isEmpty() is true
  {
    cout << "Error" << endl;
  }

  return myArray[top--];
}

char GenStack::peek()
{
  if (isEmpty()) //checks if empty
  {
    cout << "Error" << endl;
  }

  return myArray[top];
}

bool GenStack::isFull()
{
  return (top >= size - 1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}
