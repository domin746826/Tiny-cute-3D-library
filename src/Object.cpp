#include "Plate.h"
#include "Point.h"
#include "Object.h"
#include <vector>

void Object::addPlate(Plate plate, int color)
{
  allPlates.push_back(plate);
  allPlates[allPlates.size()-1].setCameraRotation(camRotation);
  allPlates[allPlates.size()-1].setCameraPosition(camPosition);
  allPlates[allPlates.size()-1].setRotation(objRotation);
  allPlates[allPlates.size()-1].setPosition(objPosition);
  allPlates[allPlates.size()-1].setColor(color);
}

void Object::setRotation(Point3D rotation)
{
  objRotation = rotation;
}

void Object::setPosition(Point3D position)
{
  objPosition = position;
}

Object::Object(Point3D *rotation, Point3D *position)
{
  camRotation = rotation;
  camPosition = position;
}

int Object::render()
{
  for(int i = 0; i < allPlates.size(); i++)
  {
    allPlates[i].setRotation(objRotation);
    allPlates[i].setPosition(objPosition);
    allPlates[i].render();
    allPlates[i].display();
  }
}
