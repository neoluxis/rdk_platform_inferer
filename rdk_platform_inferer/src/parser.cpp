#include "cc/neolux/pseudomano/utils/parser.hpp"

#include "iostream"
#include "yaml-cpp/yaml.h"

namespace cc::neolux::pseudomano::utils {
Parser::Parser(/* args */) {}
Parser::Parser(const std::filesystem::path& config_path) {
    config_path_ = config_path;
}
Parser::Parser(const std::string& config_path) {
    Parser(std::filesystem::path(config_path));
}

Parser::~Parser() = default;

void Parser::parse() {
    if (config_path_.empty()) {
        throw std::runtime_error("Config path is empty. Please provide a valid config path.");
    }

    try {
        YAML::Node config = YAML::LoadFile(config_path_);
        // 这里可以添加具体的解析逻辑，将配置项存储在成员变量中供其他成员函数使用
    } catch (const std::exception& e) {
        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
        throw;
    }
}
void Parser::parse(const std::filesystem::path& config_path) {
    config_path_ = config_path;
    parse();
}
void Parser::parse(const std::string& config_path) {
    parse(std::filesystem::path(config_path));
}

}  // namespace cc::neolux::pseudomano::utils
