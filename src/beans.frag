#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 v_texCoord;

uniform sampler2D u_Texture;
//uniform float uTime;
void main()
{
	vec4 texColor = texture(u_Texture, v_texCoord);
	//float scale = sin(uTime);
	FragColor = mix(vec4(ourColor.x, ourColor.y, ourColor.z, 1.0f), texColor, 0.5);
}