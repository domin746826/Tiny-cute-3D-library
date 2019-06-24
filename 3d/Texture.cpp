/*    Tiny cute 3D library
*
*   Main Texture class file
*   Author (Discord): デビルとプログラマー、オタク#7830
*/

#include "Texture.h"


void Texture::fillShape(Point punkt1, Point punkt2, Point punkt3, Point punkt4, int color)
{

}


void Texture::maxMinLine(Point point1, Point point2, int color)		//stolen from wiki
{

	int x1 = point1.x ;
	int y1 = point1.y ;

	int x2 = point2.x ;
	int y2 = point2.y ;

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
  			if(minTable[y] == 0)
  			{
  				minTable[y] = x ;
  			}
  			if(maxTable[y] == 0)
  			{
  				maxTable[y] = x ;
  			}
  			if(x < maxTable[y])
  			{
  				maxTable[y] = x ;
  			}
  			else if(x > maxTable[y])
  			{
  				maxTable[y] = x ;
  			}
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
             if(minTable[y] == 0)
       			{
       				minTable[y] = x ;
       			}
       			if(maxTable[y] == 0)
       			{
       				maxTable[y] = x ;
       			}
       			if(x < maxTable[y])
       			{
       				maxTable[y] = x ;
       			}
       			else if(x > maxTable[y])
       			{
       				maxTable[y] = x ;
       			}
         }
     }
}

void Texture::drawIrregularTexture(Point point1, Point point2, Point point3, Point point4, int sizex, int sizey, int* txt)
{
  Point shift1 ;
	Point shift2 ;
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
