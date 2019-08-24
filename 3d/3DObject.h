#ifndef D3OBJECT_H_
#define D3OBJECT_H_

#define OK 0
#define INVALID_SIGNATURE 1

class D3Object
{
  private:
    int xPosition, yPosition, zPosition, xTextureSize, yTextureSize ;
    float xDegree, yDegree, zDegree ;
    int **textures ;
    char* structureShape ;
    int charPos ;
    char* workBuffer ;
    int platesNum ;
    char* objectName ;

    float renderTable[4][3] ;

    char getChar() ;
    int countOccurencies(char* str, char ch) ;
    long getInt() ;

  public:
    D3Object(int xsize, int ysize) ;
    ~D3Object() ;
    int loadTextures(int textureID, int* textureData) ;
    void loadStructureShape(char* shape) ;
    int renderObject() ;

    int setName(char* name) ;
    char* getName() ;
};

#endif
