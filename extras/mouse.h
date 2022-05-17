#ifndef MOUSE_H_
#define MOUSE_H_
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include "../src/Point.h"
#include <string>

using namespace std;
class Mouse
{
	private:
		string devName;
		uint8_t buttons;
	public:
		Mouse(string dev);
		~Mouse();
		Point2D getParsed();
		int init();
};

#endif
