# Autonomous Driving Project

## Dependencies

### Software
*   [doxygen](https://www.stack.nl/~dimitri/doxygen/) **[Not required]**
*   [RPLidar SDK](https://github.com/slamtec/rplidar_sdk)
*   [GoogleTest](https://github.com/google/googletest)

### Hardware
*   [RaspberryPi 3 Model B](https://www.raspberrypi.org/products/raspberry-pi-3-model-b/)
*   [RPlidar A2 (development kit)](http://www.slamtec.com/en/support#rplidar-a2)

## Setting up the workspace
```
cmake . -B"build"
```

## Building
```
cmake --build build --target all
cmake --build build --target doc
```

## Testing
```
cmake --build build --target all
cd build && ctest -VV
```