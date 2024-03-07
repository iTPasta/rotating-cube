#include <stdlib.h>
#include <map>
#include <vector>
#include <list>

using namespace std;

#include "utils.h"

int drawLine(map<char, vector<vector<double>>> *pSpace, double point1[3], double point2[3], char color)
{
    map<char, vector<vector<double>>> space = *pSpace;

    if (!space.count(color))
    {
        vector<vector<double>> v = vector<vector<double>>();
        space.insert(make_pair(color, v));
    }

    double pen[] = {point1[0], point1[1], point1[2]};
    double vec[] = {point2[0] - point1[0], point2[1] - point1[1], point2[2] - point1[2]};

    double maxCoord = max(vec[0], vec[1], vec[2]);
    double incrementation[] = {vec[0] / maxCoord, vec[1] / maxCoord, vec[2] / maxCoord};

    for (int i = 0; i < maxCoord; i++)
    {
        vector<double> coord;
        coord.push_back(pen[0]);
        coord.push_back(pen[1]);
        coord.push_back(pen[2]);
        space.at(color).push_back(coord);

        pen[0] = pen[0] + incrementation[0];
        pen[1] = pen[1] + incrementation[1];
        pen[2] = pen[2] + incrementation[2];
    }

    *pSpace = space;

    return maxCoord;
}

int drawCube(map<char, vector<vector<double>>> *pSpace, int spaceSize, int cubeSize)
{
    map<char, vector<vector<double>>> space = *pSpace;
    double center[] = {(double)spaceSize / 2, (double)spaceSize / 2, (double)spaceSize / 2};

    int pointsDrawn = 0;
    for (int x = 0; x < spaceSize; x++)
        for (int y = 0; y < spaceSize; y++)
            for (int z = 0; z < spaceSize; z++)
                if (
                    (distance(x, center[0]) == (double)cubeSize / 2 && distance(y, center[1]) == (double)cubeSize / 2 && distance(z, center[2]) <= (double)cubeSize / 2) ||
                    (distance(x, center[0]) == (double)cubeSize / 2 && distance(z, center[2]) == (double)cubeSize / 2 && distance(y, center[1]) <= (double)cubeSize / 2) ||
                    (distance(y, center[1]) == (double)cubeSize / 2 && distance(z, center[2]) == (double)cubeSize / 2 && distance(x, center[0]) <= (double)cubeSize / 2))
                {
                    vector<double> coord;
                    coord.push_back(x);
                    coord.push_back(y);
                    coord.push_back(z);
                    space['#'].push_back(coord);

                    pointsDrawn++;
                }

    *pSpace = space;
    return pointsDrawn;
}