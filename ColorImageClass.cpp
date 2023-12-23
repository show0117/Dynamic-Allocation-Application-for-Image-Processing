#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "checkPixelValue.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class mainly for image manipulation. User can initialize
// it with their own image. Besides it includes three main functions: adding
// a rectangle on the image, adding special pattern on the image, or adding
// another image on the image. User can also set a variety of parameters
// such as image location, colors, or transpancy color to customize their
// own images.  

bool ColorImageClass::checkEdge(RowColumnClass &upperLeftLoc,
                                RowColumnClass &lowerRightLoc){
  int upperLeftRow = upperLeftLoc.getRow();
  int upperLeftCol = upperLeftLoc.getCol();
  int lowerRightRow = lowerRightLoc.getRow();
  int lowerRightCol = lowerRightLoc.getCol();
  // Check if upperLeftLoc or lowerRightLoc is out of bound
  if (upperLeftRow < MIN_ROW || upperLeftCol < MIN_COL ||
      lowerRightRow > imageHeight || lowerRightCol > imageWidth){
    // Return different bool values.
    return INVALID_LOCATION;
  }
  else {
    return VALID_LOCATION;
  }
}

// Default attributes
ColorImageClass::ColorImageClass(){
  imagePointer = 0;
  transparencyColor.setToWhite();
  imageMagicNumber = EXPECTED_PPM_MAGIC_NUMBER;
  imageWidth = DEFAULT_COL;
  imageHeight = DEFAULT_ROW;
  pixelMaxValue = INITIAL_COLOR_VALUE;
}

// Initialize the class with a ppm image file by file name.
bool ColorImageClass::initializeTo(string fileName){
  ifstream inFile;
  // This end value is used to detect is the end value is an expected value
  string endValue;
  // Error checking if the file name is fine.
  inFile.open(fileName.c_str());
  if (inFile.fail()){
    // Escape the function if there is something wrong.
    cout << "Image can't be loaded!" << endl;
    return FAILURE_PROCESS;
  }

  // Descriminate first number of the input file is it is
  // our expected number of ppm file. 
  inFile >> imageMagicNumber;
  if (inFile.fail()){
    cout << "Error found when trying to read magic number "
         << "- unexpected word is loaded." << endl;
    return FAILURE_PROCESS;
  }
  else if (imageMagicNumber != EXPECTED_PPM_MAGIC_NUMBER){
    cout << "Error found when trying to read magic number "
         << "- expected " << EXPECTED_PPM_MAGIC_NUMBER
         << " but found " << imageMagicNumber << endl;
    return FAILURE_PROCESS;
  }

  // Descriminate second and third number of the input file is it is
  // our expected number of ppm file.  
  inFile >> imageWidth;
  if (inFile.fail()){
    cout << "Error found when trying to read image width number "
         << "- unexpected word is loaded." << endl;
    return FAILURE_PROCESS;
  }
  else if (imageWidth <= MIN_COL){
    cout << "Error found when trying to read image width number "
         << "- expected positive integer but found "
         << imageWidth << endl;
    return FAILURE_PROCESS;
  }

  inFile >> imageHeight;
  if (inFile.fail()){
    cout << "Error found when trying to read image height number "
         << "- unexpected word is loaded." << endl;
    return FAILURE_PROCESS;
  }
  else if (imageHeight <= MIN_ROW){
    cout << "Error found when trying to read image width number "
         << "- expected positive integer but found "
         << imageWidth << endl;
    return FAILURE_PROCESS;
  }
  // check pixel anomaly
  inFile >> pixelMaxValue;
  if (inFile.fail()){
    cout << "Error found when trying to read max pixel number "
         << "- unexpected word is loaded." << endl;
    return FAILURE_PROCESS;
  }
  else if (pixelMaxValue < MIN_COLOR_VALUE || 
           pixelMaxValue > MAX_COLOR_VALUE){
    cout << "Error found when trying to read max pixel value "
         << "- expected positive integer betweem "
         <<  MIN_COLOR_VALUE << " and " << MAX_COLOR_VALUE << " but found "
         << imageHeight << endl;
    return FAILURE_PROCESS;
  }

  // Load each pixel of input image through pointer.
  imagePointer = new ColorClass*[imageHeight];
  for (int i = 0; i < imageHeight; i++){
    imagePointer[i] = new ColorClass[imageWidth];
  }
  for (int i = 0; i < imageHeight; i++){
    for (int j = 0; j < imageWidth; j++){
      int inRed; 
      int inGreen; 
      int inBlue;
      inFile >> inRed >> inGreen >> inBlue;
      // Error checking which prevent our program terminated accidentally.
      if (inFile.fail()){
        cout << "Error found when trying to read pixel numbers "
             << "- unexpected word is loaded or unmatched size" << endl;
        return FAILURE_PROCESS;
      }
      else if (!checkPixelValue(inRed) || !checkPixelValue(inGreen) || 
               !checkPixelValue(inBlue)){
        cout << "Error found when trying to read max pixel value "
             << "- expected positive integer betweem "
             <<  MIN_COLOR_VALUE << " and " << MAX_COLOR_VALUE << endl; 
        return FAILURE_PROCESS;
      }
      else{
        imagePointer[i][j].setTo(inRed, inGreen, inBlue);
      }
    }
  }
  inFile >> endValue;
  
  // Check if the end value is in our expectation to know if the image size
  // fits the height and width.
  if (endValue != ""){
    cout << "The image size doesn't match its height and width!" << endl;
    return FAILURE_PROCESS;
  }
  // Only when no anomaly happend this will return true value.
  return SUCCESS_PROCESS;
}

