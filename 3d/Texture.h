#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Point.h"

class Texture
{
  private:
    int* minTable ;
    int* maxTable ;
    Point* txtMatrix ;
    int xSize ;
    int ySize ;
public:
    void fillShape(Point point1, Point point2, Point point3, Point point4, int color) ;
    void maxMinLine(Point point1, Point point2) ;

    Texture(int screenSizex, int screenSizey) ;
    ~Texture() ;
    void drawIrregularTexture(Point punkt1, Point punkt2, Point punkt3, Point punkt4, int sizex, int sizey, int* txt) ;
};


#endif
