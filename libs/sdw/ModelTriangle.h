#include <glm/glm.hpp>
#include <Colour.h>
#include <string>
#include "Materials.h"
class ModelTriangle {
  public:
    glm::vec3 vertices[3];
    glm::vec2 vertices_textures[3];
    Colour colour;
    glm::vec3 normals[3]; // these correspond to the averaged normals of the vertices
    MATERIAL material;
    int faceIndex;   // stores the number of which face it is out of all of them
    int objectIndex; // used in OBJ - stores the group this triangle is in.
    bool culled; // has this face been culled or not? do we need to check for intersections with it?

    ModelTriangle() {
      normals[0] = glm::vec3 (0,0,0);
      normals[1] = glm::vec3 (0,0,0);
      normals[2] = glm::vec3 (0,0,0);
      material = NONE;
      culled = false;
      faceIndex = -1;
      objectIndex = -1;
    }

    ModelTriangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, Colour trigColour) {
      vertices[0] = v0;
      vertices[1] = v1;
      vertices[2] = v2;
      colour = trigColour;
      normals[0] = glm::vec3 (0,0,0);
      normals[1] = glm::vec3 (0,0,0);
      normals[2] = glm::vec3 (0,0,0);
      material = NONE;
      culled = false;
      faceIndex = -1;
      objectIndex = -1;
    }
    glm::vec3 getNormal() {
      const glm::vec3 e0 = (vertices[1] - vertices[0]); //v1 - v0
      const glm::vec3 e1 = (vertices[2] - vertices[0]); //v2 - v1
      // return the normal = glm::cross(e0, e1); 
      return glm::normalize(glm::cross(e0, e1)); 
    }
};

std::ostream& operator<<(std::ostream& os, const ModelTriangle& triangle)
{
    os << "(" << triangle.vertices[0].x << ", " << triangle.vertices[0].y << ", " << triangle.vertices[0].z << ")" << std::endl;
    os << "(" << triangle.vertices[1].x << ", " << triangle.vertices[1].y << ", " << triangle.vertices[1].z << ")" << std::endl;
    os << "(" << triangle.vertices[2].x << ", " << triangle.vertices[2].y << ", " << triangle.vertices[2].z << ")" << std::endl;
    os << std::endl;
    return os;
}
