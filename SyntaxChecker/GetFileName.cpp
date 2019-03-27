//implementation

#include "GetFileName.h"
#include <iostream>

using namespace std;

GetFileName::GetFileName() //default constructor
{}

GetFileName::GetFileName(int num)
{
    nameNum = num;
}

GetFileName::~GetFileName()//destructor
{
  delete []fileArray; // https://www.geeksforgeeks.org/destructors-c/
}

string GetFileName::getName()
{

  cout << "What is the name of the txt file you wish to check?" << endl;
  cin >> theName;
  return theName;

}
