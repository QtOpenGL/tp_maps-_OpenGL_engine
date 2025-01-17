#ifndef tp_maps_FullScreenShader_h
#define tp_maps_FullScreenShader_h

#include "tp_maps/Shader.h"

namespace tp_maps
{

//##################################################################################################
//! The base class for post processing shaders.
class TP_MAPS_SHARED_EXPORT FullScreenShader: public Shader
{
public:
  //################################################################################################
  FullScreenShader(Map* map, tp_maps::OpenGLProfile openGLProfile);

  //################################################################################################
  ~FullScreenShader() override;

  //################################################################################################
  void compile(const char* vertexShader,
               const char* fragmentShader,
               const std::function<void(GLuint)>& bindLocations,
               const std::function<void(GLuint)>& getLocations,
               ShaderType shaderType = ShaderType::Render);

  //################################################################################################
  void setFrameMatrix(const glm::mat4& frameMatrix);

  //################################################################################################
  struct Object
  {
    //##############################################################################################
    Object(const Shader* shader_);

    //##############################################################################################
    ~Object();

    //##############################################################################################
    void bindVBO();

    GLsizei size{0};
    GLuint vboID{0};

  #ifdef TP_VERTEX_ARRAYS_SUPPORTED
    GLuint vaoID{0};
  #endif

    ShaderPointer shader;
  };

  //################################################################################################
  void draw();

  //################################################################################################
  void draw(const Object& object);

  //################################################################################################
  Object* makeObject(const std::vector<glm::vec2>& verts);

  //################################################################################################
  Object* makeRectangleObject(const glm::vec2& size);

  //################################################################################################
  Object* makeFrameObject(const glm::vec2& holeSize, const glm::vec2& size);

private:
  struct Private;
  Private* d;
  friend struct Private;
};

}

#endif
