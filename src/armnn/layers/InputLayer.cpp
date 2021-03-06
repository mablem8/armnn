//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#include "InputLayer.hpp"

#include "LayerCloneBase.hpp"

#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

namespace armnn
{

InputLayer::InputLayer(LayerBindingId id, const char* name)
    : BindableLayer(0, 1, LayerType::Input, name, id)
{
}

std::unique_ptr<IWorkload> InputLayer::CreateWorkload(const Graph& graph, const IWorkloadFactory& factory) const
{
    return nullptr;
}

InputLayer* InputLayer::Clone(Graph& graph) const
{
    return CloneBase<InputLayer>(graph, GetBindingId(), GetName());
}

void InputLayer::ValidateTensorShapesFromInputs()
{
    //The input layer should already have it's inputs set during graph building phase in the driver/parser.
    ConditionalThrow<LayerValidationException>(GetOutputSlot(0).IsTensorInfoSet(),
                                               "InputLayer should already have the TensorInfo set.");
}

} // namespace
