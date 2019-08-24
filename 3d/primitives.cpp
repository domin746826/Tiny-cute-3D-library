#include "primitives.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

Display *di ;
int sc    ;
Window ro ;
Window wi ;
GC gc ;

void setPixel(int x, int y, int color)
{
	XSetForeground(di, gc, color);
	XDrawPoint(di, wi, gc, x, y);
}

void drawHLine(Point point1, Point point2, int color) //h line used to texturing
{
	XSetForeground(di, gc, color);
	XDrawLine(di, wi, gc, point1.x, point1.y, point2.x, point2.y);
}


void drawRect(Point location, Point size, int color)
{
	XSetForeground(di, gc, color);
	if(size.x > 0 && size.y > 0)
	{
		XFillRectangle(di,wi,gc, location.x, location.y, size.x, size.y);
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
	wi = XCreateSimpleWindow(di, ro, 0, 0, width, height, 1, BlackPixel(di, sc), WhitePixel(di, sc));
	XMapWindow(di, wi); //Make window visible
	XStoreName(di, wi, "test 3d"); // Set window title

	gc = XCreateGC(di, ro, 0, NULL);
}

void deinitGraphics()
{
  XFreeGC(di, gc);
	XDestroyWindow(di, wi);
	XCloseDisplay(di);
}
