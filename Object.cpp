#include "Object.h"
//Parser Method that takes the filename in and parses as needed
void Object::readFile(std::string filename){
  ifstream inFile;


  if(filename.find("obj") == std::string::npos){
    cout << "File is not supported please provide an obj file" << endl;

  }

  else{
          inFile.open(filename.c_str());
          string line;
          GLfloat point;


      while (getline(inFile,line))
      { 


          if(line.substr(0,1).compare("t")==0){
             if(line.find("triangle")>0){
              triangle=true;
            }
            else{
              triangle = false;
            }

          }

            if(line.substr(0,1).compare("f")==0){
              int v1,v2,v3,v4, n, t1, t2, t3, t4;

              if(triangle){
                sscanf(line.c_str(),"%*s %i %*c %i %*c %i %i %*c %i %*c %i %i %*c %i %*c %i", &v1, &t1, &n, &v2, &t2, &n,&v3, &t3, &n);
                vertexArray.push_back(v[v1-1]);
                vertexArray.push_back(v[v2-1]);
                vertexArray.push_back(v[v3-1]);
                textureArray.push_back(textures[t1-1]);
                textureArray.push_back(textures[t2-1]);
                textureArray.push_back(textures[t3-1]);
                normalArray.push_back(normals[n-1]);
              }
              else{
                sscanf(line.c_str(),"%*s %i %*c %i %*c %i %i %*c %i %*c %i %i %*c %i %*c %i %i %*c %i %*c %i", &v1, &t1, &n, &v2, &t2, &n,&v3, &t3, &n, &v4, &t4, &n);
                 vertexArray.push_back(v[v1-1]);
                vertexArray.push_back(v[v2-1]);
                vertexArray.push_back(v[v3-1]);
                vertexArray.push_back(v[v4-1]);
                textureArray.push_back(textures[t1-1]);
                textureArray.push_back(textures[t2-1]);
                textureArray.push_back(textures[t3-1]);
                textureArray.push_back(textures[t4-1]);
                normalArray.push_back(normals[n-1]);
              }


          
                 }

            //Case for texture
        else if (line.substr(0,2).compare("vt")==0){
                  textureHere=true;
                  GLfloat v1, v2;
            sscanf(line.c_str(),"%*s %f %f", &v1, &v2);            
            textures.push_back(glm::vec2(v1,v2));

          }

             //Case for normals
          else if (line.substr(0,2).compare("vn")==0){
            GLfloat v1, v2, v3;
            sscanf(line.c_str(),"%*s %f %f %f", &v1, &v2, &v3);            
            normals.push_back(glm::vec3(v1,v2,v3));
                 
          }

              //Case for the vertex
          else if(line.substr(0,1).compare("v")==0){
            GLfloat v1, v2, v3;
            sscanf(line.c_str(),"%*s %f %f %f", &v1, &v2, &v3);
            
            v.push_back(glm::vec3(v1,v2,v3));

                    
         }
        }
  inFile.close();
    }
}