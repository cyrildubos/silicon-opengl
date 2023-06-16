#ifndef SILICON_PROGRAM_HPP
#define SILICON_PROGRAM_HPP

#include <GL/glew.h>

#include "shader.hpp"
#include "utilities.hpp"

namespace Silicon {
class Program {
  void check_linkage();

public:
  GLuint reference;

  // Shader vertex_shader;
  // Shader fragment_shader;

  Program(const char*, const char*);

  void use();
};
} // namespace Silicon

#endif