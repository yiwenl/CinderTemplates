attribute vec3 aNormals;

varying vec3 vNormals;

void main() {
    gl_TexCoord[0]  = gl_MultiTexCoord0;
    vec4 pos        = gl_Vertex;

    gl_Position     = gl_ModelViewProjectionMatrix * pos;
    vNormals        = aNormals;
}