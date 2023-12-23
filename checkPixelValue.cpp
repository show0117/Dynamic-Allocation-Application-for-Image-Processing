#include <iostream>
#include <string>
#include "constants.h"
#include "checkPixelValue.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This function is used to check if an integer from a ppm
// file is in the valid range of color.  

bool checkPixelValue(int pixelValue){
  if (pixelValue < MIN_COLOR_VALUE || pixelValue > MAX_COLOR_VALUE){
    return FAILURE_PROCESS;
  }
  else {
    return SUCCESS_PROCESS;
  }
}