#ifndef DRAW_H
#define DRAW_H

#include <map>
#include <vector>
#include <list>

using namespace std;

int drawLine(map<char, vector<vector<double>>> *space, double point1[3], double point2[3], char color);

int drawCube(map<char, vector<vector<double>>> *pSpace, int spaceSize, int cubeSize);

#endif