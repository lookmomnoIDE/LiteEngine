#version 330 core
layout (location = 0) in vec4 aPos;
//layout (location = 1) in vec4 aColor;
//layout (location = 2) in vec2 texCoords;

//out vec4 ourColor;
out vec2 v_texCoord;

uniform mat4 projection;

void main()
{
    gl_Position = projection * vec4(aPos.xy, 0.0, 1.0);
    v_texCoord = vec2(aPos.zw);
    //ourColor = aColor;
}