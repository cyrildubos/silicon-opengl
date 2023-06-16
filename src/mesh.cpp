#include <silicon/mesh.hpp>

void Silicon::Mesh::buffer_data() {
  glBindVertexArray(vertex_array);

  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0],
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(),
               &indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, position));

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, normal));

  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, coordinate));

  glBindVertexArray(0);
}

Silicon::Mesh::Mesh(const std::vector<Vertex>& vertices,
                     const std::vector<GLuint>& indices,
                     const std::vector<Texture>& textures) {
  this->vertices = vertices;
  this->indices = indices;
  this->textures = textures;

  glGenVertexArrays(1, &vertex_array);

  glGenBuffers(1, &vertex_buffer);
  glGenBuffers(1, &element_buffer);

  buffer_data();
}

void Silicon::Mesh::draw() {
  glBindVertexArray(vertex_array);

  glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);

  glBindVertexArray(0);
}