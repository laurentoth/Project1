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

  



};


#endif