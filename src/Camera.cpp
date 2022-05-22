#include "Camera.h"
#include "cmath"

Camera::Camera(int type, int id)
{
  cameraType = type;
  cameraId = id;
}


void Camera::setFov(int fov)
{
  cameraFov = fov;
}

void Camera::moveForward(float val)
{
	cameraPosition.x -= sin(cameraRotation.y)*val;
	cameraPosition.z += cos(cameraRotation.y)*val;
}

void Camera::moveLeft(float val)
{
	cameraPosition.x += sin(cameraRotation.y-1.5708)*val;
	cameraPosition.z -= cos(cameraRotation.y-1.5708)*val;
}

void Camera::setRotation(Point3D rotation)
{
	cameraRotation = rotation;
}

void Camera::setPosition(Point3D position)
{
	cameraPosition = position;
}

void Camera::rotate(Point3D rotation)
{
	cameraRotation = cameraRotation + rotation;
}

void Camera::move(Point3D motion)
{
	cameraPosition = cameraPosition + motion;
}

Point3D* Camera::getRotation()
{
	return &cameraRotation;
}

Point3D* Camera::getPosition()
{
	return &cameraPosition;
}



