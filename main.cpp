#include <iostream>
#include "src/Point.h"
#include "src/primitives.h"
#include "src/Plate.h"
#include "src/Object.h"
#include "src/scene.h"
#include <math.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <cstring>
#include "extras/mouse.h"


using namespace std;


Object createCube(Point3D *camRotation, Point3D *camPosition, Point3D rotation, Point3D position)
{
	Object cube(camRotation, camPosition);

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

	cube.addPlate(plate1, 0x663300);
	cube.addPlate(plate2, 0x663300);
	cube.addPlate(plate3, 0x00ff00);
	cube.addPlate(plate4, 0x663300);
	cube.addPlate(plate5, 0x663300);
	cube.addPlate(plate6, 0x663300);


	cube.setRotation(rotation);
	cube.setPosition(position);

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

Object cube = createCube(&camRotation, &camPosition, rotation0, position1);
Object cube2 = createCube(&camRotation, &camPosition, rotation0, position2);
Object cube3 = createCube(&camRotation, &camPosition, rotation0, position3);
Object cube4 = createCube(&camRotation, &camPosition, rotation0, position4);
Object cube5 = createCube(&camRotation, &camPosition, rotation0, position5);

int fps = 0;
clock_t msBefore = 0;
void renderAll(Scene *scene)
{		
    int currentMs = clock() - msBefore;
	/*cube.render();
	cube2.render();
	cube3.render();
	cube4.render();
	cube5.render();*/
	scene -> render();
	scene -> display();
    XSetForeground(di, gc, 0xffffff);

    char fpsStr[16];
    sprintf(fpsStr, "FPS: %d", 1000/currentMs);
    XDrawString (di, double_buffer, gc, 16, 16, fpsStr, strlen(fpsStr));
	redrawBuf();
    msBefore = clock();
}

int main()
{
	Scene *scene = new Scene(PERSPECTIVE, 0);
	scene -> addObject(&cube);
	scene -> addObject(&cube2);
	scene -> addObject(&cube3);
	scene -> addObject(&cube4);
	scene -> addObject(&cube5);
	
	/*Mouse *mouse = new Mouse("/dev/input/mice");
	mouse -> init();

	while(1)
	{
		Point2D res = mouse -> getParsed();
		cout << res.x << "\t" << res.y << endl;
		usleep(50000);
	}
*/
    msBefore = clock(); 
	Point2D motion;
	motion.x = 0; motion.y = 0;
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
			//motion += Mouse.getMouse();
		    int a = XNextEvent(di, &ev);
		    if (ev.type == Expose)
    		{
                //renderAll();			
	    	}
            if(ev.type == MotionNotify)
            {
                myszelel = ev.xmotion ;
                float x=myszelel.x_root;
                float y=myszelel.y_root;
                camRotation.y = (960-x)/300 ;
                camRotation.x = (y-540)/300 ;
                double dump = 0 ;
                //XClearWindow(di, wi) ;
                /*cube.render();
                cube2.render();
                cube3.render();
                cube4.render();
                cube5.render();
                redrawBuf();*/
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
                        motion.y = 1;
                        break;
                    case 39:
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
                        motion.y = 0;
                        break;

                    case 38:
                    case 40:
                        motion.x = 0;
                        break;
                }
                //XClearWindow(di, wi) ;
            }
        }

        renderAll(scene);
        usleep(10000);
		moveForward(camPosition, camRotation, motion.y*5);
		moveLeft(camPosition, camRotation, motion.x*5);

	}
	return 0;
}
