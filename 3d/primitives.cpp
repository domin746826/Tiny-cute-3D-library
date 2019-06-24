#include "primitives.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

Display *di ;//syf
int sc    ;
Window ro ;
Window wi ;
GC gc ;

void setPixel(int x, int y, int color) //pikselik
{
	XSetForeground(di, gc, color);
	XDrawPoint(di, wi, gc, x, y);
}

void drawHLine(Point punkt1, Point punkt2, int color) //linia, używana poziomo do teksturowania
{
	XSetForeground(di, gc, color);
	XDrawLine(di, wi, gc, punkt1.x, punkt1.y, punkt2.x, punkt2.y);
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

	sc    = DefaultScreen(di);
	ro = DefaultRootWindow(di);
	wi = XCreateSimpleWindow(di, ro, 0, 0, width, height, 1,
                                BlackPixel(di, sc), WhitePixel(di, sc));
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
