#include <iostream>
#include <string>
#include "chooseColor.h"
#include "constants.h"
#include "checkCin.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This function is used to show the color menu.

// Show different reminder according to different tasks.
int chooseColor(int taskNum){
  int colorNum;
  cout << "1. Red" << endl;
  cout << "2. Green" << endl;
  cout << "3. Blue" << endl;
  cout << "4. Black" << endl;
  cout << "5. White" << endl;
  if (taskNum == ANNOTATING_IMAGE_WITH_RECTANGLE){
    cout << "Enter int for rectangle color: ";
  }
  else if (taskNum == ANNOTATING_IMAGE_WITH_PATTERN_FROM_FILE){
    cout << "Enter int for pattern color: ";
  }
  else if (taskNum == INSERTING_ANOTHER_IMAGE){
    cout << "Enter int for transparecy color: ";
  }
  cin >> colorNum;
  // Error checking if input number is not valid.
  if (!checkCin() ||
     (colorNum != RED_NUM && colorNum != GREEN_NUM &&
      colorNum != BLUE_NUM && colorNum != BLACK_NUM &&
      colorNum != WHITE_NUM)){
    cout << "Invalid input!" << endl;
    // Return invalid color number to notify the program
    return INVALID_COLOR;
  }
  else {
    return colorNum;
  }
}
