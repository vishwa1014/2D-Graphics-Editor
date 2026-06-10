# 2D-Graphics-Editor
2D Graphics Editor (C Project) 📌 Project Aim The aim of this project is to design a simple menu-driven 2D graphics editor in C that demonstrates basic graphics algorithms using ASCII art. It helps visualize how shapes can be represented on a 2D grid and reinforces concepts of arrays, functions, and user input handling in C programming.

🎯 Learning Outcomes Represent a canvas using 2D arrays. Implement functions to draw basic shapes (rectangle, line, triangle, circle). Practice handling user input and menu-driven program design. Gain experience with compiling and running C programs using GCC. Manage objects with add, delete, and modify operations.

2D Graphics Editor in C
Project Description
This project is a simple 2D Graphics Editor developed in C using a 2D character array. The editor allows users to draw basic geometric shapes on a text-based canvas using the * character while empty spaces are represented using the _ character.

The program provides an interactive menu-driven interface through which users can create and display graphical objects.

Features
Draw Line
Draw Rectangle
Draw Circle
Draw Triangle
Display the Picture
Store the picture using a 2D character array
Menu-driven interface
Canvas
Canvas Width: 80 characters
Canvas Height: 24 characters
Drawing Character: *
Empty Character: _
Functions Implemented
clearPicture()
Initializes the canvas by filling it with _.

displayPicture()
Displays the current canvas on the screen.

setPixel()
Plots a single pixel at the specified coordinates.

drawLine()
Draws a line between two points.

drawRectangle()
Draws a rectangle using four lines.

drawCircle()
Draws a circle with a specified center and radius.

drawTriangle()
Draws a triangle by connecting three points.

How to Compile
gcc main.c -o editor
How to Run
./editor
Menu Options
Draw Line
Draw Rectangle
Draw Circle
Draw Triangle
Display Picture
Exit
Sample Output
________________________________________
__________**********____________________
__________*________*____________________
__________*________*____________________
__________**********____________________
________________________________________
Technologies Used
C Programming Language
Standard C Library
Author
Vishwa

Repository
This repository is maintained as part of the Advanced C Programming course assignment.
