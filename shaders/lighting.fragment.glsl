#version 330

uniform sampler2D texture0;
uniform vec4 colDiffuse;

in vec3 fragPosition;
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;

out vec4 finalColor;

vec4 linear_to_srgb(vec4 c) {
  bvec3 cutoff = lessThanEqual(c.rgb, vec3(0.0031308));
  vec3 lower  = c.rgb * 12.92;
  vec3 higher = 1.055 * pow(c.rgb, vec3(1.0/2.4)) - 0.055;

  vec3 rgb = mix(higher, lower, vec3(cutoff));
  return vec4(rgb, c.a);
}

void main() {
  finalColor = linear_to_srgb(fragColor);
}
