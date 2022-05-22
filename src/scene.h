#ifndef SCENE_H_
#define SCENE_H_


#include "Object.h"
#include "Plate.h"
#include "Camera.h"

class Scene
{
	private:
		vector<Object*> objectsArray;
		vector<Plate*> platesArray;
		vector<Camera*> cameraArray;

		struct plateCompare
		{
      bool operator()(Plate* l, Plate* r) {
        return l->getZPosition() < r->getZPosition();
      }
    };

	public:
		Scene();
		void addObject(Object *object);
		void render();
		void display();
		void addCamera(Camera *camera);

};


#endif
