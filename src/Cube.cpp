#include "Cube.h"

Cube::Cube(Point3D front[4], Point3D back[4]){

}

Cube::Cube(Point3D p[8]){
    plates = (Plate*) malloc(6 * sizeof(Plate));
    plates[0] = Plate(p[0], p[1], p[2], p[3]);
	plates[1] = Plate(p[4], p[5], p[6], p[7]);
	plates[2] = Plate(p[4], p[5], p[0], p[1]);
	plates[3] = Plate(p[6], p[7], p[2], p[3]);
	plates[4] = Plate(p[4], p[0], p[6], p[2]);
	plates[4] = Plate(p[1], p[5], p[3], p[7]);
}

Cube::Cube(Plate p[6]){
    plates = (Plate*) malloc(6 * sizeof(Plate));
    plates = p;
}

Cube::Cube(int cube_size){
    plates = (Plate*) malloc(6 * sizeof(Plate));

    plates[0] = Plate(Point3D(-cube_size, cube_size, cube_size), Point3D(cube_size, cube_size, cube_size), Point3D(-cube_size, -cube_size, cube_size), Point3D(cube_size, -cube_size, cube_size));
	plates[1] = Plate(Point3D(-cube_size, cube_size, -cube_size), Point3D(cube_size, cube_size, -cube_size), Point3D(-cube_size, -cube_size, -cube_size), Point3D(cube_size, -cube_size, -cube_size));
	plates[2] = Plate(Point3D(-cube_size, cube_size, -cube_size), Point3D(cube_size, cube_size, -cube_size), Point3D(-cube_size, cube_size, cube_size), Point3D(cube_size, cube_size, cube_size));
	plates[3] = Plate(Point3D(-cube_size, -cube_size, -cube_size), Point3D(cube_size, -cube_size, -cube_size), Point3D(-cube_size, -cube_size, cube_size), Point3D(cube_size, -cube_size, cube_size));
	plates[4] = Plate(Point3D(-cube_size, cube_size, -cube_size), Point3D(-cube_size, cube_size, cube_size), Point3D(-cube_size, -cube_size, -cube_size), Point3D(-cube_size, -cube_size, cube_size));
	plates[4] = Plate(Point3D(cube_size, cube_size, cube_size), Point3D(cube_size, cube_size, -cube_size), Point3D(cube_size, -cube_size, cube_size), Point3D(cube_size, -cube_size, -cube_size));
}

Cube::Cube(){
    plates = (Plate*) malloc(6 * sizeof(Plate));
    plates[0] = Plate(Point3D(-50, 50, 50), Point3D(50, 50, 50), Point3D(-50, -50, 50), Point3D(50, -50, 50));
	plates[1] = Plate(Point3D(-50, 50, -50), Point3D(50, 50, -50), Point3D(-50, -50, -50), Point3D(50, -50, -50));
	plates[2] = Plate(Point3D(-50, 50, -50), Point3D(50, 50, -50), Point3D(-50, 50, 50), Point3D(50, 50, 50));
	plates[3] = Plate(Point3D(-50, -50, -50), Point3D(50, -50, -50), Point3D(-50, -50, 50), Point3D(50, -50, 50));
	plates[4] = Plate(Point3D(-50, 50, -50), Point3D(-50, 50, 50), Point3D(-50, -50, -50), Point3D(-50, -50, 50));
	plates[4] = Plate(Point3D(50, 50, 50), Point3D(50, 50, -50), Point3D(50, -50, 50), Point3D(50, -50, -50));
}

Cube::~Cube(){
    free(plates);
}

void Cube::Rotate(float x, float y, float z){
    for(int i=0; i<6; i++){
        plates[i].setRotation(plates[i].getRotation()+Point3D(x, y, z));
    }
}

void Cube::SetCameraRotation(Point3D rot){
    for(int i=0; i<6; i++){
        plates[i].setCameraRotation(rot);
    }
}

void Cube::SetCameraPosition(Point3D pos) {
    for(int i=0; i<6; i++){
        plates[i].setCameraPosition(pos);
    }
}

void Cube::SetCamera(Point3D pos, Point3D rot) {
    for(int i=0; i<6; i++){
        plates[i].setCameraRotation(rot);
        plates[i].setCameraPosition(pos);
    }
}

void Cube::PlatesRender(){
    for(int i=0; i<6; i++){
        plates[i].render();
    }
}
void Cube::PlatesDisplay(){
    for(int i=0; i<6; i++){
        plates[i].display();
    }
}