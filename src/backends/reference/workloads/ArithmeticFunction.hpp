//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <armnn/Tensor.hpp>

namespace armnn
{

template <typename Functor>
struct ArithmeticFunction
{
    ArithmeticFunction(const TensorShape& inShape0,
                       const TensorShape& inShape1,
                       const TensorShape& outShape,
                       const float* inData0,
                       const float* inData1,
                       float* outData);
};

} //namespace armnn
