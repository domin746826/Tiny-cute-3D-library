/*
 * Tiny Cute 3D Library
 *
 * Author (Discord): Hisonka#4156
 * Author (Github): domin746826
 *
 *
 */


#include <iostream>
#include <algorithm>
#include "scene.h"

using namespace std;

Scene::Scene()
{
}

void Scene::addObject(Object *object)
{
	objectsArray.push_back(object);
}

void Scene::render()
{
	platesArray.erase(platesArray.begin(), platesArray.end());
	vector<Plate*> receivedVector;
	for(int i = 0; i < objectsArray.size(); i++)
	{
		objectsArray[i] -> render();
		receivedVector = objectsArray[i] -> getPlates();
		//cout << "receivedObj" << endl;
		platesArray.insert(end(platesArray), begin(receivedVector), end(receivedVector));
	}
	sort(platesArray.begin(), platesArray.end(), plateCompare());
}

void Scene::addCamera(Camera *camera)
{
	cameraArray.push_back(camera);
}

void Scene::display()
{
	for(int i = platesArray.size()-1; i >= 0; i--)
	//for(int i = 0; i < platesArray.size(); i++)
		platesArray[i]->display();
}
