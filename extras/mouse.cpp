/*    Tiny cute 3D library
*
*   Non-blocking mouse, usable for games
*	Needs sudo or to be in input group
*
*   Author (Discord): Hisonka#4156
*   Author (Github): domin746826
*/
 
#include "mouse.h"

Mouse::Mouse(string dev)
{
	devName = dev;
}

Mouse::~Mouse()
{
	close(fd);
}

int Mouse::init()
{
	fd = open(devName.c_str(), O_RDWR);
    if(fd == -1)
    	return -1;
	else
		return 0; 
}

Point2D Mouse::getParsed()
{
	Point2D returnVal(0, 0);
	struct timeval tv;
	fd_set readfds;

	tv.tv_sec = 0;
	tv.tv_usec = 400;

	FD_ZERO(&readfds);
	FD_SET( fd, & readfds );


	select(fd + 1, &readfds, NULL, NULL, & tv );

	if( FD_ISSET(fd, & readfds ) )
	{
		uint8_t bytes = read(fd, data, sizeof(data));
		if(bytes > 0)
		{
			returnVal.x = data[1];
			returnVal.y = data[2];
		}
	}

	return returnVal;
}
