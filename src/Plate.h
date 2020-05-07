/*    Tiny cute 3D library
*
*   Plate class declaration
*
*   Author (Discord): デビルとプログラマー、オタク#7830
*   Author (Github): polandoDOMINO5nihon
*/

#ifndef PLATE_H_
#define PLATE_H_
#include "Point.h"

class Plate
{
	private:
		int* texture;
    Point2D textureSize;
    float light;

		Point2D resolution;

    Point3D objPosition, objRotation;
    Point3D *camPosition, *camRotation;

    Point3D point1, point2, point3, point4;    //library is based on only 4 point plates because of optimalisation
		Point3D tmpPoint1, tmpPoint2, tmpPoint3, tmpPoint4;
		Point2D rendPoint1, rendPoint2, rendPoint3, rendPoint4;
		bool visible;

		float zPosition;

		void drawIrregularTexture(Point2D p1, Point2D p2, Point2D p3, Point2D p4, int* txt);
		Point3D transform3D(Point3D point, Point3D rotation);
		void fillShape(Point2D point1, Point2D point2, Point2D point3, Point2D point4, int color);

  public:

    void setLight(float lightLvl);
    void setCameraRotation(Point3D *rotation);
    void setCameraPosition(Point3D *position);
    void setRotation(Point3D rotation);
    void setPosition(Point3D position);
    float getZPosition();    //because of simple painter's algorithm

    int loadTextureFromFile(char* filename);
    void loadTexture(int* txt, Point2D size);

    int display();
		int render();

		bool isVisible();

    Plate(Point3D p1, Point3D p2, Point3D p3, Point3D p4);
    ~Plate();
};

#endif
