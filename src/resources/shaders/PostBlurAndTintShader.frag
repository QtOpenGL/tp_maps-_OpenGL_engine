/*TP_FRAG_SHADER_HEADER*/

/*TP_GLSL_IN_F*/vec2 coord_tex;

uniform sampler2D textureSampler;
uniform sampler2D depthSampler;

uniform mat4 projectionMatrix;
uniform mat4 invProjectionMatrix;

uniform vec2 pixelSize;

/*TP_GLSL_GLFRAGCOLOR_DEF*/

//bool hit(int x, int y)
//{
//  return (/*TP_GLSL_TEXTURE_2D*/(depthSampler, coord_tex).x<1.0f);
//}

void main()
{
  vec3 color = vec3(0.0,0.0,0.0);
  float count = 0.0;

  for(int y=-2; y<3; y++)
  {
    float sy = coord_tex.y + pixelSize.y*float(y);
    if(sy<0.0f || sy>1.0f)
      continue;

    for(int x=-2; x<3; x++)
    {
      float sx = coord_tex.x + pixelSize.x*float(x);
      if(sx<0.0f || sx>1.0f)
        continue;

      color += /*TP_GLSL_TEXTURE_2D*/(textureSampler, vec2(sx, sy)).xyz;
      count++;
    }
  }

  color = color/count;
  color *= 0.8;
  color += 0.2;

   /*TP_GLSL_GLFRAGCOLOR*/ = vec4(color, 1.0);
}
