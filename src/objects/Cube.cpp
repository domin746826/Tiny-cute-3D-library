#include "Cube.h"

Cube::Cube(Point3D *cam_rot, Point3D *cam_pos, Point3D rotation, Point3D position, Point3D size) : Object::Object(cam_rot, cam_pos) //TODO remove specifying everything here 
{
	size = size / 2;
	Point3D p1(-size.x, size.y, size.z);
	Point3D p2(size.x, size.y, size.z);
	Point3D p3(-size.x, -size.y, size.z);
	Point3D p4(size.x, -size.y, size.z);
	Point3D p5(-size.x, size.y, -size.z);
	Point3D p6(size.x, size.y, -size.z);
	Point3D p7(-size.x, -size.y, -size.z);
	Point3D p8(size.x, -size.y, -size.z);

	px = new Plate(p2, p6, p4, p8);
	nx = new Plate(p5, p1, p7, p3);
	pz = new Plate(p1, p2, p3, p4);
	nz = new Plate(p5, p6, p7, p8);
	py = new Plate(p5, p6, p1, p2);
	ny = new Plate(p7, p8, p3, p4);

	addPlate(px); addPlate(nx);
	addPlate(py); addPlate(ny);
	addPlate(pz); addPlate(nz);

	setRotation(rotation);
	setPosition(position);
}

void Cube::setColor(int face, int color)
{
	switch(face)
	{
		case CUBE_PX:
			px->setColor(color);
			break;

		case CUBE_NX:
			nx->setColor(color);
			break;

		case CUBE_PY:
			py->setColor(color);
			break;

		case CUBE_NY:
			ny->setColor(color);
			break;

		case CUBE_PZ:
			pz->setColor(color);
			break;

		case CUBE_NZ:
			nz->setColor(color);
			break;
	}
}
