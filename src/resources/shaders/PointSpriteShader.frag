/*TP_FRAG_SHADER_HEADER*/

/*TP_GLSL_IN_F*/vec2 texCoordinate;
/*TP_GLSL_IN_F*/vec4 color;
/*TP_GLSL_IN_F*/float clip;

uniform sampler2D textureSampler;

/*TP_GLSL_GLFRAGCOLOR_DEF*/

void main()
{
  /*TP_GLSL_GLFRAGCOLOR*/ = /*TP_GLSL_TEXTURE_2D*/(textureSampler, texCoordinate) * color;
  if(/*TP_GLSL_GLFRAGCOLOR*/.a < 0.001 || clip<0.1)
    discard;
}
