#include <iostream>
#include <string>
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class is used to define a rectangle image. User can set
// attributes of this rectangle, such as width, height, or color. 

RectangleClass::RectangleClass(){
  upperLeftLoc.setRow(DEFAULT_ROW);
  upperLeftLoc.setCol(DEFAULT_COL);
  lowerRightLoc.setRow(DEFAULT_ROW);
  lowerRightLoc.setCol(DEFAULT_COL);
  recColor.setToRed();
}

void RectangleClass::setLocWithUpperLeftLowerRight(int upperLeftRow,
                                                   int upperLeftCol,
                                                   int lowerRightRow,
                                                   int lowerRightCol){
  upperLeftLoc.setRow(upperLeftRow);
  upperLeftLoc.setCol(upperLeftCol);
  lowerRightLoc.setRow(lowerRightRow);
  lowerRightLoc.setCol(lowerRightCol);
}

void RectangleClass::setLocWithUpperLeftAndLength(int upperLeftRow,
                                                  int upperLeftCol,
                                                  int height,
                                                  int width){
  upperLeftLoc.setRow(upperLeftRow);
  upperLeftLoc.setCol(upperLeftCol);
  lowerRightLoc.setRow(upperLeftRow + height);
  lowerRightLoc.setCol(upperLeftCol + width);
}

void RectangleClass::setLocWithCenterAndHalfLength(int centerRow,
                                                   int centerCol,
                                                   int halfNumRow,
                                                   int halfNumCol){
  upperLeftLoc.setRow(centerRow - halfNumRow);
  upperLeftLoc.setCol(centerCol - halfNumCol);
  lowerRightLoc.setRow(centerRow + halfNumRow);
  lowerRightLoc.setCol(centerCol + halfNumCol);
}

void RectangleClass::setRecColor(int colNum){
  if (colNum == RED_NUM){
    recColor.setToRed();
  }
  else if (colNum == GREEN_NUM){
    recColor.setToGreen();
  }
  else if (colNum == BLUE_NUM){
    recColor.setToBlue();
  }
  else if (colNum == BLACK_NUM){
    recColor.setToBlack();
  }
  else if (colNum == WHITE_NUM){
    recColor.setToWhite();
  }
} 

RowColumnClass RectangleClass::getUpperLeftLoc(){
  return upperLeftLoc;
}

RowColumnClass RectangleClass::getLowerRightLoc(){
  return lowerRightLoc;
}

ColorClass RectangleClass::getRecColor(){
  return recColor;
}