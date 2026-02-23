/**
 * @brief 预处理相关实现
 * @author neolux
 * @date 2026-02-23
 */

#include "Eigen/Dense"
#include "cc/neolux/algo/rdk_platform_inferer/processing.hpp"
#include "iostream"

namespace cc::neolux::algo::rdk_platform_inferer {
PreProcess::PreProcess(/* args */) {}

PreProcess::~PreProcess() = default;

std::vector<float> PreProcess::operator()(const std::vector<float>& input) {
    std::vector<float> output = input;
    return output;
}
}  // namespace cc::neolux::algo::rdk_platform_inferer
