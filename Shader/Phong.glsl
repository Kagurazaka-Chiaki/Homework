// Vertex shader program
attribute vec4 a_Position;
//attribute vec4 a_Color;// Defined constant in main()
attribute vec4 a_Normal;
uniform mat4 u_MvpMatrix;
uniform mat4 u_ModelMatrix;// Model matrix
uniform mat4 u_NormalMatrix;// Transformation matrix of the normal
varying vec4 v_Color;
varying vec3 v_Normal;
varying vec3 v_Position;
void main() {
   vec4 color = vec4(1.0, 1.0, 1.0, 1.0);// Sphere color
   gl_Position = u_MvpMatrix * a_Position;
   // Calculate the vertex position in the world coordinate
   v_Position = vec3(u_ModelMatrix * a_Position);
   v_Normal = normalize(vec3(u_NormalMatrix * a_Normal));
   v_Color = color;
}

// Fragment shader program
#ifdef GL_ES
precision mediump float;
#endif
uniform vec3 u_LightColor;// Light color
uniform vec3 u_LightPosition;// Position of the light source
uniform vec3 u_AmbientLight;// Ambient light color
varying vec3 v_Normal;
varying vec3 v_Position;
varying vec4 v_Color;
void main() {
   // Normalize the normal because it is interpolated and not 1.0 in length any more
   vec3 normal = normalize(v_Normal);
   // Calculate the light direction and make it 1.0 in length
   vec3 lightDirection = normalize(u_LightPosition - v_Position);
   // The dot product of the light direction and the normal
   float nDotL = max(dot(lightDirection, normal), 0.0);
   // Calculate the final color from diffuse reflection and ambient reflection
   vec3 diffuse = u_LightColor * v_Color.rgb * nDotL;
   vec3 ambient = u_AmbientLight * v_Color.rgb;
   gl_FragColor = vec4(diffuse + ambient, v_Color.a);
}
