#ifndef SILICON_VERTEX_HPP
#define SILICON_VERTEX_HPP

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace Silicon {
struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 coordinate;
};
} // namespace Silicon

#endif