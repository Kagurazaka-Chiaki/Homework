// Vertex shader program
 attribute vec4 a_Position;
 // attribute vec4 a_Color;// Defined constant in main()
 attribute vec4 a_Normal;
 uniform mat4 u_MvpMatrix;
 uniform mat4 u_ModelMatrix;// Model matrix
 uniform mat4 u_NormalMatrix;// Transformation matrix of the normal
 uniform vec3 u_LightColor;// Light color
 uniform vec3 u_LightPosition;// Position of the light source
 uniform vec3 u_AmbientLight;// Ambient light color
 varying vec4 v_Color;
 void main() {
     vec4 color = vec4(1.0, 1.0, 1.0, 1.0);// Sphere color
     gl_Position = u_MvpMatrix * a_Position;
     // Calculate a normal to be fit with a model matrix, and make it 1.0 in length
     vec3 normal = normalize(vec3(u_NormalMatrix * a_Normal));
     // Calculate world coordinate of vertex
     vec4 vertexPosition = u_ModelMatrix * a_Position;
     // Calculate the light direction and make it 1.0 in length
     vec3 lightDirection = normalize(u_LightPosition - vec3(vertexPosition));
     // The dot product of the light direction and the normal
     float nDotL = max(dot(lightDirection, normal), 0.0);
     // Calculate the color due to diffuse reflection
     vec3 diffuse = u_LightColor * color.rgb * nDotL;
     // Calculate the color due to ambient reflection
     vec3 ambient = u_AmbientLight * color.rgb;
     // Add the surface colors due to diffuse reflection and ambient reflection
     v_Color = vec4(diffuse + ambient, color.a);
 }

 // Fragment shader program
 #ifdef GL_ES
 precision mediump float;
 #endif
 varying vec4 v_Color;
 void main() {
    gl_FragColor = v_Color;
 }