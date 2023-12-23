#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

#include <string>
#include <iostream> 

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This class define a two dimension location or  number of
// rows and columns. 

class RowColumnClass{
  private:
    // represents the location of row and column
    int numRow;
    int numCol;

  public:
    // default constructor which sets allattrbutes to default numbers
    RowColumnClass();
    // initializes the row and column number with given values
    RowColumnClass(int inRow, int inCol);

    // sets the row and column numbers to given values
    void setRowCol(int inRow, int inCol);
    // sets the row number to a given value
    void setRow(int inRow);
    // sets the column number to a given value
    void setCol(int inCol);
    // gets the row number
    int getRow();
    // gets the column number
    int getCol();
    // adds the numbers of row and column with the numbers of "inRowCol"
    void addRowColTo(RowColumnClass &inRowCol);
};

#endif