void ColorImageClass::setTransparencyColor(int colorNum){
  if (colorNum == RED_NUM){
    transparencyColor.setToRed();
  }
  else if (colorNum == GREEN_NUM){
    transparencyColor.setToGreen();
  }
  else if (colorNum == BLUE_NUM){
    transparencyColor.setToBlue();
  }
  else if (colorNum == BLACK_NUM){
    transparencyColor.setToBlack();
  }
  else if (colorNum == WHITE_NUM){
    transparencyColor.setToWhite();
  }
}

// Add rectangle on the main image
bool ColorImageClass::addRectangleOn(RectangleClass &recImage, 
                                     int fillOption){
  RowColumnClass recUpperLeftLoc = recImage.getUpperLeftLoc();
  RowColumnClass recLowerRightLoc = recImage.getLowerRightLoc();

  // Check if the two angle of rectangle is out of bound
  if (!checkEdge(recUpperLeftLoc, recLowerRightLoc)){
    cout << "Rectangle's edge is out of image's bound!" << endl;
    return FAILURE_PROCESS;
  }
  else {
    int startRow = recImage.getUpperLeftLoc().getRow();
    int startCol = recImage.getUpperLeftLoc().getCol();
    int endRow = recImage.getLowerRightLoc().getRow();
    int endCol = recImage.getLowerRightLoc().getCol();
    ColorClass recColor = recImage.getRecColor();
    
    // Draw filled rectangle ont main image
    if (fillOption == FILLING_RECTANGLE){
      for (int i = startRow; i <= endRow; i++){
        for (int j = startCol; j <= endCol; j++){
          imagePointer[i][j].setTo(recColor);
        }
      }
    }
    // Draw the four line ont main image for an unfilled rectangle
    else if (fillOption == NOT_FILLING_RECTANGLE){
      for (int i = startRow; i <= endRow; i++){
        imagePointer[i][startCol].setTo(recColor);
      }
      for (int i = startRow; i <= endRow; i++){
        imagePointer[i][endCol].setTo(recColor);
      }
      for (int j = startCol; j <= endCol; j++){
        imagePointer[startRow][j].setTo(recColor);
      }
      for (int j = startCol; j <= endCol; j++){
        imagePointer[endRow][j].setTo(recColor);
      }
    }
  }
  return SUCCESS_PROCESS;
}

