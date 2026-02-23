cmake_minimum_required(VERSION 4.2)

project(rdk_platform_inferer)

option(INFERER_USING_ONNXRUNTIME "Use ONNXRuntime to infer" ON)
option(INFERER_USING_HOBOT_DNN "Use Hobot DNN to infer" OFF)
option(INFERER_BUILD_APP "Build sample app using the lib" ON)

message("RDK Platform Inferer")

if(INFERER_USING_ONNXRUNTIME)
    add_subdirectory(3rdparty/generic_onnx_inferencer_pipeline-cpp)
endif(INFERER_USING_ONNXRUNTIME)

if(INFERER_USING_HOBOT_DNN)
    add_subdirectory(3rdparty/rdk_hobotdnn_inference_pipeline-cpp)
endif(INFERER_USING_HOBOT_DNN)
add_subdirectory(3rdparty/unitransmit-cpp)

set(SOURCES
    ${PROJECT_NAME}/src/rdk_platform_inferer.cpp
)

set(INCLUDE_DIRECTORIES
    ${PROJECT_NAME}/include
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRECTORIES})

if(INFERER_BUILD_APP)
    set(APP_SOURCES
        ${PROJECT_NAME}/src/main.cpp
    )    
    add_executable(${PROJECT_NAME}_app ${APP_SOURCES})
    target_link_libraries(${PROJECT_NAME}_app ${PROJECT_NAME})
endif(INFERER_BUILD_APP)
