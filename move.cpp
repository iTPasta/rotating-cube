#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

#include "utils.h"

void circularMoveXY(map<char, vector<vector<double>>> *pSpace, int spaceSize, int cubeSize, double XPIDivisor, double ZPIDivisor)
{
    double stepX = (1. / XPIDivisor) * M_PI;

    map<char, vector<vector<double>>> space = *pSpace;
    map<char, vector<vector<double>>> newSpace;

    for (map<char, vector<vector<double>>>::iterator it = space.begin(); it != space.end(); ++it)
    {
        char key = it->first;
        vector<vector<double>> val = it->second;

        if (key == ' ')
        {
            newSpace.insert(make_pair(key, val));
            break;
        }

        const double center[] = {(double)spaceSize / 2,
                                 (double)spaceSize / 2,
                                 (double)spaceSize / 2};
        vector<vector<double>> newVal;
        for (int i = 0; i < val.size(); i++)
        {
            vector<double> newPoint;

            vector<double> point = val.at(i);
            double x = point.at(0);
            double y = point.at(1);
            double z = point.at(2);

            double mod = sqrt(pow(x - center[0], 2) + pow(y - center[1], 2));

            double cosTheta = (x - center[0]) / mod;
            double theta = 0 <= (y - center[1]) ? acos(cosTheta) : acos(cosTheta) + ((M_PI - acos(cosTheta)) * 2);

            /*cout << "Avant : "
                 << "x = " << x << "; y = ;" << y << "; z = " << z << endl;*/
            x = center[0] + mod * cos(theta + stepX);
            y = center[1] + mod * sin(theta + stepX);

            /*
            cout << "Valeurs : "
                 << "mod = " << mod << "; cosTheta = " << cosTheta << "; arccos(" << cosTheta << ") = " << acos(cosTheta) << "; theta = " << theta << endl;
            cout << "x = " << center[0] << " + (" << mod << " * " << cos(theta + stepX) << "); avec step = " << step << endl;
            cout << "y = " << center[1] << " + (" << mod << " * " << sin(theta + stepX) << ")" << endl;
            cout << "Après : "
                 << "x = " << x << "; y = ;" << y << "; z = " << z << endl;
            cout << endl;
            */

            newPoint.push_back(x);
            newPoint.push_back(y);
            newPoint.push_back(z);

            newVal.push_back(newPoint);
        }

        newSpace.insert(make_pair(key, newVal));
    }

    *pSpace = newSpace;
}

void circularMoveXYZ(map<char, vector<vector<double>>> *pSpace, int spaceSize, int cubeSize, double XPIDivisor, double ZPIDivisor)
{
    double stepX = (1. / XPIDivisor) * M_PI;
    double stepZ = (1. / ZPIDivisor) * M_PI;

    map<char, vector<vector<double>>> space = *pSpace;
    map<char, vector<vector<double>>> newSpace;

    for (map<char, vector<vector<double>>>::iterator it = space.begin(); it != space.end(); ++it)
    {
        char key = it->first;
        vector<vector<double>> val = it->second;

        if (key == ' ')
        {
            newSpace.insert(make_pair(key, val));
            break;
        }

        const double center[] = {(double)spaceSize / 2,
                                 (double)spaceSize / 2,
                                 (double)spaceSize / 2};
        vector<vector<double>> newVal;
        for (int i = 0; i < val.size(); i++)
        {
            vector<double> newPoint;

            vector<double> point = val.at(i);
            double x = point.at(0);
            double y = point.at(1);
            double z = point.at(2);

            {

                double mod = sqrt(pow(x - center[0], 2) + pow(y - center[1], 2));

                double cosTheta = (x - center[0]) / mod;
                double theta = 0 <= (y - center[1]) ? acos(cosTheta) : acos(cosTheta) + ((M_PI - acos(cosTheta)) * 2);

                /*cout << "Avant : "
                     << "x = " << x << "; y = ;" << y << "; z = " << z << endl;*/
                x = center[0] + mod * cos(theta + stepX);
                y = center[1] + mod * sin(theta + stepX);

                /*cout << "Valeurs : "
                     << "mod = " << mod << "; cosTheta = " << cosTheta << "; arccos(" << cosTheta << ") = " << acos(cosTheta) << "; theta = " << theta << endl;
                cout << "x = " << center[0] << " + (" << mod << " * " << cos(theta + stepX) << "); avec step = " << step << endl;
                cout << "y = " << center[1] << " + (" << mod << " * " << sin(theta + stepX) << ")" << endl;
                cout << "Après : "
                     << "x = " << x << "; y = ;" << y << "; z = " << z << endl;
                cout << endl;*/
            }

            {

                double mod = sqrt(pow(x - center[0], 2) + pow(z - center[2], 2));

                double cosTheta = (x - center[0]) / mod;
                double theta = 0 <= (z - center[2]) ? acos(cosTheta) : acos(cosTheta) + ((M_PI - acos(cosTheta)) * 2);

                /*cout << "Avant : "
                     << "x = " << x << "; y = ;" << y << "; z = " << z << endl;*/
                x = center[2] + mod * cos(theta + (2 * M_PI - stepZ));
                z = center[2] + mod * sin(theta + (2 * M_PI - stepZ));

                /*cout << "Valeurs : "
                     << "mod = " << mod << "; cosTheta = " << cosTheta << "; arccos(" << cosTheta << ") = " << acos(cosTheta) << "; theta = " << theta << endl;
                cout << "x = " << center[0] << " + (" << mod << " * " << cos(theta + stepZ) << "); avec step = " << step << endl;
                cout << "y = " << center[1] << " + (" << mod << " * " << sin(theta + stepZ) << ")" << endl;
                cout << "z = " << center[2] << " + (" << mod << " * " << sin(theta + (2 * M_PI - step * 1.5)) << ")" << endl;
                cout << "Après : "
                     << "x = " << x << "; y = ;" << y << "; z = " << z << endl;
                cout << endl
                     << endl;*/
            }

            newPoint.push_back(x);
            newPoint.push_back(y);
            newPoint.push_back(z);

            newVal.push_back(newPoint);
        }

        newSpace.insert(make_pair(key, newVal));
    }

    *pSpace = newSpace;
}