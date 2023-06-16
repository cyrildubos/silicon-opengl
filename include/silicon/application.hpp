#ifndef OPENGL_APPLICATION_HPP
#define OPENGL_APPLICATION_HPP

#include <string>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <GLFW/glfw3.h>

#include "mesh.hpp"
#include "model.hpp"
#include "program.hpp"
#include "vertex.hpp"

#define OPENGL_VERSION_MAJOR 3
#define OPENGL_VERSION_MINOR 3

namespace Silicon {
class Application {
  GLFWwindow* window;

public:
  Application(const std::size_t, const std::size_t, const std::string&);
  ~Application();

  void run();
};
} // namespace Silicon

#endif