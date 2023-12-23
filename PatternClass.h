#ifndef _PATTERNCLASS_H_
#define _PATTERNCLASS_H_
#include <string>
#include <iostream> 
#include "ColorClass.h"
#include "RowColumnClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class is used to define a pattern image. User can initialize
// it with their own file and doing additional manipulation.

class PatternClass{
  private:
    // Location attributes of the pattern
    RowColumnClass upperLeftLoc;
    RowColumnClass lowerRightLoc;
    // Color of the pattern
    ColorClass patternColor;

    // Width of the pattern
    int imageWidth;
    // Height of the pattern
    int imageHeight;
    // This pointer will record the value loaded from a pattern file
    int **patternPointer;

  public:
    // initialize the values of colors with given values
    PatternClass();
    
    // Set the location information of the pattern
    void setLoc(int numRow, int numCol);
    // Initialize this class with a file
    bool initializeTo(string fileName);
    // Set the color
    void setPatternColor(int colorNum);

    // Get upperLeftLoc attribute of the class
    RowColumnClass getUpperLeftLoc();
    // Get lowerRightLoc attribute of the class
    RowColumnClass getLowerRightLoc();
    // Get color attribute of the class
    ColorClass getPatternColor();
    
    // Get the pattern pointer of the class
    int **getPatternPointer();
};

#endif