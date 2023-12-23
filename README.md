# Dynamic Allocation Application for Image Processing
**This is a course project of EECS 280 supervised by Andrew Morgan, University of Michigan.**
<https://eecs280.org/>

## Overview
Working with, and processing images on a computer is big business for modern computer science field. In this project, we introduce different formats of images and allow users to modify or create images in several specific ways. All images will be stored as dynamic array which takes maximum advantage of C++'s good memory control and its powerful processing efficiency.

## Background: .ppm Imagery
.ppm files, unlike most other formats, are stored in an ASCII text file. This program is specifically designed for manipulating the format of files. A .ppm image can contain the exact same image as a .gif or .jpg, but it would likely be significantly larger in file size. A very very small image of a red square on a blue background would be stored in a .ppm file as follows:

P3
4 4
255
0 0 255 0 0 255 0 0 255 0 0 255
0 0 255 255 0 0 255 0 0 0 0 255
0 0 255 255 0 0 255 0 0 0 0 255
0 0 255 0 0 255 0 0 255 0 0 255

Original file: deer.ppm
![image](https://github.com/show0117/Dynamic_Allocation_Application_for_Image_Processing/blob/main/deer.jpg)

## Background: Text Patterns
Patterns are contained in text files of the following format: The first value is an integer representing the number of columns in the rectangular pattern. The second value is an integer representing the number of rows in the rectangular pattern. What follows is a collection of zeros and ones that is (rows * columns) in length. For example, here is the contents of a pattern file that defines a pattern of the letter 'T':

6 8
1 1 1 1 1 1
1 1 1 1 1 1
0 0 1 1 0 0
0 0 1 1 0 0
0 0 1 1 0 0
0 0 1 1 0 0
0 0 1 1 0 0
0 0 1 1 0 0

## CheckCin / CheckPatternValue / CheckPixelValue
File's I/O is an important part of or program, CheckCin is used to check if input values of user are correct through different return value. If not, it will clear the input of cin and return failure information. Whereas CheckPatternValue / CheckPixelValue function are used to check if an integer from a .ppm or pattern file is in the valid range of number. 

## ChooseColor
This is a user interface for color manipulations to images or patterns.

## ColorClass
The *ColorClass* class you are required to implement for this project will contain information describing a color. Besides, the class is used to for color manipulation, such as setting to a specific color or getting current color pixel numbers. 

## ColorImageClass
*ColorImageClass* will represent a small image, which is stored by a 2D dynamic array. This class mainly for image manipulation. User can initialize it with their own image. Besides it includes three main functions: adding a rectangle on the image, adding special pattern on the image, or adding another image on the image. User can also set a variety of parameters such as image location, colors, or transpancy color to customize their own images.

## RectangleClass
*RectangleClass* class is a very simple class to uniquely identify a specific pixel within an image. Instead of writing this class, we could have chosen to always refer to a pixel by providing both index values separately. It allows our program locate the specific space of pixels through pointers. 

## PatternClass / RectangleClass
Classes used to define a pattern or rectangle image. User can initialize it as their own file and do additional manipulations. 

## main.cpp
This is the user interface of the program. It includes five main functions in the interface which are as follows:

1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program

External users can use its user interface to finish their customized images. In this interface, five main functions are included, and users and manipulate this by entering different integer numbers.

**Makefile**
g++ -std=c++98 main.o checkPatternValue.o checkPixelValue.o checkCin.o chooseColor.o ColorClass.o RowColumnClass.o RectangleClass.o PatternClass.o ColorImageClass.o -o proj3.exe

**Sample Output**
![image](https://github.com/show0117/Dynamic_Allocation_Application_for_Image_Processing/blob/main/new5.jpg)