#include <silicon/shader.hpp>

Silicon::Shader::Shader(GLenum type, const std::string& path) {
  auto string = read_file(path);

  auto source = string.c_str();

  reference = glCreateShader(type);

  glShaderSource(reference, 1, &source, NULL);
  glCompileShader(reference);

  check_compilation();
}

Silicon::Shader::~Shader() { glDeleteShader(reference); }

void Silicon::Shader::check_compilation() {
  GLint compile_status;
  glGetShaderiv(reference, GL_COMPILE_STATUS, &compile_status);

  if (!compile_status) {
    GLint info_log_length;
    glGetShaderiv(reference, GL_INFO_LOG_LENGTH, &info_log_length);

    GLchar info_log[info_log_length];
    glGetShaderInfoLog(reference, info_log_length, NULL, info_log);

    std::cerr << info_log;

    throw std::runtime_error("failed to compile shader");
  }
}