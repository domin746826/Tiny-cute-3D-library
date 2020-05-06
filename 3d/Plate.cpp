/*    Tiny cute 3D library
*
*   Plate render functions, position, rotate etc
*
*   Author (Discord): デビルとプログラマー、オタク#7830
*   Author (Github): polandoDOMINO5nihon
*/

#include "Plate.h"
#include "Point.h"
#include "loadTexture.h"
#include "primitives.h"
#include <math.h>

Plate::Plate(Point3D p1, Point3D p2, Point3D p3, Point3D p4)
{
  light = 1;
  point1 = p1;
  point2 = p2;
  point3 = p3;
  point4 = p4;
  resolution.x = 1920;
  resolution.y = 1040;
}

Plate::~Plate()
{
}

Point3D Plate::transform3D(Point3D point, Point3D rotation)
{
  float tmpPoint;
  Point3D result = point;

  tmpPoint = result.z*sin(rotation.y) + result.x*cos(rotation.y);
  result.z = result.z*cos(rotation.y) - result.x*sin(rotation.y);
	result.x = tmpPoint;

  tmpPoint = result.y*cos(rotation.x) - result.z*sin(rotation.x);
  result.z = result.y*sin(rotation.x) + result.z*cos(rotation.x);
	result.y = tmpPoint;

  tmpPoint = result.x*cos(rotation.z) - result.y*sin(rotation.z);
  result.y = result.x*sin(rotation.z) + result.y*cos(rotation.z);
	result.x = tmpPoint;

  return result;
}

int Plate::render()
{
  //self rotating object
  tmpPoint1 = transform3D(point1, objRotation);
  tmpPoint2 = transform3D(point2, objRotation);
  tmpPoint3 = transform3D(point3, objRotation);
  tmpPoint4 = transform3D(point4, objRotation);

  //moving object
  tmpPoint1 = tmpPoint1 + objPosition + camPosition;
  tmpPoint2 = tmpPoint2 + objPosition + camPosition;
  tmpPoint3 = tmpPoint3 + objPosition + camPosition;
  tmpPoint4 = tmpPoint4 + objPosition + camPosition;

  //camera rotation
  tmpPoint1 = transform3D(tmpPoint1, camRotation);
  tmpPoint2 = transform3D(tmpPoint2, camRotation);
  tmpPoint3 = transform3D(tmpPoint3, camRotation);
  tmpPoint4 = transform3D(tmpPoint4, camRotation);

  int f = -50;

	float t1 = -tmpPoint1.z / 10;
	float t2 = -tmpPoint2.z / 10;
	float t3 = -tmpPoint3.z / 10;
	float t4 = -tmpPoint4.z / 10;

  rendPoint1.x = tmpPoint1.x / t1*f;
  rendPoint1.y = tmpPoint1.y / t1*f;
  rendPoint2.x = tmpPoint2.x / t2*f;
  rendPoint2.y = tmpPoint2.y / t2*f;
  rendPoint3.x = tmpPoint3.x / t3*f;
  rendPoint3.y = tmpPoint3.y / t3*f;
  rendPoint4.x = tmpPoint4.x / t4*f;
  rendPoint4.y = tmpPoint4.y / t4*f;

  if(tmpPoint1.z > 0 || tmpPoint2.z > 0 || tmpPoint3.z > 0 || tmpPoint4.z > 0)
  {
    visible = false;
    return 1;
  }
  else
  {
    visible = true;
    return 1;
  }
}

void Plate::setLight(float lightLvl)
{
  light = lightLvl;
}

void Plate::setCameraRotation(Point3D rotation)
{
  camRotation = rotation;
}

void Plate::setCameraPosition(Point3D position)
{
  camPosition = position;
}

void Plate::setRotation(Point3D rotation)
{
    objRotation = rotation;
}

void Plate::setPosition(Point3D position)
{
  objPosition = position;
}

float Plate::getZPosition()
{
  return zPosition;
}

int Plate::loadTextureFromFile(char* filename)
{
  int x,y;
  int error = loadTextureToRam(filename, texture, x, y);
  textureSize.x = x;
  textureSize.y = y;
  return error;
}

void Plate::loadTexture(int* txt, Point2D size)
{
  texture = txt;
  textureSize = size;
}

int Plate::display()
{
  if(!visible)
  {
    return 0;
  }

  cout << "Plate rend" << endl;
  Point2D centerScreen = resolution/2;
  rendPoint1 = rendPoint1 + centerScreen;
  rendPoint2 = rendPoint2 + centerScreen;
  rendPoint3 = rendPoint3 + centerScreen;
  rendPoint4 = rendPoint4 + centerScreen;

  cout << "P1: " << rendPoint1.x << "\t" << rendPoint1.y << endl;
  cout << "P2: " << rendPoint2.x << "\t" << rendPoint2.y << endl;
  cout << "P3: " << rendPoint3.x << "\t" << rendPoint3.y << endl;
  cout << "P4: " << rendPoint4.x << "\t" << rendPoint4.y << endl;
  drawLine(rendPoint1, rendPoint2, 0);
  drawLine(rendPoint3, rendPoint4, 0);
  drawLine(rendPoint1, rendPoint3, 0);
  drawLine(rendPoint2, rendPoint4, 0);
}