// Adding pattern on the main image
bool ColorImageClass::addPatternOn(PatternClass &patternImage){
  RowColumnClass patternUpperLeftLoc = patternImage.getUpperLeftLoc();
  RowColumnClass patternLowerRightLoc = patternImage.getLowerRightLoc();

  if (!checkEdge(patternUpperLeftLoc, patternLowerRightLoc)){
    cout << "Pattern's edge is out of image's bound!" << endl;
    return FAILURE_PROCESS;
  }
  else {
    int startRow = patternImage.getUpperLeftLoc().getRow();
    int startCol = patternImage.getUpperLeftLoc().getCol();
    int endRow = patternImage.getLowerRightLoc().getRow();
    int endCol = patternImage.getLowerRightLoc().getCol();
    int **patternPointer = patternImage.getPatternPointer();
    ColorClass patternColor = patternImage.getPatternColor();

    for (int i = startRow; i < endRow; i++){
      for (int j = startCol; j < endCol; j++){
        // We use the arrtibute of Pattern class to descriminate
        // if the pixel should be modefied or not.
        if (patternPointer[i-startRow][j-startCol] == 1){
          imagePointer[i][j].setTo(patternColor);
        }
      }
    }
  }
  return SUCCESS_PROCESS;
}

// Adding image on the main image
bool ColorImageClass::addImageOn(ColorImageClass &newImage, 
                                 RowColumnClass &upperLeftLoc){
  RowColumnClass lowerRightLoc;
  int newImageHeight = newImage.getHeight();
  int newImageWidth = newImage.getWidth();
  lowerRightLoc.setRow(upperLeftLoc.getRow() + newImageHeight);
  lowerRightLoc.setCol(upperLeftLoc.getCol() + newImageWidth);
  
  // Check if the boundry is valid or not
  if (!checkEdge(upperLeftLoc, lowerRightLoc)){
    cout << "New image's edge is out of origin image's bound!" << endl;
    return FAILURE_PROCESS;
  }
  else {
    int startRow = upperLeftLoc.getRow();
    int startCol = upperLeftLoc.getCol();
    int endRow = lowerRightLoc.getRow();
    int endCol = lowerRightLoc.getCol();
    ColorClass **newImagePointer = newImage.getImagePointer();

    for (int i = startRow; i < endRow; i++){
      for (int j = startCol; j < endCol; j++){
        string newImageColor = newImagePointer[i-startRow][j-startCol].
                               printComponentValues();
        if (newImageColor != 
            newImage.getTransparencyColor().printComponentValues()){
          imagePointer[i][j].setTo(newImagePointer[i-startRow][j-startCol]);
        }
      }
    }
  }
  return SUCCESS_PROCESS;
}

ColorClass **ColorImageClass::getImagePointer(){
  return imagePointer;
}

ColorClass ColorImageClass::getTransparencyColor(){
  return transparencyColor;
}

int ColorImageClass::getHeight(){
  return imageHeight;
}

int ColorImageClass::getWidth(){
  return imageWidth;
}

// Export image to specific file name
bool ColorImageClass::exportImageFile(string outFileName){
  ofstream outFile;
  outFile.open(outFileName.c_str());
  
  if(outFile.fail()){
    cout << "File can't be open!" << endl;
    return FAILURE_PROCESS;
  }
  else{
    outFile << imageMagicNumber << endl; 
    outFile << imageWidth << " " << imageHeight << endl;
    outFile << pixelMaxValue << endl;

    for(int i = 0; i < imageHeight; i++){
      for(int j = 0; j < imageWidth; j++){
        outFile << imagePointer[i][j].printComponentValues();
      }    
    }
  }
  outFile.close();
  return SUCCESS_PROCESS;
}