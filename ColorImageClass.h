#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_
#include <string>
#include <iostream> 
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class mainly for image manipulation. User can initialize
// it with their own image. Besides it includes three main functions: adding
// a rectangle on the image, adding special pattern on the image, or adding
// another image on the image. User can also set a variety of parameters
// such as image location, colors, or transpancy color to customize their
// own images.  

// This class is mainly responsible for color manipulation with
// several functions.
class ColorImageClass{
  private:
    // This attriute represents a pointer represent dynamic array which
    // help image manipulation
    ColorClass **imagePointer;
    // Transparency color of the class
    ColorClass transparencyColor;
    // Image magic number of the class. The expected value of a ppm file
    // is P3.
    string imageMagicNumber;
    // Image width loaded from a ppm file.
    int imageWidth;
    // Image height loaded from a ppm file.
    int imageHeight;
    // Image max pixel value loaded from a ppm file.
    int pixelMaxValue;
 
    // This function is used to check if the edge of an image which is 
    // going to be added is out of the bound of main image or not.
    bool checkEdge(RowColumnClass &upperLeftLoc,
                   RowColumnClass &lowerRightLoc);

  public:  
    // default constructor which sets all pixels to values representing black
    ColorImageClass();

    // initializes all pixels to a input picture
    bool initializeTo(string inFileName);
    // Set the transparency color of this class
    void setTransparencyColor(int colorNum);

    // Add a given rectangle on the main image. 
    bool addRectangleOn(RectangleClass &recLoc, int fillOption);
    // Add a given pattern on the main image. 
    bool addPatternOn(PatternClass &patternImage);
    // Add a given image on the main image. 
    bool addImageOn(ColorImageClass &newImage, RowColumnClass &upperLeftLoc);
    
    // Get the image pointer from the class
    ColorClass **getImagePointer();
    // get the transparency color of this class
    ColorClass getTransparencyColor();
    // Get the height of the class
    int getHeight();
    // Get the width of the class
    int getWidth();

    // Export the present image with specific file name
    bool exportImageFile(string outFileName);
};

#endif