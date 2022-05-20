#include "Camera.h"

Camera::Camera(int type, int id)
{
  cameraType = type;
  cameraId = id;
}


void Camera::setFov(int fov)
{
  cameraFov = fov;
}
