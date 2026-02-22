cmake_minimum_required(VERSION 4.2)

project(rdk_platform_inferer)

option(INFERER_USING_ONNXRUNTIME "Use ONNXRuntime to infer" ON)
option(INFERER_USING_HOBOT_DNN "Use Hobot DNN to infer" OFF)

message("RDK Platform Inferer")

if(INFERER_USING_ONNXRUNTIME)
    add_subdirectory(3rdparty/generic_onnx_inferencer_pipeline-cpp)
endif(INFERER_USING_ONNXRUNTIME)

if(INFERER_USING_HOBOT_DNN)
    add_subdirectory(3rdparty/rdk_hobotdnn_inference_pipeline-cpp)
endif(INFERER_USING_HOBOT_DNN)
add_subdirectory(3rdparty/unitransmit-cpp)

