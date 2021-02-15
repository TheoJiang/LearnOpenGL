#version 330 core
out vec4 color;
in vec4 vColor;
uniform vec4 changingColor = vec4(1,1,1,1);
void main()
{
    color = vec4(vColor) + changingColor;
}