#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include <string>

using namespace std;

// Author: Te-Hsiu Tsai
// Date: 11/2/2023
// Purpose: These are global constants of the whole program.

// Global Constant Declarations
const int INITIAL_COLOR_VALUE = 255; // initial value of each RGB color
const int MAX_COLOR_VALUE = 255; // max value of each RGB color
const int MIN_COLOR_VALUE = 0; // min value of each RGB color

const int DEFAULT_ROW = 0; // Default row for initilization
const int DEFAULT_COL = 0; // Default column for initilization
const int MIN_ROW = 0; // Minimun row in any situation
const int MIN_COL = 0; // Minimun column in any situation

// The expected magic number of a ppm file
const string EXPECTED_PPM_MAGIC_NUMBER = "P3";

const bool INVALID_LOCATION = false; // For checking valid location
const bool VALID_LOCATION = true; // For checking valid location

// When loading a pattern file, this number means a pattern valeu.
const int PATTERN_COLOR = 1; 
// When loading a pattern file, this number means a pattern color
// is transparent.
const int PATTERN_TRANSPARENCY = 0;

// When user input invalid color number, return this value
const int INVALID_COLOR = 0;
const int RED_NUM = 1; // Number of red in color menu
const int GREEN_NUM = 2; // Number of green in color menu
const int BLUE_NUM = 3; // Number of blue in color menu
const int BLACK_NUM = 4; // Number of black in color menu
const int WHITE_NUM = 5; // Number of white in color menu

// Main function of the main menu of user interface
const int ANNOTATING_IMAGE_WITH_RECTANGLE = 1; // Adding rectangle
const int ANNOTATING_IMAGE_WITH_PATTERN_FROM_FILE = 2; // Adding pattern
const int INSERTING_ANOTHER_IMAGE = 3; // Inserting an image
const int WRITING_OUT_CURRENT_IMAGE = 4; // Exporting the current image
const int EXITING_THE_PROGRAM = 5; // Exiting the program

// Different ways to choose to input rectangle locations
// Setting with upper left and lower right location
const int SETTING_LOC_UPPER_LEFT_LOWER_RIGHT = 1; 
// Setting with upper left and the length of width and height
const int SETTING_LOC_UPPER_LEFT_LENGTH = 2; 
// Setting with certer point and half of the height and width
const int SETTING_LOC_CENTER_HALF_LENGTH = 3;

// Whether user decide to fill the rectangle or not
const int NOT_FILLING_RECTANGLE = 1; // Not fillinf the recrangle
const int FILLING_RECTANGLE = 2; // Choose to fill in 

// Used to descriminate if there's anomaly happen in processes
const bool FAILURE_PROCESS = false; // Anomaly happen
const bool SUCCESS_PROCESS = true; // Process is normal

#endif