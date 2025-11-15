#version 330

uniform vec3 surfaceColor;

out vec4 fragColor;

in vec3 fragPosition;
in vec3 fragNormal;

void main() {
  vec3 lightPosition = vec3(-2.0, 3.0, 3.0);
  vec3 lightDiffuse = vec3(1.0, 1.0, 1.0);
  vec3 lightAmbient = vec3(1.0, 1.0, 1.0);

  vec3 surfaceAmbient = vec3(0.4, 0.4, 0.4);
  vec3 surfaceDiffuse = vec3(0.5, 0.5, 0.5);

  vec3 ambient = lightAmbient * surfaceAmbient;

  vec3 lightDirection = normalize(fragPosition - lightPosition);
  float diff = max(dot(fragNormal, -lightDirection), 0);
  vec3 diffuse = diff * lightDiffuse * surfaceDiffuse;

  fragColor = vec4((ambient + diffuse) * surfaceColor, 1.0);
}
