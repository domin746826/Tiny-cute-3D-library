#include "3DObject.h"
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include "Point.h"
#include "loadTexture.h"
#include "Texture.h"
#include "primitives.h"
#include <unistd.h>
/*
 *      Example code for cube
 *
 *TC3L:6
 *1:-10:10:-10  10:10:-10 -10:10:10 10:10:10
 *2:-10:10:10 10:10:10  -10:-10:10  10:-10:10
 *3:10:10:10  10:10:-10 10:-10:10 10:-10:-10
 *4:10:10:-10 10:10:-10 -10:-10:-10 10:-10:-10
 *5:-10:10:10 -10:10:-10  -10:-10:10  -10:-10:-10
 *6:-10:-10:-10 10:-10:-10  -10:-10:10  10:-10:10
*/

using namespace std ;

int D3Object::loadTextures(int textureID, int* textureData)
{
  textures[textureID] = textureData ;
  return OK ;
}

D3Object::D3Object(int xsize, int ysize)
{
  xPosition = 1 ;
  yPosition = 2 ;
  zPosition = 0 ;
  xTextureSize = xsize ;
  yTextureSize = ysize ;

  xDegree = 0.5 ;
  yDegree = 0.4;
  zDegree = 0 ;

  charPos = 0 ;
}

D3Object::~D3Object()
{
  delete[] textures ;
  delete structureShape ;
  delete workBuffer ;
  delete objectName ;
}

void D3Object::loadStructureShape(char* shape)
{
  workBuffer = new char[1024] ; //should be ok
  structureShape = shape ;
  //cout << structureShape ;

  platesNum = countOccurencies(structureShape, '\n') ;
  textures = new int*[platesNum] ; //creating buffer for textures' addresses
}

int D3Object::renderObject()
{
  cout << "***Begin rendering object***\n" ;
  cout << "Name: " << objectName << "\n" ;

  cout << "Number of plates: " << platesNum << "\n" ;

  charPos = 0 ;
  for(int i = 0 ; i < 6 ; i++)
  {
    workBuffer[i] = getChar() ;
  }
  workBuffer[6] = 0 ;

  if(strcmp(workBuffer, "TC3L:\n") != 0)
  {
    cout << "Error: not valid signature: " << workBuffer << "\n" ;
    return INVALID_SIGNATURE ;
  }

  for(int i = 0 ; i < platesNum ; i++)
  {
    getInt() ; //first number is helper

    for(int i2 = 0 ; i2 < 4 ; i2++)
    {
      for(int i3 = 0 ; i3 < 3 ; i3++)
      {
        renderTable[i2][i3] = getInt()*10 ;
      }
    }

    for(int i2 = 0 ; i2 < 4 ; i2++)
    {
      renderTable[i2][1] = renderTable[i2][1]*cos(xDegree) - renderTable[i2][2]*sin(xDegree) ;
      renderTable[i2][2] = renderTable[i2][1]*sin(xDegree) + renderTable[i2][2]*cos(xDegree) ;

      renderTable[i2][0] = renderTable[i2][2]*sin(yDegree) + renderTable[i2][0]*cos(yDegree) ;
      renderTable[i2][2] = renderTable[i2][2]*cos(yDegree) - renderTable[i2][0]*sin(yDegree) ;

      renderTable[i2][0] = renderTable[i2][0]*cos(zDegree) - renderTable[i2][1]*sin(zDegree) ;
      renderTable[i2][1] = renderTable[i2][0]*sin(zDegree) + renderTable[i2][1]*cos(zDegree) ;
    }

    //Temporary code only for testing if all works properly
    //TODO remove code under and replace it with final code and make class Texture not rendering instantly

    Point punkt1(renderTable[0][0]+300, renderTable[0][1]+300) ;
    Point punkt2(renderTable[1][0]+300, renderTable[1][1]+300) ;
    Point punkt3(renderTable[2][0]+300, renderTable[2][1]+300) ;
    Point punkt4(renderTable[3][0]+300, renderTable[3][1]+300) ;

    cout << "\n\nPoint1: " << punkt1.x << " " << punkt1.y << "\n" ;
    cout << "Point2: " << punkt2.x << " " << punkt2.y << "\n" ;
    cout << "Point3: " << punkt3.x << " " << punkt3.y << "\n" ;
    cout << "Point4: " << punkt4.x << " " << punkt4.y << "\n" ;

    int *teksturaraw ; //comment up to 'delete[] teks...' to remove texturing
    int txtwidth, txtheight ;
    Texture teksturka(800, 600) ;
    loadTexture("res/dirt.bmp", teksturaraw, txtwidth, txtheight) ; //load to buffer
    teksturka.drawIrregularTexture(punkt1, punkt2, punkt3, punkt4, txtwidth, txtheight, teksturaraw) ;
    delete[] teksturaraw ;

    drawHLine(punkt1, punkt2, 0) ;
    drawHLine(punkt3, punkt4, 0) ;
    drawHLine(punkt1, punkt3, 0) ;
    drawHLine(punkt2, punkt4, 0) ;

    for(int i2 = 0 ; i2 < 4 ; i2++)
    {
      for(int i3 = 0 ; i3 < 3 ; i3++)
      {
        cout << renderTable[i2][i3] << " " ;
      }
      cout << "\t" ;
    }
    cout << "\n" ;
  }

  cout << "***End rendering object***\n\n" ;
}

char D3Object::getChar()
{
  return structureShape[charPos++] ;
}

long D3Object::getInt()
{
  char i = 0 ;
  char strToParse[16] = {0} ;
  long resultInt = 0 ;

  while(strToParse[i-1] != '\n' && strToParse[i-1] != ' ' && strToParse[i-1] != ':')
  {
    strToParse[i++] = getChar() ;
  }

  i-- ;

  //cout << " ->" << strToParse << "<- " ;

  if(strToParse[0] == '-')
  {
    for(int i2 = 1 ; i2 < i ; i2++)
    {
      resultInt += (strToParse[i2] - 48) * pow(10, i-i2-1) ;
    }
    return -resultInt ;
  }

  for(int i2 = 0 ; i2 < i ; i2++)
  {
    resultInt += (strToParse[i2] - 48) * pow(10, i-i2-1) ;
  }
  return resultInt ;
}

int D3Object::countOccurencies(char* str, char ch)
{
  int i = 0 ;
  int Count = 0 ;

  while(str[i] != '\0')
  {
  	if(str[i] == ch)
  	{
    		Count++;
   	}
 	  i++;
	}
  return Count ;
}

int D3Object::setName(char* name)
{
  objectName = name ;
}

char* D3Object::getName()
{
  return objectName ;
}
