#include <memory>
#include <iostream>
#include <cstdlib>
#include "rplidar.h"
#include "presets.hpp"

using RPlidarDriver = rp::standalone::rplidar::RPlidarDriver;

int main(int argc, char const *argv[]) {
    // create managed instance of RPlidarDriver to controll the lidar device
    std::unique_ptr<RPlidarDriver> rplidar(RPlidarDriver::CreateDriver());
    if(!rplidar){
        std::cerr << "Could not allocate RPlidarDriver instance" << std::endl;
        return EXIT_FAILURE;
    }

    // connect to lidar device
    if(!IS_OK(rplidar->connect(RPLIDAR_CONNECTION, RPLIDAR_BAUD_RATE))){
        std::cerr << "Serial connection could not be established" << std::endl;
        return EXIT_FAILURE;
    }

    // disconnect
    rplidar->disconnect();

    return EXIT_SUCCESS;
}
