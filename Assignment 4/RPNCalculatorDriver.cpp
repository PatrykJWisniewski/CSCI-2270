/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  RPNCalculator RPNcalc;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
       string input;
       float result;
       cout << "#> ";

       getline(cin, input);

       if(isNumber(input))
       {
            RPNcalc.push(stof(input));
       }
       else if(input == "*" || input == "+")
       {
            RPNcalc.compute(input);
       }
       else if(input == "=")
       {
            //If the stack is empt...
            if(RPNcalc.isEmpty())
            {
                 std::cout << "No operands: Nothing to evaluate" << '\n';
                 return 0;
            }
            //If it is not empty...
            else
            {
                 //Pull the value from the head and remove it
                 result = RPNcalc.peek()->number;
                 RPNcalc.pop();
            }

            //If the stack is emepty after poping the last elemet...
            if(RPNcalc.isEmpty())
            {
                 std::cout << result << '\n';
                 return 0;
            }
            //If it is not empty then there are still uncomputed inputs in the stack
            else
            {
                 std::cout << "Invalid expression" << '\n';
                 return 0;
            }
       }
  }

  return 0;
}
