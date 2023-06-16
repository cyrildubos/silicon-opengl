#include <silicon/texture.hpp>

Silicon::Texture::Texture(GLenum type) {
  glGenTextures(1, &reference);

  glBindTexture(type, reference);

  glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Silicon::Texture::data(const std::size_t width, const std::size_t height,
                             const float* data) {
  glTexImage2D(type, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,
               data);

  glGenerateMipmap(type);
}