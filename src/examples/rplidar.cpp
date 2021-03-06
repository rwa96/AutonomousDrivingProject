#include <memory>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "rplidar.h"        // RPlidar sdk
#include "project_info.hpp" // Serial port and baud rate
#include "utils.hpp"        // Error messages

namespace RPlidar = rp::standalone::rplidar;

/**
 * Example implementation using rplidar sdk interface.
 */
int main() {
    // create managed instance of RPlidarDriver to controll the lidar device
    std::unique_ptr<RPlidar::RPlidarDriver, decltype(&RPlidar::RPlidarDriver::DisposeDriver)>
    rplidar(
        RPlidar::RPlidarDriver::CreateDriver(), 
        &RPlidar::RPlidarDriver::DisposeDriver
    );

    if (!rplidar) {
        ERROR_MSG("Could not allocate RPlidarDriver instance");
        return EXIT_FAILURE;
    }

    // connect to lidar device
    if (IS_FAIL(rplidar->connect(RPLIDAR_CONNECTION, RPLIDAR_BAUD_RATE))) {
        ERROR_MSG("Serial connection could not be established");
        return EXIT_FAILURE;
    }

    // check health status
    rplidar_response_device_health_t healthinfo;

    if (IS_OK(rplidar->getHealth(healthinfo))) {
        std::cout << "RPLidar health status: " << healthinfo.status << std::endl;

        if (healthinfo.status == RPLIDAR_STATUS_ERROR) {
            ERROR_MSG("RPlidar internal error detected. Please reboot the device to retry");
            //rplidar->reset(); // in a real implementation, reset should be used
            return EXIT_FAILURE;
        }
    } else {
        ERROR_MSG("Cannot retrieve the lidar health");
        return EXIT_FAILURE;
    }

    // get device info
    rplidar_response_device_info_t devinfo;

    if (IS_OK(rplidar->getDeviceInfo(devinfo))) {
        std::cout << "RPlidar S/N: ";

        for(int pos = 0; pos < 16 ; ++pos) {std::cout << devinfo.serialnum[pos];}

        std::cout << "\nFirmware Ver: " << (devinfo.firmware_version >> 8) << '.'
                  << (devinfo.firmware_version & 0xFF);
        std::cout << "\nHardware Rev: " << devinfo.hardware_version << std::endl;
    }

    // start motor
    if (IS_FAIL(rplidar->startMotor())) {
        ERROR_MSG("Could not start motor");
        rplidar->disconnect();
        return EXIT_FAILURE;
    }

    // get scan modes and start scanning
    std::vector<RPlidar::RplidarScanMode> scanModes;

    if (IS_FAIL(rplidar->getAllSupportedScanModes(scanModes))) {
        ERROR_MSG("Could not get information about supported scanning modes");
        return EXIT_FAILURE;
    }
    
    RPlidar::RplidarScanMode selectedScanMode;
    if (IS_FAIL(rplidar->startScanExpress(false, scanModes[0].id, 0, &selectedScanMode))) {
        ERROR_MSG("Scan could not be started");
        return EXIT_FAILURE;
    }

    //RPlidar::RplidarScanMode selectedScanMode;
    //rplidar->startScan(false, true, 0, &selectedScanMode);


    // stop and disconnect RPlidar
    rplidar->stop();
    rplidar->stopMotor();
    rplidar->disconnect();

    return EXIT_SUCCESS;
}
