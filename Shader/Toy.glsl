vec3 sdfCircle(vec2 uv, float r) {
  float x = uv.x;
  float y = uv.y;

  float d = length(vec2(x, y)) - r;

  return d > 0. ? vec3(0.) : 0.5 + 0.5 * cos(iTime + uv.xyx + vec3(0,2,4));
}

vec3 rect(vec2 uv, vec2 size) {
  vec2 d = abs(uv) - size;
  return vec3(min(max(d.x, d.y), 0.0) + length(max(d, 0.0)), 0.0, 0.0);
}


void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
  vec2 uv = fragCoord/iResolution.xy; // <0,1>
  uv -= 0.5;
  uv.x *= iResolution.x/iResolution.y; // fix aspect ratio

  vec3 col = sdfCircle(uv, .2);

  // vec3 col = vec3(rect(uv, vec2(.2, .2)));

  // Output to screen
  fragColor = vec4( col, 1.0);
}
