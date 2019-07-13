/*    Tiny cute 3D library
*
*   Code loading texture from file to RAM
*
*   Author (Discord): デビルとプログラマー、オタク#7830
*/

#include <inttypes.h>
#include <iostream>
#include <fstream>
#include <string>
#include "loadTexture.h"

using namespace std ;

uint16_t read16(ifstream &file) ;
uint32_t read32(ifstream &file) ;

int loadTexture(string filename, int *&table, int &width, int &height) //read texture from file to RAM
{
    ifstream texture_file;
	texture_file.open(filename, ios::binary | ios::in) ;

   	if(!texture_file.is_open())
	{
		return -1 ;
	}

	if(read16(texture_file) != 0x4D42) //invalid start of bitmap
	{
		return -2 ;
	}

	uint8_t dumb[20] = {0} ;
	texture_file.read((char*)dumb, 12) ; //not used bytes

	if(read32(texture_file) != 40) //invalid header type
	{
		return -3 ;
	}

	width = read32(texture_file) ;
	height = read32(texture_file) ;

	if(read16(texture_file) != 1)	//invalid number of planes
	{
		return -5 ;
	}

	if(read16(texture_file) != 24)	//invalid bit depth
	{
		return -6 ;
	}

	if(read32(texture_file) != 0)	//compressed bitmaps are not currently supported
	{
		return -7 ;
	}

	texture_file.read((char*)dumb, 20) ;

	//all valid

  table = new int[height*width*2] ;
  int align = 4-((width*3)%4) ; //align to 4

	for(int y = height ; y > 0 ; y--)
	{
		for(int x = 0 ; x < width ; x++)
		{
			uint8_t colour[3] = {0} ;
			texture_file.read((char*)colour, 3) ;	//read colors
			table[y*width+x-width] = colour[0] + colour[1]*256 + colour[2]*65536 ;
		}
    texture_file.read((char*)dumb, align) ;
	}
	texture_file.close() ;
	//delete[] buffer ;
	return 0 ;
}

uint16_t read16(ifstream &file)
{
	uint8_t value[2] = {0} ;
    file.read((char*)value, 2) ;
	return value[0] + value[1]*256 ;
}

uint32_t read32(ifstream &file)
{
	return read16(file) + (read16(file) * 0x00010000) ;
}
