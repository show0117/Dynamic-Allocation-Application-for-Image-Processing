#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "checkPatternValue.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "PatternClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class is used to define a pattern image. User can initialize
// it with their own file and doing additional manipulation.

PatternClass::PatternClass(){
  upperLeftLoc.setRow(DEFAULT_ROW);
  upperLeftLoc.setCol(DEFAULT_COL);
  lowerRightLoc.setRow(DEFAULT_ROW);
  lowerRightLoc.setCol(DEFAULT_COL);
  patternColor.setToBlack();

  imageWidth = DEFAULT_COL;
  imageHeight = DEFAULT_ROW;

  patternPointer = 0;
}
 
void PatternClass::setLoc(int numRow, int numCol){
  upperLeftLoc.setRow(numRow);
  upperLeftLoc.setCol(numCol);
  lowerRightLoc.setRow(numRow + imageHeight);
  lowerRightLoc.setCol(numCol + imageWidth);
}

bool PatternClass::initializeTo(string fileName){
  ifstream inFile;
  // This end value is used to detect is the end value is an expected value
  string endValue;
  inFile.open(fileName.c_str());
  
  // Initialize the pattern image through set by step error checking
  if (inFile.fail()){
    cout << "Image can't be loaded!" << endl;
    return FAILURE_PROCESS;
  }
  inFile >> imageWidth;

  if (inFile.fail()){
    cout << "Error found when trying to read pattern width number "
         << "- unexpected word is loaded." << endl;
    return FAILURE_PROCESS;
  }
  else if (imageWidth <= MIN_COL){
    cout << "Error found when trying to read pattern width number "
         << "- expected positive integer but found "
         << imageWidth << endl;
    return FAILURE_PROCESS;
  }
  inFile >> imageHeight;

  if (inFile.fail()){
    cout << "Error found when trying to read pattern height number "
         << "- unexpected word is loaded." << endl;
    return FAILURE_PROCESS;
  }
  else if (imageHeight <= MIN_ROW){
    cout << "Error found when trying to read pattern width number "
         << "- expected positive integer but found "
         << imageWidth << endl;
    return FAILURE_PROCESS;
  }
  patternPointer = new int*[imageHeight];

  for (int i = 0; i < imageHeight; i++){
    patternPointer[i] = new int[imageWidth];
  }
  for (int i = 0; i < imageHeight; i++){
    for (int j = 0; j < imageWidth; j++){
      int patternValue;
      inFile >> patternValue;
      if (inFile.fail()){
        cout << "Error found when trying to read pattern numbers " 
             << "- file imcomplete or unexpected value loaded." << endl;
        return FAILURE_PROCESS;
      } 
      else if (!checkPatternValue(patternValue)){
        cout << "Error found when trying to read pattern value "
             << "- expected value of "
             <<  PATTERN_TRANSPARENCY << " and " << PATTERN_COLOR << endl;
        return FAILURE_PROCESS;
      }
      else{
        patternPointer[i][j] = patternValue;
      }
    }
  }
  inFile >> endValue;

  // Check if the end value is in our expectation to know if the image size
  // fits the height and width.  
  if (endValue != ""){
    cout << "The pattern size doesn't match its height and width!" << endl;
    return FAILURE_PROCESS;
  }
  return SUCCESS_PROCESS;
}
 
void PatternClass::setPatternColor(int colorNum){
  if (colorNum == RED_NUM){
    patternColor.setToRed();
  }
  else if (colorNum == GREEN_NUM){
    patternColor.setToGreen();
  }
  else if (colorNum == BLUE_NUM){
    patternColor.setToBlue();
  }
  else if (colorNum == BLACK_NUM){
    patternColor.setToBlack();
  }
  else if (colorNum == WHITE_NUM){
    patternColor.setToWhite();
  }
}

RowColumnClass PatternClass::getUpperLeftLoc(){
  return upperLeftLoc;
}
RowColumnClass PatternClass::getLowerRightLoc(){
  return lowerRightLoc;
}
    

ColorClass PatternClass::getPatternColor(){
  return patternColor;
}

int **PatternClass::getPatternPointer(){
  return patternPointer;
}