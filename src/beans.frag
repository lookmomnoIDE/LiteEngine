#version 330 core
out vec4 FragColor;
in vec4 ourColor;
in vec2 v_texCoord;

uniform sampler2D texture0;
//uniform float uTime;
void main()
{
	//vec4 texColor = texture(u_Texture, v_texCoord);
	//float scale = sin(uTime);
	FragColor = texture(texture0, v_texCoord);//mix(texture(texture0), ourColor, .5);
}
