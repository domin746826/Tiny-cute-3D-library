#ifndef POINT_H_
#define POINT_H_

class Point
{
  public:
     int x ;
     int y ;

  Point(int xpos, int ypos) ;
  Point(const Point &point) ;
  Point() ;
  Point operator+(const Point &point) ;
  Point operator-(const Point &point) ;
  Point operator/(const Point &point) ;
  Point operator*(const Point &point) ;
  Point operator/(int by) ;
  Point operator*(int by) ;
};

class FPoint
{
  public:
     float x ;
     float y ;

  FPoint(float xpos, float ypos) ;
  FPoint(const FPoint &point) ;
  FPoint() ;
  FPoint operator+(const FPoint &point) ;
  FPoint operator-(const FPoint &point) ;
  FPoint operator/(const FPoint &point) ;
  FPoint operator*(const FPoint &point) ;
  FPoint operator/(int by) ;
  FPoint operator*(int by) ;
};

#endif
