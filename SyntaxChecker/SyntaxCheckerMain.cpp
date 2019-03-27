//#include "GenStack.h"
#include "SyntaxChecker.h"
#include "GetFileName.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
  string repeat = "no";
  SyntaxChecker one;
  GetFileName two;

  do
  {

    one.reading(two.getName());
    cout << "Do you want to check another file or recheck the fixed file? (yes or no)" << endl;
    cin >> repeat;
  }

  while(repeat == "yes" || repeat == "Yes");

  return 0;
}
