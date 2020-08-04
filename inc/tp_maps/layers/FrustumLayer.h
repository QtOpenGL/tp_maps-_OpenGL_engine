#ifndef tp_maps_FrustumLayer_h
#define tp_maps_FrustumLayer_h

#include "tp_maps/Layer.h"

namespace tp_maps
{

//##################################################################################################
class TP_MAPS_SHARED_EXPORT FrustumLayer: public Layer
{
public:
  //################################################################################################
  FrustumLayer();

  //################################################################################################
  virtual ~FrustumLayer();

  //################################################################################################
  void setCameraMatrix(const glm::mat4& matrix);

  //################################################################################################
  void setCameraMatrices(const std::vector<glm::mat4>& matrices);

  //################################################################################################
  bool renderFrustumBorder() const;

  //################################################################################################
  void setRenderFrustumBorder(bool renderFrustumBorder);

  //################################################################################################
  bool renderRays() const;

  //################################################################################################
  void setRenderRays(bool renderRays);

  //################################################################################################
  glm::vec3 frustumBorderColor() const;

  //################################################################################################
  void setFrustumBorderColor(const glm::vec4& frustumBorderColor);

  //################################################################################################
  glm::vec3 raysColor() const;

  //################################################################################################
  void setRaysColor(const glm::vec4& raysColor);

protected:
  //################################################################################################
  void render(RenderInfo& renderInfo) override;

  //################################################################################################
  void invalidateBuffers() override;

private:
  struct Private;
  Private* d;
  friend struct Private;
};

}

#endif
