#ifndef OBJECT_H
#define OBJECT_H
#include "Vertex.h"
#include "glm/glm/vec3.hpp"
#include "glm/glm/vec2.hpp"
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <GLUT/glut.h>
using namespace std;

class Object{

public:
	Object(){};
  void readFile(std::string filename);
  vector<glm::vec3> getVertexArray(){return vertexArray;};
  vector<glm::vec3> getNormalArray(){return normalArray;};
  vector<glm::vec2> getTextureArray(){return textureArray;};
  bool getTriangle(){return triangle;};
  glm::vec3 getTranslate(){return Translate;};
  float getXScale(){return sx;};
  float getYScale(){return sy;};
  float getZScale(){return sz;}
  void setTranslate(float x, float y, float z){Translate = glm::vec3(x,y,z);};
  void setScale(float x, float y, float z){sx=x; sy=y; sz=z;};
  void setColors(float red, float green, float blue){r=red; g=green; b=blue;};
  float getRed(){return r;};
  float getGreen(){return g;};
  float getBlue(){return b;};



private:
  string filename;
  vector <glm::vec3> v;
  vector <glm::vec3> normals;
  vector<glm::vec3> vertexArray;
  vector <glm::vec3> normalArray;
  vector <glm::vec2> textureArray; 
  vector<glm::vec2 >textures;
  bool triangle;
  bool textureHere;
  glm::vec3 Translate;
  float sx, sy, sz;
  float r,g,b;

  



};


#endif