# Rotating Console Cube

## Description

A little C++ program for displaying a rotating cube into the console.

## How to use it

Use the following command : ./rotating-cube spaceSize [cubeSize] [fps] [XPIDivisor] [ZPIDivisor]
Space size is the length, in characters, of the sides of the area on which you want the cube to display.
Cube size is the length, in characters, of the edges of the cube.
Fps is the number of printing per second you want.
XPIDivisor and ZPIDivisor define the calculation precision of the rotation. In each frame, the cube rotates PI / XPIDivisor radians on the x axis and PI / ZPIDivisor on the z axis.

## Examples

./rotating-cube 30
./rotating-cube 30 16
./rotating-cube 30 16 60 170 170
./rotating-cube 30 16 60 -170 -170
