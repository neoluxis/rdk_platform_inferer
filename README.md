# RDK 平台推理库

在 RDK 平台部署的推理代码。支持 `onnx` 模型和地瓜机器人 `bin` 格式模型。

其中 `onnx` 模型使用 `onnxruntime` 进行推理，`bin` 格式模型使用地瓜提供的 `hobot_dnn`

- 对于 `onnx` 模型，可以直接在电脑编译，调试运行；同时配置了 docker 可以用于交叉编译。
本地调试时，我直接使用了地瓜机器人提供的 RDK 平台的 rootfs 打包 docker 镜像，具体操作方法可以参考博客文章:
[配置交叉编译环境 - PC to Raspi/RDK/…](https://me.neolux.eu.org/2026/02/05/linux/cross_compile_pc2arm/)

- 对于 `bin` 模型，由于 x86 平台没有可用的 BPU 加速单元，也没有对应的驱动，因此需要在板端调试。编译则可以在板端或交叉编译环境中进行

## 交叉编译环境配置

可以参考博客文章配置，但需要把对应镜像名称设置为 `rdkx3-img`；或者自定义名称后，在 `Dockerfile` 和 `docker-compose.yaml` 中做对应修改

## 相关工作

- 灵巧手项目依赖于 `unitransmit-cpp` 与其它设备进行通信，其提供了一个统一的通信接口用于多种协议通讯的统一解析
- onnx 推理部分使用了 `generic_onnx_inferencer_pipeline-cpp`，提供了一个通用的推理管线，在本项目中只需要提供对应的前后处理方法即可
- `hobot_dnn` 推理部分使用了 `hobot_dnn_inferencer_pipeline-cpp`，其提供的内容类似与 onnx 部分

## Usage

```bash
git clone https://github.com/neoluxis/rdk_platform_inferer.git --recursive
cd rdk_platform_inferer
cmake -S . -B build -DINFERER_BUILD_APP=ON
cmake --build build -j
```

## Note

该项目为灵巧手项目部署模型使用，因此数据获取、前后处理、结果处理均为灵巧手项目所需，同时配有注释，编译迁移其他项目。可以 [fork 本项目](https://github.com/neoluxis/rdk_platform_inferer/fork) 后修改
