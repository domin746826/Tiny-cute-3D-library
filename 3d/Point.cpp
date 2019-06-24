#include "Point.h"

Point::Point(int xpos, int ypos)
{
  x = xpos ;
  y = ypos ;
}

Point::Point(const Point &point)
{
  x = point.x ;
  y = point.y ;
}

Point::Point()
{
  x = 0 ;
  y = 0 ;
}


Point Point::operator+(const Point &point)
{
   Point point2(x + point.x, y + point.y);
   return point2 ;
}

Point Point::operator-(const Point &point)
{
   Point point2(x - point.x, y - point.y);
   return point2 ;
}

Point Point::operator/(const Point &point)
{
   Point point2(x / point.x, y / point.y);
   return point2 ;
}

Point Point::operator*(const Point &point)
{
   Point point2(x / point.x, y / point.y);
   return point2 ;
}

Point Point::operator/(int by)
{
   Point point2(x / by, y / by);
   return point2 ;
}

Point Point::operator*(int by)
{
   Point point2(x * by, y * by);
   return point2 ;
}
