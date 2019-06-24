#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Point.h"

class Texture
{
  private:
    int* minTable ;
    int* maxTable ;

    Texture();
    void fillShape(Point punkt1, Point punkt2, Point punkt3, Point punkt4, int color) ;
    void maxMinLine(Point point1, Point point2, int color) ;

    void drawIrregularTexture(Point punkt1, Point punkt2, Point punkt3, Point punkt4, int sizex, int sizey, int* txt) ;
};


#endif
