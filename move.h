#ifndef MOVE_H
#define MOVE_H

#include <map>
#include <vector>

using namespace std;

void circularMoveXY(map<char, vector<vector<double>>> *pSpace, int spaceSize, int cubeSize, double XPIDivisor);

void circularMoveXYZ(map<char, vector<vector<double>>> *pSpace, int spaceSize, int cubeSize, double XPIDivisor, double ZPIDivisor);

#endif