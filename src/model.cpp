#include <silicon/model.hpp>

void Silicon::Model::draw() {
  for (auto& mesh : meshes)
    mesh.draw();
}