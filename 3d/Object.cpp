#include "Plate.h"
#include "Point.h"
#include "Object.h"
#include <vector>

void Object::addPlate(Plate plate)
{
  allPlates.push_back(plate);
}

void Object::setCameraRotation(Point3D rotation)
{
  camRotation = rotation;
}

void Object::setCameraPosition(Point3D position)
{
  camPosition = position;
}

void Object::setRotation(Point3D rotation)
{
  objRotation = rotation;
}

void Object::setPosition(Point3D position)
{
  objPosition = position;
}

int Object::render()
{
  for(int i = 0; i < allPlates.size(); i++)
  {
    allPlates[i].setRotation(objRotation);
    allPlates[i].setPosition(objPosition);
    allPlates[i].setCameraRotation(camRotation);
    allPlates[i].setCameraPosition(camPosition);
    allPlates[i].render();
    allPlates[i].display();
  }
}
