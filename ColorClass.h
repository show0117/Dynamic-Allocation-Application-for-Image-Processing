#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_
#include <string>
#include <iostream> 

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class is used to for color manipulation. Such as 
// setting to a specific color or getting current color pixel numbers.

// This class contains the information describing a color. Its member 
// functions can help itself to complete some color manipulations. 
class ColorClass{
  private:
    // values of the original colors in this class
    int valueRed;
    int valueGreen;
    int valueBlue;

  public:
    // default constructor which sets all values to default values
    ColorClass();
    // initialize the values of colors with given values
    ColorClass(int inRed, int inGreen, int inBlue);

    void setToBlack(); // sets color values to which represent black
    void setToRed(); // sets color values to which represent red
    void setToGreen(); // sets color values to which represent green
    void setToBlue(); // sets color values to which represent blue
    void setToWhite(); // sets color values to which represent white
    // sets color values to provided values
    void setTo(int inRed, int inGreen, int inBlue);
    // sets color values to the color values of "inColor"
    void setTo(ColorClass &inColor);

    // get the information of Componeant values
    string printComponentValues();
};

#endif