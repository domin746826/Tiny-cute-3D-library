/*    Tiny cute 3D library
*
*   Main Texture class file
*   Author (Discord): デビルとプログラマー、オタク#7830
*   Author (Github): polandoDOMINO5nihon
*/

#include "Texture.h"
#include "primitives.h"
#include <iostream>


void Texture::fillShape(Point point1, Point point2, Point point3, Point point4, int color)
{
	for(int i = 0 ; i < ySize ; i++)
	{
		minTable[i] = 8191 ;
		maxTable[i] = 0 ;
	}
	maxMinLine(point1, point2) ;
	maxMinLine(point3, point4) ;

	maxMinLine(point1, point3) ;
	maxMinLine(point2, point4) ;

	for(int i = 0 ; i < ySize ; i++)
	{
		if(minTable[i] != 8191 && maxTable[i] != 0)
		{
			Point tmp1(minTable[i], i) ;
			Point tmp2(maxTable[i], i) ;

			drawHLine(tmp1, tmp2, color) ;
		}
	}
}

Texture::Texture(int screenSizex, int screenSizey)
{
	xSize = screenSizex ;
	ySize = screenSizey ;
	minTable = new int[screenSizey] ;
	maxTable = new int[screenSizey] ;
}

Texture::~Texture()
{
	delete[] minTable, maxTable, txtMatrix ;
}

void Texture::maxMinLine(Point point1, Point point2)		//partially stolen from wikipedia
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
  			if(minTable[y] == 8191)
  			{
  				minTable[y] = x ;
  			}
  			if(maxTable[y] == 0)
  			{
  				maxTable[y] = x ;
  			}
  			if(x < minTable[y])
  			{
  				minTable[y] = x ;
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
             if(minTable[y] == 8191)
       			{
       				minTable[y] = x ;
       			}
       			if(maxTable[y] == 0)
       			{
       				maxTable[y] = x ;
       			}
       			if(x < minTable[y])
       			{
       				minTable[y] = x ;
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
	txtMatrix = new Point[(sizex+1)*(sizey+1)];

	FPoint localPoint1(point1.x, point1.y) ;
	FPoint localPoint2(point2.x, point2.y) ;
	FPoint localPoint3(point3.x, point3.y) ;
	FPoint localPoint4(point4.x, point4.y) ;

  FPoint shift1 ;
	FPoint shift2 ;
	shift1 = (localPoint3 - localPoint1)/sizey ;
	shift2 = (localPoint4 - localPoint2)/sizey ;

	for(int y = 0 ; y < (sizey+1) ; y++)
	{
		FPoint xshift ;
		xshift = (localPoint2 - localPoint1)/sizex ;

		for(int x = 0 ; x < (sizex+1) ; x++)
		{
			txtMatrix[x+y*(sizex+1)].x = localPoint1.x + xshift.x*x ;
			txtMatrix[x+y*(sizex+1)].y = localPoint1.y + xshift.y*x ;
		}
		localPoint1 = localPoint1 + shift1 ;
		localPoint2 = localPoint2 + shift2 ;
	}

	for(int y = 0 ; y < sizey ; y++)//fast texturing
	{
		for(int x = 0 ; x < sizex ; x++)
		{
			//drawRect(txtMatrix[x+y*(sizex+1)], txtMatrix[x+(y+1)*(sizex+1)+1]-txtMatrix[x+y*(sizex+1)], txt[y*(sizex)+x]) ;
			drawRect(txtMatrix[x+y*(sizex+1)], txtMatrix[x+(y+1)*(sizex+1)+1]-txtMatrix[x+y*(sizex+1)], txt[y*(sizex)+x]) ;
			drawRect(txtMatrix[x+y*(sizex+1)+1], txtMatrix[x+(y+1)*(sizex+1)]-txtMatrix[x+y*(sizex+1)+1], txt[y*(sizex)+x]) ;
		}
	}

	//TODO auto switching between fast texturing and precious texturing
/*
	for(int y = 0 ; y < (sizey+1) ; y++) //precious texturing
	{
		//drawLine(punkt1, punkt2, 0x000000) ;

		FPoint xshift ;
		xshift = (localPoint2 - localPoint1)/sizex ;

		for(int x = 0 ; x < (sizex+1) ; x++)
		{
			txtMatrix[x+y*(sizex+1)].x = localPoint1.x + xshift.x*x ;
			txtMatrix[x+y*(sizex+1)].y = localPoint1.y + xshift.y*x ;
		}
		localPoint1 = localPoint1 + shift1 ;
		localPoint2 = localPoint2 + shift2 ;
	}

	for(int y = 0 ; y < sizey ; y++)
	{
		for(int x = 0 ; x < sizex ; x++)
		{
			fillShape(txtMatrix[x+y*(sizex+1)], txtMatrix[x+y*(sizex+1)+1], txtMatrix[x+(y+1)*(sizex+1)], txtMatrix[x+(y+1)*(sizex+1)+1], txt[y*(sizex)+x]) ;
		}
	}*/
}
