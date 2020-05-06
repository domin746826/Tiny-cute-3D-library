#include <iostream>
#include "src/Point.h"
#include "src/primitives.h"
#include "src/Plate.h"
#include "src/Object.h"

using namespace std;

Object createCube()
{
	Object cube;

	Point3D p1(-50, 50, 50);
	Point3D p2(50, 50, 50);
	Point3D p3(-50, -50, 50);
	Point3D p4(50, -50, 50);
	Point3D p5(-50, 50, -50);
	Point3D p6(50, 50, -50);
	Point3D p7(-50, -50, -50);
	Point3D p8(50, -50, -50);

	Plate plate1(p1, p2, p3, p4);
	Plate plate2(p5, p6, p7, p8);
	Plate plate3(p5, p6, p1, p2);
	Plate plate4(p7, p8, p3, p4);
	Plate plate5(p5, p1, p7, p3);
	Plate plate6(p2, p6, p4, p8);

	cube.addPlate(plate1);
	cube.addPlate(plate2);
	cube.addPlate(plate3);
	cube.addPlate(plate4);
	cube.addPlate(plate5);
	cube.addPlate(plate6);

	return cube;
}

int main()
{
	initGraphics(1920, 1040);

	Point3D rotation(0.2, 0.5, 0); //cam rotation
	Point3D camPosition(0, 0, 400); //cam position in world

	Point3D position1(0, 0, -800);
	Point3D position2(100, 0, -500);
	Point3D position3(200, 0, -500);
	Point3D position4(300, 0, -500);
	Point3D position5(300, -100, -500);
	Point3D position6(0, -100, -800);

	cout << "TC3L Test" << endl;

	Object cube[16];

	for(int i = 0; i < 16; i++)
	{
		cube[i] = createCube();
		cube[i].setCameraRotation(rotation);
		cube[i].setCameraPosition(camPosition);
	}

	cube[0].setPosition(position1);
	cube[1].setPosition(position2);
	cube[2].setPosition(position3);
	cube[3].setPosition(position4);
	cube[4].setPosition(position5);
	cube[5].setPosition(position6);

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
			cube[0].render();
			cube[1].render();
			cube[2].render();
			cube[3].render();
			cube[4].render();
			cube[5].render();
		}
	}
	return 0;
}
