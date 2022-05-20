#include <iostream>
#include "src/Point.h"
#include "src/primitives.h"
#include "src/Plate.h"
#include "src/Object.h"
#include "src/scene.h"
#include "src/Camera.h"
#include <math.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <cstring>
#include "extras/mouse.h"
#include "src/objects/Cube.h"

using namespace std;


Cube* createCube(Point3D *camRotation, Point3D *camPosition, Point3D rotation, Point3D position)
{
	Cube* cube = new Cube(camRotation, camPosition);

	Point3D p1(-50, 50, 50);
	Point3D p2(50, 50, 50);
	Point3D p3(-50, -50, 50);
	Point3D p4(50, -50, 50);
	Point3D p5(-50, 50, -50);
	Point3D p6(50, 50, -50);
	Point3D p7(-50, -50, -50);
	Point3D p8(50, -50, -50);

	Plate *px = new Plate(p2, p6, p4, p8);
	Plate *nx = new Plate(p5, p1, p7, p3);
	Plate *pz = new Plate(p1, p2, p3, p4);
	Plate *nz = new Plate(p5, p6, p7, p8);
	Plate *py = new Plate(p5, p6, p1, p2);
	Plate *ny = new Plate(p7, p8, p3, p4);

	px->setColor(0x663300);
	nx->setColor(0x663300);
	pz->setColor(0x663300);
	nz->setColor(0x663300);
	py->setColor(0x00ff00);
	ny->setColor(0x663300);

	cube->addPlate(px); cube->addPlate(nx);
	cube->addPlate(py); cube->addPlate(ny);
	cube->addPlate(pz); cube->addPlate(nz);

	cube->setRotation(rotation);
	cube->setPosition(position);

	return cube;
}

void moveForward(Point3D &camPosition, Point3D &camRotation, double val)
{
	camPosition.x -= sin(camRotation.y)*val;
	camPosition.z += cos(camRotation.y)*val;
}

void moveLeft(Point3D &camPosition, Point3D &camRotation, double val)
{
	camPosition.x += sin(camRotation.y-1.5708)*val;
	camPosition.z -= cos(camRotation.y-1.5708)*val;
}


Point3D camRotation(0.2, 0.5, 0);
Point3D camPosition(0, 0, 400);

Point3D position1(0, 0, -700);
Point3D position2(0, 0, -600);
Point3D position3(0, -100, -600);
Point3D position4(100, -100, -600);
Point3D position5(100, -100, -1000);
Point3D rotation0(0, 0, 0);


int fps = 0;
clock_t msBefore = 0;
void renderAll(Scene *scene)
{
	int currentMs = clock() - msBefore;
	scene->render();
	scene->display();
	XSetForeground(di, gc, 0xffffff);

	char fpsStr[16];
  sprintf(fpsStr, "FPS: %.0f", (float)1000/currentMs);
  XDrawString (di, double_buffer, gc, 16, 16, fpsStr, strlen(fpsStr));

	char positionStr[32];
  sprintf(positionStr, "X: %.2f, Y: %.2f, Z: %.2f", camPosition.x, camPosition.y, camPosition.z);
  XDrawString (di, double_buffer, gc, 16, 30, positionStr, strlen(positionStr));
	redrawBuf();
  msBefore = clock();
}

int main()
{
	Scene *scene = new Scene();

	Cube* cube = createCube(&camRotation, &camPosition, rotation0, position1);
	Cube* cube2 = createCube(&camRotation, &camPosition, rotation0, position2);
	Cube* cube3 = createCube(&camRotation, &camPosition, rotation0, position3);
	Cube* cube4 = createCube(&camRotation, &camPosition, rotation0, position4);
	Cube* cube5 = createCube(&camRotation, &camPosition, rotation0, position5);
	scene->addObject(cube);
	scene->addObject(cube2);
	scene->addObject(cube3);
	scene->addObject(cube4);
	scene->addObject(cube5);

	Mouse *mouse = new Mouse("/dev/input/mice");
	mouse->init();

	msBefore = clock();
	Point3D motion;
	motion.x = 0; motion.y = 0; motion.z = 0;
	initGraphics(1600, 900);

	cout << "TC3L Test" << endl;

	XSelectInput(di, wi, KeyPressMask | KeyReleaseMask | ExposureMask | PointerMotionMask);
	XEvent ev;
	XMotionEvent myszelel;
	XKeyEvent bieg;

    bool autoRepeatSupported = false;

	int quit = 0;
	while (!quit)
	{
		while(XPending(di))
		{
			Point2D mouseData = mouse->getParsed();
			camRotation.x -= mouseData.y/200;
			camRotation.y -= mouseData.x/200;
		    int a = XNextEvent(di, &ev);
		    if (ev.type == Expose)
    		{
                //renderAll();
	    	}
            if (ev.type == KeyPress)
            {
                /* exit on ESC key press */
                if ( ev.xkey.keycode == 0x09 )
                    quit = 1;
                switch(ev.xkey.keycode)
                {
                    case 25:
                        motion.z = 1;
                        break;
                    case 39:
                        motion.z = -1;
                        break;

					case 65:
						motion.y = 1;
						break;

					case 50:
						motion.y = -1;
						break;

                    case 38:
                        motion.x = 1;
                        break;
                    case 40:
                        motion.x = -1;
                        break;
                }
            }
            else if (ev.type == KeyRelease)
            {
                switch(ev.xkey.keycode)
                {
                    case 25:
                    case 39:
                        motion.z = 0;
                        break;

                    case 38:
                    case 40:
                        motion.x = 0;
                        break;

					case 50:
					case 65:
						motion.y = 0;
						break;
                }
                //XClearWindow(di, wi) ;
            }
        }

        renderAll(scene);
        usleep(10000);
		moveForward(camPosition, camRotation, motion.z*5);
		moveLeft(camPosition, camRotation, motion.x*5);
		camPosition.y -= motion.y*5;
	}
	return 0;
}
