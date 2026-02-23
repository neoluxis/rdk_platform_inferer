cmake_minimum_required(VERSION 3.20)

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

find_package(Eigen3 REQUIRED)
find_package(yaml-cpp REQUIRED)

set(INFERER_SOURCES
    ${PROJECT_NAME}/src/rdk_platform_inferer.cpp
)

set(UTIL_SOURCES
    ${PROJECT_NAME}/src/parser.cpp
    ${PROJECT_NAME}/src/pre_proc.cpp
    ${PROJECT_NAME}/src/post_proc.cpp
)

set(INCLUDE_DIRECTORIES
    ${PROJECT_NAME}/include
)

add_library(${PROJECT_NAME} SHARED ${INFERER_SOURCES} ${UTIL_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRECTORIES})

target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen yaml-cpp::yaml-cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN 1
    )
    target_compile_options(${PROJECT_NAME} PRIVATE -O3 -march=native)
endif(CMAKE_BUILD_TYPE STREQUAL "Release")

if(INFERER_BUILD_APP)
    set(APP_SOURCES
        ${PROJECT_NAME}/src/main.cpp
    )
    add_executable(${PROJECT_NAME}_app ${APP_SOURCES})
    target_link_libraries(${PROJECT_NAME}_app ${PROJECT_NAME})
endif(INFERER_BUILD_APP)
