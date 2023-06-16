cmake_minimum_required(VERSION 3.0.0)

project(silicon-opengl VERSION 0.1.0 LANGUAGES CXX)

set(OpenGL_GL_PREFERENCE LEGACY)

find_package(OpenGL REQUIRED)
find_package(GLEW   REQUIRED)
find_package(glm    REQUIRED)
find_package(glfw3  REQUIRED)

add_library(Silicon 
  src/application.cpp 
  src/mesh.cpp 
  src/model.cpp 
  src/program.cpp 
  src/shader.cpp 
  src/texture.cpp 
  src/utilities.cpp
)

target_link_libraries(Silicon PRIVATE OpenGL::GL)
target_link_libraries(Silicon PRIVATE GLEW::glew)
target_link_libraries(Silicon PRIVATE glm::glm)
target_link_libraries(Silicon PRIVATE glfw)

target_include_directories (Silicon PUBLIC include)


add_executable(main
  src/main.cpp)

target_link_libraries(main PUBLIC Silicon)
