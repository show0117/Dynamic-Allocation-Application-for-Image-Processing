#include <iostream>
#include <string>
#include "constants.h"
#include "RowColumnClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class define a two dimension location or  number of
// rows and columns. 
 
RowColumnClass::RowColumnClass(){
  numRow = DEFAULT_ROW;
  numCol = DEFAULT_COL;
}

RowColumnClass::RowColumnClass(int inRow, int inCol){
  numRow = inRow;
  numCol = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol){
  numRow = inRow;
  numCol = inCol;
}

void RowColumnClass::setRow(int inRow){
  numRow = inRow;
}

void RowColumnClass::setCol(int inCol){
  numCol = inCol;
}

int RowColumnClass::getRow(){
  return numRow;
}
int RowColumnClass::getCol(){
  return numCol;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol){
  numRow += inRowCol.numRow;
  numCol += inRowCol.numCol;
}