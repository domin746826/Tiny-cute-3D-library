#ifndef SCENE_H_
#define SCENE_H_

#define ORTOGRAPHIC 0
#define PERSPECTIVE 1

#include "Object.h"

class Scene
{
	private:
		vector<Plate> platesArray;
		int type, fov;

	public:
		Scene(int type, int fov);
};


#endif
