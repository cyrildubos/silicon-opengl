#ifndef SILICON_TEXTURE_HPP
#define SILICON_TEXTURE_HPP

#include <GL/glew.h>

namespace Silicon {
class Texture {
  GLuint reference;

  GLenum type;

public:
  Texture(GLenum);

  void data(const std::size_t, const std::size_t, const float*);
};
} // namespace Silicon

#endif