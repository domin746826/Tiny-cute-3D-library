/*
 * Tiny Cute 3D Library
 *
 * Author (Discord): Hisonka#4156
 * Author (Github): domin746826
 *
 *
 */
 


#include "scene.h"

Scene::Scene(int renderType, int renderFov)
{
	type = renderType;
	fov = renderFov;
}

void Scene::addObject(Object *object)
{
	objectsArray.push_back(object);
}

void Scene::render()
{
	for(int i = 0; i < objectsArray.size(); i++)
		objectsArray[i] -> render();
}

void Scene::display()
{
	//for(int i = 0; i < objectsArray.size(); i++)
//		objectsArray[i] -> display();
}
