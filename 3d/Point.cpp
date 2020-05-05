/*    Tiny cute 3D library
*
*   Helper structures
*
*   Author (Discord): デビルとプログラマー、オタク#7830
*   Author (Github): polandoDOMINO5nihon
*/

#include "Point.h"

Point2D::Point2D(float xpos, float ypos)
{
  x = xpos ;
  y = ypos ;
}

Point2D::Point2D(const Point2D &point)
{
  x = point.x ;
  y = point.y ;
}

Point2D::Point2D()
{
  x = 0 ;
  y = 0 ;
}

Point2D Point2D::operator+(const Point2D &point)
{
   Point2D point2(x + point.x, y + point.y);
   return point2 ;
}

Point2D Point2D::operator-(const Point2D &point)
{
   Point2D point2(x - point.x, y - point.y);
   return point2 ;
}

Point2D Point2D::operator/(const Point2D &point)
{
   Point2D point2(x / point.x, y / point.y);
   return point2 ;
}

Point2D Point2D::operator*(const Point2D &point)
{
   Point2D point2(x * point.x, y * point.y);
   return point2 ;
}

Point2D Point2D::operator/(int by)
{
   Point2D point2(x / by, y / by);
   return point2 ;
}

Point2D Point2D::operator*(int by)
{
   Point2D point2(x * by, y * by);
   return point2 ;
}




Point3D::Point3D(float xpos, float ypos, float zpos)
{
  x = xpos ;
  y = ypos ;
  z = zpos ;
}

Point3D::Point3D(const Point3D &point)
{
  x = point.x ;
  y = point.y ;
  z = point.z ;
}

Point3D::Point3D()
{
  x = 0 ;
  y = 0 ;
  z = 0 ;
}

Point3D Point3D::operator+(const Point3D &point)
{
   Point3D point2(x + point.x, y + point.y, z + point.z) ;
   return point2 ;
}

Point3D Point3D::operator-(const Point3D &point)
{
   Point3D point2(x - point.x, y - point.y, z - point.z) ;
   return point2 ;
}

Point3D Point3D::operator/(const Point3D &point)
{
   Point3D point2(x / point.x, y / point.y, z / point.z) ;
   return point2 ;
}

Point3D Point3D::operator*(const Point3D &point)
{
   Point3D point2(x * point.x, y * point.y, z * point.z) ;
   return point2 ;
}

Point3D Point3D::operator/(int by)
{
   Point3D point2(x / by, y / by, z / by) ;
   return point2 ;
}

Point3D Point3D::operator*(int by)
{
   Point3D point2(x * by, y * by, z * by) ;
   return point2 ;
}
