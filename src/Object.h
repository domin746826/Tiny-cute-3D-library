/*    Tiny cute 3D library
*
*   Object class declaration
*
*   Author (Discord): デビルとプログラマー、オタク#7830
*   Author (Github): polandoDOMINO5nihon
*/

#ifndef OBJECT_H_
#define OBJECT_H_
#include "Plate.h"
#include "Point.h"
#include <vector>

using namespace std;

class Object
{
  private:
    vector<Plate> allPlates;
    Point3D objPosition, objRotation;
    Point3D *camPosition, *camRotation;

  public:
    void addPlate(Plate plate);
    //void setCameraRotation(Point3D rotation);
    //void setCameraPosition(Point3D position);
    Object(Point3D *rotation, Point3D *position);
    void setRotation(Point3D rotation);
    void setPosition(Point3D position);
    int render();
};

#endif
