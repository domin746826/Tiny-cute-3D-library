/*    Tiny cute 3D library
*
*   Low level 2D functions
*
*   Author (Discord): デビルとプログラマー、オタク#7830
*   Author (Github): polandoDOMINO5nihon
*/

#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_
#include "Point.h"
#include <X11/Xlib.h>

extern Display *di;//syf
extern int sc;
extern Window ro;
extern Window wi;
extern GC gc;

void setPixel(int x, int y, int color);
void drawHLine(Point2D point1, Point2D point2, int color);
int initGraphics(int width, int height);
void drawRect(Point2D location, Point2D size, int color);
void deinitGraphics();
Point2D getResolution();
void drawLine(Point2D point1, Point2D point2, int color);

#endif
