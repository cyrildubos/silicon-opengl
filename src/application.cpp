#include <silicon/application.hpp>

void initialize_glfw() {
  if (!glfwInit())
    throw std::runtime_error("failed to initialize GLFW");

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* create_window(const std::size_t width, const std::size_t height,
                          const std::string& title) {
  auto window = glfwCreateWindow(width, height, title.data(), NULL, NULL);

  if (!window) {
    glfwTerminate();

    throw std::runtime_error("failed to create window");
  }

  glfwMakeContextCurrent(window);

  glfwSetFramebufferSizeCallback(window,
                                 [](GLFWwindow* window, int width, int height) {
                                   glViewport(0, 0, width, height);
                                 });

  return window;
}

void initialize_glew() {
  if (glewInit() != GLEW_OK) {
    glfwTerminate();

    throw std::runtime_error("failed to initialize GLEW");
  }

  glEnable(GL_DEPTH_TEST);
}

Silicon::Application::Application(const std::size_t width,
                                  const std::size_t height,
                                  const std::string& title) {
  initialize_glfw();

  window = create_window(width, height, title);

  initialize_glew();
}

Silicon::Application::~Application() {
  glfwDestroyWindow(window);

  glfwTerminate();
}

void Silicon::Application::run() {
  Program program("../res/vertex_shader.glsl", "../res/fragment_shader.glsl");

  program.use();

  std::vector<Vertex> vertices;
  vertices.push_back(Vertex{{-1.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0}});
  vertices.push_back(Vertex{{-1.0, +1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0}});
  vertices.push_back(Vertex{{+1.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0}});
  vertices.push_back(Vertex{{+1.0, +1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0}});

  Model model;
  model.meshes.push_back(
      Mesh(vertices, {0, 1, 2, 1, 2, 3}, std::vector<Texture>()));

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    model.draw();

    glfwSwapBuffers(window);
  }
}
