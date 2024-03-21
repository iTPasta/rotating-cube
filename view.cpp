#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

char *get_view(map<char, vector<vector<double>>> space, int spaceSize)
{
    double minCharForEachViewPoint[spaceSize][spaceSize][2];
    char *view = (char *)malloc((sizeof(char[spaceSize * (spaceSize + 1)])) * 2 + 1);

    for (int x = 0; x < spaceSize; x++)
        for (int y = 0; y < spaceSize; y++)
        {
            minCharForEachViewPoint[x][y][0] = ' ';
            minCharForEachViewPoint[x][y][1] = (double)spaceSize;
        }

    for (map<char, vector<vector<double>>>::iterator it = space.begin(); it != space.end(); ++it)
    {
        char key = it->first;
        vector<vector<double>> val = it->second;

        if (key == ' ')
            break;

        for (int i = 0; i < (int)val.size(); i++)
        {
            if (val.at(i).at(2) <= minCharForEachViewPoint[(int)val.at(i).at(0)][(int)val.at(i).at(1)][1])
            {
                if ((int)val.at(i).at(0) < spaceSize && (int)val.at(i).at(1) < spaceSize)
                {
                    minCharForEachViewPoint[(int)val.at(i).at(0)][(int)val.at(i).at(1)][0] = key;
                    minCharForEachViewPoint[(int)val.at(i).at(0)][(int)val.at(i).at(1)][1] = val.at(i)[2];
                }
            }
        }
    }

    for (int x = 0; x < spaceSize; x++)
    {
        for (int y = 0; y < spaceSize; y++)
        {
            view[(x * (spaceSize + 1) + y) * 2] = minCharForEachViewPoint[x][y][0];
            view[(x * (spaceSize + 1) + y) * 2 + 1] = ' ';
            // cout << "(x * (spaceSize + 1) + y) * 2 = " << (x * (spaceSize + 1) + y) * 2 << "; (x * (spaceSize + 1) + y) * 2 + 1 = " << (x * (spaceSize + 1) + y) * 2 + 1 << endl;
        }
        view[(x * (spaceSize + 1) + spaceSize) * 2] = ' ';
        view[(x * (spaceSize + 1) + spaceSize) * 2 + 1] = '\n';
        // cout << "\\n on (x * (spaceSize + 1) + spaceSize) * 2 + 1 = " << (x * (spaceSize + 1) + spaceSize) * 2 + 1 << endl;
    }
    view[((spaceSize + 1) * spaceSize) * 2] = '\0';
    // cout << "\\0 on ((spaceSize + 1) * spaceSize) * 2 = " << ((spaceSize + 1) * spaceSize) * 2 << endl;

    return view;
}

void clearConsole()
{
    char clearString[80];
    for (int i = 0; i < 80; i++)
        clearString[i] = '\n';
    clearString[79] = '\0';
    cout << clearString << endl;
}

void displayView(char *view)
{
    cout << view;
}