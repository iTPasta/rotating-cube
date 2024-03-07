#include <iostream>
#include <map>
#include <vector>
#include <thread>
#include <chrono>
#include <math.h>
#include "view.h"
#include "draw.h"
#include "move.h"
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 4 || 6 < argc)
    {
        cout << "Usage: " << argv[0] << " spaceSize cubeSize fps [XPIDivisor] [ZPIDivisor]\n";
        exit(EXIT_FAILURE);
    }

    const int spaceSize = atoi(argv[1]);
    const int cubeSize = atoi(argv[2]);
    const int fps = atoi(argv[3]);
    const double XPIDivisor = argc >= 5 ? (double)atoi(argv[4]) : 24.;
    const double ZPIDivisor = argc == 5 ? (double)atoi(argv[4]) : (argc == 6 ? (double)atoi(argv[5]) : 24.);

    if (spaceSize < cubeSize)
    {
        cout << "Space size must be greater than cube size.\n";
        exit(EXIT_FAILURE);
    }

    if (spaceSize % 2 != 0 || cubeSize % 2 != 0)
    {
        cout << "Space size and cube size must be even." << endl;
        exit(EXIT_FAILURE);
    }

    {
        const double center[] = {(double)spaceSize / 2., (double)spaceSize / 2., (double)spaceSize / 2.};
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