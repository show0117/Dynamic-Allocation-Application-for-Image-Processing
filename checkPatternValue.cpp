#include <iostream>
#include "constants.h"
#include "checkPatternValue.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This function is used to descriminate if an integer from a 
// pattern file is valid. 

bool checkPatternValue(int patternValue){
  if (patternValue != PATTERN_COLOR && patternValue != PATTERN_TRANSPARENCY){
    // If single value isn't color or transprency, return anomaly, vice
    // versa. 
    return FAILURE_PROCESS;
  }
  else {
    return SUCCESS_PROCESS;
  }
}