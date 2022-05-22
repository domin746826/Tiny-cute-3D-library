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
	Point3D cameraRotation;
	Point3D cameraPosition;

  public:
    Camera(int type, int id);
    void setFov(int fov);
	void setRotation(Point3D rotation);
	void setPosition(Point3D position);
	void rotate(Point3D rotation);
	void move(Point3D motion);
	void moveForward(float val);
	void moveLeft(float val);
	Point3D* getRotation();
	Point3D* getPosition();
};

#endif
