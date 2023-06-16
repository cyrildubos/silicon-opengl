#ifndef SILICON_SHADER_HPP
#define SILICON_SHADER_HPP

#include <GL/glew.h>

#include "utilities.hpp"

namespace Silicon {
class Shader {
public:
  GLuint reference;

  Shader(GLenum, const char*);
  ~Shader();

  void check_compilation();
};
} // namespace Silicon

#endif