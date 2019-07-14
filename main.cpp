#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include "3d/loadTexture.h"
#include "3d/Point.h"
#include "3d/primitives.h"
#include "3d/Texture.h"


void redraw()
{

	Point punkt1 ;
	Point punkt2 ;
	Point punkt3 ;
	Point punkt4 ;

	//location of corners
	//punkt 1 - upper left    |    2 - upper right
	//punkt 3 - lower left    |    4 - lower right
	punkt1.x = 80 ; punkt1.y = 60 ;
	punkt2.x = 420 ; punkt2.y = 80 ;
	punkt3.x = 100 ; punkt3.y = 400 ;
	punkt4.x = 400 ; punkt4.y = 480 ;

	Texture teksturka(800, 600) ;

	int *teksturaraw ;
	int txtwidth, txtheight ;
	loadTexture("res/icon.bmp", teksturaraw, txtwidth, txtheight) ; //load to buffer
	teksturka.drawIrregularTexture(punkt1, punkt2, punkt3, punkt4, txtwidth, txtheight, teksturaraw) ;
	delete[] teksturaraw ;
}

int main() //syf
{
	initGraphics(800, 600) ;
	redraw() ;

	//Select what events the window will listen to
	XSelectInput(di, wi, KeyPressMask | ExposureMask);
	XEvent ev;
	int quit = 0;
	while (!quit) {
		int a = XNextEvent(di, &ev);
		if (ev.type == KeyPress)
			quit = 1; // quit if someone presses a key
		if (ev.type == Expose) {
			//setPixel(10, 10, 0x00ff00); //green
			redraw() ;
		}
	}
	deinitGraphics() ;
	return 0;
}
