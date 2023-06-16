#ifndef SILICON_MODEL_HPP
#define SILICON_MODEL_HPP

#include <string>
#include <vector>

#include "mesh.hpp"

namespace Silicon {
class Model {
public:
  std::vector<Mesh> meshes;

  void draw();
};
} // namespace Silicon

#endif