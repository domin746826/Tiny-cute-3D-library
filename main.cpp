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
#include <cstdlib>

using namespace std;


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


Point3D camRotation(0.7, -0.8, 0);
Point3D camPosition(200, -100, -200);



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
	srand((unsigned) time(NULL)); 
	Scene *scene = new Scene();
	
	Point3D position1(0, 0, 0);
	Point3D rotation0(0, 0, 0);

	for(int i = 0; i < 64; i++)
	{
		position1.x = -rand()%800;
		position1.y = -rand()%800;
		position1.z = -rand()%800;

		Cube *cube = new Cube(&camRotation, &camPosition, rotation0, position1, Point3D(100, 100, 100));
		cube->setColor(CUBE_PX, 0x663300);
		cube->setColor(CUBE_NX, 0x663300);
		cube->setColor(CUBE_PY, 0x00FF00);
		cube->setColor(CUBE_NY, 0x663300);
		cube->setColor(CUBE_PZ, 0x663300);
		cube->setColor(CUBE_NZ, 0x663300);
		scene->addObject(cube);

	}

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
		moveForward(camPosition, camRotation, motion.z*10);
		moveLeft(camPosition, camRotation, motion.x*10);
		camPosition.y -= motion.y*10;
	}
	return 0;
}
