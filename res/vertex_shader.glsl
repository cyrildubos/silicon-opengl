#version 330 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec3 a_Normal;
layout (location = 2) in vec2 a_Coordinate;

out vec3 v_Position;
out vec3 v_Normal;
out vec2 v_Coordinate;

void  main() { 
  gl_Position = vec4(a_Position, 1.0); 
  
  v_Position = a_Position; 
  v_Normal = a_Normal; 
  v_Coordinate = a_Coordinate;
}