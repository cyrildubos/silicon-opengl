#version 330 core

in vec3 v_Position;
in vec3 v_Normal;
in vec2 v_Coordinate;

out vec4 f_Color;

void main() {
  f_Color = vec4(0.0, 0.5, 0.5, 1.0);
}