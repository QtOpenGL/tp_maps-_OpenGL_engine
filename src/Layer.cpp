#include "tp_maps/Layer.h"
#include "tp_maps/Map.h"

#include "tp_math_utils/Transformation.h"

#include "tp_utils/DebugUtils.h"
#include "tp_utils/StackTrace.h"

namespace tp_maps
{
struct Layer::Private
{
  TP_REF_COUNT_OBJECTS("tp_maps::Layer::Private");
  TP_NONCOPYABLE(Private);

  Layer* q;

  Map* map{nullptr};
  Layer* parent{nullptr};
  std::vector<Layer*> layers;
  tp_utils::StringID coordinateSystem{defaultSID()};
  RenderPass defaultRenderPass{RenderPass::Normal};
  bool visible{true};

  //################################################################################################
  Private(Layer* q_):
    q(q_)
  {

  }
};

//##################################################################################################
Layer::Layer():
  d(new Private(this))
{
}

//##################################################################################################
Layer::~Layer()
{  
  clearChildLayers();

  if(d->parent)
    d->parent->childLayerDestroyed(this);
  else if(d->map)
    d->map->layerDestroyed(this);

  delete d;
}

//##################################################################################################
Map* Layer::map()const
{
  return d->map;
}

//##################################################################################################
void Layer::setCoordinateSystem(const tp_utils::StringID& coordinateSystem)
{
  d->coordinateSystem = coordinateSystem;
}

//##################################################################################################
const tp_utils::StringID& Layer::coordinateSystem()const
{
  return d->coordinateSystem;
}

//##################################################################################################
bool Layer::visible() const
{
  return d->visible;
}

//##################################################################################################
void Layer::setVisible(bool visible)
{
  d->visible = visible;
  update();
}

//##################################################################################################
RenderPass Layer::defaultRenderPass() const
{
  return d->defaultRenderPass;
}

//##################################################################################################
void Layer::setDefaultRenderPass(RenderPass defaultRenderPass)
{
  d->defaultRenderPass = defaultRenderPass;
}

//##################################################################################################
void Layer::addChildLayer(Layer* layer)
{
  insertChildLayer(d->layers.size(), layer);
}

//##################################################################################################
void Layer::insertChildLayer(size_t i, Layer *layer)
{
  if(layer->map())
  {
    tpWarning() << "Error! Map::insertLayer inserting a layer that is already in a map!";
    tp_utils::printStackTrace();
    return;
  }

  d->layers.insert(d->layers.begin()+int(i), layer);
  layer->setMap(map(), this);
  update();
}

//##################################################################################################
void Layer::removeChildLayer(Layer* layer)
{
  tpRemoveOne(d->layers, layer);
  layer->clearMap();
}

//##################################################################################################
void Layer::clearChildLayers()
{
  while(!d->layers.empty())
    delete d->layers.at(d->layers.size()-1);
}

//##################################################################################################
const std::vector<Layer*>& Layer::childLayers()const
{
  return d->layers;
}

//##################################################################################################
std::vector<Layer*>& Layer::childLayers()
{
  return d->layers;
}

//##################################################################################################
void Layer::render(RenderInfo& renderInfo)
{
  for(auto l : d->layers)
    if(l->visible())
      l->render(renderInfo);
}

//##################################################################################################
void Layer::invalidateBuffers()
{
  for(auto i : d->layers)
    i->invalidateBuffers();
}

//##################################################################################################
bool Layer::mouseEvent(const MouseEvent& event)
{
  for(Layer** l = d->layers.data() + d->layers.size(); l>d->layers.data();)
    if((*(--l))->mouseEvent(event))
      return true;
  return false;
}

//##################################################################################################
bool Layer::keyEvent(const KeyEvent& event)
{
  for(Layer** l = d->layers.data() + d->layers.size(); l>d->layers.data();)
    if((*(--l))->keyEvent(event))
      return true;
  return false;
}

//##################################################################################################
bool Layer::textEditingEvent(const TextEditingEvent& event)
{
  for(Layer** l = d->layers.data() + d->layers.size(); l>d->layers.data();)
    if((*(--l))->textEditingEvent(event))
      return true;
  return false;
}

//##################################################################################################
bool Layer::textInputEvent(const TextInputEvent& event)
{
  for(Layer** l = d->layers.data() + d->layers.size(); l>d->layers.data();)
    if((*(--l))->textInputEvent(event))
      return true;
  return false;
}

//##################################################################################################
void Layer::animate(double timestampMS)
{
  for(auto l : d->layers)
    l->animate(timestampMS);

  animateCallbacks(timestampMS);
}

//##################################################################################################
void Layer::lightsChanged(LightingModelChanged lightingModelChanged)
{
  for(auto l : d->layers)
    l->lightsChanged(lightingModelChanged);
}

//##################################################################################################
void Layer::update()
{
  if(d->map)
    d->map->update();
}

//##################################################################################################
void Layer::childLayerDestroyed(Layer* layer)
{
  tpRemoveOne(d->layers, layer);
  update();
}

//##################################################################################################
void Layer::setMap(Map* map, Layer* parent)
{
  d->map = map;
  d->parent = parent;
  for(auto layer : d->layers)
    layer->setMap(map, this);
}

//##################################################################################################
void Layer::clearMap()
{
  d->map = nullptr;
  d->parent = nullptr;
}
}
