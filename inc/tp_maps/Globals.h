#ifndef tp_maps_Globals_h
#define tp_maps_Globals_h

#if defined(TP_MAPS_LIBRARY)
#  define TP_MAPS_SHARED_EXPORT
#else
#  define TP_MAPS_SHARED_EXPORT
#endif

#include "tp_utils/StringID.h"

//https://github.com/mattdesl/lwjgl-basics/wiki/GLSL-Versions

#ifdef TDP_OSX //-----------------------------------------------------------------------------------
#  define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#  include <GLES3/gl3.h>
#  include <OpenGL/glext.h>

#  define TP_VERT_SHADER_HEADER "#version 120\n"
#  define TP_FRAG_SHADER_HEADER "#version 120\n"

#  define TP_GLSL_IN_V "attribute "
#  define TP_GLSL_IN_F "varying "
#  define TP_GLSL_OUT_V "varying "
#  define TP_GLSL_OUT_F "varying "
#  define TP_GLSL_GLFRAGCOLOR "gl_FragColor"
#  define TP_GLSL_GLFRAGCOLOR_DEF
#  define TP_GLSL_TEXTURE "texture2D"

#  define tpGenVertexArrays glGenVertexArraysAPPLE
#  define tpBindVertexArray glBindVertexArrayAPPLE
#  define tpDeleteVertexArrays glDeleteVertexArraysAPPLE
#elif defined(TDP_EMSCRIPTEN) //--------------------------------------------------------------------
#  include <GLES3/gl3.h>

#  define TP_VERT_SHADER_HEADER "#version 100\nprecision mediump float;\n"
#  define TP_FRAG_SHADER_HEADER "#version 100\nprecision mediump float;\n"

#  define TP_GLSL_IN_V "attribute "
#  define TP_GLSL_IN_F "varying "
#  define TP_GLSL_OUT_V "varying "
#  define TP_GLSL_OUT_F "varying "
#  define TP_GLSL_GLFRAGCOLOR "gl_FragColor"
#  define TP_GLSL_GLFRAGCOLOR_DEF
#  define TP_GLSL_TEXTURE "texture2D"

#  define tpGenVertexArrays glGenVertexArrays
#  define tpBindVertexArray glBindVertexArray
#  define tpDeleteVertexArrays glDeleteVertexArrays
#elif defined(TDP_ANDROID) //-----------------------------------------------------------------------
#  include <GLES3/gl3.h>

#  define TP_VERT_SHADER_HEADER "#version 100\nprecision mediump float;\n"
#  define TP_FRAG_SHADER_HEADER "#version 100\nprecision mediump float;\n"

#  define TP_GLSL_IN_V "attribute "
#  define TP_GLSL_IN_F "varying "
#  define TP_GLSL_OUT_V "varying "
#  define TP_GLSL_OUT_F "varying "
#  define TP_GLSL_GLFRAGCOLOR "gl_FragColor"
#  define TP_GLSL_GLFRAGCOLOR_DEF
#  define TP_GLSL_TEXTURE "texture2D"

#  define tpGenVertexArrays glGenVertexArrays
#  define tpBindVertexArray glBindVertexArray
#  define tpDeleteVertexArrays glDeleteVertexArrays
#else //--------------------------------------------------------------------------------------------
#  include <GLES3/gl3.h>

#  define TP_VERT_SHADER_HEADER "#version 130\nprecision mediump float;\n"
#  define TP_FRAG_SHADER_HEADER "#version 130\nprecision mediump float;\n"

#  define TP_GLSL_IN_V "in "
#  define TP_GLSL_IN_F "in "
#  define TP_GLSL_OUT_V "out "
#  define TP_GLSL_OUT_F "out "
#  define TP_GLSL_GLFRAGCOLOR "fragColor"
#  define TP_GLSL_GLFRAGCOLOR_DEF "out vec4 fragColor;\n"
#  define TP_GLSL_TEXTURE "texture"

#  define tpGenVertexArrays glGenVertexArrays
#  define tpBindVertexArray glBindVertexArray
#  define tpDeleteVertexArrays glDeleteVertexArrays
#endif //-------------------------------------------------------------------------------------------

//##################################################################################################
//! A simple 3D engine
namespace tp_maps
{
TDP_DECLARE_ID(                      defaultSID,                          "Default")
TDP_DECLARE_ID(                   lineShaderSID,                      "Line shader")
TDP_DECLARE_ID(                  imageShaderSID,                     "Image shader")
TDP_DECLARE_ID(            pointSpriteShaderSID,              "Point sprite shader")
TDP_DECLARE_ID(               materialShaderSID,                  "Material shader")
}

typedef float tpGLfloat;

#endif
