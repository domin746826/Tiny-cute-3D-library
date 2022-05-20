#ifndef CAMERA_H_
#define CAMERA_H_
#include "Point.h"

#define ORTOGRAPHIC 0
#define PERSPECTIVE 1

class Camera
{
  private:
    int cameraType, cameraId;
    int cameraFov = 60;

  public:
    Camera(int type, int id);
    void setFov(int fov);
};

#endif
