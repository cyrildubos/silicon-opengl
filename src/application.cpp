#include <silicon/application.hpp>

void initialize_glfw() {
  if (!glfwInit())
    throw std::runtime_error("failed to initialize GLFW");

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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

  window = glfwCreateWindow(width, height, title.data(), NULL, NULL);

  if (!window) {
    glfwTerminate();

    throw std::runtime_error("failed to create window");
  }

  glfwMakeContextCurrent(window);

  glfwSetFramebufferSizeCallback(window,
                                 [](GLFWwindow* window, int width, int height) {
                                   glViewport(0, 0, width, height);
                                 });

  initialize_glew();
}

Silicon::Application::~Application() {
  glfwDestroyWindow(window);

  glfwTerminate();
}

void Silicon::Application::run() {
  Program program("../res/vertex_shader.glsl", "../res/fragment_shader.glsl");

  program.use();

  Model model;
  model.meshes.push_back(
      Mesh({{{-1.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0}},
            {{-1.0, +1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0}},
            {{+1.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0}},
            {{+1.0, +1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0}}},
           {0, 1, 2, 1, 2, 3}, {}));

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    model.draw();

    glfwSwapBuffers(window);
  }
}
