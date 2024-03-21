#include <iostream>
#include <map>
#include <vector>
#include <thread>
#include <chrono>
#include <string.h>
#include <math.h>
#include "view.h"
#include "draw.h"
#include "move.h"
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2 || 6 < argc)
    {
        cout << "Usage: " << argv[0] << " spaceSize [cubeSize] [fps] [XPIDivisor] [ZPIDivisor]\n";
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "help") == 0)
    {
        cout << "Usage: " << argv[0] << " spaceSize [cubeSize] [fps] [XPIDivisor] [ZPIDivisor]\n";
        exit(EXIT_SUCCESS);
    }

    const int spaceSize = atoi(argv[1]);
    int cubeSize = 3 <= argc ? atoi(argv[2]) : -100;
    const int fps = 4 <= argc ? atoi(argv[3]) : 30;
    const double XPIDivisor = 5 <= argc ? (double)atoi(argv[4]) : 2.25 * (double)fps;
    const double ZPIDivisor = 6 == argc ? (double)atoi(argv[5]) : XPIDivisor;

    if (spaceSize < 4)
    {
        cout << "Value of space size must be at least 4.";
        exit(EXIT_FAILURE);
    }

    if (cubeSize != -100 && cubeSize < 0)
    {
        cubeSize = 0;
    }

    if (cubeSize != -100 && spaceSize < cubeSize)
    {
        cout << "Space size must be greater than cube size.\n";
        exit(EXIT_FAILURE);
    }

    if (spaceSize % 2 != 0 || cubeSize % 2 != 0)
    {
        cout << "Space size and cube size must be even." << endl;
        exit(EXIT_FAILURE);
    }

    if (cubeSize != -100 && cubeSize <= 0)
    {
        cout << "Cube size must be strictly positive." << endl;
        exit(EXIT_FAILURE);
    }

    const double center[] = {(double)spaceSize / 2., (double)spaceSize / 2., (double)spaceSize / 2.};

    if (cubeSize == -100)
    {
        cubeSize = 0;
        double maxPoint[] = {center[0] + (double)cubeSize / 2,
                             center[1] + (double)cubeSize / 2,
                             center[2] + (double)cubeSize / 2};
        double dPoints = sqrt(pow(distance(center[0], maxPoint[0]), 2) +
                              pow(distance(center[1], maxPoint[1]), 2) +
                              pow(distance(center[2], maxPoint[2]), 2));

        while (dPoints < (double)spaceSize / 2)
        {
            cubeSize += 2;
            maxPoint[0] = center[0] + (double)cubeSize / 2;
            maxPoint[1] = center[1] + (double)cubeSize / 2;
            maxPoint[2] = center[2] + (double)cubeSize / 2;
            dPoints = sqrt(pow(distance(center[0], maxPoint[0]), 2) +
                           pow(distance(center[1], maxPoint[1]), 2) +
                           pow(distance(center[2], maxPoint[2]), 2));
        }

        cubeSize -= 2;
    }
    else
    {
        const double maxPoint[] = {center[0] + (double)cubeSize / 2,
                                   center[1] + (double)cubeSize / 2,
                                   center[2] + (double)cubeSize / 2};
        const double dPoints = sqrt(pow(distance(center[0], maxPoint[0]), 2) +
                                    pow(distance(center[1], maxPoint[1]), 2) +
                                    pow(distance(center[2], maxPoint[2]), 2));

        if ((double)spaceSize / 2 <= dPoints)
        {
            cout << "Warning : Cube will go out of the space." << endl
                 << "To avoid this, space size must be greater, or cube be smaller." << endl;
            this_thread::sleep_for(chrono::milliseconds(4000));
        }
    }

    map<char, vector<vector<double>>> space;
    drawCube(&space, spaceSize, cubeSize);

    while (true)
    {
        clearConsole();
        char *view = get_view(space, spaceSize);
        displayView(view);
        this_thread::sleep_for(chrono::milliseconds((int)(1000 / fps)));
        circularMoveXYZ(&space, spaceSize, cubeSize, XPIDivisor, ZPIDivisor);
        free(view);
    }

    exit(EXIT_SUCCESS);
}