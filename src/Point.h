/*    Tiny cute 3D library
*
*   Helper structures
*
*   Author (Discord): デビルとプログラマー、オタク#7830
*   Author (Github): polandoDOMINO5nihon
*/

#ifndef POINT_H_
#define POINT_H_

class Point2D
{
  public:
     float x;
     float y;

  Point2D(float xpos, float ypos);
  Point2D(const Point2D &point);
  Point2D();
  Point2D operator+(const Point2D &point);
  Point2D operator-(const Point2D &point);
  Point2D operator/(const Point2D &point);
  Point2D operator*(const Point2D &point);
  Point2D operator/(int by);
  Point2D operator*(int by);
};

class Point3D
{
  public:
     float x;
     float y;
     float z;

  Point3D(float xpos, float ypos, float zpos);
  Point3D(const Point3D &point);
  Point3D();
  Point3D operator+(const Point3D &point);
  Point3D operator-(const Point3D &point);
  Point3D operator/(const Point3D &point);
  Point3D operator*(const Point3D &point);
  Point3D operator/(int by);
  Point3D operator*(int by);
  float distanceToZero();
};

#endif
