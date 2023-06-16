#ifndef SILICON_MESH_HPP
#define SILICON_MESH_HPP

#include <GL/glew.h>

#include <vector>

#include "texture.hpp"
#include "vertex.hpp"

namespace Silicon {
class Mesh {
  GLuint vertex_array;

  GLuint vertex_buffer;
  GLuint element_buffer;

  void buffer_data();

public:
  std::vector<Vertex> vertices;
  std::vector<GLuint> indices;
  std::vector<Texture> textures;

  Mesh(const std::vector<Vertex>&, const std::vector<GLuint>&,
       const std::vector<Texture>&);

  void draw();
};
} // namespace Silicon

#endif