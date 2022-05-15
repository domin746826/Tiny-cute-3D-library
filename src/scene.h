#ifndef SCENE_H_
#define SCENE_H_

#define ORTOGRAPHIC 0
#define PERSPECTIVE 1

#include "Object.h"
#include "Plate.h"

class Scene
{
	private:
		vector<Object*> objectsArray;
		vector<Plate> platesArray;
		int type, fov;

	public:
		Scene(int renderType, int renderFov);
		void addObject(Object *object);
		void render();
		void display();
};


#endif
