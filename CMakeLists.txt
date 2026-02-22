cmake_minimum_required(VERSION 4.2)

project(rdk_platform_inferer)

option(INFERER_USING_ONNXRUNTIME "Use ONNXRuntime to infer" ON)
option(INFERER_USING_HOBOT_DNN "Use Hobot DNN to infer" OFF

message("RDK Platform Inferer")

if(INFERER_USING_ONNXRUNTIME)
    add_subdirectory(3rdparty/onnx_runner)
endif(INFERER_USING_ONNXRUNTIME)

if(INFERER_USING_HOBOT_DNN)
    add_subdirectory(3rdparty/hobotdnn_runner)
endif(INFERER_USING_HOBOT_DNN)
add_subdirectory(3rdparty/unitransmit)

