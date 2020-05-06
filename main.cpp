#include <iostream>
#include <string.h>
#include "src/Point.h"
#include "src/primitives.h"
#include "src/Plate.h"
#include "src/Cube.h"

using namespace std;

int main()
{
	initGraphics(1920, 1040);

	//if int in constructor argument - it's size of points apart from each other
	Cube *cube = new Cube(30);

	Point3D rotation(0, 0, 0);
	Point3D position(0, 0, -100);

	cout << "TC3L Test" << endl;
	cube->SetCamera(position, rotation);
	cube->PlatesRender();
	cube->PlatesDisplay();

	XSelectInput(di, wi, KeyPressMask | KeyReleaseMask | ExposureMask);
	XEvent ev;
	XMotionEvent myszelel;
	XKeyEvent bieg;

	int quit = 0;
	while (!quit)
	{
		int a = XNextEvent(di, &ev);
		//int b = XQueryPointer(di, &myszelel);
		
		if (ev.type == Expose)
		{
			cube->Rotate(0, 0.1, 0);
			cube->PlatesRender();
			cube->PlatesDisplay();
		}
	}
	return 0;
}
