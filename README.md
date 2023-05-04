# CSCI2312: Bonus Homework

## Problem Statement

The current system uses a class called ShapeReader to read in text files in the format listed below, checks to make sure
they're valid rectangles, and stores the characteristic information. This file is not commented, so the best place to start
is to comment what you can to try and figure out how everything works.

Your job is to make a derived class called TriangleReader that overloads the 'readFile' and 'write' methods for a new format
shown below. You'll also need to add a few new member variables, including one to store what type of triangle was detected.

Just like the original, you'll want to do some error checking to make sure the program does not accept invalid triangles.

### Input File Structure
The current input file itself is composed of '0' characters separated by spaces. Each row of '0' characters are separated by a newline
character (\n). Each row is the same length of '0's with an arbitrary height. Example:
```
0 0 0 0 0 
0 0 0 0 0
0 0 0 0 0
```
This file would result in a shape with a width of 5 and a height of 4.

The format for triangles is almost identical, but is now in the shape of a triangle. You don't need to worry about
slopes other than one step per line. You do need to be able to detect what type of triangle you're reading in. The
following are examples of the different types of triangles you'll be needing to detect. You are given test files for
each of these.

Isosceles (Two sides are the same length):
```
0
0 0
0 0 0
0 0
0
```

Right Triangle (3x3) (Bottom Heavy):
```
0
0 0
0 0 0
```

Right Triangle (3x3) (Top Heavy):
```
0 0 0
0 0
0
```

Any deviation from this style, such as using a different input character or unexpected row pattern, will result in an error.

## Grading

You'll be graded based on how far you're able to get in the list of tasks below. The more you do, the more extra credit you can get:
1) Comment the original program to the best of your abilities.
2) Write a new set of source files for TriangleReader.
3) Overload the 'readFile' and 'write' functions such that they work for valid files.
4) Do some error checking in 'readFile' such that it rejects invalid files.
5) Copy the test functions, and make a new version that works for the triangle files.

## Submission

You have two options for how to submit this assignment. 

1) You can fork this GitHub repository, then push your new code and submit the link to your repository on Canvas.
2) You can download the Zip of this repository, work on it locally, and when you're ready, zip your files and submit on Canvas.

Both are good options, though forking is the best method, but if you don't know how to merge files, it may get tricky if 
I need to push a bugfix to my version, and you want to merge with upstream (You will need to do this manually, but it will be good Git practice).

## Troubleshooting:
### Files can't be read:
Currently, the files are accessed with the assumption you're using CLion, which compiles the EXE for the application in 
a folder called 'cmake-build-debug' inside the project folder. The test files are in the project folder, so for the EXE file
to access them, it needs to use a filepath structure like this '../filename.txt'. If you're using a different structure, 
be sure to correct the file paths as necessary.

