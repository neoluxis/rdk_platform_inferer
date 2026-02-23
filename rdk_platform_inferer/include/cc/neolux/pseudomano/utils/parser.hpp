#pragma once

#include "filesystem"
#include "string"

namespace cc::neolux::pseudomano::utils {
class Parser {
private:
    std::filesystem::path config_path_;

public:
    Parser();
    Parser(const std::filesystem::path& config_path);
    Parser(const std::string& config_path);
    ~Parser();

    /**
     * @brief 解析配置文件
     * @details 解析配置文件并将结果存储在成员变量中，供其他成员函数使用
     * @param config_path 配置文件路径，如果不提供则使用构造函数中设置的路径
     */
    void parse();
    void parse(const std::filesystem::path& config_path);
    void parse(const std::string& config_path);
};
}  // namespace cc::neolux::pseudomano::utils
