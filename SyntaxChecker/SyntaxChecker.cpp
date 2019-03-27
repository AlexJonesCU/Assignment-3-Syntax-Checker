#include "GenStack.h"
#include "SyntaxChecker.h"
#include <iostream>
#include <string>
#include <fstream> //source: http://www.cplusplus.com/doc/tutorial/files/

using namespace std;

GenStack s(100);

SyntaxChecker::SyntaxChecker()
{
  GenStack s(100);
}

SyntaxChecker::SyntaxChecker(int num)
{

  GenStack s(num);
}
SyntaxChecker::~SyntaxChecker() //not used for this program but could be utilized
{}


void SyntaxChecker::reading(string fileName)
{
  isOK = true;
  lineNumber = 0;
  string line;

  ifstream readFile (fileName);
  if(readFile.is_open())
  {
    while (getline (readFile, line)) //http://www.cplusplus.com/doc/tutorial/files/
    {
      lineNumber++;
      for(int i = 0; i < line.length(); i++)
      {
        if(line.at(i) == '{' || line.at(i) == '(' || line.at(i) == '[') //if current char is an opening delimeter
        {
          s.push(line.at(i)); //puts a "starting" delimiter on a stack
        }
        else if (line.at(i) == '}' || line.at(i) == ')' || line.at(i) == ']') //if current char is a closing delimeter
        {
          if (s.isEmpty())//closing should not come before there is an opeing counter part
          {
            isOK = false;
            cout << "Delimiter Error with " << line.at(i) << " at line: " << lineNumber << endl;
            break;
            //delimiterCheck();
          }
          else if (line.at(i) == '}' && s.peek() != '{') //if stack is not empty, but char does not equal the correct delimeter, retrun false
          {
            isOK = false;
            cout << "Delimiter Error with } at line: " << lineNumber << endl;
            break;
          }
          else if (line.at(i) == ')' && s.peek() != '(')
          {
            isOK = false;
            cout << "Delimiter Error with ) at line: " << lineNumber << endl;
            break;
          }
          else if (line.at(i) == ']' && s.peek() != '[')
          {
            isOK = false;
            cout << "Delimiter Error with ] at line: " << lineNumber << endl;
            break;
          }
          else //if true
          {
            s.pop(); //if the closing delimiter is equal to its opening counterpart on the stack, then pop the opening off the stack
          }
        }
      }
      if (s.isEmpty()) //if nothing is left stored on the stack
      {
        isOK = true; //every symbol must have matched
      }
      else if (!s.isEmpty()) //if there are delimiters on the stack, then there are extra delimiters that do not have counterparts
      {
        isOK = false;
        cout << "Delimiter Error with " << s.peek() << " at line: " << lineNumber << endl; //any delimiters that were never matched
        break;
      }
    }

    readFile.close();
    delimiterCheck();

  }
}

void SyntaxChecker::delimiterCheck()
{
  if (isOK == true)
    cout << "The delimeter syntax checker is complete and there are no delimeter errors" << endl;
}
