#ifndef OBJ_CUBE_H_
#define OBJ_CUBE_H_

#define CUBE_PX 0
#define CUBE_NX 1
#define CUBE_PY 2
#define CUBE_NY 3
#define CUBE_PZ 4
#define CUBE_NZ 5

#include "../Object.h"

class Cube : public Object
{
	private:
		Plate *px, *nx, *py, *ny, *pz, *nz;
    public:
        Cube();
        Cube(Point3D *cam_rot, Point3D *cam_pos, Point3D rotation, Point3D position, Point3D size);
		void setColor(int face, int color);
};

#endif
