#include <iostream>
#include "src/Point.h"
#include "src/primitives.h"
#include "src/Plate.h"
#include "src/Object.h"
#include <math.h>

using namespace std;

/*Object createCube()
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
}*/



int main()
{
	initGraphics(1600, 900);

	Point3D camRotation(0.2, 0.5, 0);
	Point3D camPosition(0, 0, 400);

	Point3D position1(0, 0, -700);
	Point3D position2(0, 0, -600);
	Point3D position3(0, -100, -600);
	Point3D position4(100, -100, -600);

	Object cube(&camRotation, &camPosition);
	Object cube2(&camRotation, &camPosition);
	Object cube3(&camRotation, &camPosition);
	Object cube4(&camRotation, &camPosition);

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

	cube2.addPlate(plate1);
	cube2.addPlate(plate2);
	cube2.addPlate(plate3);
	cube2.addPlate(plate4);
	cube2.addPlate(plate5);
	cube2.addPlate(plate6);

	cube3.addPlate(plate1);
	cube3.addPlate(plate2);
	cube3.addPlate(plate3);
	cube3.addPlate(plate4);
	cube3.addPlate(plate5);
	cube3.addPlate(plate6);

	cube4.addPlate(plate1);
	cube4.addPlate(plate2);
	cube4.addPlate(plate3);
	cube4.addPlate(plate4);
	cube4.addPlate(plate5);
	cube4.addPlate(plate6);

	//camRotation.y=0.5;

	cout << "TC3L Test" << endl;


	cube.setPosition(position1);
	cube2.setPosition(position2);
	cube3.setPosition(position3);
	cube4.setPosition(position4);

	XSelectInput(di, wi, KeyPressMask | KeyReleaseMask | ExposureMask | PointerMotionMask);
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
			cube.render();
		}
		if(ev.type == MotionNotify)
		{
			myszelel = ev.xmotion ;
			float x=myszelel.x_root;
			float y=myszelel.y_root;
			camRotation.y = (960-x)/300 ;
			camRotation.x = (y-540)/300 ;
			double dump = 0 ;
			XClearWindow(di, wi) ;
			cube.render();
			cube2.render();
			cube3.render();
			cube4.render();
		}
		if (ev.type == KeyPress)
    {

            /* exit on ESC key press */
            if ( ev.xkey.keycode == 0x09 )
                break;
    }
    else if (ev.type == KeyRelease)
    {
				if(ev.xkey.keycode == 25)
				{
					camPosition.x -= sin(camRotation.y)*10;
					camPosition.z += cos(camRotation.y)*10;
				}
				else if(ev.xkey.keycode == 39)
				{
					camPosition.x += sin(camRotation.y)*10;
					camPosition.z -= cos(camRotation.y)*10;
				}

				XClearWindow(di, wi) ;
				cube.render();
				cube2.render();
				cube3.render();
				cube4.render();
    }
	}
	return 0;
}
