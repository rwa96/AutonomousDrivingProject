# Autonomous Driving Project

## Dependencies

### Software
*   [crosstool-ng](https://crosstool-ng.github.io/) to create the cross toolchain
*   [doxygen](https://www.stack.nl/~dimitri/doxygen/) to generate source code documentation

### Hardware
*   [RaspberryPi 3 Model B](https://www.raspberrypi.org/products/raspberry-pi-3-model-b/)
*   [RPlidar A2 (development kit)](http://www.slamtec.com/en/support#rplidar-a2)


## Setting up the workspace

### Linux (using crosstool-ng)
```
cd tools
CC=path/to/gcc CXX=path/to/g++ ct-ng build
cd ..
cmake . -B".build" -DCMAKE_TOOLCHAIN_FILE=tools/crosstool-ng-toolchain.cmake
```

## Building
```
cmake --build .build --target all
cmake --build .build --target doc
```
