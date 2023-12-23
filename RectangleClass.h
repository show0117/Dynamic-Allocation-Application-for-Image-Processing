#ifndef _RECTANGLECLASS_H_
#define _RECTANGLECLASS_H_
#include <string>
#include <iostream> 
#include "ColorClass.h"
#include "RowColumnClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class is used to define a rectangle image. User can set
// attributes of this rectangle, such as width, height, or color. 

class RectangleClass{
  private:
    RowColumnClass upperLeftLoc; // The upper left location of the rectangle
    RowColumnClass lowerRightLoc; // The lower right location of the rectangle
    ColorClass recColor; // The color of the rectangle 

  public:
    // Initialize the values of colors with given values
    RectangleClass();

    // Set rectangle's location by directing entering these
    // two location's information.
    void setLocWithUpperLeftLowerRight(int upperLeftRow, int upperLeftCol,
                                       int lowerRightRow, int lowerRightCol);
    // Set rectangle's location with the upper left location
    // and the height as well width.
    void setLocWithUpperLeftAndLength(int upperLeftRow, int upperLeftCol,
                                      int height, int width);
    // Set rectangle's location information by center point and the 
    // half of width and height.
    void setLocWithCenterAndHalfLength(int centerRow, int centerCol,
                                       int halfNumRow, int halfNumCol);
    // Set color attrbute of the rectangle.
    void setRecColor(int colorNum);

    // Get the upper left location of the rectangle.
    RowColumnClass getUpperLeftLoc();
    // Get the lower right location of the rectangle.
    RowColumnClass getLowerRightLoc();
    // Get the color attribute of the rectangle.
    ColorClass getRecColor();
};

#endif