#include "tp_maps/picking_results/HandlePickingResult.h"
#include "tp_maps/layers/HandleLayer.h"

namespace tp_maps
{

//##################################################################################################
HandlePickingResult::HandlePickingResult(const tp_utils::StringID& pickingType_,
                                       const PickingDetails& details_,
                                       const RenderInfo& renderInfo_,
                                       HandleDetails *handle_):
  PickingResult(pickingType_, details_, renderInfo_, handle_->layer()),
  handle(handle_)
{

}

}
