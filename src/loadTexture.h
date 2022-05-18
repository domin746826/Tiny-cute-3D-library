#ifndef LOADTEXTURE_H_
#define LOADTEXTURE_H_
#include <string>
#include <iostream>

using namespace std;

int loadTextureToRam(string filename, int *&table, int &width, int &height);

#endif
