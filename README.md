# Autonomous Driving Project

## Dependencies

### Software
*   [crosstool-ng](https://crosstool-ng.github.io/) to create the cross toolchain
*   [doxygen](https://www.stack.nl/~dimitri/doxygen/) to generate source code documentation **[Not required]**
*   [RPlidar sdk](https://github.com/robopeak/rplidar_ros)

### Hardware
*   [RaspberryPi 3 Model B](https://www.raspberrypi.org/products/raspberry-pi-3-model-b/)
*   [RPlidar A2 (development kit)](http://www.slamtec.com/en/support#rplidar-a2)


## Setting up the workspace
1.  Build cross toolchain
```
cd tools
CC=/path/to/gcc-6 CXX=/path/to/g++-6 ct-ng build
```
2.  Create RPlidar sdk *(if lib/librplidar_sdk.a doesn't work)*
```
cd /tmp
wget -O rplidar-sdk.zip https://download.slamtec.com/api/download/rplidar-sdk/1.6.1?lang=netural
unzip rplidar-sdk
cd rplidar_sdk_v1.6.1/sdk
CROSS_COMPILE_PREFIX=/path/to/cross-compiler-prefix ./cross_compile.sh
cp ../output/Linux/Release/librplidar_sdk.a /path/to/project/lib/
```
3.  Create CMake project
```
cmake . -B".build" -DCMAKE_TOOLCHAIN_FILE=tools/crosstool-ng-toolchain.cmake
```

## Building
```
cmake --build .build --target all
cmake --build .build --target doc
```
