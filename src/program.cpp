#include <silicon/program.hpp>

void Silicon::Program::check_linkage() {
  GLint link_status;
  glGetProgramiv(reference, GL_LINK_STATUS, &link_status);

  if (!link_status) {
    GLint info_log_length;
    glGetProgramiv(reference, GL_INFO_LOG_LENGTH, &info_log_length);

    GLchar info_log[info_log_length];
    glGetProgramInfoLog(reference, info_log_length, NULL, info_log);

    std::cerr << info_log;

    throw std::runtime_error("failed to link program");
  }
}

Silicon::Program::Program(const char* vertex_shader_path,
                           const char* fragment_shader_path) {
  Shader vertex_shader(GL_VERTEX_SHADER, vertex_shader_path);
  Shader fragment_shader(GL_FRAGMENT_SHADER, fragment_shader_path);

  reference = glCreateProgram();

  glAttachShader(reference, vertex_shader.reference);
  glAttachShader(reference, fragment_shader.reference);

  glLinkProgram(reference);

  check_linkage();

  // glDetachShader(program, vertex_shader.reference);
  // glDetachShader(program, fragment_shader.reference);
}

void Silicon::Program::use() { glUseProgram(reference); }