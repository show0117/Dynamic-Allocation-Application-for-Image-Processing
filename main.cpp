#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "checkPixelValue.h"
#include "checkPatternValue.h"
#include "checkCin.h"
#include "chooseColor.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: This is the main function of whole program. It is used to build
// an user interface for external users. External users can use its user 
// interface to finish their customized images. In this interface, five main
// functions are included, and users and manipulate this by entering 
// different integer numbers.
int main() { 
  string fileName; // Name of initializing file
  ColorImageClass userImage; // Load the file to a image class
  int menuChoice; // The menu choice which depends on user's input 

  cout << "Enter string for PPM image file name to load: "; 
  cin >> fileName;

  // If initialize fail, exit the program. 
  if (userImage.initializeTo(fileName)){
    // After initializing successfully, main functions will be initialized.
    // Only when user choose to exit the program will stop.
    while (menuChoice != EXITING_THE_PROGRAM){
      cout << "1. Annotate image with rectangle" << endl; 
      cout << "2. Annotate image with pattern from file" << endl;
      cout << "3. Insert another image" << endl;
      cout << "4. Write out current image" << endl;
      cout << "5. Exit the program" << endl;
      cout << "Enter int for main menu choice: ";
      cin >> menuChoice;
      // Error checking step by step.
      if (!checkCin() ||
         (menuChoice != ANNOTATING_IMAGE_WITH_RECTANGLE &&
          menuChoice != ANNOTATING_IMAGE_WITH_PATTERN_FROM_FILE &&
          menuChoice != INSERTING_ANOTHER_IMAGE &&
          menuChoice != WRITING_OUT_CURRENT_IMAGE &&
          menuChoice != EXITING_THE_PROGRAM)){
        cout << "Invalid input!" << endl;
      }
      else {
        // The main function of adding a customized rectangle on the 
        // loaded image.
        if (menuChoice == ANNOTATING_IMAGE_WITH_RECTANGLE){
          int rectangleChoice;
          RectangleClass userRectangle;
          int colNum;
          int fillOption;
          // This is a special variable for the adding rectangle function.
          // It will help do the flow control in this function. If something
          // wrong happen in the flow control process, it will return false.
          bool processStatus;

          cout << "1. Specify upper left and lower right corners of rectangle"
               << endl;
          cout << "2. Specify upper left corner and dimensions of rectangle"
               << endl;
          cout << "3. Specify extent from center of rectangle"
               << endl;
          cout << "Enter int for rectangle specification method: ";
          cin >> rectangleChoice;

          // Choose different way to set the location information of
          // the rectangle.
          if (!checkCin() || 
             (rectangleChoice != SETTING_LOC_UPPER_LEFT_LOWER_RIGHT &&
              rectangleChoice != SETTING_LOC_UPPER_LEFT_LENGTH &&
              rectangleChoice != SETTING_LOC_CENTER_HALF_LENGTH)){
            cout << "Invalid input!" << endl;
            processStatus = FAILURE_PROCESS;
          }
          else {
            if (rectangleChoice == SETTING_LOC_UPPER_LEFT_LOWER_RIGHT){
              int upperLeftRow;
              int upperLeftCol;
              int lowerRightRow;
              int lowerRightCol;

              cout << "Enter upper left corner row and column: ";
              cin >> upperLeftRow >> upperLeftCol;
              if (!checkCin() || upperLeftRow <= MIN_ROW ||
                  upperLeftCol <= MIN_COL){
                cout << "Invalid input!" << endl;
                processStatus = FAILURE_PROCESS;
              }
              else{
                cout << "Enter lower right corner row and column: ";
                cin >> lowerRightRow >> lowerRightCol;
                if (!checkCin() || lowerRightRow <= MIN_ROW ||
                    lowerRightCol <= MIN_COL){
                  cout << "Invalid input!" << endl;
                  processStatus = FAILURE_PROCESS;
                }
                else {
                  userRectangle.setLocWithUpperLeftLowerRight(upperLeftRow,
                                                              upperLeftCol,
                                                              lowerRightRow,
                                                              lowerRightCol);
                  processStatus = SUCCESS_PROCESS;
                }
              }
            }
            else if (rectangleChoice == SETTING_LOC_UPPER_LEFT_LENGTH){
              int upperLeftRow;
              int upperLeftCol;
              int numRows;
              int numCols;

              cout << "Enter upper left corner row and column: ";
              cin >> upperLeftRow >> upperLeftCol;
              if (!checkCin() || upperLeftRow <= MIN_ROW ||
                  upperLeftCol <= MIN_COL){
                cout << "Invalid input!" << endl;
                processStatus = FAILURE_PROCESS;
              }
              else{
                cout << "Enter int for number of rows: ";
                cin >> numRows;
                if (!checkCin() || numRows <= MIN_ROW){
                  cout << "Invalid input!" << endl;
                  processStatus = FAILURE_PROCESS;
                }
                else {
                  cout << "Enter int for number of columns: ";
                  cin >> numCols;
                  if (!checkCin() || numCols <= MIN_COL){
                    cout << "Invalid input!" << endl;
                    processStatus = FAILURE_PROCESS;
                  }
                  else{
                    userRectangle.setLocWithUpperLeftAndLength(upperLeftRow,
                                                               upperLeftCol,
                                                               numRows,
                                                               numCols);
                    processStatus = SUCCESS_PROCESS;
                  }
                }
              }
            }
            else if (rectangleChoice == SETTING_LOC_CENTER_HALF_LENGTH){
              int centerRow;
              int centerCol;
              int halfNumRow;
              int halfNumCol;

              cout << "Enter rectangle center row and column: ";
              cin >> centerRow >> centerCol;
              if (!checkCin() || centerRow <= MIN_ROW ||
                  centerCol <= MIN_COL){
                cout << "Invalid input!" << endl;
                processStatus = FAILURE_PROCESS;
              }
              else{
                cout << "Enter int for half number of rows: ";
                cin >> halfNumRow;
                if (!checkCin() || halfNumRow <= MIN_ROW){
                  cout << "Invalid input!" << endl;
                  processStatus = FAILURE_PROCESS;
                }
                else {
                  cout << "Enter int for half number of columns: ";
                  cin >> halfNumCol;
                  if (!checkCin() || halfNumCol <= MIN_COL){
                    cout << "Invalid input!" << endl;
                    processStatus = FAILURE_PROCESS;
                  }
                  else{
                    userRectangle.setLocWithCenterAndHalfLength(centerRow,
                                                                centerCol,
                                                                halfNumRow,
                                                                halfNumCol);
                    processStatus = SUCCESS_PROCESS;
                  }
                }
              }
            }
            // If something get wrong before, this will not proceed.
            if (processStatus){
             int upperLeftRow = userRectangle.getUpperLeftLoc().getRow();
             int upperLeftCol = userRectangle.getUpperLeftLoc().getCol();
             int lowerRightRow = userRectangle.getLowerRightLoc().getRow();
             int lowerRightCol = userRectangle.getLowerRightLoc().getCol();

             if (upperLeftRow >= lowerRightRow || 
                 upperLeftCol >= lowerRightCol){
               cout << "Lower right location rows and columns should be "
                    << "larger than upper left locatio!" << endl;
             }
             else {
               colNum = chooseColor(menuChoice);
               if (colNum != INVALID_COLOR){
                 userRectangle.setRecColor(colNum);
                 cout << "1. No" << endl;
                 cout << "2. Yes" << endl;
                 cout << "Enter int for rectangle fill option: ";
                 cin >> fillOption;
                 if (!checkCin() ||
                    (fillOption != NOT_FILLING_RECTANGLE &&
                     fillOption != FILLING_RECTANGLE)){
                   cout << "Invalid input!" << endl;
                 }
                 else {
                   userImage.addRectangleOn(userRectangle, fillOption);
                 }
               }
             }
            }
          }
        }
        // This main function of adding a pattern image on the loaded image.
        else if (menuChoice == ANNOTATING_IMAGE_WITH_PATTERN_FROM_FILE){
          string patternFile;
          PatternClass userPattern;
          int patternRow;
          int patternCol;
          int patternColor;

          cout << "Enter string for file name containing pattern: ";
          cin >> patternFile;
          if (userPattern.initializeTo(patternFile)){
            cout << "Enter upper left corner of pattern row and column: ";
            cin >> patternRow >> patternCol;
            if (!checkCin() || patternRow <= MIN_ROW ||
                patternCol <= MIN_COL){
              cout << "Invalid input!" << endl;
            }
            else {
              userPattern.setLoc(patternRow, patternCol);
              patternColor = chooseColor(menuChoice);
              if (patternColor != INVALID_COLOR){
                userPattern.setPatternColor(patternColor);
                userImage.addPatternOn(userPattern);
              }
            }
          }
        }
        // This main function of adding another image to the loaded image.
        else if (menuChoice == INSERTING_ANOTHER_IMAGE){
          string insertingImageFile;
          ColorImageClass insertingImage;
          RowColumnClass imageUpperLeftLoc;
          int insertingImageRow;
          int insertingImageCol;
          int transparencyColor;

          cout << "Enter string for file name of PPM image to insert: ";
          cin >> insertingImageFile;
          if (insertingImage.initializeTo(insertingImageFile)){
            cout << "Enter upper left corner to insert image"
                 << " row and column: ";
            cin >> insertingImageRow >> insertingImageCol;
            if (!checkCin() || insertingImageRow <= MIN_ROW ||
                insertingImageCol <= MIN_COL){
              cout << "Invalid input!" << endl;
            }
            else {
              imageUpperLeftLoc.setRow(insertingImageRow);
              imageUpperLeftLoc.setCol(insertingImageCol);
              transparencyColor = chooseColor(menuChoice);
              if (transparencyColor != INVALID_COLOR){
                insertingImage.setTransparencyColor(transparencyColor);
                userImage.addImageOn(insertingImage, imageUpperLeftLoc);
              }
            }
          }
        }
        // The main function of exporting the proceeded image with 
        // specific filename.
        else if (menuChoice == WRITING_OUT_CURRENT_IMAGE){
          string outputFileName;
          cout << "Enter string for PPM file name to output: ";
          cin >> outputFileName;
          userImage.exportImageFile(outputFileName);
        }
        // This is the last function of our interface: exiting the program.
        else if (menuChoice == EXITING_THE_PROGRAM){
          cout << "Thank you for using this program";
        }
      }
    }
  }
  return 0;
}