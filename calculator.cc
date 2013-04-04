// Complex Number Calculator
// Mac Clayton, 2012
// ECE 3090 Lab 1


#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "complex.h"
#include "string-parse.h"

using namespace std;

int main()
{
// Add any variables you might need here
    Complex left;
    Complex right;
  while(true)
    {
      string st = GetStringFromKeyboard(); // Get the  next input line
      StringVec_t operands; // Variable length array of operands
      CharVec_t   delims;   // Variable length array of delimiters
      int count = StringParse(st, "+-*/", operands, delims);
      if (count == 0) break; // All done        
        //If there's only one complex number entered:
        if (operands[0].empty()) {
            right = operands[1];
        }else if (delims[0] == 0) {
            left = operands[0];
        }else {
            left = operands[0];
            right = operands[1];
        }
        
        //Do the math:
        if (delims[0] == '+') {
            left = left + right;
        } else if (delims[0] == '-') {
            left = left - right;
        } else if (delims[0] == '*') {
            left = left * right;
        } else if (delims[0] == '/') {
            left = left / right;
        }
        
        //Print out the value in Left:
        left.Print();

    }
      
  return 0;  // Successful completion of main()
}


