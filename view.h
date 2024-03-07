#ifndef VIEW_H
#define VIEW_H

#include <map>
#include <vector>
#include <list>

using namespace std;

char *get_view(map<char, vector<vector<double>>> space, int spaceSize);

void clearConsole();

void displayView(char *view);

#endif