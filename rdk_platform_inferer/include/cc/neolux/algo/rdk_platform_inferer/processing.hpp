#pragma once
/**
 * @brief 前后处理接口定义
 * @author neolux
 * @date 2026-02-23
 */
#include "vector"

namespace cc::neolux::algo::rdk_platform_inferer {
class PreProcess {
private:
    /* data */
public:
    PreProcess(/* args */);
    ~PreProcess();
    std::vector<float> operator()(const std::vector<float>& input);
};

class PostProcess {
private:
    /* data */
public:
    PostProcess(/* args */);
    ~PostProcess();
    std::vector<float> operator()(const std::vector<float>& input);
};
}  // namespace cc::neolux::algo::rdk_platform_inferer
