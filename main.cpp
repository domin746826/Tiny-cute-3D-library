#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include "3d/loadTexture.h"
#include "3d/Point.h"
#include "3d/primitives.h"

int tabelaDanychL[800] = {0} ; //do kubełka z painta tablica wartości granicznych
int tabelaDanychH[800] = {0} ;

/*struct Point	//prosta struktura zeby się iksy i y nie mieszały
{
	float x = 0 ;
	float y = 0 ;
} ;  */

Point tekstura[17][17]  ; //x y, używane przy wyliczaniu textury


void BresenhamLine(Point punkt1, Point punkt2, int color)		//z wiki podebrane i przerobione by wyliczało punkty graniczne wielokąta
{

	int x1 = punkt1.x ;
	int y1 = punkt1.y ;

	int x2 = punkt2.x ;
	int y2 = punkt2.y ;

     int d, dx, dy, ai, bi, xi, yi;
     int x = x1, y = y1;
     if (x1 < x2)
     {
         xi = 1;
         dx = x2 - x1;
     }
     else
     {
         xi = -1;
         dx = x1 - x2;
     }
     if (y1 < y2)
     {
         yi = 1;
         dy = y2 - y1;
     }
     else
     {
         yi = -1;
         dy = y1 - y2;
     }
     //glVertex2i(x, y);
     if (dx > dy)
     {
         ai = (dy - dx) * 2;
         bi = dy * 2;
         d = bi - dx;
         while (x != x2)
         {
             if (d >= 0)
             {
                 x += xi;
                 y += yi;
                 d += ai;
             }
             else
             {
                 d += bi;
                 x += xi;
             }
			if(tabelaDanychL[y] == 0)			//17 linijek licząc od tej napisane
			{
				tabelaDanychL[y] = x ;
			}
			if(tabelaDanychH[y] == 0)
			{
				tabelaDanychH[y] = x ;
			}
			if(x < tabelaDanychL[y])
			{
				tabelaDanychL[y] = x ;
			}
			else if(x > tabelaDanychH[y])
			{
				tabelaDanychH[y] = x ;
			}
			setPixel(x, y, color) ;
         }
     }
     else
     {
         ai = ( dx - dy ) * 2;
         bi = dx * 2;
         d = bi - dy;
         while (y != y2)
         {
             if (d >= 0)
             {
                 x += xi;
                 y += yi;
                 d += ai;
             }
             else
             {
                 d += bi;
                 y += yi;
             }
			if(tabelaDanychL[y] == 0)//17 linijek licząc od tej napisane
			{
				tabelaDanychL[y] = x ;
			}
			if(tabelaDanychH[y] == 0)
			{
				tabelaDanychH[y] = x ;
			}

			if(x < tabelaDanychL[y])
			{
				tabelaDanychL[y] = x ;
			}
			else if(x > tabelaDanychH[y])
			{
				tabelaDanychH[y] = x ;
			}
			setPixel(x, y, color) ;
         }
     }
}

void fillShape(Point punkt1, Point punkt2, Point punkt3, Point punkt4, int color) //wypełnianie kształtu(kubełek z painta)
{
	for(int i = 0 ; i < 800 ; i++)
	{
		tabelaDanychL[i] = 3000 ;
		tabelaDanychH[i] = 0 ;
	}
	BresenhamLine(punkt1, punkt2, color) ;
	BresenhamLine(punkt3, punkt4, color) ;

	BresenhamLine(punkt1, punkt3, color) ;
	BresenhamLine(punkt2, punkt4, color) ;

	for(int i = 0 ; i < 800 ; i++)
	{
		if(tabelaDanychL[i] != 0 && tabelaDanychH[i] != 0)
		{
			Point tmp1 ; tmp1.x = tabelaDanychL[i] ; tmp1.y = i ;
			Point tmp2 ; tmp2.x = tabelaDanychH[i] ; tmp2.y = i ;

			drawHLine(tmp1, tmp2, color) ;
		}
	}
}

void drawIrregularTexture(Point punkt1, Point punkt2, Point punkt3, Point punkt4, int *txt)		//wyliczanie rozciągnięcia textury i texturowanie
{
	Point przesunieciey1 ;
	Point przesunieciey2 ;
	przesunieciey1.x = (punkt3.x - punkt1.x)/16 ; przesunieciey1.y = (punkt3.y - punkt1.y)/16 ;
	przesunieciey2.x = (punkt4.x - punkt2.x)/16 ; przesunieciey2.y = (punkt4.y - punkt2.y)/16 ;


	for(int y = 0 ; y < 17 ; y++)
	{
		//drawLine(punkt1, punkt2, 0x000000) ;

		Point przesunieciex ;
		przesunieciex.x = (punkt2.x - punkt1.x)/16 ; przesunieciex.y = (punkt2.y - punkt1.y)/16 ;

		for(int x = 0 ; x < 17 ; x++)
		{
			tekstura[x][y].x = punkt1.x + przesunieciex.x*x ;
			tekstura[x][y].y = punkt1.y + przesunieciex.y*x ;
		}
		punkt1.x = punkt1.x + przesunieciey1.x ; punkt1.y = punkt1.y + przesunieciey1.y ;
		punkt2.x = punkt2.x + przesunieciey2.x ; punkt2.y = punkt2.y + przesunieciey2.y ;
	}

	for(int y = 0 ; y < 16 ; y++)
	{
		for(int x = 0 ; x < 16 ; x++)
		{
			fillShape(tekstura[x][y], tekstura[x+1][y], tekstura[x][y+1], tekstura[x+1][y+1], txt[y*16+x]) ;
		}
	}
}

void przerysuj()
{
	int *teksturaraw = new int[256] ;
	loadTexture("res/grass.bmp", teksturaraw) ;

	Point punkt1 ;
	Point punkt2 ;
	Point punkt3 ;
	Point punkt4 ;

	//położenie rogów czworokąta
	//punkt 1 - lewy górny    |    2 - prawy górny
	//punkt 3 - lewy dolny    |    4 - prawy dolny
	/*punkt1.x = 80 ; punkt1.y = 60 ;
	punkt2.x = 420 ; punkt2.y = 80 ;
	punkt3.x = 100 ; punkt3.y = 400 ;
	punkt4.x = 400 ; punkt4.y = 480 ;*/

	punkt1.x = 80 ; punkt1.y = 20 ;
	punkt2.x = 260 ; punkt2.y = 20 ;
	punkt3.x = 100 ; punkt3.y = 120 ;
	punkt4.x = 240 ; punkt4.y = 120 ;

	drawIrregularTexture(punkt1, punkt2, punkt3, punkt4, teksturaraw) ;

	delete[] teksturaraw ;
}




int main() //syf
{
	initGraphics(800, 600) ;
	przerysuj() ;

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
			przerysuj() ;
		}
	}
	deinitGraphics() ;
	return 0;
}
