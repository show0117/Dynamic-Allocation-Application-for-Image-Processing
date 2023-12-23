#include <iostream>
#include <string>
#include <sstream>
#include "constants.h"
#include "ColorClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class is used to for color manipulation. Such as 
// setting to a specific color or getting current color pixel numbers.  

ColorClass::ColorClass(){
  valueRed = INITIAL_COLOR_VALUE;
  valueGreen = INITIAL_COLOR_VALUE;
  valueBlue = INITIAL_COLOR_VALUE;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue){
  valueRed = inRed;
  valueGreen = inGreen;
  valueBlue = inBlue;
}

void ColorClass::setToBlack(){
  valueRed =  MIN_COLOR_VALUE;
  valueGreen = MIN_COLOR_VALUE;
  valueBlue = MIN_COLOR_VALUE;
}

void ColorClass::setToRed(){
  valueRed =  MAX_COLOR_VALUE;
  valueGreen = MIN_COLOR_VALUE;
  valueBlue = MIN_COLOR_VALUE;
}

void ColorClass::setToGreen(){
  valueRed =  MIN_COLOR_VALUE;
  valueGreen = MAX_COLOR_VALUE;
  valueBlue = MIN_COLOR_VALUE;
}

void ColorClass::setToBlue(){
  valueRed =  MIN_COLOR_VALUE;
  valueGreen = MIN_COLOR_VALUE;
  valueBlue = MAX_COLOR_VALUE;
}

void ColorClass::setToWhite(){
  valueRed =  MAX_COLOR_VALUE;
  valueGreen = MAX_COLOR_VALUE;
  valueBlue = MAX_COLOR_VALUE;
}

void ColorClass::setTo(int inRed, int inGreen, int inBlue){
  // set the values of colors
  valueRed = inRed;
  valueGreen = inGreen;
  valueBlue = inBlue;
}

void ColorClass::setTo(ColorClass &inColor){
  // Using another ColorClass to set colors
  valueRed = inColor.valueRed;
  valueGreen = inColor.valueGreen;
  valueBlue = inColor.valueBlue;
}

string ColorClass::printComponentValues(){
  ostringstream fnameStream;
  fnameStream << valueRed << " " << valueGreen
              << " " << valueBlue << " ";
  return fnameStream.str();
}