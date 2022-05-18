#ifndef OBJ_CUBE_H_
#define OBJ_CUBE_H_

#include "../Object.h"

class Cube : public Object {
    public:
        Cube();
        Cube(Point3D *cam_rot, Point3D *cam_pos);
};

#endif