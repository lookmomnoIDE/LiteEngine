#version 330 core
out vec4 FragColor;
in vec4 ourColor;
//in vec2 v_texCoord;

//uniform sampler2D u_Texture;
//uniform float uTime;
void main()
{
	//vec4 texColor = texture(u_Texture, v_texCoord);
	//float scale = sin(uTime);
	FragColor = ourColor;
}