#version 120

varying vec2 texCoord0;
varying vec3 normal0;

uniform sampler2D diffuse;

void main() {
	vec3 lightDirection = vec3(0,0,1);
	float reflectAmount = clamp(dot(-lightDirection, normal0), 0, 1);
	gl_FragColor = texture2D(diffuse, texCoord0) * reflectAmount;
	//gl_FragColor = vec4(1.0,1.0,0.0,1.0);
}