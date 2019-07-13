#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_
#include "Point.h"
#include <X11/Xlib.h>

extern Display *di ;//syf
extern int sc    ;
extern Window ro ;
extern Window wi ;
extern GC gc ;

void setPixel(int x, int y, int color) ;
void drawHLine(Point point1, Point point2, int color) ;
int initGraphics(int width, int height) ;
void deinitGraphics() ;

#endif
