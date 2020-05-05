#include <iostream>
#include "src/Point.h"
#include "src/primitives.h"
#include "src/Plate.h"

using namespace std;

int main()
{
	initGraphics(1920, 1040);
	Point3D p1(-50, 50, 50);
	Point3D p2(50, 50, 50);
	Point3D p3(-50, -50, 50);
	Point3D p4(50, -50, 50);
	Point3D p5(-50, 50, -50);
	Point3D p6(50, 50, -50);
	Point3D p7(-50, -50, -50);
	Point3D p8(50, -50, -50);

	Point3D rotation(0, 0.6, 0);
	Point3D position(0, 0, -100);

	cout << "TC3L Test" << endl;
	Plate plate1(p1, p2, p3, p4);
	Plate plate2(p5, p6, p7, p8);
	Plate plate3(p5, p6, p1, p2);
	Plate plate4(p7, p8, p3, p4);
	Plate plate5(p5, p1, p7, p3);
	Plate plate6(p2, p6, p4, p8);
	plate1.setCameraRotation(rotation);
	plate1.setCameraPosition(position);
	plate2.setCameraRotation(rotation);
	plate2.setCameraPosition(position);
	plate3.setCameraRotation(rotation);
	plate3.setCameraPosition(position);
	plate4.setCameraRotation(rotation);
	plate4.setCameraPosition(position);
	plate5.setCameraRotation(rotation);
	plate5.setCameraPosition(position);
	plate6.setCameraRotation(rotation);
	plate6.setCameraPosition(position);

	plate1.render();
	plate2.render();
	plate3.render();
	plate4.render();
	plate5.render();
	plate6.render();

	plate1.display();
	plate2.display();
	plate3.display();
	plate4.display();
	plate5.display();
	plate6.display();
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
			plate1.render();
			plate2.render();
			plate3.render();
			plate4.render();
			plate5.render();
			plate6.render();

			plate1.display();
			plate2.display();
			plate3.display();
			plate4.display();
			plate5.display();
			plate6.display();
		}
	}
	return 0;
}
