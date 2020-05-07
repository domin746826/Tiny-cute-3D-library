/*    Tiny cute 3D library
*
*   Low level 2D functions, edit if you want to port my library
*
*   Author (Discord): デビルとプログラマー、オタク#7830
*   Author (Github): polandoDOMINO5nihon
*/

#include "primitives.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

Display *di ;
int sc    ;
Window ro ;
Window wi ;
GC gc ;
Pixmap double_buffer;
XWindowAttributes wa;
void setPixel(int x, int y, int color)
{
	XSetForeground(di, gc, color);
	XDrawPoint(di, double_buffer, gc, x, y);
}

void drawHLine(Point2D point1, Point2D point2, int color) //h line used to texturing
{
	XSetForeground(di, gc, color);
	XDrawLine(di, double_buffer, gc, point1.x, point1.y, point2.x, point2.y);

}

void drawLine(Point2D point1, Point2D point2, int color)
{
	XSetForeground(di, gc, color);
	XDrawLine(di, double_buffer, gc, point1.x, point1.y, point2.x, point2.y);
}


void drawRect(Point2D location, Point2D size, int color)
{
	XSetForeground(di, gc, color);
	if(size.x > 0 && size.y > 0)
	{
		XFillRectangle(di,wi, gc, location.x, location.y, size.x, size.y);
		return ;
	}
	if(size.x < 0 && size.y > 0)
	{
		XFillRectangle(di,wi,gc, location.x+size.x, location.y, 0-size.x, size.y);
		return ;
	}
	if(size.x > 0 && size.y < 0)
	{
		XFillRectangle(di,wi,gc, location.x, location.y+size.y, size.x, 0-size.y);
		return ;
	}
	if(size.x < 0 && size.y < 0)
	{
		XFillRectangle(di,wi,gc, location.x+size.x, location.y+size.y, 0-size.x, 0-size.y);
		return ;
	}
}

int initGraphics(int width, int height)
{
  //Open Display
	di = XOpenDisplay(getenv("DISPLAY"));
	if (di == NULL) {
		printf("Couldn't open display.\n");
		return -1;
	}

	//Create Window

	sc = DefaultScreen(di);
	ro = DefaultRootWindow(di);
	XGetWindowAttributes(di, ro, &wa);
	wi = XCreateSimpleWindow(di, ro, 0, 0, width, height, 1, BlackPixel(di, sc), WhitePixel(di, sc));
	XMapWindow(di, wi); //Make window visible
	XStoreName(di, wi, "test 3d"); // Set window title

	gc = XCreateGC(di, ro, 0, NULL);

	double_buffer = XCreatePixmap(di, ro,
                  wa.width, wa.height, wa.depth);
}

void deinitGraphics()
{
  XFreeGC(di, gc);
	XDestroyWindow(di, wi);
	XCloseDisplay(di);
}

void redrawBuf()
{
	XGetWindowAttributes(di, ro, &wa);
	XCopyArea(di, double_buffer, wi, gc, 0, 0, wa.width, wa.height, 0, 0);
	XSetForeground(di, gc, 0);
  XFillRectangle(di, double_buffer, gc, 0, 0, wa.width, wa.height);
}
