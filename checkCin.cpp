#include <iostream>
#include "constants.h"
#include "checkCin.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This function is used to check if input values of user are 
// correct through different return value. If not, it will clear the 
// input of cin and return failure information.

bool checkCin(){
  if (cin.fail()){
    // Clear and drop to the next line if the input is invalid.
    cin.clear();
    cin.ignore(1000,'\n');
    return FAILURE_PROCESS;
  }
  else {
    return SUCCESS_PROCESS;
  }
}