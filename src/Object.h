/*    Tiny cute 3D library
*
*   Object class declaration
*
*   Author (Discord): Hisonka#4156
*   Author (Github): domin746826
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
    void addPlate(Plate plate, int color);
    //void setCameraRotation(Point3D rotation);
    //void setCameraPosition(Point3D position);
    Object(Point3D *rotation, Point3D *position); //camera rotation & position
    void setRotation(Point3D rotation);
    void setPosition(Point3D position);
    void render();
    vector<Plate> getPlates();
};

#endif
